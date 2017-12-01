//BENGI YORUKOGLU
//131044046
//File:   CPUProgram.h
 //Created on 24 Ekim 2016 Pazartesi, 14:24
 

#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H
#include <iostream>
using namespace std;
class CPUProgram {
public:
    CPUProgram();
    CPUProgram(int option);
    CPUProgram(const char* al);
    string convert;
    int size();
    void ReadFile(const char* gelen2);
    void BuyukHarf(string& gelen);
    string getLine(int index);
    
private:
    string line[300];
    string name;
    char *alinan;
    int count;
    int secim;
};


#endif /* CPUPROGRAM_H */
