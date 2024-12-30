#include "setting.h"
#include "const.h"  

SimulationParams setup_simulation() {
    SimulationParams params = {
        .num_steps = 10,
        .t_ini = 0.0,
        .t_end = 2.0 * PI,
        .dt = (2.0 * PI) / 10
    };
    return params;
}
