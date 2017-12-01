//BENGI YORUKOGLU
//131044046
//File:   CPUProgramDyn.h
 //Created on 24 Ekim 2016 Pazartesi, 14:24
 

#ifndef CPUProgramDyn_H
#define CPUProgramDyn_H
#include <iostream>
#include<vector>
using namespace std;

namespace anotherMorning
{

	class CPUProgramDyn {
	public:
		CPUProgramDyn();
		CPUProgramDyn(int option);
		CPUProgramDyn(const char* al);
		CPUProgramDyn(const CPUProgramDyn& myCPUProgramDyn);
		void addElement(string gelen);
		int size();
		void ReadFile(const char* gelen2);
		void BuyukHarf(string& gelen);
		string getLine(int index)const;
		string operator[](int index)const;
		CPUProgramDyn& operator =(const CPUProgramDyn& rightSide);
		CPUProgramDyn operator+(string line)const;
		const CPUProgramDyn& operator+=(string gelen);
		CPUProgramDyn operator--();//prefix
		CPUProgramDyn operator--(int);//postfix
		CPUProgramDyn operator+( CPUProgramDyn& y);
		CPUProgramDyn operator()(int x,int y);
		bool operator==(const CPUProgramDyn& y)const;
		bool operator!=(const CPUProgramDyn& y)const;
		bool operator<(const CPUProgramDyn& y)const;
		bool operator>=(const CPUProgramDyn& y)const;
		bool operator>(const CPUProgramDyn& y)const;
		bool operator<=(const CPUProgramDyn& y)const;
		const int getCount()const{return count;};
	   friend ostream& operator <<(ostream& outs,const CPUProgramDyn& x);
		~CPUProgramDyn();
		
	private:
		string* line ;
		string name;
		
		int kapasite;
		int count;
		int secim;
	};
}

#endif /* CPUProgramDyn_H */
