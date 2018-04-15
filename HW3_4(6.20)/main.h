//
// Created by 왕진영 on 2018. 4. 3..
//

#ifndef HW3_4_6_20_MAIN_H
#define HW3_4_6_20_MAIN_H
#include <cstdio>
#include <cmath>
#include <cstdlib>
#endif //HW3_4_6_20_MAIN_H
class hw4{
public:
    void SecantMethod(double initial);
    void fpx(double _x);
private:
    double H, Hnew, Hold;
    const double Q = 5;
    const double S = 0.0002;
    const double B = 20;
    const double n = 0.03;
    double fx(double _x);
    double error();
};