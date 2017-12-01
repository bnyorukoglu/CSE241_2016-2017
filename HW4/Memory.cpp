#include "Memory.h"
#include<iostream>



using namespace std;


Memory::Memory(){
    //tum memory degerleri sifirlanir
   for(int i=0 ; i<50; ++i){
       
       setMem(i,0);
       
   } 
    
}
void Memory::setMem(int index, int value) {

    memarr[index] = value;

}
/* tek parametre alan contructor*/
Memory::Memory(int option){
    //private olan secim degerine option olarak gelen deger atanir
    secim=option;
    for(int i=0 ; i<50; ++i){
       
       setMem(i,0);
       
   } 
}
/* tum address degerlerini tek tek basar*/
void Memory:: printAll(){
    
    for(int i=0 ; i<50 ; ++i){
        
        cout<<"["<<i<<"]"<<"->"<<getMem(i)<<endl;
        
    }
    
}
