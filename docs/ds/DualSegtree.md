---
title: Dual Segment Tree
documentation_of: //cpstl/ds/DualSegtree.hpp
---

# 概要
Dual Segment Tree (双対セグメント木) は Lazy Segment Tree の作用素のみを取り出したデータ構造．
Lazy Segtree と比較すると時間・空間ともに定数倍高速．

# 使い方
## テンプレート引数
```cpp
template <typename F, auto composition, auto id>
```
- `F`
  - 作用素の型
- `composition`
  - 作用素を合成する関数
  - `F composition(F, F)` の形で定義する
- `id`
  - 恒等写像
  - `F id()` の形で定義する

Dual Segtree にはモノイドが載る．

## コンストラクタ
```cpp
(1) DualSegtree()
(2) DualSegtree(int N)
```
1. 空の Dual Segtree を作成する．
2. 長さ `N`，初期値 `id()` で初期化．

### 計算量
1. $\mathrm{O}(1)$ time
2. $\mathrm{O}(\log{N})$ time

## set
```cpp
void set(int pos, const F &f)
```
`A[pos]` への作用素を `f` に更新する．

### 計算量
- $\mathrm{O}(\log{N})$ time

## apply
```cpp
(1) void apply(int pos, const F &f)
(2) void apply(int l, int r, const F &f)
```
1. `A[pos]` に `f` を作用させる．
2. `A[l, r)` に `f` を作用させる．

### 計算量
- $\mathrm{O}(\log{N})$ time
