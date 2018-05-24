//
// Created by andreea on 18.05.2018.
//

#include <csignal>
#include "Map.h"

void Map::add(std::string &key, int &value) {
    TElement elem(key, value);
    int pos = t.search(elem);
    if(pos != -1)
        throw "The car is already in the parking lot";
    t.add(elem);
}

TValue Map::remove(TKey key) {
    TElement elem(key, 0);
    int pos = t.search(elem);
    int value = t.getElems()[pos].getArea();
    t.remove(elem);
    return value;
}

TValue Map::search(TKey k, TValue v) {
    TElement elem(k, v);
    int pos = t.search(elem);
    if(pos == -1)
        throw "Element not found";
    return t.getElems()[pos].getArea();
}

bool Iterator::valid() {
    return current <= m.getTable().getLength();
}

void Iterator::next() {

    current ++;
    while(m.getTable().getElems()[current].isEmpty())
        current++;
}
