<div id="top"></div>

## 使用技術一覧
* C言語
* Python

## 目次

1. [プロジェクトについて](#プロジェクトについて)
2. [環境](#環境)
3. [ディレクトリ構成](#ディレクトリ構成)
4. [トラブルシューティング](#トラブルシューティング)


## プロジェクト名
4次のRunge-Kutta法のデモ

<!-- プロジェクトについて -->

## プロジェクトについて
<!-- プロジェクトの概要を記載 -->
このプロジェクトでは簡単な微分方程式を解くことができます。  
といっても物理で出てくる常微分方程式なら、基本的に解けるはずです。  
解けない場合は、それは硬い微分方程式ですので、陰的ルンゲクッタ法を組みましょう。  

<p align="right">(<a href="#top">トップへ</a>)</p>

## 環境

<!-- 言語、フレームワーク、ミドルウェア、インフラの一覧とバージョンを記載 -->

| 対象  | バージョン |
| --------------------- | ---------- |
| clang |Apple clang version 12.0.5 |
| Python | Python 3.12.6 |
| matplotlib | 3.10.0 |
| numpy | 2.2.1 |


<p align="right">(<a href="#top">トップへ</a>)</p>

## ディレクトリ構成

<!-- Treeコマンドを使ってディレクトリ構成を記載 -->
 <pre>
.
├── .gitignore
├── Makefile
├── README.md
├── fig_make.py
├── main.c
├── obj
├── output
│   ├── dat
│   └── fig
├── requirements.txt
└── src
    ├── calc.c
    ├── calc.h
    ├── const.c
    ├── const.h
    ├── diffeqs.c
    ├── diffeqs.h
    ├── initialize.c
    ├── initialize.h
    ├── run.c
    ├── run.h
    ├── setting.c
    └── setting.h
</pre>   


### Makefile
実行を担う重要なファイルです。

### fig_make.py  
C言語で作られたデータファイルを元に図を出力するスクリプトです。フォントはTeXを使用しています。

### main.c
実行の流れが記されたファイルです。

### obj/
オブジェクトファイルの格納先です。

### output/
#### dat/
計算結果のdatファイルが格納されるディレクトリです。

#### fig/
計算結果のdatファイルに基づいて、出力される図が格納されるディレクトリです。

### requirements.txt
Pythonで必要なライブラリが記載されたファイルです。

### src/
#### calc.c calc.h
数値計算のルーチンが格納されているファイルです。現状、4次の陽的ルンゲクッタ法しか入っていません。

#### const.c const.h
数学定数や物理定数が格納されるファイルです。例えば円周率$\pi$やネイピア数$e$、重力定数$G$など定義すれば良いです。

#### diffeqs.c diffeqs/h
微分方程式の具体的な形が記されているファイルです。ここを変更すると、さまざまな微分方程式が解けるようになります。ただし、２階微分方程式のような高階のものに関しては、連立の1解微分方程式に帰着する必要があります。

#### initilize.c initialize.h
ファイルを開いたり、配列の初期化のような関数が格納されているファイルです。正直、ファイルに関してはfile_utils.cなどを作成する予定です。。

#### run.c run.h
微分方程式を実行する関数が格納されているファイル。基本的にfor文で単調に回しているが、例えば質量が変化するような場合の減衰振動を扱う場合には、このファイルの時間ステップをうまく修正する必要があります。

#### setting.c settin.h
設定ファイル。微分方程式をどこからどこまで計算するのかを与えます。また、フリーパラメタはconst.cではなく、こちらのsetting.cに書くべきです。

<p align="right">(<a href="#top">トップへ</a>)</p>

## 開発環境構築
```
git clone https://github.com/TatsukiKodama/rk4_demo.git
```
のあと
```
cd rk4_demo
```
でワークディレクトリに入りましょう。

まずはPythonの仮想環境を作成し、アクティベートします。
```
python3 -m venv venv
source venv/bin/activate
```
必要なライブラ入りをpipでインストールします
```
pip install -r requirements.txt
```
続いて
```
make
```
と入力すると、objディレクトリやmain実行ファイルが生成されます。最後に
```
./main
```
とすれば、準備完了です。いまあなたの目の前には$\sin$カーブ$\cos$カーブが見えているはずです。

## トラブルシューティング
工事中👷

### GitHub系

#### 間違って不必要なファイルをpush
焦らずに.gitignoreに、そのファイル名を記入後、
```
git rm --cashed [file name]
```
と入力する。

#### 間違って不必要なディレクトリをpush
焦らずに.gitignoreに、そのディレクトr名を記入後、
```
git rm -r --cached [directory name]/
```

<p align="right">(<a href="#top">トップへ</a>)</p>
