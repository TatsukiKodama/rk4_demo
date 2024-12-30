#include "setting.h"
#include "const.h"  

CalculationParams setup_calculation() {
    CalculationParams params = {
        .num_steps = 100,
        .t_ini = 0.0,
        .t_end = 4.0*PI
    };
    return params;
}
