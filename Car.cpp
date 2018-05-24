//
// Created by andreea on 18.05.2018.
//

#include "Car.h"

bool Car::isEmpty() {
    if((this -> area == 0 && this ->licence == "") || (this -> area == -1 && this->licence == "DELETED"))
        return true;
    return false;
}
