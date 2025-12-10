#ifndef ILACMANAGER_H
#define ILACMANAGER_H

#include <vector>
#include "Ilac.h"

using namespace std;

class IlacManager {
private:
    vector<Ilac> ilaclar;

public:
    IlacManager();

    void ilacEkle(const Ilac& ilac);
    void ilacSil(int barkod);
    void stokArtir(int barkod, int miktar);
    void stokAzalt(int barkod, int miktar);

    void listele();
    Ilac* ilacBul(int barkod);
};

#endif
