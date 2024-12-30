#include "calc.h"

// forth order explicit Runge-Kutta method
void runge_kutta_4(double (*pf)(double,double[],int), double x, double y[], double dx, int N)
{
    double h = dx/2.0;
    double t1[N], t2[N], t3[N];             
    double k1[N], k2[N], k3[N], k4[N];          
    int i;
    for (i = 0; i < N; i++) {
        k1[i] = dx*pf(x, y, i);
        t1[i] = y[i] + 0.5*k1[i];
    }
    for (i = 0; i < N; i++) {
        k2[i] = dx*pf(x + h, t1, i);
        t2[i] = y[i] + 0.5*k2[i];
    } 
    for (i = 0; i < N; i++) {
        k3[i] = dx*pf(x + h, t2, i);
        t3[i] = y[i] + k3[i];
    }
    for (i = 0; i<N; i++) {
        k4[i] = dx*pf(x + dx, t3, i);
    }
    for (i = 0; i < N; i++) y[i] += (k1[i] + 2*k2[i] + 2*k3[i] + k4[i])/6.0;
}