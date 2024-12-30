#ifndef SETTING_H
#define SETTING_H

#include "const.h"  // 必要に応じてインクルード

typedef struct {
    int num_steps;
    double t_ini;
    double t_end;
} CalculationParams;

CalculationParams setup_calculation();

#endif
