import numpy as np
import matplotlib.pyplot as plt

# データファイルの読み込み
data = np.loadtxt('output/dat/test.dat')

# データファイルのそれぞれの列を配列に格納
x = data[:, 0] 
y1 = data[:, 1] 
y2 = data[:, 2]

# プロット
plt.plot(x, y1, label='y[0]')  # 2列目をプロット
plt.plot(x, y2, label='y[1]')  # 3列目をプロット

# ラベルとタイトルの設定
plt.xlabel('Column 1')
plt.ylabel('Values')
plt.title('Plot of Columns 1, 2, and 3')

# 凡例の表示
plt.legend()

# 表示
plt.show()

# 保存
plt.savefig('output/fig/plot.pdf', format='pdf')
