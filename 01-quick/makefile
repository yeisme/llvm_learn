
CC:=clang
CXX:=clang++

CFLAGS:=

ifneq ($(OS),Windows_NT)
	EXT:=
else
	EXT:=.exe
endif

SOURCES:=hello.cpp
TARGET:=hello$(EXT)

OUTPUT_DIR:=build

.PHONY: build i ir opt llc clean all cc-print-phases

all: build i ir opt llc

# 清理生成的文件
clean:
	rm -rf $(OUTPUT_DIR)/*

# 从源文件生成可执行文件
build:
	$(CXX) $(CFLAGS) -o $(OUTPUT_DIR)/$(TARGET) $(SOURCES)

# 预处理生成 .i 文件
i:
	$(CXX) $(CFLAGS) -E $(SOURCES) -o $(OUTPUT_DIR)/hello.i

# 编译为 LLVM IR 文件
ir:
	$(CXX) $(CFLAGS) -S -emit-llvm $(SOURCES) -o $(OUTPUT_DIR)/hello.ll

# 优化LLVM IR
opt:
	$(CXX) $(CFLAGS) -S -emit-llvm -O1   $(SOURCES) -o $(OUTPUT_DIR)/hello.opt1.ll   # -O1：基本优化，平衡编译时间和性能
	$(CXX) $(CFLAGS) -S -emit-llvm -O2   $(SOURCES) -o $(OUTPUT_DIR)/hello.opt2.ll   # -O2：更多激进优化，适合发布构建
	$(CXX) $(CFLAGS) -S -emit-llvm -O3   $(SOURCES) -o $(OUTPUT_DIR)/hello.opt3.ll   # -O3：最高级别优化，可能增大代码体积
	$(CXX) $(CFLAGS) -S -emit-llvm -Os   $(SOURCES) -o $(OUTPUT_DIR)/hello.optOs.ll  # -Os：针对代码大小优化，禁用某些速度优化
	$(CXX) $(CFLAGS) -S -emit-llvm -Oz   $(SOURCES) -o $(OUTPUT_DIR)/hello.optOz.ll  # -Oz：更激进的体积优化，适用于内存受限场景

# 生成目标文件 针对 x86_64
llc:
	$(CXX) $(CFLAGS) -c $(SOURCES) -o $(OUTPUT_DIR)/hello.o

# 打印编译过程中的各个阶段（预处理、编译、汇编、链接等）
cc-print-phases:
	$(CXX) $(CFLAGS) -ccc-print-phases $(SOURCES) -o $(OUTPUT_DIR)/$(TARGET)

# ast
ast:
	$(CXX) $(CFLAGS) -Xclang -ast-dump -fsyntax-only $(SOURCES) > $(OUTPUT_DIR)/hello.ast
