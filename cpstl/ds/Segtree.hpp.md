---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/lc-Point-Add-Range-Sum-Segtree.test.cpp
    title: verify/ds/lc-Point-Add-Range-Sum-Segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/yuki-0875-Segtree.test.cpp
    title: verify/ds/yuki-0875-Segtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"cpstl/ds/Segtree.hpp\"\n\n#include <vector>\n\nnamespace\
    \ cpstd {\n\n// Segment Tree\n\ntemplate <\n\ttypename S,\n\tauto op,\n\tauto\
    \ e\n>\nclass Segtree {\n\tprivate:\n\tstd::vector<S> dat;\n\tint N, sz;\n\n\t\
    public:\n\tSegtree() {}\n\texplicit Segtree(int n) : Segtree(std::vector<S>(n,\
    \ e())) {}\n\texplicit Segtree(int n, const S &init) : Segtree(std::vector<S>(n,\
    \ init)) {}\n\texplicit Segtree(const std::vector<S> &v) : N((int)v.size()) {\n\
    \t\tsz = 1;\n\t\twhile (sz < N) sz <<= 1;\n\t\tdat.assign(sz << 1, e());\n\t\t\
    for (int i = 0; i < N; ++i) dat[i + sz] = v[i];\n\t\tfor (int i = sz - 1; i >=\
    \ 1; --i) dat[i] = op(dat[i << 1], dat[i << 1 | 1]);\n\t}\n\ttemplate <class Inputit>\n\
    \tSegtree(Inputit first, Inputit last) : Segtree(std::vector<S>(first, last))\
    \ {}\n\n\t// A[pos] \u2190 x \u3067\u66F4\u65B0\n\t// O(logN) time\n\tvoid set(int\
    \ pos, const S &x) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tdat[pos]\
    \ = x;\n\t\twhile (pos > 1) {\n\t\t\tpos >>= 1;\n\t\t\tdat[pos] = op(dat[pos <<\
    \ 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\t// A[pos] \u2190 A[pos] + x \u3067\u66F4\
    \u65B0\n\t// O(logN) time\n\tvoid add(int pos, const S &x) {\n\t\tassert(0 <=\
    \ pos && pos < N);\n\t\tpos += sz;\n\t\tdat[pos] += x;\n\t\twhile (pos > 1) {\n\
    \t\t\tpos >>= 1;\n\t\t\tdat[pos] = op(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t\
    }\n\t}\n\n\t// A[pos] \u2190 mapping(f, A[pos]) \u3067\u66F4\u65B0\n\t// O(logN)\
    \ time\n\ttemplate <\n\t\ttypename F,\n\t\tauto mapping\n\t>\n\tvoid set(int pos,\
    \ const F &f) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tdat[pos]\
    \ = mapping(f, dat[pos]);\n\t\twhile (pos > 1) {\n\t\t\tpos >>= 1;\n\t\t\tdat[pos]\
    \ = op(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\t// A[pos] \u3092\u8FD4\
    \u3059\n\t// O(logN) time\n\tconst S& get(int pos) const {\n\t\tassert(0 <= pos\
    \ && pos < N);\n\t\treturn dat[pos + sz];\n\t}\n\n\t// A[pos] \u3092\u8FD4\u3059\
    \ (assert \u306A\u3057)\n\t// O(logN) time\n\tconst S& operator[](int pos) const\
    \ noexcept { return dat[pos + sz]; }\n\n\t// op[l, r) \u3092\u8FD4\u3059\n\t//\
    \ O(logN) time\n\tS fold(int l, int r) const {\n\t\tassert(0 <= l && l <= r &&\
    \ r <= N);\n\t\tif (l == r) return e();\n\t\tS resl = e(), resr = e();\n\t\tfor\
    \ (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) resl = op(resl,\
    \ dat[l++]);\n\t\t\tif (r & 1) resr = op(dat[--r], resr);\n\t\t}\n\t\treturn op(resl,\
    \ resr);\n\t}\n\n\t// op[1, N] \u3092\u8FD4\u3059\n\t// O(1) time\n\tS all_fold()\
    \ const { return dat[1]; }\n\n\t// `r = l` \u307E\u305F\u306F `f(op[l, r)) = true`\n\
    \t// `r = n` \u307E\u305F\u306F `f(op[l, r]) = false`\n\t// \u3053\u308C\u3089\
    \u3092\u4E21\u65B9\u6E80\u305F\u3059 `r` \u3092\u8FD4\u3059 (`f` \u304C\u5358\u8ABF\
    \u306A\u3089 `f(op[l, r)) = true` \u3068\u306A\u308B\u6700\u5927\u306E `r`)\n\t\
    // O(logN) time\n\ttemplate <typename F>\n\tint max_right(int l, const F& f) const\
    \ {\n\t\tassert(0 <= l && l <= N);\n\t\tassert(f(e()));\n\t\tif (l == N) return\
    \ N;\n\t\tl += sz;\n\t\tS s = e();\n\t\tdo {\n\t\t\twhile (!(l & 1)) l >>= 1;\n\
    \t\t\tif (!f(op(s, dat[l]))) {\n\t\t\t\twhile (l < sz) {\n\t\t\t\t\tl <<= 1;\n\
    \t\t\t\t\tif (f(op(s, dat[l]))) s = op(s, dat[l++]);\n\t\t\t\t}\n\t\t\t\treturn\
    \ l - sz;\n\t\t\t}\n\t\t\ts = op(s, dat[l++]);\n\t\t} while ((l & -l) != l);\n\
    \t\treturn N;\n\t}\n\n\t// `l = r` \u307E\u305F\u306F `f(op[l, r)) = true`\n\t\
    // `l = 0` \u307E\u305F\u306F `f(op[l - 1, r)) = false`\n\t// \u3053\u308C\u3089\
    \u3092\u4E21\u65B9\u6E80\u305F\u3059 `l` \u3092\u8FD4\u3059 (`f` \u304C\u5358\u8ABF\
    \u306A\u3089 `f(op[l, r)) = true` \u3068\u306A\u308B\u6700\u5C0F\u306E `l`)\n\t\
    // O(logN) time\n\ttemplate <typename F>\n\tint min_left(int r, const F &f) const\
    \ {\n\t\tassert(0 <= r && r <= N);\n\t\tassert(f(e()));\n\t\tif (r == 0) return\
    \ 0;\n\t\tr += sz;\n\t\tS s = e();\n\t\tdo {\n\t\t\t--r;\n\t\t\twhile (r > 1 &&\
    \ (r & 1)) r >>= 1;\n\t\t\tif (!f(op(dat[r], s))) {\n\t\t\t\twhile (r < sz) {\n\
    \t\t\t\t\tr = r << 1 | 1;\n\t\t\t\t\tif (f(op(dat[r], s))) s = op(dat[r--], s);\n\
    \t\t\t\t}\n\t\t\t\treturn r + 1 - sz;\n\t\t\t}\n\t\t\ts = op(dat[r], s);\n\t\t\
    } while ((r & -r) != r);\n\t\treturn 0;\n\t}\n};\n};\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace cpstd {\n\n// Segment Tree\n\
    \ntemplate <\n\ttypename S,\n\tauto op,\n\tauto e\n>\nclass Segtree {\n\tprivate:\n\
    \tstd::vector<S> dat;\n\tint N, sz;\n\n\tpublic:\n\tSegtree() {}\n\texplicit Segtree(int\
    \ n) : Segtree(std::vector<S>(n, e())) {}\n\texplicit Segtree(int n, const S &init)\
    \ : Segtree(std::vector<S>(n, init)) {}\n\texplicit Segtree(const std::vector<S>\
    \ &v) : N((int)v.size()) {\n\t\tsz = 1;\n\t\twhile (sz < N) sz <<= 1;\n\t\tdat.assign(sz\
    \ << 1, e());\n\t\tfor (int i = 0; i < N; ++i) dat[i + sz] = v[i];\n\t\tfor (int\
    \ i = sz - 1; i >= 1; --i) dat[i] = op(dat[i << 1], dat[i << 1 | 1]);\n\t}\n\t\
    template <class Inputit>\n\tSegtree(Inputit first, Inputit last) : Segtree(std::vector<S>(first,\
    \ last)) {}\n\n\t// A[pos] \u2190 x \u3067\u66F4\u65B0\n\t// O(logN) time\n\t\
    void set(int pos, const S &x) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos +=\
    \ sz;\n\t\tdat[pos] = x;\n\t\twhile (pos > 1) {\n\t\t\tpos >>= 1;\n\t\t\tdat[pos]\
    \ = op(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\t// A[pos] \u2190 A[pos]\
    \ + x \u3067\u66F4\u65B0\n\t// O(logN) time\n\tvoid add(int pos, const S &x) {\n\
    \t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tdat[pos] += x;\n\t\twhile\
    \ (pos > 1) {\n\t\t\tpos >>= 1;\n\t\t\tdat[pos] = op(dat[pos << 1], dat[pos <<\
    \ 1 | 1]);\n\t\t}\n\t}\n\n\t// A[pos] \u2190 mapping(f, A[pos]) \u3067\u66F4\u65B0\
    \n\t// O(logN) time\n\ttemplate <\n\t\ttypename F,\n\t\tauto mapping\n\t>\n\t\
    void set(int pos, const F &f) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos +=\
    \ sz;\n\t\tdat[pos] = mapping(f, dat[pos]);\n\t\twhile (pos > 1) {\n\t\t\tpos\
    \ >>= 1;\n\t\t\tdat[pos] = op(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\
    \n\t// A[pos] \u3092\u8FD4\u3059\n\t// O(logN) time\n\tconst S& get(int pos) const\
    \ {\n\t\tassert(0 <= pos && pos < N);\n\t\treturn dat[pos + sz];\n\t}\n\n\t//\
    \ A[pos] \u3092\u8FD4\u3059 (assert \u306A\u3057)\n\t// O(logN) time\n\tconst\
    \ S& operator[](int pos) const noexcept { return dat[pos + sz]; }\n\n\t// op[l,\
    \ r) \u3092\u8FD4\u3059\n\t// O(logN) time\n\tS fold(int l, int r) const {\n\t\
    \tassert(0 <= l && l <= r && r <= N);\n\t\tif (l == r) return e();\n\t\tS resl\
    \ = e(), resr = e();\n\t\tfor (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {\n\t\
    \t\tif (l & 1) resl = op(resl, dat[l++]);\n\t\t\tif (r & 1) resr = op(dat[--r],\
    \ resr);\n\t\t}\n\t\treturn op(resl, resr);\n\t}\n\n\t// op[1, N] \u3092\u8FD4\
    \u3059\n\t// O(1) time\n\tS all_fold() const { return dat[1]; }\n\n\t// `r = l`\
    \ \u307E\u305F\u306F `f(op[l, r)) = true`\n\t// `r = n` \u307E\u305F\u306F `f(op[l,\
    \ r]) = false`\n\t// \u3053\u308C\u3089\u3092\u4E21\u65B9\u6E80\u305F\u3059 `r`\
    \ \u3092\u8FD4\u3059 (`f` \u304C\u5358\u8ABF\u306A\u3089 `f(op[l, r)) = true`\
    \ \u3068\u306A\u308B\u6700\u5927\u306E `r`)\n\t// O(logN) time\n\ttemplate <typename\
    \ F>\n\tint max_right(int l, const F& f) const {\n\t\tassert(0 <= l && l <= N);\n\
    \t\tassert(f(e()));\n\t\tif (l == N) return N;\n\t\tl += sz;\n\t\tS s = e();\n\
    \t\tdo {\n\t\t\twhile (!(l & 1)) l >>= 1;\n\t\t\tif (!f(op(s, dat[l]))) {\n\t\t\
    \t\twhile (l < sz) {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif (f(op(s, dat[l]))) s =\
    \ op(s, dat[l++]);\n\t\t\t\t}\n\t\t\t\treturn l - sz;\n\t\t\t}\n\t\t\ts = op(s,\
    \ dat[l++]);\n\t\t} while ((l & -l) != l);\n\t\treturn N;\n\t}\n\n\t// `l = r`\
    \ \u307E\u305F\u306F `f(op[l, r)) = true`\n\t// `l = 0` \u307E\u305F\u306F `f(op[l\
    \ - 1, r)) = false`\n\t// \u3053\u308C\u3089\u3092\u4E21\u65B9\u6E80\u305F\u3059\
    \ `l` \u3092\u8FD4\u3059 (`f` \u304C\u5358\u8ABF\u306A\u3089 `f(op[l, r)) = true`\
    \ \u3068\u306A\u308B\u6700\u5C0F\u306E `l`)\n\t// O(logN) time\n\ttemplate <typename\
    \ F>\n\tint min_left(int r, const F &f) const {\n\t\tassert(0 <= r && r <= N);\n\
    \t\tassert(f(e()));\n\t\tif (r == 0) return 0;\n\t\tr += sz;\n\t\tS s = e();\n\
    \t\tdo {\n\t\t\t--r;\n\t\t\twhile (r > 1 && (r & 1)) r >>= 1;\n\t\t\tif (!f(op(dat[r],\
    \ s))) {\n\t\t\t\twhile (r < sz) {\n\t\t\t\t\tr = r << 1 | 1;\n\t\t\t\t\tif (f(op(dat[r],\
    \ s))) s = op(dat[r--], s);\n\t\t\t\t}\n\t\t\t\treturn r + 1 - sz;\n\t\t\t}\n\t\
    \t\ts = op(dat[r], s);\n\t\t} while ((r & -r) != r);\n\t\treturn 0;\n\t}\n};\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/ds/Segtree.hpp
  requiredBy: []
  timestamp: '2025-07-29 00:18:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/yuki-0875-Segtree.test.cpp
  - verify/ds/lc-Point-Add-Range-Sum-Segtree.test.cpp
documentation_of: cpstl/ds/Segtree.hpp
layout: document
title: Segment Tree
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
