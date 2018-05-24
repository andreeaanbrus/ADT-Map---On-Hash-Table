#include <iostream>
#include <fstream>
#include "HashTable.h"
#include "Map.h"

void read(Map& m);
typedef int TValue;

void printMenu();
void printMap(const Map&m);
void addCar(const std::string& s);
int main() {
    Map m;
    read(m);
    int cmd = -1;
    while(cmd != 0) {
        printMenu();
        std::cin >> cmd;
        if(cmd == 1){
            printMap(m);
        }
        if(cmd == 2){
            std::string s;
            std::cout << "Give your licence plate\n";
            std::cin >> s;
            addCar(s);
        }
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

void read(Map& m){
    std::ifstream fin("cars.txt");
    int ncars, maxcap;
    std::string cars[10];
    TValue val;
    fin >> ncars;
    fin >> maxcap;
    m.setLength(maxcap);
    for(int i = 0; i < ncars; i++) {
        fin >> cars[i];
        fin >> val;
        m.add(cars[i], val);
    }

    m.search("BN96VAD", 2);
    m.remove("BN03LXF");
}
void printMenu(){
    std::cout << "0 -> Exit\n";
    std::cout << "1 -> Print the map\n";
    std::cout << "2 -> Add a new car to the parking lot\n";
}

void printMap(const Map &m){
    Iterator i{m};
    while(i.valid()){
        std::cout << i.getCurrent().getLicence() << '\n';
        i.next();
    }
}

void addCar(const std::string &s){
    std::cout << "Aici se face add\n";
}