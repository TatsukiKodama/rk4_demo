#include "calc.h"

// forth order explicit Runge-Kutta method
void runge_kutta_4(double (*pf)(double,double[],int), double x, double y[], int y_size, double dx) {
    double h = dx/2.0;
    double t1[y_size], t2[y_size], t3[y_size];             
    double k1[y_size], k2[y_size], k3[y_size], k4[y_size];          
    int i;
    for (i = 0; i < y_size; i++) {
        k1[i] = dx*pf(x, y, i);
        t1[i] = y[i] + 0.5*k1[i];
    }
    for (i = 0; i < y_size; i++) {
        k2[i] = dx*pf(x + h, t1, i);
        t2[i] = y[i] + 0.5*k2[i];
    } 
    for (i = 0; i < y_size; i++) {
        k3[i] = dx*pf(x + h, t2, i);
        t3[i] = y[i] + k3[i];
    }
    for (i = 0; i<y_size; i++) {
        k4[i] = dx*pf(x + dx, t3, i);
    }
    for (i = 0; i < y_size; i++) y[i] += (k1[i] + 2*k2[i] + 2*k3[i] + k4[i])/6.0;
}