#include <stdio.h>
#include <stdlib.h>
#include "./src/const.h"        // 定数
#include "./src/calc.h"         // 数値計算用のルーチン
#include "./src/diffeqs.h"      // いろんな種類の微分方程式がある（予定）
#include "./src/setting.h"      //
#include "./src/initialize.h"   //
#include "./src/run.h"          //

int main(void) {
    // シミュレーションパラメータを設定
    SimulationParams params = {
        .num_steps = 10,
        .t_ini = 0.0,
        .t_end = 2.0 * PI
    };

    // 出力ファイルを開く
    FILE *fp = open_file("./output/test.dat");

    // 状態配列を初期化
    int y_size = 2;
    double *y = initialize_array(y_size);
    y[0] = 1.0;
    y[1] = 0.0;

    // シミュレーションを実行
    run_calculation(fp, params, y, y_size);

    // 後処理
    free(y);
    fclose(fp);
    return 0;
}
