# <div align="center"><img src="https://readme-typing-svg.demolab.com?font=Orbitron&weight=900&size=36&duration=1800&pause=400&color=00F5FF&center=true&vCenter=true&multiline=true&repeat=true&width=1000&height=120&lines=SEAMS;Smart+Environmental+Alert+%26+Monitoring+System;Scan+%E2%80%A2+Sense+%E2%80%A2+Alert+%E2%80%A2+Respond" alt="Animated SEAMS title" /></div>

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:020617,25:0f172a,50:0ea5e9,75:22d3ee,100:67e8f9&height=280&section=header&text=SEAMS&fontSize=78&fontColor=ffffff&animation=twinkling&fontAlignY=36&desc=Radar-inspired%20embedded%20safety%20monitoring%20system&descAlignY=58&descAlign=50" alt="SEAMS header banner" />
</div>

<div align="center">







</div>

<div align="center">
  <img src="https://github-profile-trophy.vercel.app/?username=Naman2641&theme=algolia&no-frame=true&no-bg=true&row=1&column=6&margin-w=10" alt="GitHub trophies" />
</div>

<div align="center">
  <img src="https://streak-stats.demolab.com?user=Naman2641&theme=transparent&hide_border=true&ring=22d3ee&fire=38bdf8&currStreakLabel=e2e8f0&sideLabels=e2e8f0&currStreakNum=ffffff&sideNums=ffffff" alt="GitHub streak" />
</div>

<div align="center">
  <img src="https://readme-jokes.vercel.app/api?theme=algolia&hideBorder" alt="Random dev joke" />
</div>

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExNjRmMXMwdWRoYWVmdWs4NWMwdDdreHZwZnBjd2R5aTRwaDU4bm8xbiZlcD12MV9naWZzX3NlYXJjaCZjdD1n/3o7TKsQ8UQKZxXQj0Y/giphy.gif" width="28" /> Mission Profile

SEAMS is an Arduino-based smart monitoring system that scans physical surroundings using an ultrasonic sensor and servo motor, then reacts through LEDs, buzzer output, LCD status text, and serial telemetry. The repository currently contains `main.ino` and `README.md`, and the firmware implements distance measurement, servo sweep motion, local alert outputs, and serial-controlled risk state changes. [1]

The project supports three main operating states — `SAFE`, `HIGH`, and `EMERGENCY` — while also accepting incoming commands like `CMD:RISK:HIGH`, `CMD:RISK:EMERGENCY`, and `CMD:SAFE` over Serial. It also emits structured telemetry such as `DISTANCE:<value>,ANGLE:<value>` and reset events, which makes it ready for future integration with a website or dashboard. [1]

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExZnhyMHQweTFpczhxbmp6eW5rOW9jc2V4dXZ0Nm1tM2t2bW1wMnA4aSZlcD12MV9naWZzX3NlYXJjaCZjdD1n/l0MYt5jPR6QX5pnqM/giphy.gif" width="28" /> Visual Command Deck

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&color=0:0f172a,100:0ea5e9&height=120&section=header&text=LIVE%20SAFETY%20SCAN&fontSize=36&fontColor=ffffff&animation=blink" alt="Live safety scan banner" />
</div>

```mermaid
flowchart LR
    A[Ultrasonic Sensor] --> B[Arduino Brain]
    C[Reset Button] --> B
    D[Serial Commands from Web/App] --> B
    B --> E[Servo Scanner]
    B --> F[I2C LCD]
    B --> G[Green LED]
    B --> H[Red LED]
    B --> I[Buzzer Alarm]
```

<div align="center">
  <img src="https://img.shields.io/badge/SCAN_RANGE-0%C2%B0_to_180%C2%B0-22c55e?style=flat-square" alt="Scan range" />
  <img src="https://img.shields.io/badge/SERIAL-9600_BAUD-f59e0b?style=flat-square" alt="Serial baud" />
  <img src="https://img.shields.io/badge/I2C_LCD-0x27_or_0x3F-a855f7?style=flat-square" alt="LCD addresses" />
  <img src="https://img.shields.io/badge/FEEDBACK-LCD+LED+BUZZER-ef4444?style=flat-square" alt="Feedback outputs" />
</div>

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExdzQyOTM1dGE4MTdxY3hyN2V5dXZvOXJld3I3c2ZqYmI1ZW55Y3g2NSZlcD12MV9naWZzX3NlYXJjaCZjdD1n/xTiTnuhyBF54B852nK/giphy.gif" width="28" /> Features That Move

<table>
<tr>
<td width="50%">

### 📡 Radar-style sweep
The servo sweeps across the environment from `0°` to `180°` and back continuously, creating a dynamic scan pattern for environmental monitoring. [1]

</td>
<td width="50%">

### 📏 Live telemetry stream
The firmware transmits values in a structured `DISTANCE:x,ANGLE:y` format so the sensing logic can be visualized externally. [1]

</td>
</tr>
<tr>
<td width="50%">

### 🚨 Multi-risk states
The system switches behavior based on `SAFE`, `HIGH`, and `EMERGENCY` modes with separate output actions. [1]

</td>
<td width="50%">

### 🖥️ Human-readable LCD feedback
The I2C LCD shows initialization text, safe state updates, and emergency messages for direct on-device status reporting. [1]

</td>
</tr>
<tr>
<td width="50%">

### 🔕 One-press alarm silence
The hardware reset button forces the system back to `SAFE`, silences the buzzer, and sends reset events over serial. [1]

</td>
<td width="50%">

### 🔌 Website-ready command bridge
Serial command handling already allows a future website or Python app to control system risk states in real time. [1]

</td>
</tr>
</table>

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExdXhtNnJ6d2l4b2hmNmo3dWJhZ2UzMnI0bnFxaWhnZXdoaGNuM2E4NyZlcD12MV9naWZzX3NlYXJjaCZjdD1n/26BRv0ThflsHCqDrG/giphy.gif" width="28" /> Hardware Matrix

| Component | Role | Pin |
|---|---|---:|
| Ultrasonic TRIG | Trigger pulse output | D9 [1] |
| Ultrasonic ECHO | Echo pulse input | D10 [1] |
| Green LED | Safe indication | D2 [1] |
| Red LED | Risk indication | D3 [1] |
| Buzzer | Audible alarm | D4 [1] |
| Reset Button | Manual alarm reset | D5 [1] |
| Servo Motor | Scan sweep | D6 [1] |
| I2C LCD | Status display | SDA/SCL [1] |

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExdHV6YnFsbWJmMGYyYjV5eWlra3J0c2VlYWhxczFzOHNlYjFwbXhkaiZlcD12MV9naWZzX3NlYXJjaCZjdD1n/3o7TKTDn976rzVgky4/giphy.gif" width="28" /> Operating States

```mermaid
stateDiagram-v2
    [*] --> SAFE
    SAFE --> HIGH: CMD:RISK:HIGH
    SAFE --> EMERGENCY: CMD:RISK:EMERGENCY
    HIGH --> SAFE: CMD:SAFE / RESET
    EMERGENCY --> SAFE: CMD:SAFE / RESET
    HIGH --> EMERGENCY: Escalation
```

- **SAFE** — Green LED on, buzzer off, LCD shows safe monitoring text, servo continues scanning. [1]
- **HIGH** — Red LED on, buzzer active, LCD shows `Risk: HIGH`. [1]
- **EMERGENCY** — Red LED on, buzzer active, LCD shows `Risk: EMERGENCY!` and prompts a user response. [1]
- **RESET** — Forces safe state and emits `EVENT:RESET_PRESSED` for external systems. [1]

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExbHNxMXl6MGRkNGxudHlqcjNmdWt0dTB1cnNjbDNubmQ2MzAzMmc0NyZlcD12MV9naWZzX3NlYXJjaCZjdD1n/f3iwJFOVOwuy7K6FFw/giphy.gif" width="28" /> Serial Interface

### Incoming commands

```text
CMD:RISK:HIGH
CMD:RISK:EMERGENCY
CMD:SAFE
```

### Outgoing events

```text
DISTANCE:42,ANGLE:97
EVENT:RESET_PRESSED
```

This protocol is already implemented in the current repository and is ideal for building a web dashboard or host control interface on top of the Arduino firmware. [1]

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExMGo0eW16d2F1enRnNWxjbnQxcnIycnRtMXRoeG5wZXVhOWM0a2lmMSZlcD12MV9naWZzX3NlYXJjaCZjdD1n/l41YtZOb9EUABnuqA/giphy.gif" width="28" /> Firmware Highlights

```cpp
if (incomingCommand == "CMD:RISK:HIGH") riskState = "HIGH";
else if (incomingCommand == "CMD:RISK:EMERGENCY") riskState = "EMERGENCY";
else if (incomingCommand == "CMD:SAFE") riskState = "SAFE";
```

```cpp
Serial.print("DISTANCE:");
Serial.print(distance);
Serial.print(",ANGLE:");
Serial.println(servoAngle);
```

```cpp
if (riskState == "EMERGENCY") {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  tone(BUZZER_PIN, 1000);
}
```

These behaviors match the current `main.ino` implementation that powers the repo. [1]

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExaW1jbTVoNnN1Yno4NjZhc2djMmk0eXJ5a3pib2lvaXNtNWdxc3dkZCZlcD12MV9naWZzX3NlYXJjaCZjdD1n/3orieTfp1MeFLiBQR2/giphy.gif" width="28" /> Launch Sequence

```bash
git clone https://github.com/Naman2641/SEAMS.git
cd SEAMS
```

1. Open `main.ino` in Arduino IDE. [1]
2. Install `Wire`, `LiquidCrystal_I2C`, and `Servo` libraries before upload. [1]
3. Select the correct board and COM port. [1]
4. Upload the firmware. [1]
5. Open Serial Monitor at `9600 baud` to view telemetry and command interaction. [1]

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExOXcxeWNoaHBxY2p4bmFxOWxjcHRucmMzaGdtNmQ5NTEwdmoyMzFrNiZlcD12MV9naWZzX3NlYXJjaCZjdD1n/13HgwGsXF0aiGY/giphy.gif" width="28" /> Upgrade Path

If you continue building SEAMS, the most natural next steps are a radar-style web dashboard, a threat heatmap from angle-distance telemetry, anomaly scoring, multi-sensor fusion, and remote alert transport through GSM or desktop software. Those future directions fit the existing command-and-telemetry architecture already present in the repo. [1]

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExb25qb3Y4MWRkZjJ0cGw0a25mbnZqOTBhb3lndmVhZ2h3cjdqejl0aCZlcD12MV9naWZzX3NlYXJjaCZjdD1n/5VKbvrjxpVJCM/giphy.gif" width="28" /> Repo Layout

```text
SEAMS/
├── README.md
└── main.ino
```

The current repository view shows `README.md` and `main.ino` on the `main` branch. [1]

***

## <img src="https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExM3pkcmlkM2xzNjBoNm5xazYwYW1ncjYzdnd3eHZ0NWg3OGVkYTZjbiZlcD12MV9naWZzX3NlYXJjaCZjdD1n/xT0xeJpnrWC4XWblEk/giphy.gif" width="28" /> Author Console

<div align="center">
  <img src="https://komarev.com/ghpvc/?username=Naman2641&style=for-the-badge&color=0ea5e9" alt="Profile views" />
  <img src="https://img.shields.io/badge/Built%20by-Naman%20Kumar%20Gupta-111827?style=for-the-badge" alt="Author badge" />
  <img src="https://img.shields.io/badge/Theme-Radar%20Intelligence-06b6d4?style=for-the-badge" alt="Theme badge" />
</div>

**Naman Kumar Gupta** — embedded systems, Arduino prototyping, and hardware-software integration. [1]

<div align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:67e8f9,50:0ea5e9,100:020617&height=140&section=footer&animation=twinkling" alt="SEAMS footer banner" />
</div>
