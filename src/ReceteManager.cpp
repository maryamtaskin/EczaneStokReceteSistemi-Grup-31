#include "ReceteManager.h"
#include <iostream>
using namespace std;

ReceteManager::ReceteManager() {
    sonReceteNo = 1000;  
}

Recete* ReceteManager::receteOlustur(const Hasta& hasta) {
    sonReceteNo++;
    Recete yeni(sonReceteNo, hasta);
    receteler.push_back(yeni);
    return &receteler.back();
}

void ReceteManager::receteyeIlacEkle(int receteNo, int barkod, int miktar, IlacManager& ilacManager) {

    Ilac* ilac = ilacManager.ilacBul(barkod);
    if (ilac == nullptr) {
        cout << "Ilac bulunamadi!" << endl;
        return;
    }

    if (ilac->getStok() < miktar) {
        cout << "Yetersiz stok!" << endl;
        return;
    }

    for (int i = 0; i < receteler.size(); i++) {
        if (receteler[i].getReceteNo() == receteNo) {
            Ilac kopya = *ilac;
            kopya.setStok(miktar);

            receteler[i].ilacEkle(kopya);

            ilacManager.stokAzalt(barkod, miktar);

            cout << "Ilac receteye eklendi." << endl;
            return;
        }
    }

    cout << "Recete bulunamadi!" << endl;
}

void ReceteManager::listele() {
    cout << "=== RECETE LISTESI ===" << endl;
    for (int i = 0; i < receteler.size(); i++) {
        receteler[i].listele();
        cout << "-----------------------" << endl;
    }
}
