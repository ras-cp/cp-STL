---
title: Segment Tree
documentation_of: /cpstl/ds/Segtree.hpp
---

# 概要
列に対して単一要素の更新・区間集約が高速に行えるデータ構造．非再帰・列のサイズを $2$ のべき乗に合わせる実装．以下，管理する列を `A`，列の長さを `N` とする．

# 使い方
## テンプレート引数
```cpp
template <typename S, auto op, auto e>
```
- `S`
  - 載せるデータの型
- `op`
  - 集約を行う演算
  - `S op(S, S)` の形で定義する (lambda 式でも OK)
- `e`
  - 演算の単位元
  - `S e()` の形で定義する．

`op` は結合法則を満たす必要がある．すなわち，任意の `S` の元 `a, b, c` に対し `op(op(a, b), c) = op(a, op(b, c))` となる必要がある．
以下，`op` で `A[l], A[l + 1], ..., A[r]` を集約した値を `op[l, r]`，`A[l], A[l + 1], ..., A[r - 1]` を集約した値を `op[l, r)` で表す．

## コンストラクタ
```cpp
(1) Segtree()
(2) Segtree(int N)
(3) Segtree(int N, const S &init)
(4) Segtree(const std::vector<S> &v)
(5) template <class Inputit> Segtree(Inputit first, Inputit last)
```
1. 空の `Segtree` を作成する．
2. 長さ `N`，初期値 `e()` で初期化．
3. 長さ `N`，初期値 `init` で初期化．
4. `v` で初期化．
5. 範囲 `[first, last)` の値で初期化．
### 計算量
1. $\mathrm{O}(1)$ time
2. $\mathrm{O}(N)$ time
3. $\mathrm{O}(N)$ time
4. $\mathrm{O}(N)$ time
5. $\mathrm{O}(N)$ time

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
`A[pos] += x` で更新．`S` に `operator+=` が定義されている必要がある．
### 計算量
- $\mathrm{O}(\log{N})$ time

## apply
```cpp
template <typename F, auto mapping> void set(int pos, const F &f)
```
`A[pos] = mapping(f, A[pos])` で更新．`mapping` は `S mapping(F, S)` の形で定義されている必要がある (lambda 式でも OK)．
### 計算量
- $\mathrm{O}(\log{N})$ time

## get
```cpp
const S& get(int pos) const
```
`A[pos]` を返す．
### 計算量
- $\mathrm{O}(1)$ time

## operator[]
```cpp
const S& get(int pos) const noexcept
```
`A[pos]` を返す．
### 計算量
- $\mathrm{O}(1)$ time

## fold
```cpp
S fold(int l, int r) const
```
`op[l, r)` を返す．
### 計算量
- $\mathrm{O}(\log{N})$ time

## all_fold
```cpp
S all_fold() const
```
`op[1, N]` を返す．
### 計算量
- $\mathrm{O}(1)$ time

## max_right
```cpp
<typename F> int max_right(int l, const F& f)
```
- `r = l` または `f(op[l, r)) = true`
- `r = n` または `f(op[l, r]) = false`

これらを両方満たす `r` を返す．`f` が単調な場合，`f(op[l, r)) = true` となる最大の `r` が返ってくる．
### 計算量
- $\mathrm{O}(\log{N})$ time

## min_left
```cpp
<typename F> int min_left(int r, const F& f) const
```
- `l = r` または `f(op[l, r)) = true`
- `l = 0` または `f(op[l - 1, r)) = false`

これらを両方満たす `r` を返す．`f` が単調な場合，`f(op[l, r)) = true` となる最小の `l` が返ってくる．
### 計算量
- $\mathrm{O}(\log{N})$ time
