#include "setting.h"
#include "const.h"  

CalculationParams setup_simulation() {
    CalculationParams params = {
        .num_steps = 10,
        .t_ini = 0.0,
        .t_end = 2.0 * PI
    };
    return params;
}
