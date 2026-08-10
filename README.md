# XTCalc / 小天才计算器

**XTCalc:** Compute XTC V1/V2 verification codes — C++ port of XTCADBCode-Web

**小天才计算器：** 计算小天才 V1、V2 校验码，XTCADBCode-Web 的 C++ 版

## Overview / 简介

A terminal tool to calculate verification codes for XTC (Xiao Tian Cai) smart watches.

一款用于**计算小天才手表校验码**的终端工具。

## Features / 功能

- **V1 (10-digit) & V2 (8-digit)** code generation  
**V1/V2** 校验码计算
- **ADB and Self-test** modes switching  
**ADB / 自检模式**切换
- **Time-line** progress bar & **colored** output  
**进度条**与**彩色**输出

## Build & Run / 编译运行

### macOS & Linux

```bash
g++ -std=c++11 main.cpp -o xtc_calc
./xtc_calc
```

### Windows (MinGW-w64)

> Requires [MinGW-w64](https://www.mingw-w64.org/) installed and properly added to your system `PATH`.
> 
> 需提前安装 [MinGW-w64](https://www.mingw-w64.org/) 并配置好环境变量。

```bat
g++ -std=c++11 main.cpp -o xtc_calc.exe
xtc_calc.exe
```

## AI Disclosure / AI 声明

Core algorithm functions (Hy3) and related helper functions are AI-generated via assistance.

核心算法函数（Hy3）及相关辅助函数由 AI 辅助生成。

## Credits / 致谢

Based on [**XTCADBCode-Web**](https://github.com/OnesoftQwQ/XTCADBCode-Web) by **OnesoftQwQ** (xtc-code.onesoft.top) .

基于 **OnesoftQwQ** 的 [**XTCADBCode-Web**](https://github.com/OnesoftQwQ/XTCADBCode-Web)。

## Copyright & License / 版权与许可

This project is for technical research only. It is not affiliated with XTC (Xiao Tian Cai). Do not use it for any unauthorized or illegal purposes.  
本项目仅用于技术研究，与小天才官方无关，请勿用于违规用途

Copyright © 2026 wuyou. All rights reserved.

MIT License © 2026 wuyou