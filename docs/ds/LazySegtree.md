---
title: Lazy Segment Tree
documentation_of: //cpstl/ds/LazySegtree.hpp
---

# 概要
Lazy Segment Tree は列に対して区間更新・区間集約を高速に行えるデータ構造．非再帰・列のサイズを $2$ のべき乗に合わせる実装．

# 使い方
## テンプレート引数
```cpp
template <typename S, auto op, auto e, typename F, auto mapping, auto composition, auto id>
```
- `S`
  - 載せるデータの型
- `op`
  - 集約を行う演算
  - `S op(S, S)` の形で定義
- `e`
  - 単位元
  - `S e()` の形で定義
- `F`
  - 作用素の型
- `mapping`
  - 作用素を作用させる関数
  - `S mapping(F, S)` の形で定義
- `composition`
  - 作用素を合成する関数
  - `F composition(F, F)` の形で定義
- `id`
  - 恒等作用素
  - `F id()` の形で定義

## コンストラクタ
```cpp
(1) LazySegtree()
(2) LazySegtree(int n)
(3) LazySegtree(int n, const S &init)
(4) LazySegtree(const std::vector<S> &v)
```
1. 空の `LazySegtree` を作成する．
2. 長さ `N`，初期値 `e()` で初期化．
3. 長さ `N`，初期値 `init` で初期化．
4. `v` で初期化．
5. 範囲 `[first, last)` の値で初期化．

### 計算量
- (1): $\mathrm{O}(1)$ time
- (2)～(5) $\mathrm{O}(\log{N})$ time

## set
```cpp
void set(int pos, const S &x)
```
`A[pos] = x` で更新．

### 計算量
- $\mathrm{O}(\log{N})$ time

## add
```cpp
void add(int pos, const S &x)
```
`A[pos] += x` で更新．

### 計算量
- $\mathrm{O}(\log{N})$ time

## apply
```cpp
(1) void apply(int pos, const F &f)
(2) void apply(int l, int r)
```
1. `A[pos]` に `f` を作用させる．
2. `A[l, r)` に `f` を作用させる．

### 計算量
- $\mathrm{O}(\log{N})$ time

## get
```cpp
S& get(int pos)
```
`A[pos]` を返す．

### 計算量
- $\mathrm{O}(\log{N})$ time

## operator[]
```cpp
S& operator[](int pos) noexcept
```
`A[pos]` を返す．

### 計算量
- $\mathrm{O}(\log{N})$ time

## fold
```cpp
S fold(int l, int r)
```
`op[l, r)` を返す．

### 計算量
- $\mathrm{O}(\log{N})$ time

## all_fold
```cpp
S all_fold() const
```

### 計算量
- $\mathrm{O}(1)$ time

## max_right
```cpp
template <typename G> int max_right(int l, const G &g)
```
- `r = l` または `f(op[l, r)) = true`
- `r = n` または `f(op[l, r]) = false`

これらを両方満たす `r` を返す．`f` が単調な場合，`f(op[l, r)) = true` となる最大の `r` が返ってくる．

### 計算量
- $\mathrm{O}(\log{N})$ time

## min_left
```cpp
template <typename G> int min_left(int r, const G &g)
```
- `l = r` または `f(op[l, r)) = true`
- `l = 0` または `f(op[l - 1, r)) = false`

これらを両方満たす `r` を返す．`f` が単調な場合，`f(op[l, r)) = true` となる最小の `l` が返ってくる．

### 計算量
- $\mathrm{O}(\log{N})$ time
