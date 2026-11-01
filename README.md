# ERC Induction

My projects and assignments for the ERC induction, built and simulated using [Tinkercad Circuits](https://www.tinkercad.com/).

## Repository Structure

```text
ERC-induction/
├── Week1/
│   ├── Task1/
│   ├── Task2/
│   ├── ...
│   └── Links.md
├── Week2/
│   ├── Task1/
│   ├── Task2/
│   ├── Task3/
│   └── Links.md
├── Week3/
│   ├── Task1/
│   ├── Task2/
│   ├── Task3/
│   └── Links.md
└── README.md
```

Each task folder contains the Arduino code (`.ino`) and the circuit file exported from Tinkercad (`.brd`). Each week's `links.md` contains links to the Tinkercad projects.

## Assignments

### Week 1 — Arduino Basics

- **Task 1:** Debug an LED blink program and explain its intended behaviour.
- **Task 2:** Control LED blink speed through Serial input and brightness using a potentiometer. Optional bonus: add a pushbutton ON/OFF override.
- **Task 3:** Build an ultrasonic distance indicator using an HC-SR04 and an RGB LED. Optional bonus: add a buzzer for very close objects.
- **Task 4:** Trace and explain the provided code.

[Tinkercad projects →](Week1/links.md)

### Week 2 — Displays, Timing and Communication

- **Task 1:** Build a calculator with Serial input and LCD output, with an interrupt-based ON/OFF pushbutton. Optional bonus: use a 4×4 keypad for input.
- **Task 2:** Build an LDR-based box alarm with an RGB LED and buzzer. Once triggered, the alarm stays active until a reset button is pressed.
- **Task 3:** Use I2C communication between two Arduinos to display a message on an LCD when a button on the other Arduino is pressed. Optional bonus: use UART instead.

[Tinkercad projects →](Week2/links.md)

### Week 3 — Motors and Sensors

- **Task 1:** Build a torch-following car using two LDRs, two motors and an L293D motor driver. The car turns towards the illuminated sensor, moves forward when both are illuminated, and stops when neither is illuminated.
- **Task 2:** Control a servo using six pushbuttons: five for adding 15°, 30°, 60°, 90° and 180°, and one for resetting to 0°. Optional bonus: display the number of turns on an LCD.
- **Task 3:** Build a servo-mounted ultrasonic scanner that sweeps between 0° and 180° and indicates detected obstacles using an LED and Serial output.

[Tinkercad projects →](Week3/links.md)