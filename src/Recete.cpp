#include "Recete.h"
#include <iostream>
using namespace std;

/*
 * Recete sinifi
 * Hastaya ait recete bilgilerini ve recetedeki ilaclari tutar.
 */
Recete::Recete() {
    // Varsayilan recete numarasi
    receteNo = 0;
}

/*
 * Parametreli constructor
 * Recete numarasi ve hasta bilgisi ile recete olusturur
 */
Recete::Recete(int no, const Hasta& h) {
    receteNo = no;
    hasta = h;
}

// Receteye yeni bir ilac ekler
void Recete::ilacEkle(const Ilac& ilac) {
    ilaclar.push_back(ilac);
}

// Recete bilgilerini ve ilac listesini ekrana yazdirir
void Recete::listele() const {
    cout << "=== RECETE BILGILERI ===" << endl;
    cout << "Recete No: " << receteNo << endl;
    cout << "Hasta: " << hasta.getAdSoyad()
         << " | TC: " << hasta.getTcKimlik() << endl;

    cout << "--- Ilaclar ---" << endl;
    for (int i = 0; i < ilaclar.size(); i++) {
        cout << ilaclar[i].getIlacAdi()
             << " | Barkod: " << ilaclar[i].getBarkod()
             << " | Stok: " << ilaclar[i].getStok()
             << endl;
    }
}

// Recete numarasini dondurur
int Recete::getReceteNo() const {
    return receteNo;
}

// Receteye ait hasta bilgisini dondurur
Hasta Recete::getHasta() const {
    return hasta;
}

// Recetede bulunan ilac listesini dondurur
vector<Ilac> Recete::getIlaclar() const {
    return ilaclar;
}
