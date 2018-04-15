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
private:
    double f1(x, y, z);
    double f2(x, y, z);
    double f3(x, y, z);
    double df1dx(x, y, z);
    double df1dy(x, y, z);
    double df1dz(x, y, z);
    double df2dx(x, y, z);
    double df2dy(x, y, z);
    double df2dz(x, y, z);
    double df3dx(x, y, z);
    double df3dy(x, y, z);
    double df3dz(x, y, z);
    void BuildMat(x,y,z);

    double * Jacobian = (double *)malloc(sizeof(double)*9);
    double * Jx = (double *)malloc(sizeof(double)*9);
    double * Jy = (double *)malloc(sizeof(double)*9);
    double * Jz = (double *)malloc(sizeof(double)*9);
    double Det(double *M);
};
/*class hw1{
public:
    double x,y,z;
    double ErrTol = 0.1;
    void MainCompute(double _x, double _y, double _z);
private:
    double xnew, ynew, znew;
    double f1, f2, f3;
    double f1x, f1y, f1z;
    double f2x, f2y, f2z;
    double f3x, f3y, f3z;
    double Er1, Er2, Er3;
    double* Jmat = (double *)malloc(sizeof(double) * 9);
    double* Xmat = (double *)malloc(sizeof(double) * 9);
    double* Ymat = (double *)malloc(sizeof(double) * 9);
    double* Zmat = (double *)malloc(sizeof(double) * 9);
    double* xxmat = (double *)malloc(sizeof(double) * 3);
    double* yymat = (double *)malloc(sizeof(double) * 3);
    double detJ, detX, detY, detZ;
    double func1(double _x, double _y, double _z);
    double func2(double _x, double _y, double _z);
    double func3(double _x, double _y, double _z);
    void df1dx();
    void df1dy();
    void df1dz();
    void df2dx();
    void df2dy();
    void df2dz();
    void df3dx();
    void df3dy();
    void df3dz();
    void defineMatrix();
    double det(double * mat);
    void UpdateParameters();
    void ComputeCramer();
    void NewStep();
    void ComputeError();
    double ErrorSub(double n, double o);
    void FileOpen();
    void FileWrite();
    void FileClose();


};
*/