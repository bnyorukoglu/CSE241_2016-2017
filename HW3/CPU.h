//BENGI YORUKOGLU
//131044046
 //File:   CPU.h
//Created on 24 Ekim 2016 Pazartesi, 14:16
 

#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <string>
using namespace std;
class CPU {
    
public:
    int getReg(int index) { return arr[index]; }
    CPU(char value);
    bool execute(string line);
    bool halted();
    void setReg();
    bool funcMov(string line);
    bool funcPrn(string line);
    bool funcSub(string line);
    bool funcAdd(string line);
    bool funcJmp(string line); 
    bool funcDiger(string line);
    void movFonk(int& reg1, int& reg2);
    void movFonkConstant(int& reg1,int sayi);
    void prn(int sayi);
    void addRegReg(int& reg1, int reg2);
    void addRegConstant(int& reg1,int sayi);
    void subRegReg(int& reg1,int reg2);
    void subRegConstant(int& reg1,int sayi);
    long int sayiDegeri(string kelime);
    int noktaliBul(string kelime);
    int virgulBul(string kelime);
    int getPC(){ return PC; }
    void setPC(int value){ PC=value;}
private:
    void print();
    int arr[6];
    int PC;
    bool hlt=false;
    char atama;
};


#endif /* CPU_H */

