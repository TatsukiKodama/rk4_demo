# コンパイラとフラグ
CC = clang
CFLAGS = -Wall -Wextra -O2

# ターゲット名
TARGET = main

# ソースファイルと出力ファイル
SRCDIR = src
SRCS = main.c $(SRCDIR)/calc.c $(SRCDIR)/diffeq.c
OBJS = $(SRCS:.c=.o)

# ルール: 実行ファイルを作成
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

# ルール: 個別にオブジェクトファイルを作成
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# クリーンアップ
clean:
	rm -f $(OBJS) $(TARGET)
