#pragma once
#include "Car.h"
class Truck :
    public Car
{
private:
    int axles;
    double tons;
public:
    Truck(int a, double t, int n, const string& hs);

    ~Truck();

    void setAxles(int l) { axles = l; }
    int getAxles() const { return axles; }
    void setCapacity(double t) { tons = t; }
    double getCapacity() const { return tons; }
    void display() const;




};

