#include <stdio.h>
#include <stdlib.h>
#include "./src/setting.h"      // 設定
#include "./src/initialize.h"   // 初期化
#include "./src/run.h"          // 実行

int main(void) {
    CalculationParams params = setup_calculation();
    FILE *fp = open_file("./output/dat/test.dat");

    // 初期条件
    int y_size = 2;
    double *y = initialize_array(y_size);
    y[0] = 1.0;
    y[1] = 0.0;

    // 計算を実行
    run_calculation_rk4(fp, params, y, y_size);

    // 後処理
    free(y);
    fclose(fp);

    // プロットするためにpythonを実行
    char script_name[256] = "make_figure.py";
    run_python(script_name);
    return 0;
}
