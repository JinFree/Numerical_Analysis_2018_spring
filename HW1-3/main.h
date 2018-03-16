//
// Created by 왕진영 on 2018. 3. 16..
//

#ifndef HW1_3_MAIN_H
#define HW1_3_MAIN_H

#endif //HW1_3_MAIN_H
#include <cstdio>
#include <cmath>
class HW1_3{
private:
    const double H1 = 10;
    const double H2 = 5;
    const double r1 = 4;
    const double r2 = 6.5;
    const double phi = M_PI;
    double h, V;
    void ComputeSeries(void);
    void computeVolume(void);
public:
    HW1_3(){}
    void computeVolume(double _h);
};