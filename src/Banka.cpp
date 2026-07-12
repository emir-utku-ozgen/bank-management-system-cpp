#include "Banka.h"
#include <fstream>

using namespace std;

void Banka::hesapEkle(int id,string ad,double bakiye){
    Hesap yeniHesap(id,ad,bakiye);
    hesaplar.push_back(yeniHesap);
}
Hesap* Banka::hesapBul(int id){
    for(size_t i=0;i<hesaplar.size();i++){
        if(hesaplar[i].hesapId==id){
            return &hesaplar[i];
        }
    }
    return nullptr;
}
bool Banka::havaleYap(int gonderenId,int alanId,double miktar){
    Hesap gönderen=hesapBul(gonderenId);
    Hesap alan=hesapBul(alanId);
    if(gonderen==nullptr || alan==nullptr){
        return false;
    }
    if(gonderen->paraCek(miktar)==false){
        return false;
    }
    alan->paraYatir(miktar);
    return true;
}

void Banka:: dosyayaKaydet(){
    ofstream dosya(dosyaAdi);
    if(dosya.is_open()){
        for(size_t i=0;i<hesaplar.size();i++){
            dosya << hesaplar[i].hesapId << " " 
                  << hesaplar[i].musteriAdi << " " 
                  << hesaplar[i].bakiye << endl;
        }
        dosya.close();
    }
}
void Banka::dosyadanYukle() {
   
    ifstream dosya(dosyaAdi);
    
    if (dosya.is_open()) {
        hesaplar.clear();
        int id;
        string isim;
        double bak;
        while (dosya >> id >> isim >> bak) {
            hesapEkle(id, isim, bak);
        }
        dosya.close(); 
    }
}