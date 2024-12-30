#include <stdio.h>
#include "./src/const.h"  // 定数
#include "./src/calc.h"   // 数値計算用のルーチン
#include "./src/diffeqs.h"// いろんな種類の微分方程式がある（予定）

int main (void) {
    FILE *fp;
    fp = fopen("./output/test.dat", "w");

    double y[2];
    y[0] = 1.0;
    y[1] = 0.0;
    int num = 10;
    double t_ini = 0;
    double t_end = 2.0;
    double dt = (t_end - t_ini)/num;
    double t = t_ini;
    while(t <= t_end) {
        runge_kutta_4(diffeq_harmonic_oscillator, t, y, dt, 2);
        printf("%e %e %e\n", t, y[0], y[1]);
        t += dt;
    }

    return 0;
}

