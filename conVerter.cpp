/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: conVerter.cpp
VERSION: 1.0

IMPLEMENTATION INVARIANTS:  convertMessage() is a virtual function and can be overridden in any child 
                            classes. removePun() cannot be overridden since derrived conVerter classes
                            can choose to suppress functionality of removePun() or use it for convertMessage(). 
*/

#include <iostream>
#include "conVerter.h"

conVerter::conVerter(std::string m): msg(m){}

std::string conVerter::removePun(std::string s){
    for(int i = 0, len = s.size(); i < len; i++) 
    { 
      if (std::ispunct(s[i])) 
        { 
            s.erase(i--, 1); 
            len = s.size(); 
        } 
    } 
    std::cout<<s<<std::endl;
    return s;
}

int* conVerter::convertMessage(unsigned int r){
    
    int x;
    int* numArray =  new int[r];
    std::string m = removePun(msg);
    std::cout<<m<<std::endl;
    
    if(r > m.size()){
      r = m.size()%r;
    }

    for(int i=0; i<r; i++){
      x = m[i];
      numArray[i] = x;
    }
    
    return numArray;
}
