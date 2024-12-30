#ifndef CALC_H
#define CALC_H

void runge_kutta_4(double (*pf)(double,double[],int), double x, double y[], double dx, int N);

#endif  /* CALC_H */