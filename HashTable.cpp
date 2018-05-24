//
// Created by andreea on 18.05.2018.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "HashTable.h"

int HashTable::h1(TKey &k) {
    std::string s[41] = {"AB","AR","AG","BC","BH","BN","BT","BV","BR","BZ", "CS","CL","CJ","CT","CV","DB","DJ","GL","GR","GJ","HR","HD","IL","IS", "IF","MM","MH","MS","NT","OT","PH","SM","SJ", "SB","SV", "TR","TM", "TL","VS", "VL" ,"VN"};
    int judet = 0, number;
    bool found = false;
    for(int i = 0; i < 41 && !found; i++)
        if(k[0] == s[i][0] && k[1] == s[i][1])
            judet = i, found = true;
    int sum = 0;
    sum += judet * 26 * 26 * 26 * 100;
    char nr[2];
    nr[0] = k[2];
    nr[1] = k[3];
    number = std::stoi(nr);
    sum += number * 26 * 26 * 26;
    sum += (k[4] - 'A')* 26 * 26 + (k[5] - 'A') * 26 + (k[6] - 'A');
    return sum;
}

int HashTable::hash(TKey k, int i) {
    /*
     * pre: the given key, the first try - i strats from 0
     * Linear probing hash function
     * h(k, i) = (h'(k) % m + i) % m
     * post: the free position in the hash table where the new key can be put
     * exception if the hashtable is full
     * */

    int sum = h1(k);
    while(!t[(sum % lenght + i) % lenght].isEmpty())
        i++;
    int pos =( sum%lenght + i) % lenght;
    return pos;

}

void HashTable::add(TElement e) {
    /*
     * Adds a new element in the hashtable
     * */
    int pos = hash(e.getLicence(), 0);
    t[pos] = e;
}

TValue HashTable::search(TElement e) {
    /*
     * searches in the hashtable the element e (by the key)
     * returns the position of e
     * raise exception if e is not found
     * */
    int i = 0;
    TKey k = e.getLicence();
    int pos = h1(k) % lenght;
    while(t[pos].getLicence() != e.getLicence()){
        i++;
        pos = (h1(k) % lenght + i)%lenght;
        if(i > lenght)
            return false;
    }
    return pos;
}

TValue HashTable::remove(TElement e) {
    /*
     * removes a certain element and returns the value of the removed elem
     * search function raises exception if the element is not in the map
     * */
    int pos = search(e);
    TElement delem("DELETED", -1);
    t[pos] = delem;
    return e.getArea();
}