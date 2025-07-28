---
title: Disjoint Set Union
documentation_of: //cpstl/ds/Dsu.hpp
---

# 概要
集合族を管理するデータ構造．集合の併合 (merge) や指定した $2$ 要素が同じ集合に属するかの判定 (same) などが非常に高速に行える．

# 使い方
## コンストラクタ
```cpp
(1) Dsu()
(2) Dsu(int N)
```
1. 空の `Dsu` を作成する．
2. 集合族を $\lbrace \lbrace 1 \rbrace, \lbrace 2 \rbrace, \dots, \lbrace N-1 \rbrace \rbrace$ で初期化する．

### 計算量
1. $\mathrm{O}(1)$ time
2. $\mathrm{O}(N)$ time

## leader
```cpp
int leader(int x)
```
`x` の属する集合の代表元を返す．

### 計算量
- amortized $\mathrm{O}(\alpha(N))$ time

## merge
```cpp
bool merge(int a, int b)
```
`a`, `b` の属する集合を併合し，元々異なる集合に属していたかを返す．

### 計算量
- amoritzed $\mathrm{O}(\alpha(N))$ time

## same
```cpp
bool same(int a, int b)
```
`a` と `b` が同じ集合に属するか返す．

### 計算量
- amortized $\mathrm{O}(\alpha(N))$ time

## size
```cpp
int size(int x)
```
`x` が属する集合の大きさを返す．

### 計算量
- amortized $\mathrm{O}(\alpha(N))$ time

## groups
```cpp
std::vector<std::vector<int>> groups()
```
集合ごとに配列にまとめた配列を返す．

### 計算量
- $\mathrm{O}(N\alpha(N))$ time
