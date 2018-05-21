#include <HAFI.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <SPI.h>
#include <RFID.h>
#define SS_PIN 53
#define RST_PIN 47

HAFI HAFI;

SoftwareSerial bluetooth(13, 2);
RFID rfid(SS_PIN, RST_PIN);

int mesafeOn;
int mesafeArka;
int btVeri;

boolean motorRunning = HAFI.motorKontrol();
boolean arabaCalis = false;
boolean geri = HAFI.geriKontrol();

byte card_number[5] = {
    64, 48, 39, 168, 255
};

float getDistance(int trig, int echo) {
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  return pulseIn(echo, HIGH, 30000) / 58.0;
}

void setup() {
  SPI.begin();
  rfid.init();
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(28, OUTPUT); //buzzer
  pinMode(29, OUTPUT); //far

  HAFI.hiz(100);

  digitalWrite(28, HIGH);
  delay(500);
  digitalWrite(28, LOW);
}

void loop() {
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      for (int a = 0; a < 5; a++) {
        if (rfid.serNum[a] == card_number[a]) {
          if (arabaCalis == false) {
            arabaCalis = true;
            digitalWrite(28, HIGH);
            delay(50);
            digitalWrite(28, LOW);
          } else {
            arabaCalis = false;
            dur();
            digitalWrite(28, HIGH);
            digitalWrite(29, HIGH);
            delay(500);
            digitalWrite(28, LOW);
            digitalWrite(29, LOW);
          }
        } else arabaCalis = false;
      }
    }
  }

  if (motorRunning == true) sensorKontrol();
  if (arabaCalis == true) btKontrol();
}

void btKontrol() {
  if (bluetooth.available() > 0) {
    sensorKontrol();
    btVeri = bluetooth.read();
    //Serial.println(btVeri);

    if (btVeri == 7) HAFI.hiz(100);
    if (btVeri == 8) HAFI.hiz(500);

    if (mesafeOn == 0 || mesafeOn > 25) {
      if (btVeri == 1) HAFI.ileri();
      if (btVeri == 2) HAFI.sag();
      if (btVeri == 3) HAFI.sol();
      if (btVeri == 4) HAFI.dur();
      if (btVeri == 9) HAFI.dans();
    }

    if (mesafeArka == 0 || mesafeArka > 25) if (btVeri == 5) HAFI.geri();
  }
}

void sensorKontrol() {
  mesafeOn = getDistance(24, 25);
  mesafeArka = getDistance(36, 37);
  Serial.println(mesafeOn);
  Serial.println(mesafeArka);
  if (analogRead(A7) >= 50) digitalWrite(29, LOW);
  else digitalWrite(29, HIGH);

  if (mesafeArka < 50 & mesafeArka != 0 & motorRunning == true) {
    digitalWrite(28, HIGH);
    delay(10 * mesafeArka);
    digitalWrite(28, LOW);
  }

  if (geri == true) {
    if (mesafeArka != 0 & mesafeArka < 25 & motorRunning == true) HAFI.dur();
  }

  if (mesafeOn < 25 & mesafeOn != 0 & motorRunning == true) {
    HAFI.dur();
    delay(3000);
    HAFI.geri();
    delay(1000);
    HAFI.dur();
  }
}