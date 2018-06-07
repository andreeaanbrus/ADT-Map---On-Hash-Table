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
public:


    HashTable(){}
    int h1(TKey &k);
    int getLength(){return lenght;}
    TElement* getElems(){return t;}
    void setLength(int x){this-> lenght = x;}
    void read();
    void add(TElement e);
    TValue search(TElement e);
    TValue remove(TElement k);
    ~HashTable(){}
};


#endif //ADTMAP_HASHTABLE_H
