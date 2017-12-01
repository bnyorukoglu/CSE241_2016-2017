/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Computer.h
 * Author: bengi
 *
 * Created on 05 Kasım 2016 Cumartesi, 10:34
 */

#ifndef COMPUTER_H
#define COMPUTER_H


#include <iostream>
#include <string>
#include "CPU.h"

#include "CPUProgram.h"
#include "Memory.h"
using namespace std;

class Computer{
    
    
    
public:
    Computer();//default constructor
    Computer(int option);
    Computer(CPU x,CPUProgram y,Memory & z,int option);
    void execute();
    CPU getCPU(){return myCPU;};
    CPUProgram getCPUProgram(){return myCPUProgram;};
    Memory getMemory(){return myMemory; };
    void setCPU(CPU x);
    void setCPUProgram(CPUProgram x);
    void setMemory(Memory x);
private:
    
    CPU myCPU;
    CPUProgram myCPUProgram;
    Memory myMemory;
    int secim;
    
};
#endif /* COMPUTER_H */