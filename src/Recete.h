#ifndef RECETE_H
#define RECETE_H

#include <string>
#include <vector>
#include "Ilac.h"
#include "Hasta.h"

using namespace std;

class Recete {
private:
    int receteNo;
    Hasta hasta;
    vector<Ilac> ilaclar;

public:
    Recete();
    Recete(int no, const Hasta& h);

    void ilacEkle(const Ilac& ilac);
    void listele() const;

    int getReceteNo() const;
    Hasta getHasta() const;
    vector<Ilac> getIlaclar() const;
};

#endif
