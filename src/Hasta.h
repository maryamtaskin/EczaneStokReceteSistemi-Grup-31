#ifndef HASTA_H
#define HASTA_H

#include <string>
using namespace std;

class Hasta {
private:
    string adSoyad;
    string tcKimlik;
    int yas;

public:
    Hasta();
    Hasta(string ad, string tc, int y);

    // Get - Set
    void setAdSoyad(string ad);
    void setTcKimlik(string tc);
    void setYas(int y);

    string getAdSoyad() const;
    string getTcKimlik() const;
    int getYas() const;
};

#endif
