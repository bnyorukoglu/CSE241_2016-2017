//BENGI YORUKOGLU
//131044046
//Created on 24 Ekim 2016 Pazartesi, 14:26



#include "requiredIncs.h"


int main(int argc, char** argv) {

		CPU meinCPU;//CPU objesi olustururlur.
		const char* filename = argv[1];
		int option = meinCPU.sayiDegeri(argv[2]);

		//memory objesi olusturulur ve tek parametreli constructorı ile
		Memory myMemory(option);


		//CPU objesi tek option alan tek parametreli constructorı ile
		//olusturulur
		CPU myCPU(option);
		//CPUProgram objesi olusturulur tek parametreli option alan 
		//constructor ile
		CPUProgram myCPUProgram(option);
		myCPUProgram.ReadFile(filename);

		/* Computer test*/
		Computer myComputer1(myCPU, myCPUProgram, myMemory, option);
		//computer classinin execute'u cagirilir
		myComputer1.execute();



    return 0;
}

