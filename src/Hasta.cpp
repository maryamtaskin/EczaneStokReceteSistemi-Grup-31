#include "Hasta.h"

Hasta::Hasta() {
    adSoyad = "";
    tcKimlik = "";
    yas = 0;
}

Hasta::Hasta(string ad, string tc, int y) {
    adSoyad = ad;
    tcKimlik = tc;
    yas = y;
}

void Hasta::setAdSoyad(string ad) { adSoyad = ad; }
void Hasta::setTcKimlik(string tc) { tcKimlik = tc; }
void Hasta::setYas(int y) { yas = y; }

string Hasta::getAdSoyad() const { return adSoyad; }
string Hasta::getTcKimlik() const { return tcKimlik; }
int Hasta::getYas() const { return yas; }
