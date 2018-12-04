/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: repS.cpp
VERSION: 1.1

IMPLEMENTATION INVARIANTS: isOn() and onMessage(int q) are the only overridden function. isOn() is
    overridden so object can track how many times it has been toggled on/off, and compares it with 
    its' data member cap. When object is on, its' overriden onMessage(int q) is called which selects 
    the qth position of the message, and repeats the pth character in the message, q times.
    When object is off, object calls parent class' offMessage, and it will return an empty string. 
*/

#include <iostream>
#include "repS.h"

repS::repS(unsigned int input, std::string m, unsigned int c) : iSlogan(input, m), cap(c) {}

std::string repS::onMessage(unsigned int q){
    if(p == q){
        return "";
    }

    std::string msg = "";
    for(int i=0; i<message.length(); i++){
        msg += message[i];
        if(i == q){
            for(int j=0; j<q; j++){
                msg += message[p];
            }
        }
    }
    return msg;
}

bool repS::isOn(){
    if(count <= cap){
        ++count;
        if(count % p == 0){
            on = !on;
        }
    }else if(count > cap){
        on = false;
    }
    return on;
}

