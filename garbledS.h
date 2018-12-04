/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: garbledS.h
VERSION: 1.1

DESCRIPTION: garbledS is the child class of iSlogan, and is closely tied to the parent class (iSlogan).
    object uses their parent's data members: on, count, message, and p. garbledS only overrides
    iSlogan's onMessage(int q). When off, garbledS acts like an iSlogan object when it is off,
    otherwise, when on, garbledS switches the pth and qth index of its' message, and mixes
    cases randomly. garbledS inherits its' message and p value from the parent class, and calls 
    iSlogan's isOn() function to toggle states, thus garbledS uses its' parents' on and count data members. 

ASSUMPTIONS: It is assumed that iSlogan is initalized to an ON state (on == true),
    once set, the message is not changed. It is also assumed that q is a single digit
    integer value where 0 < q < 10 and userpassed in int p is a pos int greater than 0
    and that the set message is >= 10 characters.

CLASS INVARIANTS: garbledS constructor takes 0, 1, or 2 parameters. It inherits its' parents'
    message, or can have it's own message passed in, garbledS' p value is the same
    as parents. garbledS does not have its' own on or count data member. Instead,
    it uses its' parents' isOn() function which toggles on/off and increments count.

INTERFACE INVARIANTS: When quering, the value passed in must also be a positive
    integer value between 0 and 9. On/Off states will toggle every pth request.
 */

#pragma once
#include <iostream>
#include "iSlogan.h"

class garbledS: public iSlogan{
public:
    
    /*
        Description:    garbledS constructor takes in 0, 1, or 2 parameters. User can set
                        their own p value, or string value, otherwise garbledS uses its' 
                        default p value and message. garbledS uses its' parents data members
                        on, and count. garbledS only added data member is a random number generator.

        Post:           message is set to m, p value is set to passed unsigned int p value
    */

    garbledS(unsigned int p=1, std::string m="default message");
  
protected:

    /*
        Description:    onMessage accepts a pos int q value between 0 and 9, and switches its'
                        qth and pth characters, and mixes case randomly in the string. Similarly to
                        iSlogan, if p == q, object will act like an iSlogan object. 

        Pre:            on == true
        Post:           changed message is returned
    */

    std::string onMessage(unsigned int q);

};
