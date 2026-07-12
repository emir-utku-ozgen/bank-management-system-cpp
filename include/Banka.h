#pragma once 
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Hesap{
    public:
    int hesapId;
    string musteriAdi;
    double bakiye;
    Hesap(int id,string ad,double para):hesapId(id),musteriAdi(ad),bakiye(para){}
    void paraYatir(double miktar){
        bakiye+=miktar;
    }
    bool paraCek(double miktar){
        if(miktar>bakiye){
            return false;
        }
        bakiye-=miktar;
        return true;
    }
};

class Banka{

    private:
    vector<Hesap> hesaplar;
    string dosyaAdi;
    public:
    Banka(string dosya){
        dosyaAdi=dosya;
    }
    void hesapEkle(int id, string isim, double ilkBakiye);

   
    Hesap* hesapBul(int id);

    bool havaleYap(int gonderenId, int alanId, double miktar);


    void dosyayaKaydet();

    void dosyadanYukle();

    int toplamHesapSayisi(){
        return hesaplar.size();
    }
};