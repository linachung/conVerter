/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: repS.h
VERSION: 1.1

DESCRIPTION: repS is a child class of iSlogan, but only uses its' parents p value, and message.
    repS overrides both iSlogan's isOn() function and onMessage(int q) function. When
    off, object acts like an iSlogan object, but has an internal capacity.
    Like iSlogan, repS's state is toggled on/off every pth request however, once its' capacity
    has been reached, state is set to off and cannot be turned back on, repS
    also behaves like an iSlogan when it is off, and will not output any message if off.
    When on, repS takes the message and repeats pth character q times at the qth character.

ASSUMPTIONS: It is assumed that iSlogan is initalized to an ON state (on == true),
    once set, the message is not changed. It is also assumed that q is a single digit
    integer value where 0 < q < 10 and userpassed in int p is a pos int greater than 0
    and that the set message is >= 10 characters.  int cap must be a pos int value greater than
    0.

CLASS INVARIANTS: repS constructor takes 0, 1, 2, or 3 parameters. It inherits its' parents p value,
    and message but has its' own data member on, and count as well as a new data member, cap which
    denotes how often the object can be turned on or off. After the cap has been reached, object
    is permanently set to off and cannot be changed. User can also set their own message, different
    from the parent, but once the message is set, it cannot be changed.

INTERFACE INVARIANTS: When quering, the value passed in must also be a positive
    integer value between 0 and 9. On/Off states will toggle every pth request.
 */

#pragma once
#include <iostream>
#include "iSlogan.h"

class repS : public iSlogan{
    private:
        unsigned int cap;

    public:

        /*
        DESCRIPTION: repS constructor takes 0,1,2 or 3 arguments. The first and second argument
                       must be a pos int value greater than 0, the third argument must be a string, 
                       if the user does not pass in any or one of the parameters, the default value
                       is used. 

         Postcondition: All data members are set to their passed in value, or default value
        */

        repS(unsigned int input=1, std::string message = "Default message", unsigned int c=2);
        
    protected:
        
        /*
        DESCRIPTION: onMessage accepts a pos int q value between 0 and 9, and selects the qth
                       character in the message, and replaces it with the pth character and repeats
                       it q times. If p == q, then the object acts like an iSlogan object and returns
                       an empty string. 
                       
         Precondition: on == true
         Postcondition: changed message is returned
        */

        std::string onMessage(unsigned int q);

       /*
        DESCRIPTION: isOn() takes in no arguments, if data member count is a multiple of p
                     then it's "on" state is toggeled. Otherwise, the state is left as is.
                     Returns true or false based on if the object is on or off. If the number
                     of times toggled reaches capacity size, state is permentantely set to off
                     and cannot change. 
                     
        Precondition: p is a unsigned int value > 0
        Postcondition: count is incremented by one, on may be toggled to true or false, or
                       state may be permenanently set to off. 
        */

        bool isOn();

};
