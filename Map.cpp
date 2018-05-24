//
// Created by andreea on 18.05.2018.
//

#include "Map.h"

void Map::add(std::string &key, int &value) {
    TElement elem(key, value);

    t.add(elem);
}

TValue Map::remove(TKey key) {
    TElement elem(key, 0);
    t.remove(elem);
    return 0;
}

TValue Map::search(TKey k, TValue v) {
    TElement elem(k, v);
    t.search(elem);
}

bool Iterator::valid() {
    return current <= m.getTable().getLength();
}

void Iterator::next() {

    current ++;
    while(m.getTable().getElems()[current].isEmpty())
        current++;
}
