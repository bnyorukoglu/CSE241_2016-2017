/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Computer.cpp
 * Author: bengi
 *
 * Created on 05 Kasım 2016 Cumartesi, 10:40
 */


#include "Computer.h"
#include<iostream>


using namespace std;



Computer::Computer(int option){
    
     secim=option;
    
}

Computer::Computer(CPU x,CPUProgram y,Memory &z,int option){ 
    
    myCPU=x;
    myCPUProgram=y;
    myMemory=z;
    secim=option;
    
}


Computer::Computer(){
    
}

void Computer::execute(){
    
 
     while (!myCPU.halted()) {
        // some code here
        string instruction = myCPUProgram.getLine(myCPU.getPC()-1);
        myCPU.execute(instruction,myMemory);
        // some code here
    }
    
}

void Computer::setCPU(CPU x){
    
    myCPU=x;
    
}
void Computer::setCPUProgram(CPUProgram x){
    
    myCPUProgram=x;
    
    
}
void Computer::setMemory(Memory x){
    
    
    myMemory=x;
    
}