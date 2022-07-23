#include "CShape.h"

CShape::CShape() {
    width = 0;
    height = 0;

    name = "NoName1";
}

void CShape::setHeight(int h) {
    height = h;
}

void CShape::setWidth(int w) {
    width = w;
}

void CShape::printName() {
    cout << "MyShapeName: " << name << endl;
}