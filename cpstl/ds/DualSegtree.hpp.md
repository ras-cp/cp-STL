---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
    title: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"cpstl/ds/DualSegtree.hpp\"\n\n#include <vector>\n#include\
    \ <bit>\n\nnamespace cpstd {\n\n// Dual Segment Tree\n\ntemplate <\n\ttypename\
    \ F,\n\tauto composition,\n\tauto id\n>\nclass DualSegtree {\n\tprivate:\n\tstd::vector<F>\
    \ lazy;\n\tint N, sz, log;\n\n\tvoid pushdown(int pos) {\n\t\tfor (int i = log;\
    \ i >= 1; --i) {\n\t\t\tint p = pos >> i;\n\t\t\tlazy[p << 1] = composition(lazy[p],\
    \ lazy[p << 1]);\n\t\t\tlazy[p << 1 | 1] = composition(lazy[p], lazy[p << 1 |\
    \ 1]);\n\t\t\tlazy[p] = id();\n\t\t}\n\t}\n\n\tpublic:\n\tDualSegtree() {}\n\t\
    explicit DualSegtree(int n) : N(n) {\n\t\tsz = std::bit_ceil((unsigned int)(N));\n\
    \t\tlog = std::bit_width((unsigned int)(sz)) - 1;\n\t\tlazy.assign(sz << 1, id());\n\
    \t}\n\n\t// A[pos] \u3078\u306E\u4F5C\u7528\u7D20\u3092 f \u306B\u3059\u308B\n\
    \t// O(logN) time\n\tvoid set(int pos, const F &f) {\n\t\tassert(0 <= pos && pos\
    \ < N);\n\t\tpos += sz;\n\t\tpushdown(pos);\n\t\tlazy[pos] = f;\n\t}\n\n\t// A[pos]\
    \ \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B\n\t// O(logN) time\n\tvoid apply(int\
    \ pos, const F &f) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tpushdown(pos);\n\
    \t\tlazy[pos] = composition(f, lazy[pos]);\n\t}\n\n\t// A[l, r) \u306B f \u3092\
    \u4F5C\u7528\u3055\u305B\u308B\n\t// O(logN) time\n\tvoid apply(int l, int r,\
    \ const F &f) {\n\t\tassert(0 <= l && l <= r && r <= N);\n\t\tif (l == r) return;\n\
    \t\tl += sz, r += sz;\n\t\tpushdown(l), pushdown(r - 1);\n\t\tfor (; l < r; l\
    \ >>= 1, r >>= 1) {\n\t\t\tif (l & 1) lazy[l] = composition(f, lazy[l]), ++l;\n\
    \t\t\tif (r & 1) --r, lazy[r] = composition(f, lazy[r]);\n\t\t}\n\t}\n\n\t// A[pos]\
    \ \u306E\u4F5C\u7528\u7D20\u3092\u8FD4\u3059\n\t// O(logN) time\n\tF get(int pos)\
    \ {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tpushdown(pos);\n\t\t\
    return lazy[pos];\n\t}\n\n\t// A[pos] \u306E\u4F5C\u7528\u7D20\u3092\u8FD4\u3059\
    \n\t// O(logN) time\n\tF operator[](int pos) noexcept {\n\t\tpos += sz;\n\t\t\
    pushdown(pos);\n\t\treturn lazy[pos];\n\t}\n};\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <bit>\n\nnamespace cpstd {\n\n\
    // Dual Segment Tree\n\ntemplate <\n\ttypename F,\n\tauto composition,\n\tauto\
    \ id\n>\nclass DualSegtree {\n\tprivate:\n\tstd::vector<F> lazy;\n\tint N, sz,\
    \ log;\n\n\tvoid pushdown(int pos) {\n\t\tfor (int i = log; i >= 1; --i) {\n\t\
    \t\tint p = pos >> i;\n\t\t\tlazy[p << 1] = composition(lazy[p], lazy[p << 1]);\n\
    \t\t\tlazy[p << 1 | 1] = composition(lazy[p], lazy[p << 1 | 1]);\n\t\t\tlazy[p]\
    \ = id();\n\t\t}\n\t}\n\n\tpublic:\n\tDualSegtree() {}\n\texplicit DualSegtree(int\
    \ n) : N(n) {\n\t\tsz = std::bit_ceil((unsigned int)(N));\n\t\tlog = std::bit_width((unsigned\
    \ int)(sz)) - 1;\n\t\tlazy.assign(sz << 1, id());\n\t}\n\n\t// A[pos] \u3078\u306E\
    \u4F5C\u7528\u7D20\u3092 f \u306B\u3059\u308B\n\t// O(logN) time\n\tvoid set(int\
    \ pos, const F &f) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tpushdown(pos);\n\
    \t\tlazy[pos] = f;\n\t}\n\n\t// A[pos] \u306B f \u3092\u4F5C\u7528\u3055\u305B\
    \u308B\n\t// O(logN) time\n\tvoid apply(int pos, const F &f) {\n\t\tassert(0 <=\
    \ pos && pos < N);\n\t\tpos += sz;\n\t\tpushdown(pos);\n\t\tlazy[pos] = composition(f,\
    \ lazy[pos]);\n\t}\n\n\t// A[l, r) \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B\
    \n\t// O(logN) time\n\tvoid apply(int l, int r, const F &f) {\n\t\tassert(0 <=\
    \ l && l <= r && r <= N);\n\t\tif (l == r) return;\n\t\tl += sz, r += sz;\n\t\t\
    pushdown(l), pushdown(r - 1);\n\t\tfor (; l < r; l >>= 1, r >>= 1) {\n\t\t\tif\
    \ (l & 1) lazy[l] = composition(f, lazy[l]), ++l;\n\t\t\tif (r & 1) --r, lazy[r]\
    \ = composition(f, lazy[r]);\n\t\t}\n\t}\n\n\t// A[pos] \u306E\u4F5C\u7528\u7D20\
    \u3092\u8FD4\u3059\n\t// O(logN) time\n\tF get(int pos) {\n\t\tassert(0 <= pos\
    \ && pos < N);\n\t\tpos += sz;\n\t\tpushdown(pos);\n\t\treturn lazy[pos];\n\t\
    }\n\n\t// A[pos] \u306E\u4F5C\u7528\u7D20\u3092\u8FD4\u3059\n\t// O(logN) time\n\
    \tF operator[](int pos) noexcept {\n\t\tpos += sz;\n\t\tpushdown(pos);\n\t\treturn\
    \ lazy[pos];\n\t}\n};\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/ds/DualSegtree.hpp
  requiredBy: []
  timestamp: '2025-07-30 01:48:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
documentation_of: cpstl/ds/DualSegtree.hpp
layout: document
title: Dual Segment Tree
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
