#include "ReceteManager.h"
#include <iostream>
using namespace std;

/*
 * ReceteManager sinifi
 * Recetelerin olusturulmasi, ilac eklenmesi ve listelenmesini yonetir.
 */
ReceteManager::ReceteManager() {
    // Recete numaralari 1000'den baslatilir
    sonReceteNo = 1000;  
}

/*
 * Yeni bir recete olusturur
 * Recete numarasini otomatik artirir ve receteyi listeye ekler
 */
Recete* ReceteManager::receteOlustur(const Hasta& hasta) {
    sonReceteNo++;
    Recete yeni(sonReceteNo, hasta);
    receteler.push_back(yeni);
    return &receteler.back();
}

/*
 * Belirtilen receteye ilac ekler
 * Stok ve recete kontrolleri bu fonksiyonda yapilir
 */
void ReceteManager::receteyeIlacEkle(int receteNo, int barkod, int miktar, IlacManager& ilacManager) {

    // Ilac barkoda gore bulunur
    Ilac* ilac = ilacManager.ilacBul(barkod);
    if (ilac == nullptr) {
        cout << "Ilac bulunamadi!" << endl;
        return;
    }

    // Stok yeterli mi kontrol edilir
    if (ilac->getStok() < miktar) {
        cout << "Yetersiz stok!" << endl;
        return;
    }

    // Recete bulunur ve ilac eklenir
    for (int i = 0; i < receteler.size(); i++) {
        if (receteler[i].getReceteNo() == receteNo) {

            // Ilacin recete icin kopyasi olusturulur
            Ilac kopya = *ilac;
            kopya.setStok(miktar);

            // Ilac receteye eklenir
            receteler[i].ilacEkle(kopya);

            // Ana stoktan dusum yapilir
            ilacManager.stokAzalt(barkod, miktar);

            cout << "Ilac receteye eklendi." << endl;
            return;
        }
    }

    // Recete bulunamazsa
    cout << "Recete bulunamadi!" << endl;
}

/*
 * Tum receteleri ekrana listeler
 */
void ReceteManager::listele() {
    cout << "=== RECETE LISTESI ===" << endl;
    for (int i = 0; i < receteler.size(); i++) {
        receteler[i].listele();
        cout << "-----------------------" << endl;
    }
}
