#ifndef RUN_H
#define RUN_H

#include <stdio.h>
#include "setting.h"

void run_python(const char *script_name);
void run_calculation_rk4(FILE *fp, CalculationParams params, double *y, int y_size);

#endif
