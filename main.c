#include <stdio.h>
#include <stdlib.h>
#include "./src/const.h"        // 定数
#include "./src/calc.h"         // 数値計算用のルーチン
#include "./src/diffeqs.h"      // いろんな種類の微分方程式がある（予定）
#include "./src/setting.h"      
#include "./src/initialize.h"   
#include "./src/run.h"          

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
