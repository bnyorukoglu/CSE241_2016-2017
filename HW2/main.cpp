/*BENGI YORUKOGLU                                       */
/* ---------------------------------------------------- */
/* Tarih:17/10/2016                                     */
/* -----------------------------------------------------*/
/* OBJECT ORENTED PROGRAMMING  HOMEWORK#2               */
/* -----------------------------------------------------*/
#include <iostream>
#include <fstream>

using namespace std;

/*gelen stringin her karakterini buyuk harfe cevirir*/
void BuyukHarf(string& gelen);

/*reg1'i reg2ye atar*/
void movRegReg(int& reg1, int& reg2);

/* Constant sayiyi reg1'e atar             */
void movRegConstant(int& reg1,int sayi);
/* addressteki deger registera atanir*/
void movAddressReg(unsigned int& addres,int& reg);
/* registerdaki deger adrese atanir*/
void movRegAddress(int& reg,unsigned int& address);
/* constant sayimiz addresse atanir*/
void movAddressConstant(unsigned int& address,int& sayi);
/* sayiyi print eder   */
void prn(int sayi);

/* reg1 ve reg2'yi toplar reg1e ekler */
void addRegReg(int& reg1, int reg2);

/*reg ile constanti toplar reg1e ekler*/
void addRegConstant(int& reg1,int sayi);

void addRegAddress(int& a,unsigned int& b );

/*reg1'den reg2'yi cikarir reg1e ekler */
void subRegReg(int& reg1,int reg2);

/*reg1den sayiyi cikarir reg1e ekler */
void subRegConstant(int& reg1,int sayi);
/* registedaki degerden addressteki deger cikarilir*/
/* sonuc registera atanir*/
void subRegAddress(int& a,unsigned int& b);

/*gelen stringi sayiya cevirir sayi degerini bulur*/
long int sayiDegeri(string kelime);

/*kac noktali virgul var  bulur*/
int noktaliBul(string kelime);

/* kac virgul var bulur*/
int virgulBul(string kelime);

int main(int argc, char** argv) {
    
    string line[200];
    int spaceCount = 0, count = 0, index, degis = 0;
    ifstream myfile(argv[1]);
    int R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0;
    string val;
    int atama;
    atama=sayiDegeri(argv[2]);
    int x=0;
    int deneme;
    bool hlt=false;
    int arr[6]={0,0,0,0,0,0};
    unsigned int arr2[50]={0};
   
    /* Dosyadan okudugumuz her satiri string arrayine attik   */
    /* Daha sonra her satirdaki harfleri büyük harfe cevirdik */
    /* DOsyayi okuduktan sonra kapattik                       */

    if (myfile.is_open()) {
        while (getline(myfile, line[count])) {

            line[count].push_back('\n');
			/* satiri okudukca buyuk harfe ceviriyoruz*/
            BuyukHarf(line[count]);

            ++count;
        }
        myfile.close();
    }
    else
        cout<<"The file can not be open !";
	
	
	
	
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
            
            
            /* komuttaki ilk parametreyi bulduk reg'e atadik*/
            while (k < j) {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg.push_back(line[index].at(k));
                ++k;
            }

            ++k;
            
            /* komuttaki ikinci parametreyi bulduk reg2'ye atadik*/
            while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg2.push_back(line[index].at(k));
                ++k;

            }
            /* eger ilk parametre register ise*/
            if(reg=="R1"|| reg=="R2" || reg=="R3" || reg=="R4" || reg=="R5"){
                
                /*ikinci parametre adres ise register-address fonksiyonu cagir */
                if(reg2[0]=='#'){
                    
                    int sayi,a,n;
                    sayi=sayiDegeri(&reg2[1]);
                    for(n=1;n<6;++n){

                        if((reg[1]-'0')==n)
                              a=n;
                    }
                    movRegAddress(arr[a],arr2[sayi]);
                    
                }
                /*ikinci parametre register ise register registeer fonksiyonu cagir*/
                else if(reg2=="R1"||reg2=="R2"||reg2=="R3"||reg2=="R4"||reg2=="R5"){
                    
                    int n;
                    int a=0,b=0;
                    for(n=1;n<6;++n){

                        if((reg[1]-'0')==n)
                            a=n;


                    }

                    for(n=1;n<6;++n){

                        if((reg2[1]-'0')==n)
                            b=n;
                    }
                    
                    movRegReg(arr[a],arr[b]);
                    
                }
                
                /* İkinci parametre bir constanttir*/
                else{
                    
                    
                    int sayi,n,b;
                    sayi=sayiDegeri(reg2);
                    /*girilen sayimizin icerisinde gecersiz bir karakter*/
                    /*karismis ise bu sayimiz gecersizdir ve program hata */
                    /*mesaji vererek cikar! */
                    if(sayi==-1){
                        
                        cout<<"MOV komutunda girilen constantta gecersiz ";
                        cout<<"karakter var!! "<<endl;
                        x=1;
                    }
                    else{
                        
                        for(n=1;n<6;++n){

                            if((reg[1]-'0')==n)
                                b=n;
                        }
                        movRegConstant(arr[b],sayi);
                        
                        
                    }
                    
                }
                
                
                
                
                
            }
            /*Mov komutunun ilk parametresi adres ise bu kosula girer*/
            else if(reg[0]=='#'){
                /*ikinci parametresi register ise*/
                /*address-reg fonksiyonu cagisirilir*/
                if(reg2=="R1"|| reg2=="R2" || reg2=="R3"||reg2=="R4" || reg2=="R5"){
                    int sayi,n,b;
                    sayi=sayiDegeri(&reg[1]);
                    for(n=1;n<6;++n){

                            if((reg2[1]-'0')==n)
                                b=n;
                    }
                     
                    movAddressReg(arr2[sayi],arr[b]);
                    
                }
                /* ikinci parametre registeer degil ise constanttir*/
                else{
                    
                    int sayi,sayi2,n,b;
                    sayi=sayiDegeri(reg2);
                    sayi2=sayiDegeri(&reg[1]);
                    if(sayi==-1){
                        
                        cout<<"MOV komutunda girilen constantta gecersiz ";
                        cout<<"karakter var!! "<<endl;
                        x=1;
                    }
                    else{
                        
                       
                        movAddressConstant(arr2[sayi2],sayi);
                      
                    }
                    
                }
            }
            
            else{
                cout<<"Gecersiz komut girdiniz! ";
                cout<<"MOV komutunda gecersizlik var!!"<<endl;
                x=1;
                
            }
            
            /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
            /*belirlenir */
             /* eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
            if(atama==0){
                
                
            }
            /*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
            else if(atama==1){
                    cout<<"MOV "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                    cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                    cout<<endl;
            }
            /*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
            else if(atama==2){
                int k;
                /* once register degerleri basilir*/
                cout<<"MOV "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                cout<<endl;
                
                /*daha sonra memory degerleri basilir*/
                cout<<"Memory degerleri: ";
                for(k=0;k<50;++k){
                    
                    cout<<arr2[k]<<", ";
                    
                    
                }
                 cout<<endl;     
            }
            
            
            
            
        }/*MOV MU*/
        
        
        
        else if (line[index].substr(spaceCount, 4).compare("PRN ") == 0) {

            string reg;
            int k = line[index].find("PRN") + 3;
            int j,n,a;
		    /* eger noktali virgulumuz var ise noktali virgüle kadar*/
		    /* olanlar stringe alinir*/
            if (noktaliBul(line[index]) == 1) {

                j = line[index].find(";");


                while (k < j) {
                    if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                        reg.push_back(line[index].at(k));
                    ++k;
                }


            }
			/* noktali virgul yok ise \n e kadar olanlar stringe alinir*/
            else {

                j = line[index].find("\n");

                string reg;
                while (k < j) {
                    if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                        reg.push_back(line[index].at(k));
                    ++k;
                }
            }
            
            /* eger adres ise */
            if(reg[0]=='#'){
                
                int sayi;
                /* sayi degeri hesaplanir .*/
                /* hesaplanirken #isaretini fonksiyona koymadigimiza*/
                /*dikkat etmeliyiz bu yüzden fonk.a 1.indexten itibaren*/
                /* yollariz*/
                sayi=sayiDegeri(&reg[1]);
                
                cout<<arr2[sayi]<<endl;
                
                
            }
            /* prn komutunun parametresi R1,R2,R3,R4,R5 degilse */
            /* yanlis komut girilmistir */
            else if(reg!="R1"&&reg!="R2"&&reg!="R3"&&reg!="R4"&&reg!="R5"){
               
                cout<<"gecersiz komut girdiniz!!";
                cout<<"PRN komutunda gecersizlik var!!"<<endl;
                x=1;
                
            }
            else if(reg=="R1" || reg=="R2" || reg=="R3" || reg=="R4" || reg=="R5"){
                
                for(n=1;n<6;++n){

                    if((reg[1]-'0')==n)
                        a=n;
                }
                
                cout<<arr[a]<<endl;
            }
            
            /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
            /*belirlenir */
            /* eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
            if(atama==0){
                
                
            }
            /*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
            else if(atama==1){
               
                    cout<<"PRN "<<reg<<" R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                    cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                    cout<<endl;
            }
            /*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
            else if(atama==2){
                /*register degerleri*/
                cout<<"PRN "<<reg<<" R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                cout<<endl;
                /*memory bas*/
                cout<<"memory degerleri: ";
                int k;
                for(k=0;k<50;++k){
                    
                    cout<<arr2[k]<<", ";
                   
                    
                }
                cout<<endl;      
            }
            
            
        }/*PRN KOSULU*/
        
        
        
        else if (line[index].substr(spaceCount, 4).compare("SUB ") == 0) {
            int sayi,n,a,b;
            int k = line[index].find("SUB") + 3;
            int j = line[index].find(",");
            string reg, reg2;
            /*komuttaki ilk parametreyi bulduk reg'e atadik*/
            while (k < j) {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg.push_back(line[index].at(k));
                ++k;
            }

            ++k;
            /* komuttaki ikinci parametreyi bulduk reg2'ye atadik*/
            while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg2.push_back(line[index].at(k));
                ++k;

            }
            
            /*ilk parametre register ise*/
            if(reg=="R1"|| reg=="R2"|| reg=="R3"|| reg=="R4"||reg=="R5"){
                
                /*ikinci parametre adres isareti ile basliyor ise*/
                if(reg2[0]=='#'){
                    for(n=1;n<6;++n){

                        if((reg[1]-'0')==n)
                            a=n;
                    }
                    /* sayi degeri hesaplanir*/
                    sayi=sayiDegeri(&reg2[1]);
                    subRegAddress(arr[a],arr2[sayi]);
                    
                }
               
                /* ikinci parametre adres isareti ile baslamiyorsa*/
                /*ya registerdir ya da constanttir*/
                else if(reg2[0]!='#'){
                    /*ikinci parametre eger register ise*/
                    if(reg2=="R1"||reg2=="R2"||reg2=="R3"||reg2=="R4"||reg2=="R5"){
                        
                        
                        for(n=1;n<6;++n){

                            if((reg[1]-'0')==n)
                                a=n;
                        }

                        for(n=1;n<6;++n){

                            if((reg2[1]-'0')==n)
                                    b=n;
                        }
                                
                        subRegReg(arr[a],arr[b]);
                       
                        
                    }
                    /* degilse ikinci parametre bir constanttir*/
                    else{
                        
                        sayi=sayiDegeri(reg2);
                        
                        if(sayi==-1){
                            
                            cout<<"Sayi icerisinde gecersiz bir karakter vardir";
                            cout<<"Gecersiz bir komut!";
                            x=1;
                        }
                        for(n=1;n<6;++n){
                
                            if((reg[1]-'0')==n)
                                a=n;
                            
                        }
                        subRegConstant(arr[a],sayi);
                        
                    }
                    
                    
                }
                
            }
            
            else{
                
                cout<<"Gecersiz komut girdiniz!! ";
                cout<<"Sub komutunda gecersizlik var!";
                x=1;
            }
            
            /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
            /*belirlenir */
            /* eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
            if(atama==0){
                
                
            }
            /*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
             else if(atama==1){
                    cout<<"SUB "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                    cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                    cout<<endl;
            }
            /*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
            else if(atama==2){
                int k;
                /*register degerleri*/
                cout<<"SUB "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                cout<<endl;
                /*memory*/
                cout<<"memory degerleri: "<<endl;
                for(k=0;k<50;++k){
                    
                    cout<<arr2[k]<<", ";
                    
                }
                 cout<<endl;     
            }
        }/*SUB KOSULU*/
        
        
        else if (line[index].substr(spaceCount, 4).compare("ADD ") == 0) {

            int sayi1=0,sayi2=0;
            int sayi,a,b,n;
            int k = line[index].find("ADD") + 3;
            int j = line[index].find(",");
            string reg, reg2;
            /* Add komutunun ilk parametresi reg stringinde toplaniyor*/
            while (k < j) {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg.push_back(line[index].at(k));
                ++k;
            }

            ++k;
			/* ikinci parametresi reg2 stringinde toplaniyor*/
            while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg2.push_back(line[index].at(k));
                ++k;

            }
              /*ilk parametre register ise*/
            if(reg=="R1"|| reg=="R2"|| reg=="R3"|| reg=="R4"||reg=="R5"){
                
                /*ikinci parametre adres isareti ile basliyor ise*/
                if(reg2[0]=='#'){
                    for(n=1;n<6;++n){

                        if((reg[1]-'0')==n)
                            a=n;
                    }
                    sayi=sayiDegeri(&reg2[1]);
                    addRegAddress(arr[a],arr2[sayi]);
                    
                }
               
                /* ikinci parametre adres isareti ile baslamiyorsa*/
                /*ya registerdir ya da constanttir*/
                else if(reg2[0]!='#'){
                    /*ikinci parametre eger register ise*/
                    if(reg2=="R1"||reg2=="R2"||reg2=="R3"||reg2=="R4"||reg2=="R5"){
                        
                        
                        for(n=1;n<6;++n){

                            if((reg[1]-'0')==n)
                                a=n;
                        }

                        for(n=1;n<6;++n){

                            if((reg2[1]-'0')==n)
                                    b=n;
                        }
                                
                        addRegReg(arr[a],arr[b]);
                       
                        
                    }
                    /* degilse ikinci parametre bir constanttir*/
                    else{
                        
                        sayi=sayiDegeri(reg2);
                        /*girilen sayimizin icerisinde gecersiz bir karakter*/
                        /*karismis ise bu sayimiz gecersizdir ve program hata */
                        /*mesaji vererek cikar! */
                        if(sayi==-1){
                            
                            cout<<"Sayi icerisinde gecersiz bir karakter vardir";
                            cout<<"Gecersiz bir komut!";
                            x=1;
                        }
                        for(n=1;n<6;++n){
                
                            if((reg[1]-'0')==n)
                                a=n;
                            
                        }
                        addRegConstant(arr[a],sayi);
                        
                    }
                    
                    
                }
                
            }
            else{
                cout<<"Gecersiz komut girdiniz! ";
                cout<<"Add komutunda gecersizlik var";
                x=1;
                
            }
            
            /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
            /*belirlenir */
             /* eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
            if(atama==0){
                
                
            }
            /*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
            else if(atama==1){
                    cout<<"ADD "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                    cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                    cout<<endl;
            }
            /*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
            else if(atama==2){
                /*once register degerlerini bas*/
                cout<<"ADD "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                cout<<endl;
                /*memory bas*/
                int k;
                cout<<"memory: ";
                for(k=0;k<50;++k){
                    
                    cout<<arr2[k]<<", ";
                    
                }
                cout<<endl;      
            }
          
        
        }/* ADD kosulu */
        
        
        /* eger girilen komut JMP ise*/
        else if (line[index].substr(spaceCount, 4).compare("JMP ") == 0) {

            int j, k;
            string reg, reg2;

            /*   eger virgul varsa  2 parametre almistir        */

            if (virgulBul(line[index]) == 1) {

                k = line[index].find("JMP") + 3;
                j = line[index].find(",");

				/* ilk parametre reg stringinde toplanir*/
                while (k < j) {
                    if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                        reg.push_back(line[index].at(k));
                    ++k;
                }

                ++k;
				/* ikinci parametre reg2 stringinde toplanir*/
                while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                    if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                        reg2.push_back(line[index].at(k));
                    ++k;

                }
                
                int sayicevir, sayicevir2 = 0;
                /*Komutumuzun ilk parametresi hangi registeri gösteriyor ise*/
                /*Degeri sayicevire atanir ve daha sonra 0 olup olmadigi */
                /*kontrol edilir */
                if(reg=="R1")
                   sayicevir = arr[1];
                else if(reg=="R2")
                    sayicevir=arr[2];
                else if(reg=="R3")
                    sayicevir=arr[3];
                else if(reg=="R4")
                    sayicevir=arr[4];
                else if(reg=="R5")
                    sayicevir=arr[5];
                else
                    sayicevir=-2;
                /* ilk sayi sifir ise indeximizi degistiririz*/
                /* -2 cikarmamizin sebebi indexin for döngüsü icinde en */
                /*basinda degerinin zaten 1 artiyor olusu ve indexin */
                /*satir sayisi -1e esit olmasi yani toplam 2 cikarmamiz */
                /*gerekiyor */
                if (sayicevir == 0) {
                    
                    sayicevir2 = sayiDegeri(reg2);
                    index = sayicevir2 - 2;
                    

                }

                /*ilk parametre sifir degil ise devam et*/
                else {

                }
               /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
               /*belirlenir */
               /*eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
               if(atama==0){


               }
               /*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
               else if(atama==1){
                       cout<<"JMP "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                       cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                       cout<<endl;
               }
               /*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
               else if(atama==2){
                   /*once register degerlerini bas*/
                   cout<<"JMP "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                   cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                   cout<<endl;
                   /*memory bas*/
                   int k;
                   cout<<"memory: ";
                   for(k=0;k<50;++k){

                       cout<<arr2[k]<<", ";

                   }
                   cout<<endl;      
               }
            }

            /* Virgul yoksa tek deger var demektir */
            else if (virgulBul(line[index]) == 0) {
               
                /*Eger yorum varsa ; vardir o zaman ;'e kadar kontrol et*/
                if (noktaliBul(line[index]) == 1) {

                    k = line[index].find("JMP") + 3;

                    j = line[index].find(";");

					/* parametre reg stringinde toplanir*/
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
               /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
               /*belirlenir */
               /*eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
               if(atama==0){


               }
                /*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
                else if(atama==1){
                       cout<<"JMP "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                       cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                       cout<<endl;
                }
                /*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
                else if(atama==2){
                   /*once register degerlerini bas*/
                   cout<<"JMP "<<reg; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                   cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                   cout<<endl;
                   /*memory bas*/
                   int k;
                   cout<<"memory: ";
                   for(k=0;k<50;++k){

                       cout<<arr2[k]<<", ";

                   }
                   cout<<endl;      
               }

            }

        }/* JMP kosulu*/
		
		/* eger girilen komut JPN ise*/
        else if (line[index].substr(spaceCount, 4).compare("JPN ") == 0) {

            
            int sayi,a,b,n,sayicevir;
            int k = line[index].find("JPN") + 3;
            int j = line[index].find(",");
            string reg, reg2;
            /* ilk parametre reg stringinde toplanir*/
            while (k < j) {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg.push_back(line[index].at(k));
                ++k;
            }

            ++k;
			/* ikinci parametre reg2 stringinde toplanir*/
            while (line[index].at(k) != '\n' && line[index].at(k) != ';') {
                if (line[index].at(k) != ' ' && line[index].at(k) != '\t')
                    reg2.push_back(line[index].at(k));
                ++k;

            }
           
            sayi=sayiDegeri(reg2);
                
            /* komutumuzun ilk parametresi hangi registeri gösteriyor ise*/
            /*o registerin degeri sayicevire atanir */
            if(reg=="R1")
                    sayicevir = arr[1];
            else if(reg=="R2")
                    sayicevir=arr[2];
            else if(reg=="R3")
                    sayicevir=arr[3];
            else if(reg=="R4")
                    sayicevir=arr[4];
            else if(reg=="R5")
                    sayicevir=arr[5];
            else{
                cout<<"JPN komutunun ilk parametresi yanlis girilmistir!"<<endl;
                    x=1;
            }
            /*Eger ilk parametremiz sifir veya negatif ise gösterdigi satira atla*/
            /* ilk sayi sifir ise indeximizi degistiririz*/
            /* -2 cikarmamizin sebebi indexin for döngüsü icinde en */
            /*basinda degerinin zaten 1 artiyor olusu ve indexin */
            /*satir sayisi -1e esit olmasi yani toplam 2 cikarmamiz */
            /*gerekiyor */
            if(sayicevir==0 || sayicevir<0){

                index=sayi-2;
            }
            /* degil ise devam et*/
            else{

            }
              
            
            
            /*argv[2] kontrol.bu kontrole gore konsola nasil yazilmasi gerektigi*/
            /*belirlenir */
            /*eger maine 0 parametresi yollanirsa sadece komutu yapsin*/
            if(atama==0){
                
                
            }
            /*eger maine 1 parametresi yollanirsa registerlarin degerini bassin*/
            else if(atama==1){
                    cout<<"JPN "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                    cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                    cout<<endl;
            }
            /*eger maine 2 parametresi yollanirsa adreslerin icindeki degerleri bassin*/
            else if(atama==2){
                /*once register degerlerini bas*/
                cout<<"JPN "<<reg<<"-"<< reg2; cout<< " R1= "<<arr[1];cout<<" ,R2= "<<arr[2];
                cout<<" ,R3= "<<arr[3]; cout<<" ,R4= "<<arr[4];cout<<" ,R5= "<<arr[5];
                cout<<endl;
                /*memory bas*/
                int k;
                cout<<"memory: ";
                for(k=0;k<50;++k){
                    
                    cout<<arr2[k]<<", ";
                    
                }
                cout<<endl;      
            }
        }
        /*HLT komutunu gordügü anda programimiz tüm register degerleri yazdirilarak sona erdirilir*/
        else if ((line[index].substr(spaceCount, 4).compare("HLT ") == 0) || (line[index].substr(spaceCount, 3).compare("HLT") == 0))

        {
			hlt=true;
                        /* once register degerlerini yazdir*/
                        cout<<"HLT  ";
			cout << "REG1="<< arr[1]<<",REG2="<< arr[2]<<",REG3="<<arr[3]<<",REG4="<<arr[4]<<",REG5="<<arr[5]<<endl;
                         /*memory bas*/
                        int k;
                        cout<<"memory: ";
                        for(k=0;k<50;++k){

                            cout<<arr2[k]<<", ";

                        }


	}/* HLT KOSULU*/
        
        /*Eger girilien komutta HLT,JMP,ADD,JPN,SUB yok ise yanlis bir komut girilmistir!!*/
        else if ((line[index].substr(spaceCount, 4).compare("JPN ")!= 0)&&(line[index].substr(spaceCount, 3).compare("HLT") != 0)&&(line[index].substr(spaceCount, 4).compare("JMP ") != 0)&&(line[index].substr(spaceCount, 4).compare("MOV ") != 0)&& (line[index].substr(spaceCount, 4).compare("SUB ") != 0) && (line[index].substr(spaceCount, 4).compare("PRN ") != 0)&& (line[index].substr(spaceCount, 4).compare("ADD ") != 0))
        {
                 cout<<"yanlis komut girdiniz. ";
                 cout<<"ADD,MOV,SUB,PRN,JMP,jpn disinda bir komut girdiniz!!"<<endl;
                 x=1;
        }/* KOMUT YANLISSA*/
			

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
void movRegReg(int& reg1,int& reg2) {

    reg2 = reg1;
}

/* Bu fonksiyon sayi paraetresindeki degeri reg1'e atiyor */
void movRegConstant(int& reg1,int sayi) {

    reg1 = sayi;
}
/* bu fonksiyonda ikinci parametremiz olan address registera ataniyor*/
void movAddressReg(unsigned int& addres,int& reg){
    
    
    reg=addres;
    
    
}
/* Bu fonksiyonda ikinci parametre olan sayi addresse ataniyor*/
void movAddressConstant(unsigned int& address,int& sayi){
    
    
    address=sayi;
}
/* Bu fonksiyonda ilk parametre olan register addresse ataniyor*/
void movRegAddress(int& reg,unsigned int& address){
    
    address=reg;
    
}
/* BU fonksiyon print ettirmemizi sagliyor*/
void prn(int sayi) {

    cout << sayi;
}

/* Bu fonksiyon reg1 ile reg2'nin toplamini reg1e atiyor*/
void addRegReg(int& reg1,int reg2) {

    reg1 = reg1 + reg2;
}
/* bu fonksiyonda registerdaki deger ve sayi toplanip registera*/
/* ataniyor*/
void addRegConstant(int& reg1,int sayi) {

    reg1 = reg1 + sayi;
}
/* Bu fonksiyonda registerdaki deger ve addressteki deger toplanip*/
/* registera ataniyor*/
void addRegAddress(int& a,unsigned int& b ) {

    a = a + b;
}
/*  Bu fonksiyonda iki register birbirinden cikarilip ilk parametredeki*/
/* registera ataniyor*/
void subRegReg(int& reg1,int reg2) {

    reg1 = reg1 - reg2;
}


/* Bu fonksiyonda registerdan constant sayi cikarilip*/
/* registera ataniyor*/
void subRegConstant(int& reg1,int sayi) {

    reg1 = reg1 - sayi;
}
/* BU fonksiyonda registerdaki degerden addressteki deger cikarilip*/
/* registera ataniyor*/
void subRegAddress(int& a,unsigned int& b){
    
    a=a-b;
    
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
        if(kelime[index]<'-' || kelime[index]>'9'){
            
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

