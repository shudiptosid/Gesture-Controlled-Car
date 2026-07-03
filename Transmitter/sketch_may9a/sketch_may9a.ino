#include <Wire.h>
#include <MPU6050.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

MPU6050 mpu;

RF24 radio(9, 10);

const byte address[6] = "00001";

char data;

void setup() {

  Serial.begin(9600);

  Wire.begin();
  mpu.initialize();

  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);

  radio.stopListening();

  Serial.println("Transmitter Ready");
}

void loop() {

  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  Serial.print("AX: ");
  Serial.print(ax);

  Serial.print(" AY: ");
  Serial.println(ay);

  if (ay < -7000) {
    data = 'F';
  }

  else if (ay > 7000) {
    data = 'B';
  }

  else if (ax < -7000) {
    data = 'L';
  }

  else if (ax > 7000) {
    data = 'R';
  }

  else {
    data = 'S';
  }

  radio.write(&data, sizeof(data));

  delay(100);
}