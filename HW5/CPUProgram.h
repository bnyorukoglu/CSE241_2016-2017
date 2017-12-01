//BENGI YORUKOGLU
//131044046
//File:   CPUProgram.h
 //Created on 24 Ekim 2016 Pazartesi, 14:24
 

#ifndef CPUPROGRAM_H
#define CPUPROGRAM_H
#include <iostream>
#include<vector>
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
    string operator[](int index)const;
    CPUProgram operator+(string line)const;
    const CPUProgram& operator+=(string gelen);
    CPUProgram operator--();//prefix
    CPUProgram operator--(int);//postfix
    CPUProgram operator+( CPUProgram& y);
    CPUProgram operator()(int x,int y);
    bool operator==(const CPUProgram& y)const;
    bool operator!=(const CPUProgram& y)const;
    bool operator<(const CPUProgram& y)const;
    bool operator>=(const CPUProgram& y)const;
    bool operator>(const CPUProgram& y)const;
    bool operator<=(const CPUProgram& y)const;
    const int getCount()const{return count;};
   friend ostream& operator <<(ostream& outs,const CPUProgram& x);
    
    
private:
    vector <string> line ;
    string name;
    
    int count;
    int secim;
};


#endif /* CPUPROGRAM_H */
