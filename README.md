An Arduino-based wireless robotic car that combines gesture control with automatic obstacle avoidance. The car is controlled by hand movements using an MPU6050 sensor while an ultrasonic sensor continuously detects obstacles to prevent collisions during movement.

Project Structure
Transmitter/sketch_may9a/sketch_may9a.ino
Receiver/sketch_may9b/sketch_may9b.ino
How It Works
MPU6050 gives accelerometer values ax and ay.
The transmitter converts hand tilt into command characters:
F = Forward
B = Backward
L = Left
R = Right
S = Stop
The command is transmitted wirelessly using the nRF24L01 module.
The receiver reads the command and controls the motors through the motor driver.
The HC-SR04 ultrasonic sensor continuously measures the distance to objects in front of the car.
If an obstacle is detected within a predefined safety distance, the receiver automatically stops (or changes direction, depending on implementation) to avoid collision.
Once the path is clear, the car resumes normal gesture-controlled operation.
Hardware Needed
2 × Arduino boards (UNO/Nano compatible)
2 × nRF24L01 modules
1 × MPU6050 sensor (Transmitter)
1 × HC-SR04 Ultrasonic Sensor
1 × Motor Driver (L293D/L298N or equivalent)
1 × DC motor car chassis (2/4 motors)
Jumper wires
Suitable power supply for motors and boards
Libraries Used

Install these Arduino libraries from the Arduino Library Manager:

Wire (built-in)
MPU6050
SPI (built-in)
nRF24L01
RF24
Pin Details
Common RF24 Pins (Both Transmitter and Receiver)
CE: 9
CSN: 10
Receiver Motor Pins
IN1: 2
IN2: 3
IN3: 4
IN4: 5
Ultrasonic Sensor Pins
Trig: 6
Echo: 7

Note: Change the Trig and Echo pins if your circuit uses different GPIO pins.

Upload Steps
Open Transmitter/sketch_may9a/sketch_may9a.ino in Arduino IDE.
Select the transmitter board and COM port.
Upload the transmitter sketch.
Open Receiver/sketch_may9b/sketch_may9b.ino.
Select the receiver board and COM port.
Upload the receiver sketch.
Control Logic Thresholds
Gesture Control
ay < -7000 → Forward
ay > 7000 → Backward
ax < -7000 → Left
ax > 7000 → Right
Otherwise → Stop

You can tune these thresholds to match your hand movement comfort.

Obstacle Detection
If the measured distance is less than the predefined threshold (e.g., 20 cm), the car automatically stops (or avoids the obstacle).
When the obstacle is removed, gesture control resumes normally.
Troubleshooting
If no movement: Check nRF24L01 wiring and power stability.
If wrong direction: Swap motor driver input wires.
If unstable gesture control: Recalibrate the MPU6050 and adjust thresholds.
If obstacle detection is inaccurate: Verify HC-SR04 wiring and adjust the distance threshold.
Use Serial Monitor at 9600 baud for debugging.
Future Improvements
Add PWM-based speed control
Implement intelligent obstacle avoidance with automatic path planning
Add failsafe communication timeout
Add battery level monitoring
Add MPU6050 calibration mode
Integrate Bluetooth or Wi-Fi control
Develop a mobile application for remote operation
