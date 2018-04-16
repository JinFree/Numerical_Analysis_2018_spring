#include "main.h"
double hw1::f(double x, double y, double z) {
    return x + y + z - 1.8;
}
double hw1::g(double x, double y, double z) {
    return 3*x*x + y*y - z*z - 5.8;
}
double hw1::h(double x, double y, double z) {
    return x*(y+z) - 0.8;
}
double hw1::dfdx(double x, double y, double z) {
    return 1.0;
}
double hw1::dfdy(double x, double y, double z) {
    return 1.0;
}
double hw1::dfdz(double x, double y, double z) {
    return 1.0;
}
double hw1::dgdx(double x, double y, double z) {
    return 6.0*x;
}
double hw1::dgdy(double x, double y, double z) {
    return 2.0*y;
}
double hw1::dgdz(double x, double y, double z) {
    return -2.0*z;
}
double hw1::dhdx(double x, double y, double z) {
    return y+z;
}
double hw1::dhdy(double x, double y, double z) {
    return x;
}
double hw1::dhdz(double x, double y, double z) {
    return x;
}
double hw1::Det(double *M) {
    return M[0]*(M[4]*M[8] - M[5]*M[7]) -
           M[1]*(M[3]*M[8] - M[5]*M[6]) +
           M[2]*(M[3]*M[7] - M[4]*M[6]);
}
void hw1::SolveX(double x, double y, double z) {
    B[0] = -1.0*_f;
    B[1] = -1.0*_g;
    B[2] = -1.0*_h;
    Jacobian[0] = dfdx(x,y,z);
    Jacobian[1] = dfdy(x,y,z);
    Jacobian[2] = dfdz(x,y,z);
    Jacobian[3] = dgdx(x,y,z);
    Jacobian[4] = dgdy(x,y,z);
    Jacobian[5] = dgdz(x,y,z);
    Jacobian[6] = dhdx(x,y,z);
    Jacobian[7] = dhdy(x,y,z);
    Jacobian[8] = dhdz(x,y,z);
    int i=0;
    for( i = 0 ; i < 9 ; i++){
        Jx[i]=Jacobian[i];
        Jy[i]=Jx[i];
        Jz[i]=Jy[i];
    }
    Jx[0] = B[0];
    Jx[3] = B[1];
    Jx[6] = B[2];
    Jy[1] = B[0];
    Jy[4] = B[1];
    Jy[7] = B[2];
    Jz[2] = B[0];
    Jz[5] = B[1];
    Jz[8] = B[2];
    double DetJ = Det(Jacobian);
    double DetX = Det(Jx);
    double DetY = Det(Jy);
    double DetZ = Det(Jz);
    X[0] = DetX/DetJ;
    X[1] = DetY/DetJ;
    X[2] = DetZ/DetJ;
}
void hw1::ForwardStep() {
    _x += X[0];
    _y += X[1];
    _z += X[2];
}
void hw1::GetResult() {
    _f = f(_x, _y, _z);
    _g = g(_x, _y, _z);
    _h = h(_x, _y, _z);
}
double hw1::ErrorCheck() {
    return sqrt(_f*_f+_g*_g+_h*_h)/3.0;
}
void hw1::OpenFile() {
    char name[50];
    sprintf(name, "3by3, Newton-Raphson.csv");
    file = fopen(name, "w");
    fprintf(file, "iter,f,g,h,x,y,z\n");
}
void hw1::WriteFile() {
    fprintf(file, "%d,%lf,%lf,%lf,%lf,%lf,%lf\n",iter,_f,_g,_h,_x,_y,_z);
}
void hw1::CloseFile() {
    fclose(file);
}
void hw1::Solve() {
    double error = 1.0;
    OpenFile();
    WriteFile();
    printf("iter: %d, f: %f, g: %f, h: %f, x: %f, y: %f, z: %f\n", iter, _f, _g, _h, _x, _y, _z);
    for(iter = 1 ; iter < 100 ; iter++)
    {
        SolveX(_x, _y, _z);
        ForwardStep();
        GetResult();
        WriteFile();
        error = ErrorCheck();
        printf("iter: %d, f: %f, g: %f, h: %f, x: %f, y: %f, z: %f\n", iter, _f, _g, _h, _x, _y, _z);
        if(error < 0.000001)
            break;
    }
    CloseFile();
}
int main() {
    hw1 hw1;
    hw1.Solve();
    return 0;
}