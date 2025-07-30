---
title: Static Modint
documentation_of: //cpstl/math/StaticModint.hpp
---

# 概要
Mod を自動で取ってくれる構造体．四則演算・べき乗・等値判定・入出力が可能．

# 使い方
## テンプレート引数
```cpp
template <uint32_t m>
```
法 `m` を指定する．

## コンストラクタ
```cpp
(1) constexpr StaticModint()
(2) template <typename T> constexpr StaticModint(T v)
```
1. $0$ で初期化．
2. `v` で初期化．

### 計算量
- $\mathrm{O}(1)$ time

## raw
```cpp
static constexpr mint raw(uint32_t v)
```
余りを取らずに値を設定する．

### 計算量
- $\mathrm{O}(1)$ time

## mod
```cpp
static constexpr uint32_t mod()
```
法 `m` を返す．

### 計算量
- $\mathrm{O}(1)$ time

## val
```cpp
constexpr uint32_t val() const
```
現在の値を返す．

### 計算量
- $\mathrm{O}(1)$ time

## operator
```cpp
(1) constexpr mint& operator++()
(2) constexpr mint& operator++(int)
(3) constexpr mint& operator--()
(4) constexpr mint& operator--(int)
(5) constexpr mint& operator+=(mint rhs)
(6) constexpr mint& operator-=(mint rhs)
(7) constexpr mint& operator*=(mint rhs)
(8) constexpr mint& operator/=(mint rhs)
(9) constexpr mint operator+() const
(10) constexpr mint operator-() const
(11) friend constexpr mint operator+(mint lhs, mint rhs)
(12) friend constexpr mint operator-(mint lhs, mint rhs)
(13) friend constexpr mint operator*(mint lhs, mint rhs)
(14) friend constexpr mint operator/(mint lhs, mint rhs)
(15) friend constexpr mint operator==(mint lhs, mint rhs)
(16) friend constexpr mint operator!=(mint lhs, mint rhs)
```
1. 前置インクリメント．
2. 後置インクリメント．
3. 前置デクリメント．
4. 後置デクリメント．
5. 現在の値に `rhs` を足す．
6. 現在の値から `rhs` を引く．
7. 現在の値に `rhs` を掛ける．
8. 現在の値を `rhs` で割る．
9. 現在の値を返す．
10. 現在の値を $(-1)$ 倍した値を返す．
11. `lhs + rhs` を返す．
12. `lhs - rhs` を返す．
13. `lhs * rhs` を返す．
14. `lhs / rhs` を返す．
15. `lhs` と `rhs` が等しいか返す．
16. `lhs` と `rhs` が異なるか返す．

### 計算量
- (1)～(7), (9)～(13), (15), (16): $\mathrm{O}(1)$ time
- (8), (14): $\mathrm{O}(\log{m})$ time

## pow
```cpp
constexpr mint pow(long long n) const
```
現在の値の `n` 乗を返す．

### 計算量
- $\mathrm{O}(\log{n})$ time

## inv
```cpp
constexpr mint inv() const
```
現在の値の逆元を返す．

### 計算量
- $\mathrm{O}(\log{m})$ time

## using 宣言: Modint998244353
```cpp
using Modint998244353 = StaticModint<998244353>;
```

## リテラル: operator""_M
```cpp
constexpr Modint998244353 operator""_M(unsigned long long x)
```
