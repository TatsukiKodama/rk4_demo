#include <stdio.h>
#include "./run.h"
#include "./calc.h"
#include "./diffeqs.h"

void run_calculation(FILE *fp, SimulationParams params, double *y, int y_size) {
    double t = params.t_ini;
    fprintf(fp, "%e %e %e\n", t, y[0], y[1]);
    for (int i = 0; i <= params.num_steps; i++) {
        t = params.t_ini + i * params.dt;
        printf("%e %e %e\n", t, y[0], y[1]);
        fprintf(fp, "%e %e %e\n", t, y[0], y[1]);
        runge_kutta_4(diffeq_harmonic_oscillator, t, y, y_size, params.dt);
    }
}