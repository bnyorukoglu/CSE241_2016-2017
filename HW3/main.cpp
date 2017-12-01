//BENGI YORUKOGLU
//131044046
//Created on 24 Ekim 2016 Pazartesi, 14:26

#include <iostream>
#include <fstream>
#include "CPU.h"
#include "CPUProgram.h"
using namespace std;

int main(int argc, char** argv) {

    //mainde parametre olarak yollanan dosyamizin constructor cagirimi
    CPUProgram myProg(argv[1]);
    //mainde parametre olarak yollanan optionimizin constructor cagirimi
    CPU myCPU(argv[2][0]);
    // some code here
    while (!myCPU.halted()) {
        // some code hereint a=myCPU.getPC();
        
        string instruction = myProg.getLine(myCPU.getPC());
        int a=myCPU.getPC();
        myCPU.execute(instruction);
        // some code here
    }
    return 0;
}

