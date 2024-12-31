import numpy as np
import matplotlib.pyplot as plt

# TeX フォントを使用するための設定
plt.rcParams.update({
    'text.usetex': True,  # LaTeX を有効にする
    'font.family': 'serif',  # セリフ体を使用
    'font.serif': ['Times New Roman'],  # 使用するフォントを指定（必要に応じて変更）
    'text.latex.preamble': r'\usepackage{amsmath}',  # 数式のためのパッケージを読み込む
    'font.size': 14
})

# データファイルの読み込み
data = np.loadtxt('output/dat/test.dat')

# データファイルのそれぞれの列を配列に格納
x = data[:, 0] 
y1 = data[:, 1] 
y2 = data[:, 2]

# グラフの描画
plt.plot(x, y1, "-", label=r'$y$', color='red') 
plt.plot(x, y2, "--", label=r'$\dot{y}$', color='blue') 

# ラベルとタイトルを追加
plt.xlabel(r'$t$ [time]')
plt.ylabel(r'$y, \dot{y}$')
plt.title(r'Damping oscillator')

# 凡例の表示
plt.legend()

# 保存
plt.savefig('output/fig/plot.pdf', format='pdf')

# 表示
plt.show()
