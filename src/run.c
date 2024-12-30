#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
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

void run_python(const char *script_name) {
    char cmd[256] = "python ";
    strcat(cmd, script_name);
    int result = system(cmd);
    if (result == 0) {
        printf("Python script executed successfully\n");
    } else {
        printf("Error executing Python script\n");
    }
}