#ifndef RECETE_H
#define RECETE_H

#include <string>
#include <vector>
#include "Ilac.h"
#include "Hasta.h"

using namespace std;

/*
 * Recete sinifi
 * Bir hastaya ait recete bilgilerini ve recetede bulunan
 * ilac listesini tutar.
 */
class Recete {
private:
    // Receteye ait bilgiler
    int receteNo;
    Hasta hasta;
    vector<Ilac> ilaclar;

public:
    // Constructor metotlari
    Recete();
    Recete(int no, const Hasta& h);

    // Recete islemleri
    void ilacEkle(const Ilac& ilac);
    void listele() const;

    // Get metotlari
    int getReceteNo() const;
    Hasta getHasta() const;
    vector<Ilac> getIlaclar() const;
};

#endif
