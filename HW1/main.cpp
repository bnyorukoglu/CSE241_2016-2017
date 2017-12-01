/*-----------------------BENGI YORUKOGLU-----------------------------*/
/*-----------------------131044046-----------------------------------*/

#include <iostream>
#include <fstream>

using namespace std;

/*gelen stringin her karakterini buyuk harfe cevirir*/
void BuyukHarf(string& gelen);

/*reg1'i reg2ye atar*/
void movFonk(int& reg1, int& reg2);

/* Constant sayiyi reg1'e atar             */
void movFonkConstant(int& reg1,int sayi);

/* sayiyi print eder   */
void prn(int sayi);

/* reg1 ve reg2'yi toplar reg1e ekler */
void addRegReg(int& reg1, int reg2);

/*reg ile constanti toplar reg1e ekler*/
void addRegConstant(int& reg1,int sayi);

/*reg1'den reg2'yi cikarir reg1e ekler */
void subRegReg(int& reg1,int reg2);

/*reg1den sayiyi cikarir reg1e ekler */
void subRegConstant(int& reg1,int sayi);

/*gelen stringi sayiya cevirir sayi degerini bulur*/
long int sayiDegeri(string kelime);

/*kac noktali virgul var  bulur*/
int noktaliBul(string kelime);

/* kac virgul var bulur*/
int virgulBul(string kelime);

int main(int argc, char** argv) {
    string line[100];
    int spaceCount = 0, count = 0, index, degis = 0;
    ifstream myfile(argv[1]);
    int R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    string val;
    int atama;
    atama=sayiDegeri(argv[2]);
    int x=0;
    int deneme;
    
    
   
    /* Dosyadan okudugumuz her satiri string arrayine attik   */
    /* Daha sonra her satirdaki harfleri büyük harfe cevirdik */
    /* DOsyayi okuduktan sonra kapattik                       */

    if (myfile.is_open()) {
        while (getline(myfile, line[count])) {

            line[count].push_back('\n');

            BuyukHarf(line[count]);

            ++count;
        }
        myfile.close();
    }
    else
        cout<<"The file can not be open !";
	
	
	bool hlt=false;
	
	/* 0.indexten baslayip hlt olana kadar döngü döner */
    for(index = 0; index < count && x!=1 && !hlt; ++index) {

        /* Bosluk buldukca bosluklari ihmal ettik                      */
        while (line[index].at(spaceCount) == ' ' || line[index].at(spaceCount) == '\t')
            spaceCount++;

        /*--------------------------------------------------------*/
        /*--------------------------------------------------------*/
        /*    Eger ilk 3 karakter MOV ise                         */
        if (line[index].substr(spaceCount, 4).compare("MOV ") == 0) {


            int k = line[index].find("MOV") + 3;
            int j = line[index].find(",");
            string reg, reg2;

            while (k < j) {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg.push_back(line[index].at(k));
                ++k;
            }

            ++k;

            while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg2.push_back(line[index].at(k));
                ++k;

            }
            /*ilk parametresinin R1,R2,R3,R4 veya R5 olması zorunlu*/
            /* eger disinda bir sey gelmisse hata verir*/
            if(reg!="R1"&& reg!="R2" && reg!="R3" && reg!="R4" && reg!="R5"){
                cout<<"MOV'un ilk parametresini yanlis girdiniz!";
                x=1;
                
            }
            /* Hangi registerlar üzerinde islem yapacagimizi kosullar ile*/
            /* belirledik . */
            
            if (reg == "R1") {

                if (reg2 == "R1") {

                    movFonk(R1,R1);
                    
                    if(atama==1){
                        cout<<"MOV R1 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R2") {

                    movFonk(R1,R2);
                    if(atama==1){
                        cout<<"MOV R1 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                
                }
                if (reg2 == "R3") {

                    movFonk(R1,R3);
                    if(atama==1){
                        cout<<"MOV R1 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                  
                }
                if (reg2 == "R4") {

                    movFonk(R1,R4);
                    if(atama==1){
                        cout<<"MOV R1 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                  
                }
                if (reg2 == "R5") {

                    movFonk(R1,R5);
                    if(atama==1){
                        cout<<"MOV R1 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                    }
                }


            }

            if (reg == "R2") {

                if (reg2 == "R1") {

                    movFonk(R2,R1);
                    if(atama==1){
                        cout<<"MOV R2 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R2") {

                    movFonk(R2,R2);
                    if(atama==1){
                        cout<<"MOV R2 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R3") {

                    movFonk(R2,R3);
                    if(atama==1){
                        cout<<"MOV R2 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R4") {

                    movFonk(R2,R4);
                    if(atama==1){
                        cout<<"MOV R2 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R5") {

                    movFonk(R2,R5);
                    if(atama==1){
                        cout<<"MOV R2 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

            }

            if (reg == "R3") {

                if (reg2 == "R1") {

                    movFonk(R3,R1);
                    if(atama==1){
                        cout<<"MOV R3 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }

                }

                if (reg2 == "R2") {

                    movFonk(R3,R2);
                    if(atama==1){
                        cout<<"MOV R3 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R3") {

                    movFonk(R3,R3);
                    if(atama==1){
                        cout<<"MOV R3 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R4") {

                    movFonk(R3,R4);
                    if(atama==1){
                        cout<<"MOV R3 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R5") {

                    movFonk(R3,R5);
                    if(atama==1){
                        cout<<"MOV R3 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

            }


            if (reg == "R4") {

                if (reg2 == "R1") {

                    movFonk(R4,R1);
                    if(atama==1){
                        cout<<"MOV R4 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R2") {

                    movFonk(R4,R2);
                    if(atama==1){
                        cout<<"MOV R4 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }

                }

                if (reg2 == "R3") {

                    movFonk(R4,R3);
                    if(atama==1){
                        cout<<"MOV R4 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R4") {

                    movFonk(R4,R4);
                    if(atama==1){
                        cout<<"MOV R4 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R5") {

                    movFonk(R4,R5);
                    if(atama==1){
                        cout<<"MOV R4 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

            }

            if (reg == "R5") {

                if (reg2 == "R1") {

                    movFonk(R5,R1);
                    if(atama==1){
                        cout<<"MOV R5 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R2") {

                    movFonk(R5,R2);
                    if(atama==1){
                        cout<<"MOV R5 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R3") {

                    movFonk(R5,R3);
                    if(atama==1){
                        cout<<"MOV R5 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                        cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R4") {

                    movFonk(R5,R4);
                    if(atama==1){
                        cout<<"MOV R5 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R5") {

                    movFonk(R5,R5);
                    if(atama==1){
                        cout<<"MOV R5 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                        cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5<<endl;
                    }
                    else{
                        
                        
                    }
                }

            }
          
            if(reg2!="R1" && reg2!="R2" && reg2!="R3" && reg2!="R4" && reg2!="R5"){
                
                
            
                int eldekisayi;

                eldekisayi = sayiDegeri(reg2);
                
                if(eldekisayi==-1){
                    cout<<"yanlis komut girdiniz!";
                    cout<<"sayi icinde gecersiz karakter var!";
                    cout<<endl;
                    x=1;
                    
                }
                if (eldekisayi != -1) {

                    if (reg == "R1") {

                        movFonkConstant(R1,eldekisayi);
                        if(atama==1){
                            cout<<"MOV R1, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R2") {

                        movFonkConstant(R2,eldekisayi);
                        if(atama==1){
                            cout<<"MOV R2, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R3") {

                        movFonkConstant(R3,eldekisayi);
                         if(atama==1){
                            cout<<"MOV R3, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R4") {

                        movFonkConstant(R4,eldekisayi);
                        if(atama==1){
                            cout<<"MOV R4, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R5") {

                        movFonkConstant(R5,eldekisayi);
                        if(atama==1){
                            cout<<"MOV R5, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                }
            
            }
        }

            /*--------------------------------------------------------*/
            /*--------------------------------------------------------*/
            /*     Eger ilk 3 karakter PRN ise                        */
        else if (line[index].substr(spaceCount, 4).compare("PRN ") == 0) {

            string reg;
            int k = line[index].find("PRN") + 3;
            int j;

            if (noktaliBul(line[index]) == 1) {

                j = line[index].find(";");


                while (k < j) {
                    if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                        reg.push_back(line[index].at(k));
                    ++k;
                }


            }

            else {

                j = line[index].find("\n");

                string reg;
                while (k < j) {
                    if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                        reg.push_back(line[index].at(k));
                    ++k;
                }
            }
            /*ilk parametresinin R1,R2,R3,R4 veya R5 olması zorunlu*/
            /* eger disinda bir sey gelmisse hata verir*/
            if(reg!="R1"&& reg!="R2" && reg!="R3" && reg!="R4" && reg!="R5"){
                cout<<"PRN parametresini yanlis girdiniz!";
                x=1;
                
            }
            if (reg == "R1") {

                prn(R1);
                cout<<endl;
                if(atama==1){
                    cout<<"PRN R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                }
                else{
                        
                }
                
            }

            if (reg == "R2") {

                prn(R2);
                cout<<endl;
                if(atama==1){
                    cout<<"ADD R4 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                }
                else{
                        
                }
            }

            if (reg == "R3") {

                prn(R3);
                cout<<endl;
                if(atama==1){
                    cout<<"ADD R4 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                }
                else{
                        
                }
            }

            if (reg == "R4") {

                prn(R4);
                cout<<endl;
                if(atama==1){
                    cout<<"ADD R4 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                }
                else{
                        
                }
            }

            if (reg == "R5") {

                prn(R5);
                cout<<endl;
                if(atama==1){
                    cout<<"ADD R4 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                }
                    else{
                        
                }
            }
        }

            /*--------------------------------------------------------*/
            /*--------------------------------------------------------*/
            /*      Eger ilk 3 karakter SUB ise                       */
        else if (line[index].substr(spaceCount, 4).compare("SUB ") == 0) {

            int k = line[index].find("SUB") + 3;
            int j = line[index].find(",");
            string reg, reg2;
            while (k < j) {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg.push_back(line[index].at(k));
                ++k;
            }

            ++k;

            while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg2.push_back(line[index].at(k));
                ++k;

            }
            
            /*ilk parametresinin R1,R2,R3,R4 veya R5 olması zorunlu*/
            /* eger disinda bir sey gelmisse hata verir*/
            if(reg!="R1"&& reg!="R2" && reg!="R3" && reg!="R4" && reg!="R5"){
                cout<<"SUB'un ilk parametresini yanlis girdiniz!";
                x=1;
                
            }

            if (reg == "R1") {

                if (reg2 == "R1") {

                    subRegReg(R1,R1);
                    if(atama==1){
                    cout<<"SUB R1 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R2") {

                    subRegReg(R1,R2);
                    if(atama==1){
                    cout<<"SUB R1 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                        
                    }
                }
                if (reg2 == "R3") {

                    subRegReg(R1,R3);
                    if(atama==1){
                    cout<<"MOV R1 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
                if (reg2 == "R4") {

                    subRegReg(R1,R4);
                    if(atama==1){
                    cout<<"SUB R1 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
                if (reg2 == "R5") {
                    
                    subRegReg(R1,R5);
                    if(atama==1){
                    cout<<"SUB R1 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
            }

            if (reg == "R2") {

                if (reg2 == "R1") {

                    subRegReg(R2,R1);
                    if(atama==1){
                    cout<<"SUB R2 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                }

                if (reg2 == "R2") {

                    subRegReg(R2,R2);
                    if(atama==1){
                    cout<<"SUB R2 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R3") {

                    subRegReg(R2,R3);
                    if(atama==1){
                    cout<<"SUB R2 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R4") {

                    subRegReg(R2,R4);
                    if(atama==1){
                    cout<<"SUB R2 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R5") {

                    subRegReg(R2,R5);
                    if(atama==1){
                    cout<<"SUB R2 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

            }

            if (reg == "R3") {

                if (reg2 == "R1") {

                    subRegReg(R3,R1);
                    if(atama==1){
                    cout<<"SUB R3 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R2") {

                    subRegReg(R3,R2);
                    if(atama==1){
                    cout<<"SUB R3 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R3") {

                    subRegReg(R3,R3);
                    if(atama==1){
                    cout<<"SUB R3 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R4") {

                    subRegReg(R3,R4);
                    if(atama==1){
                    cout<<"SUB R2 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R5") {

                    subRegReg(R3,R5);
                    if(atama==1){
                    cout<<"SUB R3 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
            }

            if (reg == "R4") {

                if (reg2 == "R1") {

                    subRegReg(R4, R1);
                    if(atama==1){
                    cout<<"SUB R4 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R2") {

                    subRegReg(R4, R2);
                    if(atama==1){
                    cout<<"SUB R4 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R3") {

                    subRegReg(R4, R3);
                    if(atama==1){
                    cout<<"SUB R4 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R4") {

                    subRegReg(R4, R4);
                    if(atama==1){
                    cout<<"SUB R4 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R5") {

                    subRegReg(R4, R5);
                    if(atama==1){
                    cout<<"SUB R4 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

            }

            if (reg == "R5") {

                if (reg2 == "R1") {

                    subRegReg(R5, R1);
                    if(atama==1){
                    cout<<"SUB R5 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R2") {

                    subRegReg(R5, R2);
                    if(atama==1){
                    cout<<"SUB R5 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R3") {

                    subRegReg(R5, R3);
                    if(atama==1){
                    cout<<"SUB R5 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R4") {

                    subRegReg(R5, R4);
                    if(atama==1){
                    cout<<"SUB R5 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R5") {

                    subRegReg(R5, R5);
                    if(atama==1){
                    cout<<"SUB R5 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

            }
            if(reg2!="R1" && reg2!="R2"&& reg2!="R3" && reg2!="R4" && reg2!="R5" ){
                
            
                int eldekisayi;

                eldekisayi = sayiDegeri(reg2);
                
                if(eldekisayi==-1){
                    cout<<"yanlis komut girdiniz!";
                    cout<<"sayi icinde gecersiz karakter var!";
                    cout<<endl;
                    x=1;
                    
                }
                /* return degeri -1 degil ise reg2 constant bir degerdir*/
                if (eldekisayi != -1) {

                    if (reg == "R1") {

                        subRegConstant(R1, eldekisayi);
                        if(atama==1){
                            cout<<"SUB R1, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R2") {

                        subRegConstant(R2, eldekisayi);
                        if(atama==1){
                            cout<<"SUB R2, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R3") {

                        subRegConstant(R3, eldekisayi);
                        if(atama==1){
                            cout<<"SUB R3, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R4") {

                        subRegConstant(R4, eldekisayi);
                        if(atama==1){
                            cout<<"SUB R4, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R5") {

                        subRegConstant(R5, eldekisayi);
                        if(atama==1){
                            cout<<"SUB R5, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                }
            }
        }

        /*--------------------------------------------------------*/
        /*--------------------------------------------------------*/
        /*         Eger ilk 3 karakter ADD ise                    */
        if (line[index].substr(spaceCount, 4).compare("ADD ") == 0) {

            int sayi1=0,sayi2=0;
            int k = line[index].find("ADD") + 3;
            int j = line[index].find(",");
            string reg, reg2;
            while (k < j) {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg.push_back(line[index].at(k));
                ++k;
            }

            ++k;

            while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg2.push_back(line[index].at(k));
                ++k;

            }
            
            /*ilk parametresinin R1,R2,R3,R4 veya R5 olması zorunlu*/
            /* eger disinda bir sey gelmisse hata verir*/
            if(reg!="R1"&& reg!="R2" && reg!="R3" && reg!="R4" && reg!="R5"){
                cout<<"ADD'in ilk parametresini yanlis girdiniz!";
                x=1;
                
            }
            if (reg == "R1") {
                
                if (reg2 == "R1") {
                    
                    addRegReg(R1,R1);
                    if(atama==1){
                    cout<<"ADD R1 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }


                if (reg2 == "R2") {
                    
                    addRegReg(R1,R2);
                    if(atama==1){
                    cout<<"ADD R1 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                    
                }
                if (reg2 == "R3") {

                    addRegReg(R1,R3);
                    if(atama==1){
                    cout<<"ADD R1 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
                if (reg2 == "R4") {

                    addRegReg(R1,R4);
                    if(atama==1){
                    cout<<"ADD R1 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
                if (reg2 == "R5") {

                    addRegReg(R1,R5);
                    if(atama==1){
                    cout<<"ADD R1 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
            }

            if (reg == "R2") {

                if (reg2 == "R1") {

                    addRegReg(R2, R1);
                    if(atama==1){
                    cout<<"ADD R2 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R2") {

                    addRegReg(R2, R2);
                    if(atama==1){
                    cout<<"ADD R2 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }

                }

                if (reg2 == "R3") {

                    addRegReg(R2, R3);
                    if(atama==1){
                    cout<<"ADD R2 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                        
                    }
                                 
                }

                if (reg2 == "R4") {

                    addRegReg(R2, R4);
                    if(atama==1){
                    cout<<"ADD R2 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }

                }

                if (reg2 == "R5") {

                    addRegReg(R2, R5);
                    if(atama==1){
                    cout<<"ADD R2 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
            }

            if (reg == "R3") {

                if (reg2 == "R1") {

                    addRegReg(R3, R1);
                    if(atama==1){
                    cout<<"ADD R3 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R2") {

                    addRegReg(R3, R2);
                    if(atama==1){
                    cout<<"ADD R3 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                        
                    }
                }

                if (reg2 == "R3") {

                    addRegReg(R3, R3);
                    if(atama==1){
                    cout<<"ADD R3 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R4") {

                    addRegReg(R3, R4);
                    if(atama==1){
                    cout<<"ADD R3 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R5") {

                    addRegReg(R3, R5);
                    if(atama==1){
                    cout<<"ADD R3 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                        
                    }
                }
            }

            if (reg == "R4") {

                if (reg2 == "R1") {

                    addRegReg(R4, R1);
                    if(atama==1){
                    cout<<"ADD R4 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R2") {

                    addRegReg(R4, R2);
                    if(atama==1){
                    cout<<"ADD R4 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R3") {

                    addRegReg(R4, R3);
                    if(atama==1){
                    cout<<"ADD R4 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R4") {

                    addRegReg(R4, R4);
                    if(atama==1){
                    cout<<"ADD R4 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R5") {

                    addRegReg(R4, R5);
                    if(atama==1){
                    cout<<"ADD R4 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }else{
                        
                    }
                }
            }

            if (reg == "R5") {

                if (reg2 == "R1") {

                    addRegReg(R5, R1);
                    if(atama==1){
                    cout<<"ADD R5 R1-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R2") {

                    addRegReg(R5, R2);
                    if(atama==1){
                    cout<<"ADD R5 R2-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R3") {

                    addRegReg(R5, R3);
                    if(atama==1){
                    cout<<"ADD R5 R3-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R4") {

                    addRegReg(R5, R4);
                    if(atama==1){
                    cout<<"ADD R5 R4-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }

                if (reg2 == "R5") {

                    addRegReg(R5, R5);
                    if(atama==1){
                    cout<<"ADD R5 R5-"; cout<<"R1= "<<R1;cout<<"R2= "<<R2;
                    cout<<"R3= "<<R3; cout<<"R4= "<<R4;cout<<"R5= "<<R5;
                    cout<<endl;
                    }
                    else{
                        
                    }
                }
            }
            if(reg2!="R1" && reg2!="R2"&& reg2!="R3" && reg2!="R4" && reg2!="R5" ){
                
            
                int eldekisayi;

                eldekisayi = sayiDegeri(reg2);
                  if(eldekisayi==-1){
                    cout<<"yanlis komut girdiniz!";
                    cout<<"sayi icinde gecersiz karakter var!";
                    cout<<endl;
                    x=1;
                    
                }
                /* return degeri -1 degil ise reg2 constant bir degerdir*/
                if (eldekisayi != -1) {

                    if (reg == "R1") {

                        addRegConstant(R1, eldekisayi);
                        if(atama==1){
                            cout<<"ADD R1, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R2") {

                        addRegConstant(R2, eldekisayi);
                        if(atama==1){
                            cout<<"ADD R2, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }


                    if (reg == "R3") {

                        addRegConstant(R3, eldekisayi);
                        if(atama==1){
                            cout<<"ADD R3, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R4") {

                        addRegConstant(R4, eldekisayi);
                        if(atama==1){
                            cout<<"ADD R4, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }

                    if (reg == "R5") {

                        addRegConstant(R5, eldekisayi);
                        if(atama==1){
                            cout<<"ADD R5, ";cout<<eldekisayi;
                            cout<<"- R1= "<<R1;cout<<",R2= "<<R2;cout<<",R3= "<<R3;
                            cout<<",R4= "<<R4; cout<<",R5= "<<R5<<endl;
                        }
                        else{
                        
                        
                        }
                    }
                }
            }
        }

            /*--------------------------------------------------------*/
            /*--------------------------------------------------------*/
            /*   Eger ilk 3 karakter JMP ise                          */
        else if (line[index].substr(spaceCount, 4).compare("JMP ") == 0) {

            int j, k;
            string reg, reg2;

            /*   eger virgul varsa  2 register almistir        */

            if (virgulBul(line[index]) == 1) {

                k = line[index].find("JMP") + 3;
                j = line[index].find(",");


                while (k < j) {
                    if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                        reg.push_back(line[index].at(k));
                    ++k;
                }

                ++k;

                while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                    if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                        reg2.push_back(line[index].at(k));
                    ++k;

                }

                int sayicevir, sayicevir2 = 0;
                if(reg=="R1")
                   sayicevir = R1;
                else if(reg=="R2")
                    sayicevir=R2;
                else if(reg=="R3")
                    sayicevir=R3;
                else if(reg=="R4")
                    sayicevir=R4;
                else if(reg=="R5")
                    sayicevir=R5;
                else
                    sayicevir=-2;
                /* ilk sayi sifir ise*/
                if (sayicevir == 0) {
                    
                    sayicevir2 = sayiDegeri(reg2);
                    index = sayicevir2 - 2;
                    

                }

                    /*ilk parametre sifir degil ise devam et*/
                else {

                }
            }

            /* Virgul yoksa tek deger var demektir */
            else if (virgulBul(line[index]) == 0) {
               
                /*Eger yorum varsa ; vardir o zaman ;'e kadar kontrol et*/
                if (noktaliBul(line[index]) == 1) {

                    k = line[index].find("JMP") + 3;

                    j = line[index].find(";");


                    while (k < j) {
                        if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                            reg.push_back(line[index].at(k));
                        ++k;
                    }
                    int sayicevir;
                    sayicevir = sayiDegeri(reg);

                    index = sayicevir - 2;
                }

                    /* noktali virgul yoksa \n'e kadar kontrol et */
                else {

                    k = line[index].find("JMP") + 3;

                    j = line[index].find("\n");

                    string reg;
                    while (k < j) {

                        if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                            reg.push_back(line[index].at(k));
                        ++k;
                    }

                    int sayicevir;
                    sayicevir = sayiDegeri(reg);

                    index = sayicevir - 2;
                }

            }

        }

		/* eger hlt ise döngü sonlandirilir ve tüm register degerleri bastirilir */
        else if ((line[index].substr(spaceCount, 4).compare("HLT ") == 0) || (line[index].substr(spaceCount, 3).compare("HLT") == 0))

		{
			hlt=true;
			cout << "REG1="<< R1<<",REG2="<< R2<<",REG3="<<R3<<",REG4="<<R4<<",REG5="<<R5<<endl;
	


		}
		/*eger ilk kelime mov,add,sub,prn,jmp degilse yanlis komut girilmistir */
		else if ((line[index].substr(spaceCount, 3).compare("HLT") != 0)&&(line[index].substr(spaceCount, 4).compare("JMP ") != 0)&&(line[index].substr(spaceCount, 4).compare("MOV ") != 0)&& (line[index].substr(spaceCount, 4).compare("SUB ") != 0) && (line[index].substr(spaceCount, 4).compare("PRN ") != 0)&& (line[index].substr(spaceCount, 4).compare("ADD ") != 0)){
                 cout<<"yanlis komut girdiniz";
                 x=1;
        }
			

            spaceCount = 0;


    }
    return 0;
}

/* Bu fonksiyon eger karakteerimiz eger harf ise kücük harfleri büyük */

/* harfe ceviriyor                                                    */
void BuyukHarf(string& gelen) {

    int index = 0;
    while (gelen.size() > index) {

        if ((gelen[index] < 123) && (gelen[index] > 96)) {

            gelen[index] = gelen[index] - 32;

        }
        ++index;
    }

}

/* Bu fonksiyon reg2deki degeri reg1e atiyor */
void movFonk(int& reg1,int& reg2) {

    reg2 = reg1;
}

/* Bu fonksiyon sayi paraetresindeki degeri reg1'e atiyor */
void movFonkConstant(int& reg1,int sayi) {

    reg1 = sayi;
}

/* BU fonksiyon print ettirmemizi sagliyor*/
void prn(int sayi) {

    cout << sayi;
}

/* Bu fonksiyon reg1 ile reg2'nin toplamini reg1e atiyor*/
void addRegReg(int& reg1,int reg2) {

    reg1 = reg1 + reg2;
}

void addRegConstant(int& reg1,int sayi) {

    reg1 = reg1 + sayi;
}

void subRegReg(int& reg1,int reg2) {

    reg1 = reg1 - reg2;
}

void subRegConstant(int& reg1,int sayi) {

    reg1 = reg1 - sayi;
}
/* gelen stringin icerisinde önce sayiya cevirdiğimizde*/
/* 0 ve 9 disinda karakter var mi onu buluyor */
/* eger varsa -1 return ediyor*/
/* yoksa sayi degerini buluyor*/
long int sayiDegeri(string kelime) {

   
    int index=0,a,b;
    int sonuc=1;
    long int sayi=0;
    int isaret=1;
    while(kelime.size()>index){
        /*eger ilk index - ise isareti - yapiyoruz*/
		if(kelime[0]=='-')
		{
			isaret=-1;
		}
		/* 0 ve 9 arasi disinda bir karakter varsa -1 return ediyoruz*/
        if(kelime[index]<'0' || kelime[index]>'9'){
            
            return -1;
        }
        index++;
    }
    /* size kadar 10 ile carpilir ilk basamağımız kaclar basamaginda*/
    /* bulunur*/
    for(b=0; b<kelime.size()-1 ;++b){
		
        sonuc=sonuc*10;
    }
    if(kelime[0]=='-')
		sonuc/=10;
		
    
    for(a=0; a<kelime.size() ; ++a){
        if(kelime[a]>='0' && kelime[a]<='9')
        {
			sayi+= (kelime[a]-48)*sonuc;
			sonuc=sonuc/10;
		}
    }
    return sayi*isaret;
}

/* fparametre olarak stringi alir */
/* kaç noktali virgul var onu buluyor */
int noktaliBul(string kelime) {

    int index = 0;
    while (kelime.size() > index) {

        if (kelime[index] == ';')
            return 1;

        index++;
    }
    return 0;
}

/*parametre olarak stringi alir  */
/* virgul olup olmadigini buluyor*/
int virgulBul(string kelime) {

    int index = 0;
    while (kelime.size() > index) {

        if (kelime[index] == ',')
            return 1;
        index++;
    }
    return 0;
}

