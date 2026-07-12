#include "Banka.h"
#include <iostream>

using namespace std;

int main() {
    // Gerçek verilerimizi saklayacağımız ana txt dosyamız kanka
    Banka banka("banka_verileri.txt");
    
    // Program her açıldığında eğer önceden kaydedilmiş veri varsa otomatik yüklesin
    banka.dosyadanYukle();
    
    int secim = 0;
    
    while (true) {
        cout << "\n=== YILDIZ BANKA YONETIM SISTEMI ===" << endl;
        cout << "1. Yeni Hesap Ac" << endl;
        cout << "2. Hesap Bilgisi Sorgula" << endl;
        cout << "3. Para Transferi (Havale) Yap" << endl;
        cout << "4. Verileri Dosyaya Kaydet" << endl;
        cout << "5. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;
        
        if (secim == 1) {
            int id;
            string isim;
            double bakiye;
            
            cout << "Hesap ID girin: ";
            cin >> id;
            cout << "Musteri Adi girin (Bosluksuz): ";
            cin >> isim;
            cout << "Ilk Bakiye miktarini girin: ";
            cin >> bakiye;
            
            banka.hesapEkle(id, isim, bakiye);
            cout << "Hesap basariyla olusturuldu kanka! " << endl;
        } 
        else if (secim == 2) {
            int id;
            cout << "Sorgulanacak Hesap ID girin: ";
            cin >> id;
            
            Hesap* h = banka.hesapBul(id);
            if (h != nullptr) {
                cout << "\n--- HESAP BILGILERI ---" << endl;
                cout << "ID: " << h->hesapId << endl;
                cout << "Musteri: " << h->musteriAdi << endl;
                cout << "Bakiye: " << h->bakiye << " TL" << endl;
            } else {
                cout << "Boyle bir hesap bulunamadi kanka! " << endl;
            }
        } 
        else if (secim == 3) {
            int gonderen, alan;
            double miktar;
            
            cout << "Gonderen Hesap ID: ";
            cin >> gonderen;
            cout << "Alan Hesap ID: ";
            cin >> alan;
            cout << "Gonderilecek Miktar: ";
            cin >> miktar;
            
            if (banka.havaleYap(gonderen, alan, miktar)) {
                cout << "Havale islemi basariyla gerceklestirildi kanka! " << endl;
            } else {
                cout << "Havale basarisiz! ID'leri veya bakiyeyi kontrol et kanka. " << endl;
            }
        } 
        else if (secim == 4) {
            banka.dosyayaKaydet();
            cout << "Tum veriler banka_verileri.txt dosyasina guvenle kaydedildi! " << endl;
        } 
        else if (secim == 5) {
            // Çıkarken de otomatik kaydetsin ki veri kaybı yaşanmasın
            banka.dosyayaKaydet();
            cout << "Veriler kaydedildi. Gorusmek uzere kanka! " << endl;
            break;
        } 
        else {
            cout << "Gecersiz secim kanka, tekrar dene." << endl;
        }
    }
    
    return 0;
}