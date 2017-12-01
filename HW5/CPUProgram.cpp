//BENGI YORUKOGLU
//131044046
 //File:   CPUProgram.cpp
 // Created on 24 Ekim 2016 Pazartesi, 14:26
 

#include "CPUProgram.h"
#include <fstream>
#include<iostream>
#include<vector>
using namespace std;

//readfile fonksiyonunu cagirir ve counta sifir atar! 
CPUProgram::CPUProgram(const char* fname) : count(0){
     ReadFile(fname);
}
CPUProgram::CPUProgram(int option){
    
    count=0;
    secim=option;
}
CPUProgram::CPUProgram(){
    count=0;
}
//dosyayi acar dosyadan satir satir okuyup lina arrayine doldurur.
//her satiri okuduktan sonra hepsini buyuk harfe cevirir
//eger dosya acilmazsa hata mesaji verir
void CPUProgram::ReadFile(const char* gelen2){
    
    ifstream file(gelen2);
    
     if (file.is_open()) {
         
       
        string temp;
        while (getline(file,temp)) {
            
            temp.push_back('\n');
           
           
            
            BuyukHarf(temp);
            
            line.push_back(temp);
            
           
            
            count++;
           
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
    
    
    return line.at(index);
    
}

//gelen indexteki stringi return eder
string CPUProgram::operator[](int index)const{
    
    if(index>=count){
        
        cout<<"HATA!!!";
        return"";
    }
    return line[index];
    
    
}
//parametre olarak CPUProgram ve string olarak line alir
//gelen satiri son satira ekler.
CPUProgram CPUProgram::operator+(string gelen)const{
    
    CPUProgram yeni;
    for(int i=0;i<count;++i){
             yeni+=line[i];
    }
    
    yeni.line.push_back(gelen);
    yeni.count++;
    
    return yeni;

}

//Operator+= that takes an instruction line as a string and appends the 
//instruction to the end of the program.
const CPUProgram& CPUProgram::operator+=(string gelen){
    
    if(gelen==""){
        cout<<"HATA!!!"<<endl;
        return *this;
    }
    line.push_back(gelen);
    count++;
    
    return *this;
    
}

//2 program aliyor.2.ciyi 1.ye ekleyip yeni program return ediyor
CPUProgram CPUProgram::operator+( CPUProgram& y){
    
    CPUProgram yeni=*this;
    //1.yi ekliyor
//    for(int i=0; i<getCount() ;++i){
//        
//        yeni.line.push_back(line[i]);
//        yeni.count++;
//       
//        
//    }
//    
    
    for(int i=0; i<y.getCount();++i){
        
        yeni.line.push_back(y.line[i]);
        yeni.count++;
        
    }
    
    return yeni;
    
}
//size karsilastirma
bool CPUProgram::operator==(const CPUProgram& y)const{
    
    return(count==y.getCount());
    
}

//size karsilastirma
bool CPUProgram::operator!=(const CPUProgram& y)const{
    
    if(count==y.getCount())
        return false;
    else
        return true;
    
}


//size karsilastirma
bool CPUProgram::operator<(const CPUProgram& y)const{
    
    if(count<y.getCount())
        return true;
    else
        return false;

    
}

//size karsilastirma 
bool CPUProgram::operator>=(const CPUProgram& y)const{
    
    if(count>=y.getCount())
        return true;
    else
        return false;

}
bool CPUProgram::operator>(const CPUProgram& y)const{
    
    if(count>y.getCount())
        return true;
    else
        return false;
    
    
    
}
bool CPUProgram::operator<=(const CPUProgram& y)const{
    
    
    if(count<=y.getCount())
        return true;
    else
        return false;
    
    
}
//programdaki satirlari yazdiriyor
ostream& operator <<(ostream& outs,const CPUProgram& x){
    
    
    
    for(int i=0; i<x.getCount(); ++i){
        
        outs<<x.line[i]<<endl;
        
        
    }
    
    return outs;
    
    
}
//prefix
//programdaki son satiri siliyor
CPUProgram CPUProgram::operator--(){
    
    
    line.pop_back();
    
    count--;
    
    return *this;
    
}

//postfix
//programdaki son satiri siliyor
CPUProgram CPUProgram::operator--(int){
    
    
    
    line.pop_back();
    
    count--;
    
    return *this;
    
}


CPUProgram CPUProgram::operator()(int x,int y){
    
    CPUProgram yeni;
    yeni.count=0;
    for(int i=x; i<=y ;++i){
        
        
        yeni.line.push_back(line[i]);
        yeni.count++; 
    }
    
    
    return yeni;
    
     
}