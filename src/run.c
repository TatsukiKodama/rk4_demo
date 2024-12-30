#include <stdio.h>
#include <stdlib.h> 
#include "./run.h"
#include "./calc.h"
#include "./diffeqs.h"

void run_calculation_rk4(FILE *fp, CalculationParams params, double *y, int y_size) {
    double t = params.t_ini;
    double dt = (params.t_end - params.t_ini)/params.num_steps;
    for (int i = 0; i <= params.num_steps; i++) {
        t = params.t_ini + i * dt;
        fprintf(fp, "%e %e %e\n", t, y[0], y[1]);
        runge_kutta_4(diffeq_harmonic_oscillator, t, y, y_size, dt);
    }
}

void run_python(void) {
    int result = system("python fig_make.py");
    if (result == 0) {
        printf("Python script executed successfully\n");
    } else {
        printf("Error executing Python script\n");
    }
}