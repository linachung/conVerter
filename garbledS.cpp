/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: garbledS.cpp
VERSION: 1.1

IMPLEMENTATION INVARIANTS: onMessage(int q) is the only overriden function, instead of returning
    a normal message, it will switch its' pth and qth characters and mix cases randomly. When off,
    garbledS acts like iSlogan object when iSlogan is off.
*/

#include <iostream>
#include <cstdlib>
#include "garbledS.h"

garbledS::garbledS(unsigned int input, std::string m);

std::string garbledS::onMessage(unsigned int q){
    if(p == q){
        return "";
    }

    std::string copy = message;
    char temp = copy[p];
    copy[p] = copy[q];
    copy[q] = temp;
    for(int i=0; i < copy.length()+1; i++){
        int rnd = rand() % copy.length();
        if(copy[rnd] == toupper(copy[rnd])){
            copy[rnd] = tolower(copy[rnd]);
        }else{
            copy[rnd] = toupper(copy[rnd]);
        }
    }

    return copy;
}


