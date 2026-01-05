#include "IlacManager.h"
#include <iostream>
using namespace std;

/*
 * IlacManager sinifi
 * Ilaclarin eklenmesi, silinmesi ve stok islemlerini yonetir.
 */
IlacManager::IlacManager() {}

// Ilac listesini yeni bir ilac ile gunceller
void IlacManager::ilacEkle(const Ilac& ilac) {
    ilaclar.push_back(ilac);
}

// Barkod numarasina gore ilaci listeden siler
void IlacManager::ilacSil(int barkod) {
    for (int i = 0; i < ilaclar.size(); i++) {
        if (ilaclar[i].getBarkod() == barkod) {
            ilaclar.erase(ilaclar.begin() + i);
            break;
        }
    }
}

// Belirtilen ilacin stok miktarini artirir
void IlacManager::stokArtir(int barkod, int miktar) {
    Ilac* ilac = ilacBul(barkod);
    if (ilac != nullptr)
        ilac->stokArtir(miktar);
}

// Belirtilen ilacin stok miktarini azaltir
void IlacManager::stokAzalt(int barkod, int miktar) {
    Ilac* ilac = ilacBul(barkod);
    if (ilac != nullptr)
        ilac->stokAzalt(miktar);
}

// Barkod numarasina gore ilaci bulur
Ilac* IlacManager::ilacBul(int barkod) {
    for (int i = 0; i < ilaclar.size(); i++) {
        if (ilaclar[i].getBarkod() == barkod)
            return &ilaclar[i];
    }
    return nullptr;
}

// Tum ilaclari ekrana listeler
void IlacManager::listele() {
    cout << "=== ECZANE ILAC LISTESI ===" << endl;
    for (int i = 0; i < ilaclar.size(); i++) {
        cout << "Ad: " << ilaclar[i].getIlacAdi()
             << " | Barkod: " << ilaclar[i].getBarkod()
             << " | Stok: " << ilaclar[i].getStok()
             << endl;
    }
}
