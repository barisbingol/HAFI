#include <HAFI.h>

HAFI SimpleHAFI;

void setup() {
    SimpleHAFI.kur(4, 1, 2, 3, 4);
    SimpleHAFI.hiz(50);
}

void loop() {
    SimpleHAFI.engeldenKac(2, 3, 4, 5, 20, 0);
}
