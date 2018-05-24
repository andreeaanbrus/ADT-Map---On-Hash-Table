//
// Created by andreea on 18.05.2018.
//

#ifndef ADTMAP_MAP_H
#define ADTMAP_MAP_H

#include "Car.h"
#include "HashTable.h"

typedef Car TElement;
typedef int TValue;
typedef std::string TKey;

class Map {
private:
    HashTable t;
public:
    Map(){};
    void add(std::string& key, int& value);
    TValue remove(TKey key);
    void setLength(int x){t.setLength(x);}
    TValue search(TKey k, TValue v);
    int size() {return t.getLength();};
    HashTable getTable(){return t;}
    ~Map(){}
};


class Iterator {
private:
    Map m;
    int current;
public:
    Iterator(const Map& m) : m{m}, current{0} {}
    TElement getCurrent() { return m.getTable().getElems()[current];};
    void next();
    bool valid();
    ~Iterator(){}
};
#endif //ADTMAP_MAP_H
