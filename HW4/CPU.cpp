//BENGI YORUKOGLU
//131044046
// File:   CPU.cpp
//Created on 24 Ekim 2016 Pazartesi, 14:27


#include "CPU.h"
#include <string>

using namespace std;

//program countera 1 atanan setteri cagirir.ve registerlarin bulundugu arrayin
//atamalarinin yapildigi setteri cagirir

CPU::CPU() {
	//tum registerlara en basta 0 degeri atanir
	setReg(1, 0);
    setReg(2, 0);
    setReg(3, 0);
    setReg(4, 0);
    setReg(5, 0);
    setPC(1);


}

CPU::CPU(int option) {
	//tum registerlara en basta 0 degeri atanir
    setReg(1, 0);
    setReg(2, 0);
    setReg(3, 0);
    setReg(4, 0);
    setReg(5, 0);
    setPC(1);
	//private olan atama degerine paramtre olarak gelen
	//option degeri atanir
    atama = option;

}


// registerlari set eder.registerlarin bulundugu arrayin tüm elemanlarina
//sifir atariz

void CPU::setReg(int index, int value) {

    arr[index] = value;

}
//gelen satirin once ilk3 karakterine bakar.buna gore komutu belirler
//belirlenen komuttan sonra o komutun fonksiyonu cagirilir
//fonksiyondaki islem gerceklesir
//daha sonra program counter arttirilir

bool CPU::execute(string line, Memory& x) {

    int spaceCount = 0;
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;

    bool yapilan = false;
    // eger gelen satirdaki linein 3 karakteri mov ise
    //mov komutunun islemini yapan fucMov  cagirilir
    //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    if (line.substr(spaceCount, 4).compare("MOV ") == 0) {

        yapilan = funcMov(line, x);

        ++PC;
    }// eger gelen satirdaki linein 3 karakteri prn ise
        //prn komutunun islemini yapan fucPrn  cagirilir
        //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    else if (line.substr(spaceCount, 4).compare("PRN ") == 0) {

        yapilan = funcPrn(line, x);
        ++PC;
    }// eger gelen satirdaki linein 3 karakteri sub ise
        //sub komutunun islemini yapan fucSUb cagirilir
        //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    else if (line.substr(spaceCount, 4).compare("SUB ") == 0) {

        yapilan = funcSub(line, x);
        ++PC;
    }// eger gelen satirdaki linein 3 karakteri add ise
        //add komutunun islemini yapan fucAdd cagirilir
        //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    else if (line.substr(spaceCount, 4).compare("ADD ") == 0) {

        yapilan = funcAdd(line, x);
        ++PC;
    }// eger gelen satirdaki linein 3 karakteri jmp ise
        //jmp komutunun islemini yapan fucJmp cagirilir
        //PC counter o satirin islemi yapildigi icin 1 arttirilir.
    else if (line.substr(spaceCount, 4).compare("JMP ") == 0) {

        yapilan = funcJmp(line, x);
        ++PC;

    } else if (line.substr(spaceCount, 4).compare("JPN ") == 0) {

        yapilan = funJpn(line, x);
        ++PC;
    }
        //eger gelen komut hlt ise programin sonlanmasi icin hlt'ye true atanir
    else if ((line.substr(spaceCount, 4).compare("HLT ") == 0) || (line.substr(spaceCount, 3).compare("HLT") == 0)) {
        yapilan = 1;
        hlt = true;
        print();

        cout << "memory: ";
        for (int k = 0; k < 50; ++k) {

            cout << x.getMem(k) << ", ";

        }
    }/* HLT KOSULU*/
    else {

        if (funcDiger(line) == false)
            return false;

    }
    if (yapilan)
        return true;
    else {
        cout << "yanlis komut girdiniz!!!";
        hlt = true;
        return false;
    }


}

bool CPU::halted() {

    return hlt;
}
//ilk 3 karakterde belirlenen komut mov ise bu fonksiyon cagirilir

bool CPU::funcMov(string line, Memory& x) {

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
        string reg="", reg2="";


        /* komuttaki ilk parametreyi bulduk reg'e atadik*/
        while (k < j) {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg.push_back(line.at(k));
            ++k;
        }

        ++k;

        /* komuttaki ikinci parametreyi bulduk reg2'ye atadik*/
        while (k < line.length()) {
            if (line.at(k) != '\n' && line.at(k) != ';') {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg2.push_back(line.at(k));
            }
            ++k;


        }
        /* eger ilk parametre register ise*/
        if (reg == "R1" || reg == "R2" || reg == "R3" || reg == "R4" || reg == "R5") {

            /*ikinci parametre adres ise register-address fonksiyonu cagir */
            if (reg2[0] == '#') {

                int sayi, a, n;
                sayi = sayiDegeri(&reg2[1]);
                for (n = 1; n < 6; ++n) {

                    if ((reg[1] - '0') == n)
                        a = n;
                }
                movRegAddress(a, sayi, x);

            }/*ikinci parametre register ise register registeer fonksiyonu cagir*/
            else if (reg2 == "R1" || reg2 == "R2" || reg2 == "R3" || reg2 == "R4" || reg2 == "R5") {

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

                movRegReg(a, b);

            }/* İkinci parametre bir constanttir*/
            else {


                int sayi, n, b;
                sayi = sayiDegeri(reg2);
                /*girilen sayimizin icerisinde gecersiz bir karakter*/
                /*karismis ise bu sayimiz gecersizdir ve program hata */
                /*mesaji vererek cikar! */
                if (sayi == -1) {

                    cout << "MOV komutunda girilen constantta gecersiz ";
                    cout << "karakter var!! " << endl;
                    hlt = true;
                    return false;

                } else {

                    for (n = 1; n < 6; ++n) {

                        if ((reg[1] - '0') == n)
                            b = n;
                    }
                    movRegConstant(b, sayi);


                }

            }





        }/*Mov komutunun ilk parametresi adres ise bu kosula girer*/
        else if (reg[0] == '#') {
            /*ikinci parametresi register ise*/
            /*address-reg fonksiyonu cagisirilir*/
            if (reg2 == "R1" || reg2 == "R2" || reg2 == "R3" || reg2 == "R4" || reg2 == "R5") {
                int sayi, n, b;
                sayi = sayiDegeri(&reg[1]);
                for (n = 1; n < 6; ++n) {

                    if ((reg2[1] - '0') == n)
                        b = n;
                }

                movAddressReg(sayi, b, x);

            }/* ikinci parametre registeer degil ise constanttir*/
            else {

                int sayi, sayi2, n, b;
                sayi = sayiDegeri(reg2);
                sayi2 = sayiDegeri(&reg[1]);
                if (sayi == -1) {

                    cout << "MOV komutunda girilen constantta gecersiz ";
                    cout << "karakter var!! " << endl;
                    hlt = true;
                    return false;
                } else {


                    movAddressConstant(sayi2, sayi, x);

                }

            }
        } else {
            cout << "Gecersiz komut girdiniz! ";
            cout << "MOV komutunda gecersizlik var!!" << endl;
            hlt = true;
            return false;

        }

        /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
        /*belirlenir */
        /* eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
        if (atama == 0) {


        }/*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
        else if (atama == 1) {
            cout << "MOV " << reg << "-" << reg2;
            cout << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
        }/*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
        else if (atama == 2) {
            int k;
            /* once register degerleri basilir*/

            cout << "MOV " << reg << "-" << reg2;
            cout << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;

            /*daha sonra memory degerleri basilir*/
            cout << "Memory degerleri: ";
            for (k = 0; k < 50; ++k) {

                cout << x.getMem(k) << ", ";


            }
            cout << endl;
        }




    }/*MOV MU*/

    return true;
}
//ilk 3 karakten prn ise bu fonksiyon cagirilir

bool CPU::funcPrn(string line, Memory& x) {
    line.push_back('\n');
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
        int j, n, a;

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


        if (reg[0] == '#') {

            int sayi;
            sayi = sayiDegeri(&reg[1]);

            cout << x.getMem(sayi) << endl;


        } else if (reg != "R1" && reg != "R2" && reg != "R3" && reg != "R4" && reg != "R5") {

            cout << "gecersiz komut girdiniz!!";
            cout << "PRN komutunda gecersizlik var!!" << endl;
            hlt = true;
            return false;

        } else if (reg == "R1" || reg == "R2" || reg == "R3" || reg == "R4" || reg == "R5") {

            for (n = 1; n < 6; ++n) {

                if ((reg[1] - '0') == n)
                    a = n;
            }

            cout << getReg(a) << endl;
        }

        /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
        /*belirlenir */
        /* eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
        if (atama == 0) {


        }/*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
        else if (atama == 1) {

            cout << "PRN " << reg << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
        }/*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
        else if (atama == 2) {
            /*register degerleri*/
            cout << "PRN " << reg << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
            /*memory bas*/
            cout << "memory degerleri: ";
            int k;
            for (k = 0; k < 50; ++k) {

                cout << x.getMem(k) << ", ";


            }
            cout << endl;
        }


    }/*PRN KOSULU*/

    return true;

}
//ilk 3 karakter sub ise bu fonksiyon cagirilir

bool CPU::funcSub(string line, Memory& x) {
    int spaceCount = 0;
    //0.indeksten itibaren bosluk var mi diye bakar
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;

    //bosluktan sonraki indeksten itibaren 4 indeks boyunca alir
    //alinan string sub mu diye bakar
    //sub ise devam edilir
    if (line.substr(spaceCount, 4).compare("SUB ") == 0) {
        int sayi, n, a, b;
        int k = line.find("SUB") + 3;
        int j = line.find(",");
        string reg, reg2;
        /*komuttaki ilk parametreyi bulduk reg'e atadik*/
        while (k < j) {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg.push_back(line.at(k));
            ++k;
        }

        ++k;
        /* komuttaki ikinci parametreyi bulduk reg2'ye atadik*/
       while (k < line.length()) {
            if (line.at(k) != '\n' && line.at(k) != ';') {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg2.push_back(line.at(k));
            }
            ++k;


        }

        /*ilk parametre register ise*/
        if (reg == "R1" || reg == "R2" || reg == "R3" || reg == "R4" || reg == "R5") {

            /*ikinci parametre adres isareti ile basliyor ise*/
            if (reg2[0] == '#') {
                for (n = 1; n < 6; ++n) {

                    if ((reg[1] - '0') == n)
                        a = n;
                }
                sayi = sayiDegeri(&reg2[1]);
                subRegAddress(a, sayi, x);

            }                /* ikinci parametre adres isareti ile baslamiyorsa*/
                /*ya registerdir ya da constanttir*/
            else if (reg2[0] != '#') {
                /*ikinci parametre eger register ise*/
                if (reg2 == "R1" || reg2 == "R2" || reg2 == "R3" || reg2 == "R4" || reg2 == "R5") {


                    for (n = 1; n < 6; ++n) {

                        if ((reg[1] - '0') == n)
                            a = n;
                    }

                    for (n = 1; n < 6; ++n) {

                        if ((reg2[1] - '0') == n)
                            b = n;
                    }

                    subRegReg(a, b);


                }                    /* degilse ikinci parametre bir constanttir*/
                else {

                    sayi = sayiDegeri(reg2);

                    if (sayi == -1) {

                        cout << "Sayi icerisinde gecersiz bir karakter vardir";
                        cout << "Gecersiz bir komut!";
                        hlt = true;
                        return false;
                    }
                    for (n = 1; n < 6; ++n) {

                        if ((reg[1] - '0') == n)
                            a = n;

                    }
                    subRegConstant(a, sayi);

                }


            }

        } else {

            cout << "Gecersiz komut girdiniz!! ";
            cout << "Sub komutunda gecersizlik var!";
            hlt = true;
            return false;
        }

        /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
        /*belirlenir */
        /* eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
        if (atama == 0) {


        }/*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
        else if (atama == 1) {
            cout << "SUB " << reg << "-" << reg2;
            cout << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
        }/*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
        else if (atama == 2) {
            int k;
            /*register degerleri*/
            cout << "SUB " << reg << "-" << reg2;
            cout << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
            /*memory*/
            cout << "memory degerleri: " << endl;
            for (k = 0; k < 50; ++k) {

                cout << x.getMem(k) << ", ";

            }
            cout << endl;
        }
    }/*SUB KOSULU*/



    return true;

}
//eger ilk 3 karakter add ise bu fonksiyon cagirirlir

bool CPU::funcAdd(string line, Memory& x) {
    int spaceCount = 0;
    //0.indeksten itibaren bosluk var mi diye bakar
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;

    //bosluktan sonraki indeksten itibaren 4 indeks boyunca alir
    //alinan string add mi diye bakar
    //add ise devam edilir
    if (line.substr(spaceCount, 4).compare("ADD ") == 0) {

        int sayi1 = 0, sayi2 = 0;
        int sayi, a, b, n;
        int k = line.find("ADD") + 3;
        int j = line.find(",");
        string reg, reg2;
        while (k < j) {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg.push_back(line.at(k));
            ++k;
        }

        ++k;

        while (k < line.length()) {
            if (line.at(k) != '\n' && line.at(k) != ';') {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg2.push_back(line.at(k));
            }
            ++k;


        }
        /*ilk parametre register ise*/
        if (reg == "R1" || reg == "R2" || reg == "R3" || reg == "R4" || reg == "R5") {

            /*ikinci parametre adres isareti ile basliyor ise*/
            if (reg2[0] == '#') {
                for (n = 1; n < 6; ++n) {

                    if ((reg[1] - '0') == n)
                        a = n;
                }
                sayi = sayiDegeri(&reg2[1]);
                addRegAddress(a, sayi, x);

            }/* ikinci parametre adres isareti ile baslamiyorsa*/
                /*ya registerdir ya da constanttir*/
            else if (reg2[0] != '#') {
                /*ikinci parametre eger register ise*/
                if (reg2 == "R1" || reg2 == "R2" || reg2 == "R3" || reg2 == "R4" || reg2 == "R5") {


                    for (n = 1; n < 6; ++n) {

                        if ((reg[1] - '0') == n)
                            a = n;
                    }

                    for (n = 1; n < 6; ++n) {

                        if ((reg2[1] - '0') == n)
                            b = n;
                    }

                    addRegReg(a, b);


                }/* degilse ikinci parametre bir constanttir*/
                else {

                    sayi = sayiDegeri(reg2);
                    /*girilen sayimizin icerisinde gecersiz bir karakter*/
                    /*karismis ise bu sayimiz gecersizdir ve program hata */
                    /*mesaji vererek cikar! */
                    if (sayi == -1) {

                        cout << "Sayi icerisinde gecersiz bir karakter vardir";
                        cout << "Gecersiz bir komut!";
                        hlt = true;
                        return false;
                    }
                    for (n = 1; n < 6; ++n) {

                        if ((reg[1] - '0') == n)
                            a = n;

                    }
                    addRegConstant(a, sayi);

                }


            }

        } else {
            cout << "Gecersiz komut girdiniz! ";
            cout << "Add komutunda gecersizlik var";
            hlt = true;
            return false;

        }

        /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
        /*belirlenir */
        /* eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
        if (atama == 0) {


        }/*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
        else if (atama == 1) {
            cout << "ADD " << reg << "-" << reg2;
            cout << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
        }/*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
        else if (atama == 2) {
            /*once register degerlerini bas*/
            cout << "ADD " << reg << "-" << reg2;
            cout << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
            /*memory bas*/
            int k;
            cout << "memory: ";
            for (k = 0; k < 50; ++k) {

                cout << x.getMem(k) << ", ";

            }
            cout << endl;
        }


    }/* ADD kosulu */


    return true;
}

bool CPU::funJpn(string line, Memory& x) {
    
    line.push_back('\n');
    int spaceCount = 0;
    //0.indeksten itibaren bosluk var mi diye bakar
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;

    if (line.substr(spaceCount, 4).compare("JPN ") == 0) {


        int sayi, a, b, n, sayicevir;
        int k = line.find("JPN") + 3;
        int j = line.find(",");
        string reg, reg2;
        while (k < j) {
            if (line.at(k) != ' ' && line.at(k) != '\t')
                reg.push_back(line.at(k));
            ++k;
        }

        ++k;

        while (k < line.length()) {
            if (line.at(k) != '\n' && line.at(k) != ';') {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg2.push_back(line.at(k));
            }
            ++k;


        }

        sayi = sayiDegeri(reg2);

        /* komutumuzun ilk parametresi hangi registeri gösteriyor ise*/
        /*o registerin degeri sayicevire atanir */
        if (reg == "R1")
            sayicevir = getReg(1);
        else if (reg == "R2")
            sayicevir = getReg(2);
        else if (reg == "R3")
            sayicevir = getReg(3);
        else if (reg == "R4")
            sayicevir = getReg(4);
        else if (reg == "R5")
            sayicevir = getReg(5);
        else {
            cout << "JPN komutunun ilk parametresi yanlis girilmistir!" << endl;
            hlt = true;
            return false;
        }
        /*Eger ilk parametremiz sifir veya negatif ise gösterdigi satira atla*/
        /* ilk sayi sifir ise indeximizi degistiririz*/
        /* -2 cikarmamizin sebebi indexin for döngüsü icinde en */
        /*basinda degerinin zaten 1 artiyor olusu ve indexin */
        /*satir sayisi -1e esit olmasi yani toplam 2 cikarmamiz */
        /*gerekiyor */
        if (sayicevir <= 0) {

            PC = sayi - 1;
        }/* degil ise devam et*/
        else {

        }



        /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
        /*belirlenir */
        /*eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
        if (atama == 0) {


        }/*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
        else if (atama == 1) {
            cout << "JPN " << reg << "-" << reg2;
            cout << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
        }/*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
        else if (atama == 2) {
            /*once register degerlerini bas*/
            cout << "JPN " << reg << "-" << reg2;
            cout << " R1= " << getReg(1);
            cout << " ,R2= " << getReg(2);
            cout << " ,R3= " << getReg(3);
            cout << " ,R4= " << getReg(4);
            cout << " ,R5= " << getReg(5);
            cout << endl;
            /*memory bas*/
            int k;
            cout << "memory: ";
            for (k = 0; k < 50; ++k) {

                cout << x.getMem(k) << ", ";

            }
            cout << endl;
        }
    }
    return true;



}

bool CPU::funcJmp(string line, Memory& x) {

    line.push_back('\n');
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

            while (k < line.length()) {
            if (line.at(k) != '\n' && line.at(k) != ';') {
                if (line.at(k) != ' ' && line.at(k) != '\t')
                    reg2.push_back(line.at(k));
            }
            ++k;


        }

            int sayicevir, sayicevir2 = 0;
            if (reg == "R1")
                sayicevir = getReg(1);
            else if (reg == "R2")
                sayicevir = getReg(2);
            else if (reg == "R3")
                sayicevir = getReg(3);
            else if (reg == "R4")
                sayicevir = getReg(4);
            else if (reg == "R5")
                sayicevir = getReg(5);
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


            }/*ilk parametre sifir degil ise devam et*/
            else {

            }
        }/* Virgul yoksa tek deger var demektir */
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
            }/* noktali virgul yoksa \n'e kadar kontrol et */
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
        if (atama == 1) {
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
    string instruction[7] = {"MOV", "ADD", "SUB", "PRN", "JMP", "HLT", "JPN"};
    while (line.at(spaceCount) == ' ' || line.at(spaceCount) == '\t')
        spaceCount++;
    //tek tek kontrol edilir.eger komut bunlardan biri degilse false return eder
    for (int i = 0; i < 7; ++i) {

        if (line.substr(spaceCount, 3) == instruction[i])
            return true;


    }

    cout << "yanlis komut girdiniz!!!!";
    return false;



}

/* Bu fonksiyon reg2deki degeri reg1e atiyor */
void CPU::movRegReg(int a, int b) {

    setReg(b, getReg(a));
}

/* Bu fonksiyon sayi paraetresindeki degeri reg1'e atiyor */
void CPU::movRegConstant(int a, int sayi) {

    setReg(a, sayi);
}

void CPU::movAddressReg(unsigned int a, int b, Memory& x) {

    setReg(b, x.getMem(a));



}

void CPU::movAddressConstant(unsigned int a, int sayi, Memory& x) {

    x.setMem(a, sayi);

}

void CPU::movRegAddress(int a, unsigned int b, Memory& x) {

    x.setMem(b, getReg(a));


}

/* BU fonksiyon print ettirmemizi sagliyor*/
void CPU::prn(int sayi) {

    cout << sayi;
}

/* Bu fonksiyon reg1 ile reg2'nin toplamini reg1e atiyor*/
void CPU::addRegReg(int a, int b) {

    setReg(a, getReg(a) + getReg(b));
}

void CPU::addRegConstant(int a, int sayi) {

    setReg(a, getReg(a) + sayi);
}

void CPU::addRegAddress(int a, unsigned int b, Memory& x) {
    setReg(a, getReg(a) + x.getMem(b));

}

void CPU::subRegReg(int a, int b) {

    setReg(a, getReg(a) - getReg(b));
}

void CPU::subRegConstant(int a, int sayi) {

    setReg(a, getReg(a) - sayi);
}

void CPU::subRegAddress(int a, unsigned int b, Memory& x) {

    setReg(a, x.getMem(b) - getReg(a));
    /*
    a = a - b;
     */
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
        if (kelime[index] < '-' || kelime[index] > '9') {

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

void CPU::print() {
    cout << "R1= " << getReg(1);
    cout << " ,R2= " << getReg(2);
    cout << " ,R3= " << getReg(3);
    cout << " ,R4= " << getReg(4);
    cout << " ,R5= " << getReg(5);
    cout << " ,PC= " << getPC();
    cout << endl;
}
