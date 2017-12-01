//BENGI YORUKOGLU
//131044046
 //File:   CPUProgramDyn.cpp
 // Created on 24 Ekim 2016 Pazartesi, 14:26
 

#include "CPUProgramDyn.h"
#include <fstream>
#include<iostream>
#include<vector>
using namespace std;

namespace anotherMorning
{

	//readfile fonksiyonunu cagirir ve counta sifir atar! 
	CPUProgramDyn::CPUProgramDyn(const char* fname) : kapasite(25), count(0){
		line = new string[kapasite];
		 ReadFile(fname);
	}
	CPUProgramDyn::CPUProgramDyn(int option) : kapasite(25), count(0){
		
		line = new string[kapasite];
		secim=option;
	}
	CPUProgramDyn::CPUProgramDyn() : kapasite(25), count(0){
		
		line = new string[kapasite];
	}

	CPUProgramDyn::CPUProgramDyn(const CPUProgramDyn& myCPUProgramDyn)
	: kapasite(myCPUProgramDyn.kapasite), count(myCPUProgramDyn.count) {
		line = new string[kapasite];
		for (int i = 0; i < count; i++)
		    line[i] = myCPUProgramDyn.line[i];
	}

	void CPUProgramDyn::addElement(string gelen)
	{
		if(count >= kapasite){
		    kapasite = kapasite*3;
		    string *temp = new string[kapasite];
		    for(int i=0; i<count; i++){
		        temp[i] = line[i];
		    }
		    delete [] line;
		    line = new string[kapasite];
		    for(int i=0; i<count; i++){
		        line[i] = temp[i];
		    }
		    delete [] temp;
		    
		    line[count] = gelen;
		    
		}
		else{
		    line[count] = gelen;
		    
		}
	}


	//dosyayi acar dosyadan satir satir okuyup lina arrayine doldurur.
	//her satiri okuduktan sonra hepsini buyuk harfe cevirir
	//eger dosya acilmazsa hata mesaji verir
	void CPUProgramDyn::ReadFile(const char* gelen2){
		
		ifstream file(gelen2);
		
		 if (file.is_open()) {
		     
		   
		    string temp;
		    while (getline(file,temp)) {
		        
		        temp.push_back('\n');
		       
		       
		        
		        BuyukHarf(temp);
		        
		        addElement(temp);
		        
		        
		        
		        count++;
		       
		    }
		    file.close();
		} else
		    cout << "The file can not be open !";   
	}
	//buyuk harf fonksiyonumuzda gelen stringi asciideki karsiligi 
	//kucuk harfe denk geliyosa 32 cikararak buyuk harf yapariz
	void CPUProgramDyn::BuyukHarf(string& gelen) {
		int index = 0;
		while (gelen.size() > index) {

		    if ((gelen[index] < 123) && (gelen[index] > 96)) {

		        gelen[index] = gelen[index] - 32;

		    }
		    ++index;
		}
	}

	//satir sayimizi return ediyor
	int CPUProgramDyn::size() {

		return count;
	}

	string CPUProgramDyn::getLine(int index)const{
		
		
		return line[index];
		
	}

	//gelen indexteki stringi return eder
	string CPUProgramDyn::operator[](int index)const{
		
		if(index>=count){
		    
		    cout<<"HATA!!!";
		    return"";
		}
		return line[index];
		
		
	}

	CPUProgramDyn& CPUProgramDyn::operator =(const CPUProgramDyn& rightSide) {
		if (kapasite != rightSide.kapasite) {
		    delete [] line;
		    line = new string[rightSide.kapasite];
		}

		kapasite = rightSide.kapasite;
		count = rightSide.count;
		for (int i = 0; i < count; i++)
		    line[i] = rightSide.line[i];

		return *this;
	}

	//parametre olarak CPUProgramDyn ve string olarak line alir
	//gelen satiri son satira ekler.
	CPUProgramDyn CPUProgramDyn::operator+(string gelen)const{
		
		CPUProgramDyn yeni;
		for(int i=0;i<count;++i){
		         yeni+=line[i];
		}
		
		yeni.addElement(gelen);
		yeni.count++;
		
		return yeni;

	}

	//Operator+= that takes an instruction line as a string and appends the 
	//instruction to the end of the program.
	const CPUProgramDyn& CPUProgramDyn::operator+=(string gelen){
		
		if(gelen==""){
		    cout<<"HATA!!!"<<endl;
		    return *this;
		}
		addElement(gelen);
		count++;
		
		return *this;
		
	}

	//2 program aliyor.2.ciyi 1.ye ekleyip yeni program return ediyor
	CPUProgramDyn CPUProgramDyn::operator+( CPUProgramDyn& y){
		
		CPUProgramDyn yeni=*this;
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
		    
		    yeni.addElement(y.line[i]);
		    yeni.count++;
		    
		}
		
		return yeni;
		
	}
	//size karsilastirma
	bool CPUProgramDyn::operator==(const CPUProgramDyn& y)const{
		
		return(count==y.getCount());
		
	}

	//size karsilastirma
	bool CPUProgramDyn::operator!=(const CPUProgramDyn& y)const{
		
		if(count==y.getCount())
		    return false;
		else
		    return true;
		
	}


	//size karsilastirma
	bool CPUProgramDyn::operator<(const CPUProgramDyn& y)const{
		
		if(count<y.getCount())
		    return true;
		else
		    return false;

		
	}

	//size karsilastirma 
	bool CPUProgramDyn::operator>=(const CPUProgramDyn& y)const{
		
		if(count>=y.getCount())
		    return true;
		else
		    return false;

	}
	bool CPUProgramDyn::operator>(const CPUProgramDyn& y)const{
		
		if(count>y.getCount())
		    return true;
		else
		    return false;
		
		
		
	}
	bool CPUProgramDyn::operator<=(const CPUProgramDyn& y)const{
		
		
		if(count<=y.getCount())
		    return true;
		else
		    return false;
		
		
	}
	//programdaki satirlari yazdiriyor
	ostream& operator <<(ostream& outs,const CPUProgramDyn& x){
		
		
		
		for(int i=0; i<x.getCount(); ++i){
		    
		    outs<<x.line[i]<<endl;
		    
		    
		}
		
		return outs;
		
		
	}
	//prefix
	//programdaki son satiri siliyor
	CPUProgramDyn CPUProgramDyn::operator--(){
		
		
		count--;
		
		return *this;
		
	}

	
	//postfix
	//programdaki son satiri siliyor
	CPUProgramDyn CPUProgramDyn::operator--(int){
		
		CPUProgramDyn temp=*this;
		  
		count--;
		
		return temp;
		
	}



	CPUProgramDyn CPUProgramDyn::operator()(int x,int y){
		
		CPUProgramDyn yeni;
		yeni.count=0;
		for(int i=x; i<=y ;++i){
		    
		    
		    yeni.addElement(line[i]);
		    yeni.count++; 
		}
		
		
		return yeni;
		
		 
	}

	CPUProgramDyn::~CPUProgramDyn() {
		delete [] line;
	}
	
} //anotherMorning namespace
