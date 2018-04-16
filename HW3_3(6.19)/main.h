//
// Created by 왕진영 on 2018. 4. 3..
//

#ifndef HW3_3_6_19_MAIN_H
#define HW3_3_6_19_MAIN_H
#include <cstdio>
#include <cmath>
#endif //HW3_3_6_19_MAIN_H
class hw3{
public:
    void NewtonRaphson();
private:
    const double R = 3;
    const double x0 = 3;
    const int MinIter = 3;
    const double pi = M_PI;
    double xold, xnew;
    double fx(double _x);
    double fpx(double _x);
    double error();
};
