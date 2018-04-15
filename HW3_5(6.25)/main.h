//
// Created by 왕진영 on 2018. 4. 3..
//

#ifndef HW3_5_6_25_MAIN_H
#define HW3_5_6_25_MAIN_H
#include <cstdio>
#include <cmath>
#endif //HW3_5_6_25_MAIN_H
class hw5{
public:
    void ModifiedSecantMethod(double initial);
private:
    double c, cnew;
    const int MinIter = 3;
    const double delta = 0.5;
    double fx(double _x);
    double fpx(double _x);
    double error();
};