//
// Created by 왕진영 on 2018. 4. 3..
//

#ifndef HW3_2_6_16_MAIN_H
#define HW3_2_6_16_MAIN_H
#include <cstdio>
#include <cmath>
#endif //HW3_2_6_16_MAIN_H
class hw2{
public:
    void NewtonRaphson();
private:
    const double x0 = 3.2;
    const int MinIter = 4;
    double xold, xnew;
    double fx(double _x);
    double fpx(double _x);
};