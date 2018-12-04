/*
Copyrite (c) 2018
AUTHOR: Lina Chung
FILENAME: tester.cpp
VERSION: 1.0

DESCRIPTION: Driver for testing all basic functionality, substitutability and edge cases.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "iSlogan.h"
#include "garbledS.h"
#include "repS.h"
#include "conVerter.h"
#include "iSloganConVert.h"
#include "garbledconVert.h"
#include "repconVert.h"
using namespace std;

/*
Description: function returns a random string to be used for various objects.
*/

std::string getString(){
  std::string str[] = {"Hi my name is Lina",
                                "I am a student at Seattle University",
                                "I am from Hawaii", 
                                "I speak Japanese", 
                                "I like to read", 
                                "I like whales", 
                                "I like food", 
                                "How are you?",
                                "It is cold today",
                                "I love chocolate"};
  int rnd = rand() % 9;
  return str[rnd];
};

/* 
Description: returns a pointer to an array of iSlogan objects.
*/

iSlogan* iSlog_array(unsigned int numObj){
  iSlogan* iSlog = new iSlogan[numObj];

  for(int i=0; i<numObj; i++){
    int pVal = rand() % 9 + 1;
    iSlogan s = iSlogan(pVal, getString());
    iSlog[i] = s;
  }
  return iSlog;
};

/* 
Description: returns a pointer to an array of garbledS objects.
*/

garbledS* garb_array(unsigned int numObj){
  garbledS* garb = new garbledS[numObj];

  for(int i=0; i<numObj; i++){
    int pVal = rand() % 9 + 1;
    garbledS g = garbledS(pVal, getString());
    garb[i] = g;
  }
  return garb;
}

/* 
Description: returns a pointer to an array of repS objects.
*/

repS* rep_array(unsigned int numObj){
  repS*  rep = new repS[numObj];

  for(int i=0; i<numObj; i++){
    int pVal = rand() % 9 + 1;
    int cap = rand() % 9 + 1;
    repS r = repS(pVal, getString(), cap);
    rep[i] = r;
  }
  return rep;
}

/* 
Description: returns a pointer to an array of converter objects.
*/

conVerter* cv_array(unsigned int numObj){
  conVerter* cv = new conVerter[numObj];
  
  for(int i=0; i<numObj; i++){
    conVerter c = conVerter(getString());
    cv[i] = c;
  }
  return cv;
}

/* 
Description: returns a pointer to an array of iSloganconVerter objects.
*/

iSloganConVert* iSlogCV_array(unsigned int numObj){
  iSloganConVert* iSlogCV = new iSloganConVert[numObj];

  for(int i=0; i<numObj; i++){
    int pVal = rand() % 9 + 1;
    iSloganConVert s = iSloganConVert(pVal, getString());
    iSlogCV[i] = s;
  }
  return iSlogCV;
}

/* 
Description: returns a pointer to an array of garbledconVerter objects.
*/

garbledconVert* garbCV_array(unsigned int numObj){
  garbledconVert* garbCV = new garbledconVert[numObj];

  for(int i=0; i<numObj; i++){
    int pVal = rand() % 9 + 1;
    garbledconVert g = garbledconVert(pVal, getString());
    garbCV[i] = g;
  }
  return garbCV;
}

/* 
Description: returns a pointer to an array of repconVerter objects.
*/

repconVert* repCV_array(unsigned int numObj){
  repconVert* repCV = new repconVert[numObj];

  for(int i=0; i<numObj; i++){
    int pVal = rand() % 9 + 1;
    int cap = rand() % 9 + 1;
    repconVert r = repconVert(pVal, getString(), cap);
    repCV[i] = r;
  }
  return repCV;

}

/*
Description: function takes in 3 arrays and an int value to test the functionality of each iSlogan object
               and then deallocates the memory of each pointer.
*/

void test_iSlogan(iSlogan* s, garbledS* g, repS* r, unsigned int num){
  int rnd = rand()%9;
  cout<<"Testing iSlogan..."<<endl;
  for(int i =0; i<num; i++){
    for(int j=0; j<rnd;j++){
      cout<<"   ";
      cout<<s[i].query(j)<<endl;
    }
  }
  cout<<endl;

  cout<<"Testing garbledS..."<<endl;
  for(int i =0; i<num; i++){
    for(int j=0; j<rnd;j++){
      cout<<"   ";
      cout<<g[i].query(j)<<endl;
    }
  }
  
 cout<<"Testing repS..."<<endl;
  for(int i =0; i<num; i++){
    for(int j=0; j<rnd;j++){
      cout<<"   ";
      cout<<r[i].query(j)<<endl;
    }
  }

  delete[] s;
  s = NULL;
  delete[] g;
  g = NULL;
  delete[] r;
  r = NULL;

}

/*
Description: function takes in 3 arrays and an int value to test the functionality of each converter object
               and then deallocates the memory of each pointer. Prints out each converted message array of 
               a random object in each converter array and then deallocates it. 
*/

void test_converter(conVerter* cv, iSloganConVert* scv, garbledconVert* gcv, repconVert* rcv, unsigned int num){
  int rnd = rand()%9;
  int index = rand()%num;

  int* s = scv[index].convertMessage(rnd);
  int* g = gcv[index].convertMessage(rnd);
  int* r = rcv[index].convertMessage(rnd);
  int* c = cv[index].convertMessage(rnd);

  cout<<"Testing Converter convertMessage..."<<endl;
  for(int i=0; i<rnd; i++){
    cout<<c[i];
    cout<<", ";
  }
  cout<<endl;
  cout<<endl;
  delete[] c;
  c = NULL;
  delete[] cv;
  cv = NULL;

  cout<<"Testing iSlogConverter convertMessage..."<<endl;
  for(int i=0; i<rnd; i++){
    cout<<s[i];
    cout<<", ";
  }
  cout<<endl;
  cout<<endl;
  delete[] s;
  s = NULL;
  delete[] scv;
  scv = NULL;

  cout<<"Testing garbConverter convertMessage..."<<endl;
  for(int i=0; i<rnd; i++){
    cout<<g[i];
    cout<<", ";
  }
  cout<<endl;
  cout<<endl;
  delete[] g;
  g = NULL;
  delete[] gcv;
  gcv = NULL;

  cout<<"Testing repConverter convertMessage..."<<endl;
  for(int i=0; i<rnd; i++){
    cout<<r[i];
    cout<<", ";
  }
  cout<<endl;
  cout<<endl;
  delete[] r;
  r = NULL;
  delete[] rcv; 
  rcv = NULL;
}

/*
Description: function creates an array of all the objects, and tests each one of their functionalities
               by calling their corresponding functions.
*/

void test_basic(unsigned int numObj){
  iSlogan* iSlog = iSlog_array(numObj);
  garbledS* garb = garb_array(numObj);
  repS* rep = rep_array(numObj);
  conVerter* cv = cv_array(numObj);
  iSloganConVert* iSlogCV = iSlogCV_array(numObj);
  garbledconVert* garbCV = garbCV_array(numObj);
  repconVert* repCV = repCV_array(numObj);

  test_iSlogan(iSlog, garb, rep, numObj);
  test_converter(cv, iSlogCV, garbCV, repCV, numObj);
}

/*
Description: creates a heterogeneous array of iSlogan converter types by using
               an iSlogan pointer, tests them,and then deallocates the memory.
*/

void iSlog_collection(unsigned int num){
  const int x = 2;
  const int y = 3;
  int pVal = rand()%9 + 1;
  int cap = rand()%9 + 1;
  iSlogan** iSlog = new iSlogan*[num];
  
  for(int i=0; i<num; i++){
    if(i%x == 0){
      iSlog[i] = new garbledconVert(pVal, getString());
    }
    else if(i%y == 0){
      iSlog[i] = new repconVert(pVal, getString(), cap);
    }else{
      iSlog[i] = new iSloganConVert(pVal, getString());
    }
  }
  cout<<"Testing heterogeneous collection for iSlog/iSlogCV..."<<endl;
  for(int i=0; i<num; i++){
    cout<<iSlog[i]->query(i)<<endl;
  }
  for(int i=0; i<num; i++){
    delete iSlog[i];
    iSlog[i] = NULL;
  }
  delete[] iSlog;
}

/*
Description: creates a heterogeneous array of iSlogan converter types by using
                an conVerter pointer, tests them, and then deallocates the memory.
*/

void convert_collection(unsigned int num){
  const int x = 2;
  const int y = 3;
  int pVal = rand()%9+1;
  int cap = rand()%9+1;
  conVerter** convert = new conVerter*[num];

  for(int i=0; i<num; i++){
    if(i%x == 0){
      convert[i] = new garbledconVert(pVal, getString());
    }
    else if(i%y == 0){
      convert[i] = new repconVert(pVal, getString(), cap);
    }else{
      convert[i] = new iSloganConVert(pVal, getString());
    }
  }

  cout<<"Testing heterogeneous collection for conVerter/iSlogCV..."<<endl;
  int rnd = rand()%9;
  int* numArray = convert[0]->convertMessage(rnd);
  for(int i=1; i<num; i++){
    int* a = convert[i]->convertMessage(i);
    delete[] a;
    a = NULL;
  }
  cout<<endl;
  cout<<"   Printing out the first object's converted message array..."<<endl;
  cout<<"     nums:";
  for(int i=0; i<rnd; i++){
    cout<<numArray[i];
    cout<<", ";
  }
  cout<<endl;
  delete[] numArray;
  delete[] convert;
}

/*
Description: function tests the heterogeneous collections of iSlogan/iSlogConverter types
                and converter/iSlogconverter types.
*/

void test_collection(unsigned int numObj){
  iSlog_collection(numObj);
  cout<<endl;
  convert_collection(numObj);
}

int main(){
  const int numObj = 5;
  test_basic(numObj);
  test_collection(numObj);
}

