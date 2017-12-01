

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
    Computer(int option);// tek parametreli constructor
    Computer(CPU x,CPUProgram y,Memory & z,int option);//4 parametreli construct
    void execute();
    //getterlar objeleri return ediyor
    CPU getCPU(){return myCPU;};
    CPUProgram getCPUProgram(){return myCPUProgram;};
    Memory getMemory(){return myMemory; };
    //setterlar
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
