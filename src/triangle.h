//
// Created by Omar Shaikh on 2/23/16.
//

#ifndef HW3_TRIANGLE_H
#define HW3_TRIANGLE_H
/** Header file for the class Triangle. */

#include <vector>
#include <cmath>
#include <iostream>
#include "triangle_interface.h"


using namespace std;

template<class T>
class Triangle : public triangleInterface<T> {
private:
    vector<T> side = {0, 0, 0};

public:
    Triangle();

    Triangle(T, T, T);

    virtual void setSides(T newSide1, T newSide2, T newSide3);

    virtual vector<T> getSides() const;

    virtual T getArea() const;

    virtual T getPerimeter() const;

    virtual bool isRightTriangle() const;

    virtual bool isEquilateral() const;

    virtual bool isIsosceles() const;

};

template<class T>
Triangle<T>::Triangle() {

}

template<class T>
Triangle<T>::Triangle(T side1, T side2, T side3){
        Triangle<T>::setSides(side1, side2, side3);
    }

template<class T>
void Triangle<T>::setSides(T newSide1, T newSide2, T newSide3) {
    side[0] = newSide1;
    side[1] = newSide2;
    side[2] = newSide3;
}

template<class T>
std::vector<T> Triangle<T>::getSides() const {
    return side;
}

template<class T>
T Triangle<T>::getArea() const {
    double p = Triangle<T>::getPerimeter() / 2.0;
    T area = sqrt(p*(p-side[0])*(p-side[1])*(p-side[2]));
    return area;
}

template<class T>
T Triangle<T>::getPerimeter() const {
    T perimeter = side[0]+side[1]+side[2];
    return perimeter;
}

template<class T>
bool Triangle<T>::isRightTriangle() const {
    if(side[0]*side[0] == (side[1]*side[1]) + (side[2]*side[2]))
        return true;
    if(side[1]*side[1] == (side[0]*side[0]) + (side[2]*side[2]))
        return true;
    if(side[2]*side[2] == (side[0]*side[0]) + (side[1]*side[1]))
        return true;
    else
        return false;
}

template<class T>
bool Triangle<T>::isEquilateral() const {
    if(side[0] == side[1] && side[0] == side[2])
        return true;
    else
        return false;
}

template<class T>
bool Triangle<T>::isIsosceles() const {
    if(side[0] == side[1] || side[0] == side[2] || side[1] == side[2])
        return true;
    else
        return false;
}

#endif //HW3_TRIANGLE_H
