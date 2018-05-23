#include "Arduino.h"
#include "AFMotor.h"
#include "HAFI.h"

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

HAFI::HAFI() {

}

void HAFI::ileri() {
    geriDeger = false;
    motorRunning = true;
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
}

void HAFI::sol() {
    motorRunning = true;
    geriDeger = false;
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor1.run(RELEASE);
    motor4.run(RELEASE);
}

void HAFI::sag() {
    motorRunning = true;
    geriDeger = false;
    motor1.run(FORWARD);
    motor4.run(FORWARD);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
}

void HAFI::dur() {
    motorRunning = false;
    geriDeger = false;
    motor1.run(RELEASE);
    motor2.run(RELEASE);
    motor3.run(RELEASE);
    motor4.run(RELEASE);
}

void HAFI::geri() {
    motorRunning = true;
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
