---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: cpstl/ds/Segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Fastio.hpp
    title: Fast I/O
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Template.hpp
    title: cpstl/other/Template.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/lc-Point-Add-Range-Sum-Segtree.test.cpp
    title: verify/ds/lc-Point-Add-Range-Sum-Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
    title: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
    title: verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/lc-Union-Find-Dsu.test.cpp
    title: verify/ds/lc-Union-Find-Dsu.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/yuki-0875-Segtree.test.cpp
    title: verify/ds/yuki-0875-Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/other/lc-Many-A+B-128bit-Fastio.test.cpp
    title: verify/other/lc-Many-A+B-128bit-Fastio.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://hackmd.io/@tatyam-prime/rkVCOcwQn
  bundledCode: "#line 2 \"cpstl/math/StaticModint.hpp\"\n\n#include <cstdint>\n#include\
    \ <utility>\n#include <type_traits>\n#include <cassert>\n\nnamespace cpstd {\n\
    \n// Static Modint\n\n// https://hackmd.io/@tatyam-prime/rkVCOcwQn\n\ntemplate\
    \ <uint32_t m>\nstruct StaticModint {\n\tprivate:\n\tusing mint = StaticModint;\n\
    \tuint32_t _v = 0;\n\n\tstatic constexpr bool is_prime = []() -> bool {\n\t\t\
    if (m == 1) return false;\n\t\tif (m == 2 || m == 7 || m == 61) return true;\n\
    \t\tif (!(m & 1)) return false;\n\t\tuint32_t d = m - 1;\n\t\twhile (!(d & 1))\
    \ d >>= 1;\n\t\tfor (uint32_t a : {2, 7, 61}) {\n\t\t\tuint32_t t = d;\n\t\t\t\
    mint y = mint(a).pow(t);\n\t\t\twhile (t != m - 1 && y != 1 && y != m - 1) {\n\
    \t\t\t\ty *= y;\n\t\t\t\tt <<= 1;\n\t\t\t}\n\t\t\tif (y != m - 1 && !(t & 1))\
    \ return false;\n\t\t}\n\t\treturn true;\n\t}();\n\t\n\tstatic constexpr std::pair<int32_t,\
    \ int32_t> inv_gcd(int32_t a, int32_t b) {\n\t\tif (a == 0) return {b, 0};\n\t\
    \tint32_t s = b, t = a, m0 = 0, m1 = 1;\n\t\twhile (t) {\n\t\t\tconst int32_t\
    \ q = s / t;\n\t\t\ts -= t * q, std::swap(s, t);\n\t\t\tm0 -= m1 * q, std::swap(m0,\
    \ m1);\n\t\t}\n\t\tif (m0 < 0) m0 += b / s;\n\t\treturn {s, m0};\n\t}\n\n\tpublic:\n\
    \tconstexpr StaticModint() {}\n\ttemplate <typename T>\n\tconstexpr StaticModint(T\
    \ v) {\n\t\tstatic_assert(std::is_integral_v<T>, \"T is not integral type.\");\n\
    \t\tif constexpr (std::is_signed_v<T>) {\n\t\t\tint64_t x = int64_t(v % int64_t(m));\n\
    \t\t\tif (x < 0) x += m;\n\t\t\t_v = uint32_t(x);\n\t\t}\n\t\telse _v = uint32_t(v\
    \ % m);\n\t}\n\n\tstatic constexpr mint raw(uint32_t v) { mint a; a._v = v; return\
    \ a; }\n\n\tstatic constexpr uint32_t mod() { return m; }\n\n\tconstexpr uint32_t\
    \ val() const { return _v; }\n\n\tconstexpr mint& operator++() { return *this\
    \ += 1; }\n\n\tconstexpr mint operator++(int) { mint res = *this; ++*this; return\
    \ res; }\n\n\tconstexpr mint& operator--() { return *this -= 1; }\n\n\tconstexpr\
    \ mint operator--(int) { mint res = *this; --*this; return res; }\n\n\tconstexpr\
    \ mint& operator+=(mint rhs) {\n\t\tif (_v >= m - rhs._v) _v -= m;\n\t\t_v +=\
    \ rhs._v;\n\t\treturn *this;\n\t}\n\n\tconstexpr mint& operator-=(mint rhs) {\n\
    \t\tif (_v < rhs._v) _v += m;\n\t\t_v -= rhs._v;\n\t\treturn *this;\n\t}\n\n\t\
    constexpr mint& operator*=(mint rhs) { return *this = *this * rhs; }\n\n\tconstexpr\
    \ mint& operator/=(mint rhs) { return *this *= rhs.inv(); }\n\n\tconstexpr mint\
    \ operator+() const { return *this; }\n\n\tconstexpr mint operator-() const {\
    \ return mint{} - *this; }\n\n\tconstexpr mint pow(long long n) const {\n\t\t\
    assert(0 <= n);\n\t\tif (n == 0) return 1;\n\t\tmint x = *this, r = 1;\n\t\twhile\
    \ (n > 0) {\n\t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t\tif\
    \ (!n) return r;\n\t\t}\n\t\treturn r;\n\t}\n\n\tconstexpr mint inv() const {\n\
    \t\tif constexpr (is_prime) {\n\t\t\tassert(_v);\n\t\t\treturn pow(m - 2);\n\t\
    \t}\n\t\telse {\n\t\t\tauto eg = inv_gcd(_v, m);\n\t\t\tassert(eg.first == 1);\n\
    \t\t\treturn eg.second;\n\t\t}\n\t}\n\n\tfriend constexpr mint operator+(mint\
    \ lhs, mint rhs) { return lhs += rhs; }\n\n\tfriend constexpr mint operator-(mint\
    \ lhs, mint rhs) { return lhs -= rhs; }\n\n\tfriend constexpr mint operator*(mint\
    \ lhs, mint rhs) { return uint64_t(lhs._v) * rhs._v; }\n\t\n\tfriend constexpr\
    \ mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }\n\n\tfriend constexpr\
    \ bool operator==(mint lhs, mint rhs) { return lhs._v == rhs._v; }\n\n\tfriend\
    \ constexpr bool operator!=(mint lhs, mint rhs) { return lhs._v != rhs._v; }\n\
    };\n\nusing Modint998244353 = StaticModint<998244353>;\n\nconstexpr Modint998244353\
    \ operator\"\"_M(unsigned long long x) { return x; }\n};\n"
  code: "#pragma once\n\n#include <cstdint>\n#include <utility>\n#include <type_traits>\n\
    #include <cassert>\n\nnamespace cpstd {\n\n// Static Modint\n\n// https://hackmd.io/@tatyam-prime/rkVCOcwQn\n\
    \ntemplate <uint32_t m>\nstruct StaticModint {\n\tprivate:\n\tusing mint = StaticModint;\n\
    \tuint32_t _v = 0;\n\n\tstatic constexpr bool is_prime = []() -> bool {\n\t\t\
    if (m == 1) return false;\n\t\tif (m == 2 || m == 7 || m == 61) return true;\n\
    \t\tif (!(m & 1)) return false;\n\t\tuint32_t d = m - 1;\n\t\twhile (!(d & 1))\
    \ d >>= 1;\n\t\tfor (uint32_t a : {2, 7, 61}) {\n\t\t\tuint32_t t = d;\n\t\t\t\
    mint y = mint(a).pow(t);\n\t\t\twhile (t != m - 1 && y != 1 && y != m - 1) {\n\
    \t\t\t\ty *= y;\n\t\t\t\tt <<= 1;\n\t\t\t}\n\t\t\tif (y != m - 1 && !(t & 1))\
    \ return false;\n\t\t}\n\t\treturn true;\n\t}();\n\t\n\tstatic constexpr std::pair<int32_t,\
    \ int32_t> inv_gcd(int32_t a, int32_t b) {\n\t\tif (a == 0) return {b, 0};\n\t\
    \tint32_t s = b, t = a, m0 = 0, m1 = 1;\n\t\twhile (t) {\n\t\t\tconst int32_t\
    \ q = s / t;\n\t\t\ts -= t * q, std::swap(s, t);\n\t\t\tm0 -= m1 * q, std::swap(m0,\
    \ m1);\n\t\t}\n\t\tif (m0 < 0) m0 += b / s;\n\t\treturn {s, m0};\n\t}\n\n\tpublic:\n\
    \tconstexpr StaticModint() {}\n\ttemplate <typename T>\n\tconstexpr StaticModint(T\
    \ v) {\n\t\tstatic_assert(std::is_integral_v<T>, \"T is not integral type.\");\n\
    \t\tif constexpr (std::is_signed_v<T>) {\n\t\t\tint64_t x = int64_t(v % int64_t(m));\n\
    \t\t\tif (x < 0) x += m;\n\t\t\t_v = uint32_t(x);\n\t\t}\n\t\telse _v = uint32_t(v\
    \ % m);\n\t}\n\n\tstatic constexpr mint raw(uint32_t v) { mint a; a._v = v; return\
    \ a; }\n\n\tstatic constexpr uint32_t mod() { return m; }\n\n\tconstexpr uint32_t\
    \ val() const { return _v; }\n\n\tconstexpr mint& operator++() { return *this\
    \ += 1; }\n\n\tconstexpr mint operator++(int) { mint res = *this; ++*this; return\
    \ res; }\n\n\tconstexpr mint& operator--() { return *this -= 1; }\n\n\tconstexpr\
    \ mint operator--(int) { mint res = *this; --*this; return res; }\n\n\tconstexpr\
    \ mint& operator+=(mint rhs) {\n\t\tif (_v >= m - rhs._v) _v -= m;\n\t\t_v +=\
    \ rhs._v;\n\t\treturn *this;\n\t}\n\n\tconstexpr mint& operator-=(mint rhs) {\n\
    \t\tif (_v < rhs._v) _v += m;\n\t\t_v -= rhs._v;\n\t\treturn *this;\n\t}\n\n\t\
    constexpr mint& operator*=(mint rhs) { return *this = *this * rhs; }\n\n\tconstexpr\
    \ mint& operator/=(mint rhs) { return *this *= rhs.inv(); }\n\n\tconstexpr mint\
    \ operator+() const { return *this; }\n\n\tconstexpr mint operator-() const {\
    \ return mint{} - *this; }\n\n\tconstexpr mint pow(long long n) const {\n\t\t\
    assert(0 <= n);\n\t\tif (n == 0) return 1;\n\t\tmint x = *this, r = 1;\n\t\twhile\
    \ (n > 0) {\n\t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t\tif\
    \ (!n) return r;\n\t\t}\n\t\treturn r;\n\t}\n\n\tconstexpr mint inv() const {\n\
    \t\tif constexpr (is_prime) {\n\t\t\tassert(_v);\n\t\t\treturn pow(m - 2);\n\t\
    \t}\n\t\telse {\n\t\t\tauto eg = inv_gcd(_v, m);\n\t\t\tassert(eg.first == 1);\n\
    \t\t\treturn eg.second;\n\t\t}\n\t}\n\n\tfriend constexpr mint operator+(mint\
    \ lhs, mint rhs) { return lhs += rhs; }\n\n\tfriend constexpr mint operator-(mint\
    \ lhs, mint rhs) { return lhs -= rhs; }\n\n\tfriend constexpr mint operator*(mint\
    \ lhs, mint rhs) { return uint64_t(lhs._v) * rhs._v; }\n\t\n\tfriend constexpr\
    \ mint operator/(mint lhs, mint rhs) { return lhs /= rhs; }\n\n\tfriend constexpr\
    \ bool operator==(mint lhs, mint rhs) { return lhs._v == rhs._v; }\n\n\tfriend\
    \ constexpr bool operator!=(mint lhs, mint rhs) { return lhs._v != rhs._v; }\n\
    };\n\nusing Modint998244353 = StaticModint<998244353>;\n\nconstexpr Modint998244353\
    \ operator\"\"_M(unsigned long long x) { return x; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/math/StaticModint.hpp
  requiredBy:
  - cpstl/other/Fastio.hpp
  - cpstl/other/Template.hpp
  - cpstl/ds/Segtree.hpp
  timestamp: '2025-07-30 22:35:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/other/lc-Many-A+B-128bit-Fastio.test.cpp
  - verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
  - verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
  - verify/ds/lc-Union-Find-Dsu.test.cpp
  - verify/ds/lc-Point-Add-Range-Sum-Segtree.test.cpp
  - verify/ds/yuki-0875-Segtree.test.cpp
documentation_of: cpstl/math/StaticModint.hpp
layout: document
title: Static Modint
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
