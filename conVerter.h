/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: conVerter.h
VERSION: 1.0

DESCRIPTION: conVerter class takes in a string as a parameter, converts its' first r vaules into its' ASCII
        number equivalence and returns it to the user as an array. The string message passed in cannot 
        be changed once set in the constructor, but when converted, all punctuation will be removed. 

ASSUMPTIONS: string msg is a value with at least 10 characters, and once set, cannot be changed. The string itself
        is not altered. r value that is passed into convertMessage must be a postivie int value less than
        10. There is no notion of state. Dynamic memory is used in convertMessage and ownership is 
        transferred to the user, making user responsible for deallocating the memory. 

CLASS INVARIANTS: conVerter can take in 0 or 1 parameters, the only parameter passed in is a string value
        whose char length is at least 10. If no parameters are passed in, there is a default
        message set. convertMessage checks to make sure the pos int r value is less than the string
        size with punctuation removed. If r value is greater than the string length, r is changed
        to the string length % r. 

INTERFACE INVARIANTS: When converting a message, the value passed in must be a postivie int vaue less than 10.
        convertMessage creates a dynamically allocated array within the function and transfers
        the ownership to the user. It is the user's responsibility for proper deallocation of 
        array. The array passed back is an array of integers corresponding to the first r-value
        characters of the string. 
*/

#include <iostream>
#pragma once

class conVerter{
    protected:
       std::string msg;

       /*
        Description:    removePun takes in a string m, removes the punctuation and returns it
                        if the string is solely punctuation, it will return an empty string.

        Pre:            string m has a char length greater than 9
        Post:           returns same string message but with punctuation removed.
        */

       std::string removePun(std::string m);

    public:

        /*
        Description:    converter has a default and 1 param ctor, that takes in a string value.
                        if no parameter is passed in, the string message is preset.

        Post:           msg data member set to the passed in parameter.
        */

        conVerter(std::string s = "default message");

        /*
        Description:    convertMessage takes in an unsigned int r value greater than 9, 
                        will take the first r characters in message and returns/
                        creates an integer array of each characters' corresponding ASCII value.
                        integer array is not a data member, is created within the function and
                        transfers ownership of the integer array to user. It is the user's job
                        to deallocate the memory properly.

        Post:           dynamically allocated integer array is returned.  
        */
       
        virtual int* convertMessage(unsigned int r);
};
