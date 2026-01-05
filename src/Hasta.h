#ifndef HASTA_H
#define HASTA_H

#include <string>
using namespace std;

/*
 * Hasta sinifi
 * Hastaya ait temel bilgileri (ad, TC, yas) tutar.
 * Eczane stok ve recete yonetim sisteminde kullanilir.
 */
class Hasta {
private:
    // Hasta bilgileri
    string adSoyad;
    string tcKimlik;
    int yas;

public:
    // Constructor metotlari
    Hasta();
    Hasta(string ad, string tc, int y);

    // Set metotlari: hasta bilgilerini gunceller
    void setAdSoyad(string ad);
    void setTcKimlik(string tc);
    void setYas(int y);

    // Get metotlari: hasta bilgilerini dondurur
    string getAdSoyad() const;
    string getTcKimlik() const;
    int getYas() const;
};

#endif
