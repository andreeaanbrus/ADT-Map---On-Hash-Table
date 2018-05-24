//
// Created by andreea on 18.05.2018.
//

#ifndef ADTMAP_CAR_H
#define ADTMAP_CAR_H


#include <string>

class Car {
private:
    std::string licence;
    int area;
public:
    Car(){}
    Car(const std::string& s, const int& x): licence{s}, area{x} {}
    std::string getLicence(){return licence;}
    int getArea(){return area;}
    bool isEmpty();
    bool operator==(Car&other);
    bool operator!=(Car&other);
    ~Car(){}
};


#endif //ADTMAP_CAR_H
