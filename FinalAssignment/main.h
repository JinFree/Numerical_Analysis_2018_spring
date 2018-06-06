//
// Created by 왕진영 on 2018. 6. 3..
//

#ifndef FINALASSIGNMENT_MAIN_H
#define FINALASSIGNMENT_MAIN_H
#include <cstdio>
#include <cstdlib>
#include <cmath>
#define _USE_MATH_DEFINES
#endif //FINALASSIGNMENT_MAIN_H
class Prob1 {
public:
    void Compute(double _dt, double _t_end);
private:
    double RK4Main(int n, double xi, double *yi, double x_end, double dx);
    double Integrator(double x, double *y, int n, double h, double x_end);
    double RK4(double x, double* y, int n, double h);
    void Derivs(double x, double* y, double *dy);
    char name[50];
    double dx;
    double x_end;
    double g = 9.81;
    double cd;
    double m = 0.4;
};
class Prob2 {
public:
    void Compute(double _dx, double _t_end);
private:
    double RK4Main(int n, double xi, double *yi, double x_end, double dx);
    double Integrator(double x, double *y, int n, double h, double x_end);
    double RK4(double x, double* y, int n, double h);
    void Derivs(double x, double* y, double *dy);
    char name[50];
    double dx;
    double x_end;
    double g = 9.81;
    double l = 0.5;
};
class Prob3 {
public:
    void Compute(double _dx);
private:
    double RK4Main(int n, double xi, double *yi, double x_end, double dx);
    double Integrator(double x, double *y, int n, double h, double x_end);
    double RK4(double x, double* y, int n, double h);
    void Derivs(double x, double* y, double *dy);
    double Analytical(double x);
    double L2(double y_n, double y_a);
    char name[50];
    double dx;
    double x_end;
    double E = 30000.0;
    double I = 800.0;
    double P = 1.0;
    double L = 10.0;
};
class Prob4 {
public:
    void Compute(double _dx, double _t_end);
private:
    double RK4Main(int n, double xi, double *yi, double x_end, double dx);
    double Integrator(double x, double *y, int n, double h, double x_end);
    double RK4(double x, double* y, int n, double h);
    void Derivs(double x, double* y, double *dy);
    double Area(double x);
    void IndexInit();
    char name[50];
    double dx;
    double x_end;
    double d = 0.25;
    double e = 1.0;
    double g = 9.81;
    double A[7];
    double H[7];
};