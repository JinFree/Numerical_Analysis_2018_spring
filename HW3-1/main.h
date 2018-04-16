//
// Created by 왕진영 on 2018. 4. 3..
//

#ifndef HW3_1_MAIN_H
#define HW3_1_MAIN_H
#include <cstdio>
#include <cmath>
#include <cstdlib>
#endif //HW3_1_MAIN_H
class hw1{
public:
    hw1(){
        iter = 0;
        _x = 5;_y = 5; _z = 5;
        _f=0; _g=0; _h=0;
        GetResult();}
    void Solve();
private:
    double f(double x, double y, double z);
    double g(double x, double y, double z);
    double h(double x, double y, double z);
    double dfdx(double x, double y, double z);
    double dfdy(double x, double y, double z);
    double dfdz(double x, double y, double z);
    double dgdx(double x, double y, double z);
    double dgdy(double x, double y, double z);
    double dgdz(double x, double y, double z);
    double dhdx(double x, double y, double z);
    double dhdy(double x, double y, double z);
    double dhdz(double x, double y, double z);
    double Det(double *M);
    void SolveX(double x,double y,double z);
    void ForwardStep();
    void GetResult();
    double ErrorCheck();
    void OpenFile();
    void WriteFile();
    void CloseFile();
    double * X = (double *)calloc(sizeof(double),3);
    double * B = (double *)calloc(sizeof(double),3);
    double * Jacobian = (double *)calloc(sizeof(double),9);
    double * Jx = (double *)calloc(sizeof(double),9);
    double * Jy = (double *)calloc(sizeof(double),9);
    double * Jz = (double *)calloc(sizeof(double),9);
    int iter;
    double _f, _g, _h, _x, _y, _z;
    FILE *file;
};