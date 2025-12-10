#ifndef ILAC_H
#define ILAC_H

#include <string>
using namespace std;

class Ilac {
private:
    string ilacAdi;
    int barkod;
    int stok;

public:
    Ilac();
    Ilac(string ad, int barkodNo, int adet);

    // Set-get fonksiyonlari
    void setIlacAdi(string ad);
    void setBarkod(int barkodNo);
    void setStok(int adet);

    string getIlacAdi() const;
    int getBarkod() const;
    int getStok() const;

    // stok islemleri
    void stokArtir(int miktar);
    void stokAzalt(int miktar);
};

#endif
