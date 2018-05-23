#include "Arduino.h"
#include "AFMotor.h"
#include "HAFI.h"
#include "SoftwareSerial.h"

AF_DCMotor motor1(motor1Pin);
AF_DCMotor motor2(motor2Pin);
AF_DCMotor motor3(motor3Pin);
AF_DCMotor motor4(motor4Pin);

SoftwareSerial bluetoothObje(bluetoothTX, bluetoothRX);

HAFI::HAFI() {

}

void HAFI::kur(int motorSayiDeger, int motor1PinDeger, int motor2PinDeger, int motor3PinDeger, int motor4PinDeger) {
    if (motorSayiDeger =! 2 || motorSayiDeger =! 4) throw 'Motor sayısı 2 ya da 4 olmalı.';
    motor1Pin = motor1PinDeger;
    motor2Pin = motor2PinDeger;
    motor3Pin = motor3PinDeger;
    motor4Pin = motor4PinDeger;
    motorSayi = motorSayiDeger;
}

void HAFI::ileri() {
    geriDeger = false;
    motorCalisiyor = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void HAFI::sol() {
    motorCalisiyor = true;
    geriDeger = false;
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor1.run(RELEASE);
    motor4.run(RELEASE);
}

void HAFI::sag() {
    motorCalisiyor = true;
    geriDeger = false;
    motor1.run(FORWARD);
    motor4.run(FORWARD);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
}

void HAFI::dur() {
    motorCalisiyor = false;
    geriDeger = false;
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void HAFI::geri() {
    motorCalisiyor = true;
    geriDeger = true;
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
}

void HAFI::dans() {
    geriDeger = false;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
    delay(1000);
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
    delay(1000);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor1.run(RELEASE);
    motor4.run(RELEASE);
    delay(1000);
    motor1.run(FORWARD);
    motor4.run(FORWARD);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    delay(1000);
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void HAFI::hiz(int hiz) {
    motor1.setSpeed(hiz);
    motor2.setSpeed(hiz);
    motor3.setSpeed(hiz);
    motor4.setSpeed(hiz);
}

void HAFI::serbestMod(boolean deger) {
    serbestModDeger = deger;
}

void HAFI::mesafeOlc(int trig, int echo) {
    pinMode(trig, OUTPUT);
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo, HIGH, 30000) / 58.0;
}

void HAFI::bluetoothKur(int tx, int rx) {
    bluetoothTX = tx;
    bluetoothRX = rx;
    bluetoothObje.begin(9600);
}

void HAFI::bluetoothKontrol() {
    bluetoothVeri = bluetoothObje.read();
}

void HAFI::engeldenKac(int onTrig, int onEcho, int arkaTrig, int arkaEcho, int minDeger, int donusYonu) {
    onMesafe = mesafeOlc(onTrig, onEcho);
    arkaMesafe = mesafeOlc(arkaTrig, arkaEcho);

    if (onMesafe < minDeger & onMesafe =! 0) {
        if (donusYonu == 0) sag();
        if (donusYonu == 1) sol();
    } else ileri();

    if (arkaMesafe < minDeger & arkaMesafe =! 0) {
        if (donusYonu == 0) sag();
        if (donusYonu == 1) sol();
    } else ileri();
}