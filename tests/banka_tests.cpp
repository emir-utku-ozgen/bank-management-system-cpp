#include "Banka.h"
#include <cassert>
#include <iostream>

using namespace std;

void hesapEklemeVeBulmaTesti() {
    Banka banka("test_hesaplar.txt");
    
    
    banka.hesapEkle(1, "Emir", 2000.0);
    banka.hesapEkle(2, "Baran", 1500.0);
    assert(banka.toplamHesapSayisi() == 2);
    

    Hesap* h1 = banka.hesapBul(1);
    assert(h1 != nullptr);
    assert(h1->musteriAdi == "Emir");
    assert(h1->bakiye == 2000.0);
    
    cout << "[OK] Hesap ekleme ve bulma testleri basarili kanka!" << endl;
}

void havaleTesti() {
    Banka banka("test_hesaplar.txt");
    banka.hesapEkle(1, "Emir", 2000.0);
    banka.hesapEkle(2, "Baran", 1500.0);
    
   
    bool havaleSonucu = banka.havaleYap(1, 2, 500.0);
    assert(havaleSonucu == true);
    

    assert(banka.hesapBul(1)->bakiye == 1500.0); 
    assert(banka.hesapBul(2)->bakiye == 2000.0); 
    
    // Test 4: Yetersiz bakiye durumunda havale basarisiz olmali
    bool yetersizHavale = banka.havaleYap(1, 2, 5000.0); // Emir'de 5000 TL yok
    assert(yetersizHavale == false);
    
    cout << "[OK] Havale ve bakiye kontrol testleri basarili kanka!" << endl;
}

void dosyaIslemleriTesti() {
    // Test 5: Önce verileri dosyaya kaydedelim
    {
        Banka bankaYazici("test_hesaplar.txt");
        bankaYazici.hesapEkle(1, "Emir", 2000.0);
        bankaYazici.hesapEkle(2, "Baran", 1500.0);
        bankaYazici.dosyayaKaydet(); // txt dosyasi olusturuldu ve yazildi
    } // bankaYazici nesnesi burada RAM'den temizlendi

    // Şimdi yeni bir banka nesnesi açıp dosyadan verileri geri yükleyelim
    Banka bankaOkuyucu("test_hesaplar.txt");
    bankaOkuyucu.dosyadanYukle();
    
    // Dosyadan veriler düzgün gelmiş mi kontrol edelim
    assert(bankaOkuyucu.toplamHesapSayisi() == 2);
    assert(bankaOkuyucu.hesapBul(1)->musteriAdi == "Emir");
    assert(bankaOkuyucu.hesapBul(2)->bakiye == 1500.0);
    
    cout << "[OK] Dosya kaydetme ve geri yukleme testleri basarili kanka!" << endl;
}

int main() {
    cout << "=== BANKA SISTEMI TESTLERI BASLIYOR ===" << endl;
    
    hesapEklemeVeBulmaTesti();
    havaleTesti();
    dosyaIslemleriTesti();
    
    cout << "\nTebrikler kanka! Tum testleri eksiksiz ve basariyla gectin! \n" << endl;
    return 0;
}