/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: garbledconVert.cpp
VERSION: 1.0

IMPLEMENTATION INVARIANTS: convertMessage(unsigned int r) is the only overriden function, however
		garbledS does override its' parent' onMessage(unsigned int q) method, where it returns the message
		with its' pth and qth characters and mix cases randomly. When off, garbledS acts like iSlogan object
		when iSlogan is off. convertMessage acts like the conVerter's convertMessage except it calls
		garbledS's onMessage() to recieve the garbled message, and converts that.
*/

#include "garbledconVert.h"
#include <iostream>
#include <string>

garbledconVert::garbledconVert(unsigned int p, std::string m) : garbledS(p, m), conVerter(m){}

int* garbledconVert::convertMessage(unsigned int r){
	std::string garbled = onMessage(r);
	int x;
	int* numArray = new int[r];
	
	std::string m = removePun(garbled);

    if(r >  m.size()){
      r = m.size()%r;
    }
    
	for(int i=0; i<r; i++){
		x = m[i];
		numArray[i] = x;
	}

	return numArray;
}
