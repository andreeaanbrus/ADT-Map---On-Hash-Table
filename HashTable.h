//
// Created by andreea on 18.05.2018.
//

#ifndef ADTMAP_HASHTABLE_H
#define ADTMAP_HASHTABLE_H

#include <string>
#include "Car.h"

typedef Car TElement;
typedef int TValue;
typedef std::string TKey;


class HashTable {
private:
    TElement t[200];
    int lenght;
    int hash(TKey k, int i);
    int h1(TKey &k);


public:
    HashTable(){}
    int getLength(){return lenght;}
    void add(TElement e);
    TElement* getElems(){return t;}
    void read();
    void setLength(int x){this-> lenght = x;}
    TValue search(TElement e);
    TValue remove(TElement k);
    ~HashTable(){}
};


#endif //ADTMAP_HASHTABLE_H
