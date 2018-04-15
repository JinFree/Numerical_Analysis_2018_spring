#include "main.h"
double hw1::f1(x, y, z) {
    return x+y+z-1.8;
}
double hw1::f2(x, y, z) {
    return 3.0*x*x+y*y-z*z-5.8;
}
double hw1::f3(x, y, z) {
    return x*(y+z)-0.8;
}
double hw1::df1dx(x, y, z) {
    return 1.0;
}
double hw1::df1dy(x, y, z) {
    return 1.0;
}
double hw1::df1dz(x, y, z) {
    return 1.0;
}
double hw1::df2dx(x, y, z) {
    return 6.0*x;
}
double hw1::df2dy(x, y, z) {
    return 2.0*y;
}
double hw1::df2dz(x, y, z) {
    return -2.0*z;
}
double hw1::df3dx(x, y, z) {
    return y+z;
}
double hw1::df3dy(x, y, z) {
    return x;
}
double hw1::df3dz(x, y, z) {
    return x;
}
void hw1::BuildMat(x, y, z) {
    Jacobian[0] = df1dx(x,y,z);
    Jacobian[1] = df1dy(x,y,z);
    Jacobian[2] = df1dz(x,y,z);
    Jacobian[3] = df2dx(x,y,z);
    Jacobian[4] = df2dy(x,y,z);
    Jacobian[5] = df2dz(x,y,z);
    Jacobian[6] = df3dx(x,y,z);
    Jacobian[7] = df3dy(x,y,z);
    Jacobian[8] = df3dz(x,y,z);
    int i=0;
    for( i = 0 ; i < 9 ; i++){
        Jx[i]=Jacobian[i];
        Jy[i]=Jx[i];
        Jz[i]=Jy[i];
    }
    Jx[0] =
}
double hw1::Det(double *M) {
    return M[0]*(M[4]*M[8] - M[5]*M[7]) -
            M[1]*(M[3]*M[8] - M[5]*M[6]) +
            M[2]*(M[3]*M[7] - M[4]*M[6]);
}
/*void hw1::defineMatrix() {
    yymat[0] = -f1;
    yymat[1] = -f2;
    yymat[2] = -f3;
    Jmat[0] = f1x;
    Jmat[1] = f1y;
    Jmat[2] = f1z;
    Jmat[3] = f2x;
    Jmat[4] = f2y;
    Jmat[5] = f2z;
    Jmat[6] = f3x;
    Jmat[7] = f3y;
    Jmat[8] = f3z;
    int i;
    for ( i = 0 ; i < 9 ; i++)
    {
        Xmat[i] = Jmat[i];
        Ymat[i] = Jmat[i];
        Zmat[i] = Jmat[i];
    }
    Xmat[0] = yymat[0];
    Xmat[3] = yymat[1];
    Xmat[6] = yymat[2];

    Ymat[1] = yymat[0];
    Ymat[4] = yymat[1];
    Ymat[7] = yymat[2];

    Zmat[2] = yymat[0];
    Zmat[5] = yymat[1];
    Zmat[8] = yymat[2];

}
double hw1::det(double * mat) {
    double a11, a12, a13, a21, a22, a23, a31, a32, a33;
    a11 = mat[0];
    a12 = mat[1];
    a13 = mat[2];
    a21 = mat[3];
    a22 = mat[4];
    a23 = mat[5];
    a31 = mat[6];
    a32 = mat[7];
    a33 = mat[8];
    double result = a11 * (a22 * a33 - a23 * a32);
    result = result - a12 * (a21 * a33 - a23 * a31);
    result = result + a13 * (a21 * a32 - a22 * a31);
    return result;
}
void hw1::UpdateParameters() {
    f1 = func1(x, y, z);
    f2 = func2(x, y, z);
    f3 = func3(x, y, z);
    df1dx();
    df1dy();
    df1dz();
    df2dx();
    df2dy();
    df2dz();
    df3dx();
    df3dy();
    df3dz();
}
void hw1::ComputeCramer() {
    defineMatrix();
    detJ = det(Jmat);
    detX = det(Xmat);
    detY = det(Ymat);
    detZ = det(Zmat);
    xxmat[0] = detX/detJ;
    xxmat[1] = detY/detJ;
    xxmat[2] = detZ/detJ;
    xnew = x+xxmat[0];
    ynew = y+xxmat[1];
    znew = z+xxmat[2];
}
void hw1::NewStep() {
    x = xnew;
    y = ynew;
    z = znew;
}
void hw1::ComputeError() {
    double f1n = func1(xnew, ynew, znew);
    double f2n = func2(xnew, ynew, znew);
    double f3n = func3(xnew, ynew, znew);
    double f1o = func1(x, y, z);
    double f2o = func2(x, y, z);
    double f3o = func3(x, y, z);
    if ( f1n == 0 )
        Er1 = 0;
    else
        Er1 = ErrorSub(f1n, f1o);
    if ( f2n == 0 )
        Er2 = 0;
    else
        Er2 = ErrorSub(f2n, f2o);
    if ( f3n == 0 )
        Er3 = 0;
    else
        Er3 = ErrorSub(f3n, f3o);
}
double hw1::ErrorSub(double n, double o) {
    return fabs((n-o)/n)*100;
}
void hw1::FileOpen() {

}
void hw1::FileWrite() {

}
void hw1::FileClose() {

}
void hw1::MainCompute(double _x, double _y, double _z) {
    x = _x;
    y = _y;
    z = _z;
    int iter = 0;
    UpdateParameters();
    FileOpen();
    FileWrite();
    do{
        iter++;
        ComputeCramer();
        ComputeError();
        NewStep();
        UpdateParameters();
        FileWrite();
        //printf("\rIter = %d, X = %.3f, Y = %.3f, Z = %.f, Er1 = %.3f, Er2 = %.3f = Er3 = %.3f", iter, x, y, z, Er1, Er2, Er3);
    }while((Er1 < ErrTol)&&(Er2 < ErrTol)&&(Er3 < ErrTol));
    FileClose();
    free(Jmat);
    free(Xmat);
    free(Ymat);
    free(Zmat);
    free(xxmat);
    free(yymat);
}*/
int main() {
    return 0;
}