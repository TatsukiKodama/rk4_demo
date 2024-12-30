#include <stdio.h>
#include <stdlib.h>
#include "./src/const.h"  // 定数
#include "./src/calc.h"   // 数値計算用のルーチン
#include "./src/diffeqs.h"// いろんな種類の微分方程式がある（予定）

int main (void) {
    FILE *fp;
    fp = fopen("./output/test.dat", "w");

    int y_size = 2; // 必要な配列のサイズ
    double *y = malloc(y_size * sizeof(double));
    if (y == NULL) {
        perror("Memory allocation failed");
        return 1;
    }
    y[0] = 1.0;
    y[1] = 0.0;
    int num = 10;
    double t_ini = 0;
    double t_end = 2.0*PI;
    double dt = (t_end - t_ini)/num;
    double t = 0.0;
    fprintf(fp, "%e %e %e\n", t, y[0], y[1]);
    for(int i = 0; i <= num; i++) {
        t = t_ini + i*dt;
        printf("%e %e %e\n", t, y[0], y[1]);
        fprintf(fp, "%e %e %e\n", t, y[0], y[1]);
        runge_kutta_4(diffeq_harmonic_oscillator, t, y, y_size, dt);
    }

    free(y);
    return 0;
}

