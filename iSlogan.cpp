/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: iSlogan.cpp
VERSION: 1.1

 IMPLEMENTATION INVARIANTS: OnMessage(), OffMessage() and isOn() are virtual functions, any
    child classes can change what their On, and Off messages are, and can also change the restrictions
    on their On/Off state for added extensionability. Query(int q) cannot be overriden since all iSlogan 
    type objects must have the same functionality for query. 
*/

#include "iSlogan.h"
#include <iostream>

iSlogan::iSlogan(unsigned int input, std::string m):message(m), p(input), on(true), count(0){}


std::string iSlogan::onMessage(unsigned int q){
    if(q == p){
        return "";
    }
    return message;
}

std::string iSlogan::offMessage(){
    return "";
}

bool iSlogan::isOn(){
    ++count;
    if(count % p == 0){
        on = !on;
    }
    return on;
}

std::string iSlogan::query( unsigned int q){
    if(isOn()){
       if(q < 10){
       	  return onMessage(q);
	   }
	   return offMessage();
    }
    return offMessage();
}
