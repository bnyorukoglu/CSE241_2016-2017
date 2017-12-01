//BENGI YORUKOGLU
//131044046
 //File:   CPUProgram.cpp
 // Created on 24 Ekim 2016 Pazartesi, 14:26
 

#include "CPUProgram.h"
#include <fstream>
#include<iostream>

using namespace std;

//readfile fonksiyonunu cagirir ve counta sifir atar! 
CPUProgram::CPUProgram(char* fname) : count(0){
     ReadFile(fname);
}

//dosyayi acar dosyadan satir satir okuyup lina arrayine doldurur.
//her satiri okuduktan sonra hepsini buyuk harfe cevirir
//eger dosya acilmazsa hata mesaji verir
void CPUProgram::ReadFile(char* gelen2){
    
    ifstream file(gelen2);
    
     if (file.is_open()) {
        while (getline(file, line[count])) {

            line[count].push_back('\n');
            count++;
            BuyukHarf(line[count]);

        }
        file.close();
    } else
        cout << "The file can not be open !";   
}
//buyuk harf fonksiyonumuzda gelen stringi asciideki karsiligi 
//kucuk harfe denk geliyosa 32 cikararak buyuk harf yapariz
void CPUProgram::BuyukHarf(string& gelen) {
    int index = 0;
    while (gelen.size() > index) {

        if ((gelen[index] < 123) && (gelen[index] > 96)) {

            gelen[index] = gelen[index] - 32;

        }
        ++index;
    }
}

//satir sayimizi return ediyor
int CPUProgram::size() {

    return count;
}

string CPUProgram::getLine(int index){
    
    return line[index-1];
    
}

