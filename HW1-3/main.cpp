#include "main.h"
void HW1_3::ComputeSeries() {
    FILE *file;
    char name[50];
    sprintf(name, "Computed Volume.csv");
    file = fopen(name,"w");
    fprintf(file, "h,V\n");
    do{
        computeVolume();
        fprintf(file, "%.2f, %lf\n", h, V);
        printf("\rh = %.2f, V = %lf", h, V);
        h += 0.1;
    }while(h<=16);
    fclose(file);
    return;
}
void HW1_3::computeVolume(double _h)
{
    h = _h;
    if( h == -1)
        ComputeSeries();
    else
        computeVolume();
    return;
}
void HW1_3::computeVolume()
{
    if( h <= 0)
        V = 0;
    else if( h <= H1)
    {
        V = phi*r1*r1*h;
    }
    else if( h <= H1+H2)
    {
        V = phi*r1*r1*H1;
        const double h1 = r1*H2/(r2-r1);
        const double hx = h+h1-H1;
        const double rx = r1*hx/h1;
        V = V+((rx*rx*hx)-(r1*r1*h1))*phi/3;
    }
    else
        V = 0;
}
int main()
{
    HW1_3 Start;
    Start.computeVolume(-1);
    return 0;
}