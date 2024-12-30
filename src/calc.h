#ifndef CALC_H
#define CALC_H

void runge_kutta_4(double (*pf)(double,double[],int), double x, double y[], int y_size, double dx);

#endif  /* CALC_H */