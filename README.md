# Gesture Controlled Car

A simple Arduino project where hand tilt controls a car wirelessly.

- Transmitter reads motion from MPU6050
- Commands are sent using nRF24L01
- Receiver drives motors through a motor driver

## Project Structure

- `Transmitter/sketch_may9a/sketch_may9a.ino`
- `Receiver/sketch_may9b/sketch_may9b.ino`

## How It Works

1. MPU6050 gives accelerometer values `ax` and `ay`.
2. Transmitter converts tilt into command characters:
   - `F` = Forward
   - `B` = Backward
   - `L` = Left
   - `R` = Right
   - `S` = Stop
3. Command is sent via nRF24L01.
4. Receiver reads command and sets motor pins to move the car.

## Hardware Needed

- 2 x Arduino boards (UNO/Nano compatible)
- 2 x nRF24L01 modules
- 1 x MPU6050 sensor (on transmitter side)
- 1 x Motor driver (L293D/L298N or equivalent)
- 1 x DC motor car chassis (2/4 motors)
- Jumper wires
- Suitable power supply for motors and boards

## Libraries Used

Install these Arduino libraries from Library Manager:

- Wire (built-in)
- MPU6050
- SPI (built-in)
- nRF24L01
- RF24

## Pin Details

### Common RF24 pins (both transmitter and receiver code)

- CE: `9`
- CSN: `10`

### Receiver motor pins

- IN1: `2`
- IN2: `3`
- IN3: `4`
- IN4: `5`

## Upload Steps

1. Open `Transmitter/sketch_may9a/sketch_may9a.ino` in Arduino IDE.
2. Select the transmitter board and COM port.
3. Upload transmitter sketch.
4. Open `Receiver/sketch_may9b/sketch_may9b.ino`.
5. Select the receiver board and COM port.
6. Upload receiver sketch.

## Control Logic Thresholds

In transmitter code:

- `ay < -7000` => Forward
- `ay > 7000` => Backward
- `ax < -7000` => Left
- `ax > 7000` => Right
- otherwise => Stop

You can tune these thresholds to match your hand motion comfort.

## Troubleshooting

- If no movement: check nRF24L01 wiring and power stability.
- If wrong direction: swap motor driver input wires.
- If unstable control: recalibrate MPU6050 and adjust thresholds.
- Use Serial Monitor at `9600` baud on both sides for debugging.

## Future Improvements

- Add speed control using PWM
- Add failsafe timeout on receiver
- Add battery level monitoring
- Add calibration mode button
