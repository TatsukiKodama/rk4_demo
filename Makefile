# コンパイラとフラグの設定
CC = clang
CFLAGS = -Wall -Wextra -std=c99

# ソースファイルの自動検出
SRCDIR = src
OBJDIR = obj
SRCS = $(wildcard $(SRCDIR)/*.c) main.c  # main.c を追加
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# ========================================================== #

# 出力ファイル名
TARGET = main

# すべてのターゲット
all: $(TARGET)

# 実行ファイルの生成
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# オブジェクトファイルの生成
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)/$(SRCDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# サブディレクトリの作成
$(OBJDIR)/$(SRCDIR):
	mkdir -p $(OBJDIR)

# クリーンアップ
clean:
	rm -rf $(OBJDIR) $(TARGET)
