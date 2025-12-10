#include "Recete.h"
#include <iostream>
using namespace std;

Recete::Recete() {
    receteNo = 0;
}

Recete::Recete(int no, const Hasta& h) {
    receteNo = no;
    hasta = h;
}

void Recete::ilacEkle(const Ilac& ilac) {
    ilaclar.push_back(ilac);
}

void Recete::listele() const {
    cout << "=== RECETE BILGILERI ===" << endl;
    cout << "Recete No: " << receteNo << endl;
    cout << "Hasta: " << hasta.getAdSoyad() << " | TC: " << hasta.getTcKimlik() << endl;

    cout << "--- Ilaclar ---" << endl;
    for (int i = 0; i < ilaclar.size(); i++) {
        cout << ilaclar[i].getIlacAdi()
            << " | Barkod: " << ilaclar[i].getBarkod()
            << " | Stok: " << ilaclar[i].getStok() 
            << endl;
    }
}

int Recete::getReceteNo() const { return receteNo; }
Hasta Recete::getHasta() const { return hasta; }
vector<Ilac> Recete::getIlaclar() const { return ilaclar; }
