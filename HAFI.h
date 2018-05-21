#ifndef HAFI_H
#define HAFI_H

#include "Arduino.h"
#include "AFMotor.h"
#include "HAFI.h"

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
        void motorKontrol();
        void geriKontrol();
        void serbestMod(boolean deger);
        boolean motorRunning = false;
        boolean arabaCalis = false;
        boolean geriDeger = false;
        boolean serbestModDeger = false;
};
 
#endif