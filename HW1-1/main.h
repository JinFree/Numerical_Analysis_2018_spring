//
// Created by 왕진영 on 2018. 3. 15..
//

#ifndef HW1_MAIN_H
#define HW1_MAIN_H
#include <cstdio>
#include <cmath>

#endif //HW1_MAIN_H
class Euler{
public:
    Euler(){};
    void ComputeEuler(double _dt);
    void ComputeEuler();
    void printexact();
private:
    FILE *file;
    const double T0=70;
    const double Ta=20;
    const double k=0.019;
    const double t0=0;
    const double tmax=10;
    double dt;
    double Tnew, T,time;
    void setup();
    void function();
    void timemarch();
    void paraopen();
    void parawrite();
    void paraclose();
    void printstat();
};