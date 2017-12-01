/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Memory.h
 * Author: bengi
 *
 * Created on 04 Kasım 2016 Cuma, 18:57
 */
#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <string>

using namespace std;


class Memory{
public:
    Memory();
    Memory(int option);
    void setMem(int index,int value);
    int getMem(int index)const {return memarr[index];};
    const void printAll ()const;
   
private:
    unsigned int memarr[50];
    int secim;
    
    
};

#endif /* MEMORY_H */
