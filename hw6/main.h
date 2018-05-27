#include <cstdio>
#include <cmath>
#include <cstdlib>
class hw2115 {
public:
    double Compute();
private:
    void TripleIntegral13();
    double F(double x, double y, double z);
    void Error(double exact);
    double x0, x1, x2, y0, y1, y2, z0, z1, z2, result, error;
};
class hw2126 {
public:
    double Compute();
private:
    void DoubleIntegral();
    double f00, f40, f80, f120, f02, f42, f82, f122, f04, f44, f84, f124;
    double result;
};
class hw2417 {
public:
    void Compute();
private:
    void Simpsons13(double *F);
    void Trapezoidal(double *F);
    double ResultT1, ResultT2, ResultS;

};
class hw2446 {
public:
    void Compute();
private:
    double Trapezoidal(int n, int a, int b);
    double Simpsons13(int n, int a, int b);
    double GaussQuadrature(int a, int b);
    double Romberg(int a, int b, int maxit);
    void Differentiation();
    double F(double t);
    double u, m, q, g;
    double ResultT, ResultS, ResultG, ResultR;
    int _a, _b, _n;
};