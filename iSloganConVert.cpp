/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: iSloganConVert.cpp
VERSION: 1.0

IMPLEMENTATION INVARIANTS: OnMessage(), OffMessage() and isOn() are virtual functions, any
    child classes can change what their On, and Off messages are, and can also change the restrictions
    on their On/Off state for added extensionability. Query(int q) cannot be overriden since all iSlogan 
    type objects must have the same functionality for query. convertMessage() is a virtual function and 
    can be overridden in any child classes. removePun() cannot be overridden since derrived conVerter 
    classes can choose to suppress functionality of removePun() or use it for convertMessage().

*/

#include "iSloganConVert.h"
#include <iostream>

iSloganConVert::iSloganConVert(unsigned int input, std::string m) : iSlogan(input, m), conVerter(m){}



    
