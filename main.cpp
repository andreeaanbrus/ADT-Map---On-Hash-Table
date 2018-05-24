#include <iostream>
#include <fstream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Tests.h"
#include "HashTable.h"
#include "Map.h"

void read(Map& m);

void printMenu();
void printMap(const Map&m);
void addCar(Map &m);
void findCar(Map &m);
int main(int argc, char*argv[]) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
//    Map m;
//    read(m);
//    int cmd = -1;
//    while(cmd != 0) {
//        printMenu();
//        std::cin >> cmd;
//        if(cmd == 1){
//            printMap(m);
//        }
//        if(cmd == 2){
//            addCar(m);
//        }
//        if(cmd == 3) {
//            findCar(m);
//        }
//    }
//    std::cout << "Hello, World!" << std::endl;
//    return 0;
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

}
void printMenu(){
    std::cout << "0 -> Exit\n";
    std::cout << "1 -> Print the map\n";
    std::cout << "2 -> Add a new car to the parking lot\n";
    std::cout << "3 -> Find where you left your car\n";
}

void printMap(const Map &m){
    Iterator i{m};
    while(i.valid()){
        std::cout << i.getCurrent().getLicence() << '\n';
        i.next();
    }
}

void addCar(Map &m){
    std::string licence;
    int value;
    std::cout << "Give the licence number(ex: BN04DFL): ";
    std::cin >> licence;
    std::cout << "Give the area where you parked(schimba sa se genereze automat): ";
    std::cin >> value;
    m.add(licence, value);
    std::cout << "Aici se face add\n";
}

void findCar(Map &m){
    std::string licence;
    std::cout << "Give the licence number";
    std::cin >> licence;
    int p = m.search(licence, 0);
    std::cout << p << '\n';
    std::cout << "Schimba search -> pune doar licence\n";
//    m.remove(licence);
}
