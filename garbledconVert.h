/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: garbledconVert.h
VERSION: 1.0

DESCRIPTION: garbledconVerter is the child of both garbledS and conVerter class. Since garbledS
		is the child class of iSlogan, and is closely tied to the parent class (iSlogan),
		garbledconVerter is also closely tied to iSlogan. object uses their parent's data members: on, count, 
		and p. garbledS only overrides iSlogan's onMessage(int q). When off, garbledS acts like an iSlogan 
		object when it is off, otherwise, when on, garbledS switches the pth and qth index of its' message,
		and mixes cases randomly. p, on, and count value from the parent class, and calls iSlogan's isOn() 
		function to toggle states, thus garbledS uses its' parents' on and count data members.
		garbledconVerter has conVerter class functionality and converts its' first r vaules into its'
		ASCII number equivalence and returns it to the user as an array. The string message passed in
		cannot be changed once set in the constructor, but when converted, all punctuation will be removed. 

ASSUMPTIONS:  It is assumed that object is initalized to an ON state (on == true),
    	that q is a single digit integer value where 0 < q < 10 and userpassed in int p is a pos int greater
		than 0 and that the set message is >= 10 characters and once set, cannot be changed. r value that 
		is passed into convertMessage must be a postivie int value less than 10. Dynamic memory is used in 
		convertMessage and ownership is transferred to the user, making user responsible for deallocating
		the memory. 

CLASS INVARIANTS: object constructor takes 0, 1, or 2 parameters. It inherits its' parents'
    	message, or can have it's own message passed in, garbledS' p value is the same
    	as parents. object does not have its' own on or count data member. Instead,
    	it uses its' parents' isOn() function which toggles on/off and increments count. 

INTERFACE INVARIANTS: When quering, the value passed in must also be a positive
    	integer value between 0 and 9. On/Off states will toggle every pth request. When converting a message,
	 	the value passed in must be a postivie int vaue less than 10. convertMessage creates a dynamically
		allocated array within the function and transfers the ownership to the user. It is the user's
		responsibility for proper deallocation of array. The array passed back is an array of integers 
		corresponding to the first r-value characters of the garbled string.
*/

#pragma once
#include <iostream>
#include "conVerter.h"
#include "garbledS.h"

class garbledconVert : public garbledS, public conVerter{
public:

    /*
	Description: 	garbledconVert takes in 0, 1 or 2 params. The first parameter is an unsigned int val
                 	corresponding to garbledS's p value. The second parameter is string message whose length
                 	is at least 10 characters. garbledConVert calls its' parents' constructors and passes in
                 	the corresponding data members. 

    Post: 			garbledS and conVerter ctors are called and utilized
  	*/

	garbledconVert(unsigned int input=1, std::string m = "default message");

    /*
	Description: 	convertMessage takes in an unsigned int r value greater than 9, 
				   	call garbledS's onMessage() and  will take the first r characters in 
				   	garbled message and returns/creates an integer array of each characters'
				   	corresponding ASCII value. integer array is not a data member, is created 
				   	within the function and transfers ownership of the integer array to user.
					It is the user's job to deallocate 

    Post: 			dynamically allocated integer array is returned.  
    */
   
	int* convertMessage(unsigned int r);
};
  
