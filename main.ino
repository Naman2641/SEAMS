#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#define TRIG_PIN 9
#define ECHO_PIN 10
#define GREEN_LED 2
#define RED_LED 3
#define BUZZER_PIN 4
#define RESET_BTN 5
#define SERVO_PIN 6
LiquidCrystal_I2C* lcd = nullptr;
Servo scannerServo;
// Global State
int servoAngle = 0;
int sweepDirection = 1; 
unsigned long lastSweepTime = 0;
const int sweepDelay = 60; // Slower sweep prevents voltage drops
String riskState = "SAFE"; 
String lastRiskState = "NONE"; 
String incomingCommand = "";
// Button Debounce
unsigned long lastButtonPressTime = 0;
int lastButtonState = HIGH;
void setup() {
  Serial.begin(9600);
  Wire.begin(); 
  
  // Prevent Wire library from freezing forever on loose I2C wires
  #if defined(__AVR__)
  Wire.setWireTimeout(3000, true); 
  #endif
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RESET_BTN, INPUT_PULLUP);
  
  // Guarantee silence on boot
  noTone(BUZZER_PIN);
  
  // --- GODMODE: SAFE I2C SCANNER ---
  Wire.beginTransmission(0x27);
  if (Wire.endTransmission() == 0) {
    lcd = new LiquidCrystal_I2C(0x27, 16, 2);
  } else {
    Wire.beginTransmission(0x3F);
    if (Wire.endTransmission() == 0) {
      lcd = new LiquidCrystal_I2C(0x3F, 16, 2);
    }
  }
  if (lcd != nullptr) {
    lcd->init();
    lcd->backlight();
    lcd->setCursor(0, 0);
    lcd->print("SEAMS System");
    lcd->setCursor(0, 1);
    lcd->print("Initializing...");
  }
  
  scannerServo.attach(SERVO_PIN);
  scannerServo.write(0);
  
  delay(1500);
  if (lcd != nullptr) lcd->clear();
  // Startup Chirp
  tone(BUZZER_PIN, 2000);
  delay(150);
  noTone(BUZZER_PIN);
}
long getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // 30ms timeout prevents freezing
  long distance = (duration * 0.034) / 2;
  
  if (distance == 0) return 999;
  return distance;
}
void loop() {
  // 1. Process Incoming Website Commands safely
  while (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n') {
      incomingCommand.trim();
      if (incomingCommand == "CMD:RISK:HIGH") riskState = "HIGH";
      else if (incomingCommand == "CMD:RISK:EMERGENCY") riskState = "EMERGENCY";
      else if (incomingCommand == "CMD:SAFE") riskState = "SAFE";
      incomingCommand = "";
    } else {
      incomingCommand += c;
    }
  }
  // 2. Hardware Button Logic (Debounced & Safe)
  int reading = digitalRead(RESET_BTN);
  if (reading == LOW && lastButtonState == HIGH) {
    if (millis() - lastButtonPressTime > 300) {
      lastButtonPressTime = millis();
      
      // Force hardware safe state
      riskState = "SAFE";
      lastRiskState = "NONE"; 
      
      noTone(BUZZER_PIN);
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      
      if (lcd != nullptr) {
        lcd->clear();
        lcd->print("Alarm Silenced");
      }
      
      // Send multiple times to guarantee transmission
      Serial.println("EVENT:RESET_PRESSED"); 
      Serial.println("EVENT:RESET_PRESSED"); 
      
      delay(1000); 
      if (lcd != nullptr) lcd->clear();
    }
  }
  lastButtonState = reading;
  // 3. Act on State Changes only once (Prevents buzzer/LCD crashing)
  if (riskState != lastRiskState) {
    if (lcd != nullptr) lcd->clear();
    
    if (riskState == "EMERGENCY") {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      
      tone(BUZZER_PIN, 1000); // PASSIVE BUZZER ON
      
      if (lcd != nullptr) {
        lcd->setCursor(0, 0);
        lcd->print("Risk: EMERGENCY!");
        lcd->setCursor(0, 1);
        lcd->print("Please check in!");
      }
    } 
    else if (riskState == "HIGH") {
      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
      
      tone(BUZZER_PIN, 1000); // PASSIVE BUZZER ON FOR HIGH RISK
      
      if (lcd != nullptr) {
        lcd->setCursor(0, 0);
        lcd->print("Risk: HIGH      ");
        lcd->setCursor(0, 1);
        lcd->print("No movement...  ");
      }
    } 
    else {
      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);
      noTone(BUZZER_PIN); 
    }
    
    lastRiskState = riskState; 
  }
  // 4. Update Safe LCD Display periodically without clearing the screen
  if (riskState == "SAFE" && (millis() % 2000 < 50)) { 
    if (lcd != nullptr) {
      lcd->setCursor(0, 0);
      lcd->print("Status: Safe    ");
      lcd->setCursor(0, 1);
      lcd->print("Scanning Area   ");
    }
  }
  // 5. Send telemetry data
  long distance = getDistance();
  Serial.print("DISTANCE:");
  Serial.print(distance);
  Serial.print(",ANGLE:");
  Serial.println(servoAngle);
  // 6. Sweep Servo
  if (millis() - lastSweepTime > sweepDelay) {
    lastSweepTime = millis();
    servoAngle += sweepDirection;
    
    if (servoAngle >= 180) {
      servoAngle = 180;
      sweepDirection = -1;
    } else if (servoAngle <= 0) {
      servoAngle = 0;
      sweepDirection = 1;
    }
    scannerServo.write(servoAngle);
  }
}

