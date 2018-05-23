#ifndef HAFI_H
#define HAFI_H

#include "Arduino.h"
#include "AFMotor.h"
#include "HAFI.h"
#include "SoftwareSerial.h"

class HAFI { 
    public:
        HAFI();
        void ileri();
        void sag();
        void sol();
        void geri();
        void dur();
        void dans();
        void hiz(int hiz);
        void serbestMod(boolean deger);
        void kur(int motorSayiDeger, int motor1PinDeger, int motor2PinDeger, int motor3PinDeger, int motor4PinDeger);
        void mesafeOlc(int trig, int echo);
        void bluetoothKur(int tx, int rx);
        void bluetoothKontrol();
        void engeldenKac(int onTrig, int onEcho, int arkaTrig, int arkaEcho, int minDeger, int donusYonu);
        boolean motorCalisiyor = false;
        boolean geriDeger = false;
        boolean serbestModDeger = false;
        int bluetoothVeri;
    private:
        int motor1Pin;
        int motor2Pin;
        int motor3Pin;
        int motor4Pin;
        int onMesafe;
        int arkaMesafe;
        int bluetoothObje;
        int bluetoothRX;
        int bluetoothTX;
};
 
#endif