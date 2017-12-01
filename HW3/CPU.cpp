//BENGI YORUKOGLU
//131044046
// File:   CPU.cpp
//Created on 24 Ekim 2016 Pazartesi, 14:27


#include "CPU.h"
#include <string>

using namespace std;

//program countera 1 atanan setteri cagirir.ve registerlarin bulundugu arrayin
//atamalarinin yapildigi setteri cagirir

CPU::CPU(char value) {
    setReg();
    setPC(1);
    atama = value;
    
}
// registerlari set eder.registerlarin bulundugu arrayin tüm elemanlarina
//sifir atariz
void CPU::setReg() {


    for (int i = 0; i < 7; ++i) {

        arr[i] = 0;

    }

}
//gelen satirin once ilk3 karakterine bakar.buna gore komutu belirler
//belirlenen komuttan sonra o komutun fonksiyonu cagirilir
//fonksiyondaki islem gerceklesir
//daha sonra program counter arttirilir
bool CPU::execute(string line) {

    int spaceCount = 0;
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;

    bool yapilan = false;
    // eger gelen satirdaki linein 3 karakteri mov ise
    //mov komutunun islemini yapan fucMov  cagirilir
    //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    if (line.substr(spaceCount, 4).compare("MOV ") == 0) {

        yapilan = funcMov(line);

        ++PC;
    }
    // eger gelen satirdaki linein 3 karakteri prn ise
    //prn komutunun islemini yapan fucPrn  cagirilir
    //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    else if (line.substr(spaceCount, 4).compare("PRN ") == 0) {

        yapilan = funcPrn(line);
        ++PC;
    }
    // eger gelen satirdaki linein 3 karakteri sub ise
    //sub komutunun islemini yapan fucSUb cagirilir
    //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    else if (line.substr(spaceCount, 4).compare("SUB ") == 0) {

        yapilan = funcSub(line);
        ++PC;
    }
    // eger gelen satirdaki linein 3 karakteri add ise
    //add komutunun islemini yapan fucAdd cagirilir
    //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    else if (line.substr(spaceCount, 4).compare("ADD ") == 0) {

        yapilan = funcAdd(line);
        ++PC;
    }
    // eger gelen satirdaki linein 3 karakteri jmp ise
    //jmp komutunun islemini yapan fucJmp cagirilir
    //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    else if (line.substr(spaceCount, 4).compare("JMP ") == 0) {

        yapilan = funcJmp(line);
        ++PC;

    }
    //eger gelen komut hlt ise programin sonlanmasi icin hlt'ye true atanir
    else if ((line.substr(spaceCount, 4).compare("HLT ") == 0) || (line.substr(spaceCount, 3).compare("HLT") == 0))
    {	yapilan=1;
        hlt = true;
        print();
    }/* HLT KOSULU*/
    else {

        if (funcDiger(line) == false)
            return false;

    }
    if (yapilan)
        return true;
    else{
        cout<<"yanlis komut girdiniz!!!";
        hlt=true;
        return false;
    }
    

}

bool CPU::halted() {

    return hlt;
}
//ilk 3 karakterde belirlenen komut mov ise bu fonksiyon cagirilir
bool CPU::funcMov(string line) {
 
    int spaceCount = 0;
    //0.indeksten itibaren bosluk var mi diye bakar 
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;
    //bosluktan sonraki indeksten itibaren 4 indeks boyunca alir
    //alinan string mov mu diye bakar
    //mov ise devam edilir
    if (line.substr(spaceCount, 4).compare("MOV ") == 0) {


        int k = line.find("MOV") + 3;
        int j = line.find(",");
        string reg, reg2;

        while (k < j) {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg.push_back(line.at(k));
            ++k;
        }

        ++k;

        while (line.at(k) != '\n' && line.at(k) != ';') {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg2.push_back(line.at(k));
            ++k;

        }



        int a = 0, b = 0;

        a = (reg[1] - '0');

        b = (reg2[1] - '0');
        
        //eger movun ilk parametresi R1 R2 R3 R4 R5 degil ise yanlis girdiniz
        //uyarisi verilir
        if (reg != "R1" && reg != "R2" && reg != "R3" && reg != "R4" && reg != "R5") {
            cout << "MOV'un ilk parametresini yanlis girdiniz!";
            hlt=true;
            return false;

        }




        /* eger ikinci parametre constant ise */


        if (reg2 != "R1" && reg2 != "R2" && reg2 != "R3" && reg2 != "R4" && reg2 != "R5") {

            int eldekisayi;
             //reg2de saklanmis movun 2.parametresi sayiDegeri fonksiyonu
            //ile stringden intigera cevrilip eldekisayiya atanir
            eldekisayi = sayiDegeri(reg2); 

            if (eldekisayi == -1) {
                cout << "mov yanlis komut girdiniz!";
                cout << "sayi icinde gecersiz karakter var!";
                cout << endl;
                hlt=true;
                return false;

            }

            movFonkConstant(arr[a], eldekisayi);
        } else
            movFonk(arr[a], arr[b]);
        
        //mainde parametre olarak gelen option argumani 1 ise
        //bu if kosuluna girerek registerlar bastirilir
        if (atama == '1') {
            cout << "MOV "<<reg<<"-"<<reg2<<" ";
            print();
        } else {

        }





    }/*MOV MU*/
    return true;
}
//ilk 3 karakten prn ise bu fonksiyon cagirilir
bool CPU::funcPrn(string line) {
    int spaceCount = 0;
    //0.indeksten itibaren bosluk var mi diye bakar 
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;
    //bosluktan sonraki indeksten itibaren 4 indeks boyunca alir
    //alinan string prn mi diye bakar
    //prn ise devam edilir
    if (line.substr(spaceCount, 4).compare("PRN ") == 0) {

        string reg;
        int k = line.find("PRN") + 3;
        int j;

        if (noktaliBul(line) == 1) {

            j = line.find(";");


            while (k < j) {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg.push_back(line.at(k));
                ++k;
            }


        } else {

            j = line.find("\n");

            string reg;
            while (k < j) {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg.push_back(line.at(k));
                ++k;
            }
        }
        /*ilk parametresinin R1,R2,R3,R4 veya R5 olması zorunlu*/
        /* eger disinda bir sey gelmisse hata verir*/
        if (reg != "R1" && reg != "R2" && reg != "R3" && reg != "R4" && reg != "R5") {
            cout << "PRN parametresini yanlis girdiniz!";
            hlt=true;
            return false;

        }


        int n;
        int a = 0, b = 0;
        for (n = 1; n < 6; ++n) {

            if ((reg[1] - '0') == n)
                a = n;


        }

        cout<<arr[a]<<endl;
        //mainde parametre olarak gelen option argumani 1 ise
        //bu if kosuluna girerek registerlar bastirilir
        if (atama == '1') {
            cout << "PRN"<<reg;
            print();
        } else {

        }
    }/*PRN KOSULU*/

    return true;

}
//ilk 3 karakter sub ise bu fonksiyon cagirilir
bool CPU::funcSub(string line) {
    int spaceCount = 0;
    //0.indeksten itibaren bosluk var mi diye bakar
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;

    //bosluktan sonraki indeksten itibaren 4 indeks boyunca alir
    //alinan string sub mu diye bakar
    //sub ise devam edilir
    if (line.substr(spaceCount, 4).compare("SUB ") == 0) {

        int k = line.find("SUB") + 3;
        int j = line.find(",");
        string reg, reg2;
        while (k < j) {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg.push_back(line.at(k));
            ++k;
        }

        ++k;

        while (line.at(k) != '\n' && line.at(k) != ';') {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg2.push_back(line.at(k));
            ++k;

        }

        /*ilk parametresinin R1,R2,R3,R4 veya R5 olması zorunlu*/
        /* eger disinda bir sey gelmisse hata verir*/
        if (reg != "R1" && reg != "R2" && reg != "R3" && reg != "R4" && reg != "R5") {
            cout << "SUB'un ilk parametresini yanlis girdiniz!";
            hlt=true;
            return false;

        }

        int n;
        int a = 0, b = 0;
        for (n = 1; n < 6; ++n) {

            if ((reg[1] - '0') == n)
                a = n;


        }

        for (n = 1; n < 6; ++n) {

            if ((reg2[1] - '0') == n)
                b = n;


        }

 
        subRegReg(arr[a], arr[b]);
        /* eger ikinci parametre constant ise */

        if (reg2 != "R1" && reg2 != "R2" && reg2 != "R3" && reg2 != "R4" && reg2 != "R5") {

            int eldekisayi;
            //reg2de saklanmis subun 2.parametresi sayiDegeri fonksiyonu
            //ile stringden intigera cevrilip eldekisayiya atanir
            eldekisayi = sayiDegeri(reg2);

            if (eldekisayi == -1) {
                cout << "sub yanlis komut girdiniz!";
                cout << "sayi icinde gecersiz karakter var!";
                cout << endl;
                hlt=true;
                return false;

            }

            subRegConstant(arr[a], eldekisayi);
        } else
            subRegReg(arr[a], arr[b]);
        if (atama == '1') {
            cout << "SUB "<<reg<<"-"<<reg2<<" ";
            print();
        } else {

        }


    }/*SUB KOSULU*/




    return true;

}
//eger ilk 3 karakter add ise bu fonksiyon cagirirlir
bool CPU::funcAdd(string line) {
    int spaceCount = 0;
    //0.indeksten itibaren bosluk var mi diye bakar
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;

    //bosluktan sonraki indeksten itibaren 4 indeks boyunca alir
    //alinan string add mi diye bakar
    //add ise devam edilir
    if (line.substr(spaceCount, 4).compare("ADD ") == 0) {

        int sayi1 = 0, sayi2 = 0;
        int k = line.find("ADD") + 3;
        int j = line.find(",");
        string reg, reg2;
        while (k < j) {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg.push_back(line.at(k));
            ++k;
        }

        ++k;

        while (line.at(k) != '\n' && line.at(k) != ';') {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg2.push_back(line.at(k));
            ++k;

        }

        /*ilk parametresinin R1,R2,R3,R4 veya R5 olması zorunlu*/
        /* eger disinda bir sey gelmisse hata verir*/
        if (reg != "R1" && reg != "R2" && reg != "R3" && reg != "R4" && reg != "R5") {
            cout << "ADD'in ilk parametresini yanlis girdiniz!";
            hlt=true;
            return false;

        }


        int n;
        int a = 0, b = 0;
        for (n = 1; n < 6; ++n) {

            if ((reg[1] - '0') == n)
                a = n;


        }

        for (n = 1; n < 6; ++n) {

            if ((reg2[1] - '0') == n)
                b = n;


        }

        /* eger ikinci parametre constant ise */

        
        if (reg2 != "R1" && reg2 != "R2" && reg2 != "R3" && reg2 != "R4" && reg2 != "R5") {

            int eldekisayi;
            //reg2de saklanmis addin 2.parametresi sayiDegeri fonksiyonu
            //ile stringden intigera cevrilip eldekisayiya atanir
            eldekisayi = sayiDegeri(reg2);

            if (eldekisayi == -1) {
                cout << "add yanlis komut girdiniz!";
                cout << "sayi icinde gecersiz karakter var!";
                cout << endl;
                hlt=true;
                return false;

            }

            addRegConstant(arr[a], eldekisayi);
        } else
            addRegReg(arr[a], arr[b]);
        //mainde parametre olarak gelen option argumani 1 ise
        //bu if kosuluna girerek registerlar bastirilir
        if (atama == '1') {
            cout << "ADD "<<reg<<"-"<<reg2<<" ";
            print();
        } else {

        }

    }/* ADD kosulu */

    return true;
}

bool CPU::funcJmp(string line) {

    int spaceCount = 0;
    //0.indeksten itibaren bosluk var mi diye bakar
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;

    //bosluktan sonraki indeksten itibaren 4 indeks boyunca alir
    //alinan string jmp mi diye bakar
    //jmp ise devam edilir
    if (line.substr(spaceCount, 4).compare("JMP ") == 0) {

        int j, k;
        string reg, reg2;

        /*   eger virgul varsa  2 register almistir        */

        if (virgulBul(line) == 1) {

            k = line.find("JMP") + 3;
            j = line.find(",");


            while (k < j) {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg.push_back(line.at(k));
                ++k;
            }

            ++k;

            while (line.at(k) != '\n' && line.at(k) != ';') {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg2.push_back(line.at(k));
                ++k;

            }

            int sayicevir, sayicevir2 = 0;
            if (reg == "R1")
                sayicevir = arr[1];
            else if (reg == "R2")
                sayicevir = arr[2];
            else if (reg == "R3")
                sayicevir = arr[3];
            else if (reg == "R4")
                sayicevir = arr[4];
            else if (reg == "R5")
                sayicevir = arr[5];
            else
                sayicevir = -2;
            /* ilk sayi sifir ise*/
            if (sayicevir == 0) {
                //register 2 de saklanan jmpin 2.parametresi
                //stringden integera sayiDegeri fonksiyonu ile cevrilir
                //sayicevri2 integerina atanir
                sayicevir2 = sayiDegeri(reg2);
                //sayicevirden 1 cikarilarak program counterina atanir
                PC = sayicevir2 - 1;


            }                /*ilk parametre sifir degil ise devam et*/
            else {

            }
        }            /* Virgul yoksa tek deger var demektir */
        else if (virgulBul(line) == 0) {

            /*Eger yorum varsa ; vardir o zaman ;'e kadar kontrol et*/
            if (noktaliBul(line) == 1) {

                k = line.find("JMP") + 3;

                j = line.find(";");


                while (k < j) {
                    if (line.at(k) != ' ' && line.at(k) != '\t')
                        reg.push_back(line.at(k));
                    ++k;
                }
                int sayicevir;
                //register 2 de saklanan jmpin 2.parametresi
                //stringden integera sayiDegeri fonksiyonu ile cevrilir
                //sayicevir integerina atanir
                sayicevir = sayiDegeri(reg);

                PC = sayicevir - 1;
            }                /* noktali virgul yoksa \n'e kadar kontrol et */
            else {

                k = line.find("JMP") + 3;

                j = line.find("\n");

                string reg;
                while (k < j) {

                    if (line.at(k) != ' ' && line.at(k) != '\t')
                        reg.push_back(line.at(k));
                    ++k;
                }
              
                int sayicevir;
                sayicevir = sayiDegeri(reg);

                PC = sayicevir - 1;
            }

        }
        if (atama == '1') {
            cout << "JMP ";
            print();
        } else {

        }

    }/* JMP kosulu*/



    return true;

}

bool CPU::funcDiger(string line) {

    int spaceCount = 0;
    //3 karakterden olusan tüm komutlar arraye atanir.
    string instruction[6] = {"MOV", "ADD", "SUB", "PRN", "JMP", "HLT"};
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;
    //tek tek kontrol edilir.eger komut bunlardan biri degilse false return eder
    for (int i = 0; i < 6; ++i) {

        if (line.substr(spaceCount, 3) == instruction[i])
            return true;


    }
    
    cout<<"yanlis komut girdiniz!!!!";
    return false;



}

/* Bu fonksiyon reg2deki degeri reg1e atiyor */
void CPU::movFonk(int& reg1, int& reg2) {

    reg2 = reg1;
}

/* Bu fonksiyon sayi paraetresindeki degeri reg1'e atiyor */
void CPU::movFonkConstant(int& reg1, int sayi) {

    reg1 = sayi;
}

/* BU fonksiyon print ettirmemizi sagliyor*/
void CPU::prn(int sayi) {

    cout << sayi;
}

/* Bu fonksiyon reg1 ile reg2'nin toplamini reg1e atiyor*/
void CPU::addRegReg(int& reg1, int reg2) {

    reg1 = reg1 + reg2;
}

void CPU::addRegConstant(int& reg1, int sayi) {

    reg1 = reg1 + sayi;
}

void CPU::subRegReg(int& reg1, int reg2) {

    reg1 = reg1 - reg2;
}

void CPU::subRegConstant(int& reg1, int sayi) {

    reg1 = reg1 - sayi;
}
/* gelen stringin icerisinde önce sayiya cevirdiğimizde*/
/* 0 ve 9 disinda karakter var mi onu buluyor */
/* eger varsa -1 return ediyor*/

/* yoksa sayi degerini buluyor*/
long int CPU::sayiDegeri(string kelime) {


    int index = 0, a, b;
    int sonuc = 1;
    long int sayi = 0;
    int isaret = 1;
    while (kelime.size() > index) {
        /*eger ilk index - ise isareti - yapiyoruz*/
        if (kelime[0] == '-') {
            isaret = -1;
        }
        /* 0 ve 9 arasi disinda bir karakter varsa -1 return ediyoruz*/
        if (kelime[index]<'-' || kelime[index]>'9') {

            return -1;
        }
        index++;
    }
    /* size kadar 10 ile carpilir ilk basamağımız kaclar basamaginda*/
    /* bulunur*/
    for (b = 0; b < kelime.size() - 1; ++b) {

        sonuc = sonuc * 10;
    }
    if (kelime[0] == '-')
        sonuc /= 10;


    for (a = 0; a < kelime.size(); ++a) {
        if (kelime[a] >= '0' && kelime[a] <= '9') {
            sayi += (kelime[a] - 48) * sonuc;
            sonuc = sonuc / 10;
        }
    }
    return sayi*isaret;
}

/* fparametre olarak stringi alir */

/* kaç noktali virgul var onu buluyor */
int CPU::noktaliBul(string kelime) {

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
int CPU::virgulBul(string kelime) {

    int index = 0;
    while (kelime.size() > index) {

        if (kelime[index] == ',')
            return 1;
        index++;
    }
    return 0;
}

void CPU::print(){
            cout << "R1= " << arr[1];
            cout << " ,R2= " << arr[2];
            cout << " ,R3= " << arr[3];
            cout << " ,R4= " << arr[4];
            cout << " ,R5= " << arr[5];
            cout << " ,PC= " << getPC();
            cout << endl;
}
