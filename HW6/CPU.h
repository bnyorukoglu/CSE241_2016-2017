//BENGI YORUKOGLU
//131044046
//File:   CPU.h
//Created on 24 Ekim 2016 Pazartesi, 14:16


#ifndef CPU_H
#define CPU_H
#include <iostream>
#include <string>
#include "Memory.h"
using namespace std;

class CPU {
public:

    CPU();
    CPU(int option);
    
     int getReg(int index) const{
        return arr[index];
    }
    
    bool execute(string line,Memory& x);
    bool halted();
    void setReg(int index, int value);
    bool funcMov(string line,Memory& x);
    bool funcPrn(string line,Memory& x);
    bool funcSub(string line,Memory& x);
    bool funcAdd(string line,Memory& x);
    bool funcJmp(string line,Memory& x);
    bool funcDiger(string line);
    bool funJpn(string line,Memory& x);
    void movRegReg(int a, int b);
    void movRegConstant(int a, int sayi);
    void movAddressReg(unsigned int a, int b,Memory& x);
    void movRegAddress(int a, unsigned int b,Memory& x);
    void movAddressConstant(unsigned int a, int sayi,Memory& x);
    void prn(int sayi);
    void addRegReg(int a, int b);
    void addRegConstant(int a, int sayi);
    void addRegAddress(int a,unsigned int b,Memory& x);
    void subRegReg(int a, int b);
    void subRegConstant(int a, int sayi);
    void subRegAddress(int a,unsigned int b,Memory& x);
    long int sayiDegeri(string kelime);
    int noktaliBul(string kelime);
    int virgulBul(string kelime);
    void print();
    int getPC()const  {
        return PC;
    }

    void setPC(int value) {
        PC = value;
    }
private:
  
    int arr[6];
    int PC;
    bool hlt = false;
    char atama;
};


#endif /* CPU_H */
