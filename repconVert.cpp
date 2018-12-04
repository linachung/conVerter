//NAME: Allie O'Young
//FILENAME: repconVert.h
//DATE: 11/9/18
//VERSION: 1.0

/*IMPLEMENTATION INVARIANTS: convertMessage(unsigned int r) is the only overriden function, however
		repS does override its' parent' onMessage(unsigned int q) method, and isOn() method. isOn() is
    	overridden so object can track how many times it has been toggled on/off, and compares it with 
    	its' data member cap. When object is on, its' overriden onMessage(int q) is called which selects 
    	the qth position of the message, and repeats the pth character in the message, q times.
    	When object is off, object calls parent class' offMessage, and it will return an empty string. 
		convertMessage acts like the conVerter's convertMessage except it calls repS's onMessage() to
		recieve the repeated message, and converts that.
*/
#include "repconVert.h"
#include <iostream>

repconVert::repconVert(unsigned int p, std::string m, unsigned int cap) : repS(p, m, cap), conVerter(m){}

int* repconVert::convertMessage(unsigned int r){
	std::string rep = onMessage(r);
	int x;
	int* numArray = new int[r];
	
	std::string m = removePun(rep);

    if(r >  m.size()){
      r = m.size()%r;
    }
    
	for(int i=0; i<r; i++){
		x = m[i];
		numArray[i] = x;
	}

	return numArray;
}
