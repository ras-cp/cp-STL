---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/lc-Union-Find-Dsu.test.cpp
    title: verify/ds/lc-Union-Find-Dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"cpstl/ds/Dsu.hpp\"\n\n#include <vector>\n\nnamespace cpstd\
    \ {\n\n// Disjoint Set Union\n// union by size + path compression\n\nclass Dsu\
    \ {\n\tprivate:\n\tint _n;\n\tstd::vector<int> tree;\n\n\tint _leader(int x) {\n\
    \t\treturn tree[x] < 0 ? x : tree[x] = _leader(tree[x]);\n\t}\n\n\tpublic:\n\t\
    Dsu() {}\n\texplicit Dsu(int n) : _n(n), tree(n, -1) {}\n\n\t// `x` \u306E\u5C5E\
    \u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\n\t// amortized\
    \ O(\u03B1(N)) time\n\tint leader(int x) {\n\t\tassert(0 <= x && x < _n);\n\t\t\
    return tree[x] ? x : _leader(tree[x]);\n\t}\n\n\t// `a`, `b` \u306E\u5C5E\u3059\
    \u308B\u96C6\u5408\u3092\u4F75\u5408\u3057\uFF0C\u5143\u3005\u7570\u306A\u308B\
    \u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u305F\u304B\u3092\u8FD4\u3059\n\t//\
    \ amortized O(\u03B1(N)) time\n\tbool merge(int a, int b) {\n\t\tassert(0 <= a\
    \ && a < _n);\n\t\tassert(0 <= b && b < _n);\n\t\ta = _leader(a), b = _leader(b);\n\
    \t\tif (a == b) return false;\n\t\tif (tree[a] > tree[b]) std::swap(a, b);\n\t\
    \ttree[a] += tree[b];\n\t\ttree[b] = a;\n\t\treturn true;\n\t}\n\n\t// `a` \u3068\
    \ `b` \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u8FD4\u3059\
    \n\t// amoritized O(\u03B1(N)) time\n\tbool same(int a, int b) {\n\t\tassert(0\
    \ <= a && a < _n);\n\t\tassert(0 <= b && b < _n);\n\t\treturn _leader(a) == _leader(b);\n\
    \t}\n\n\t// `x` \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\
    \u8FD4\u3059\n\t// amortized O(\u03B1(N)) time\n\tint size(int x) {\n\t\tassert(0\
    \ <= x && x < _n);\n\t\treturn -tree[_leader(x)];\n\t}\n\n\t// \u96C6\u5408\u3054\
    \u3068\u306B\u914D\u5217\u306B\u307E\u3068\u3081\u305F\u914D\u5217\u3092\u8FD4\
    \u3059\n\t// O(N\u03B1(N)) time\n\tstd::vector<std::vector<int>> groups() {\n\t\
    \tstd::vector<std::vector<int>> mem, res;\n\t\tfor (int i = 0; i < _n; ++i) mem[_leader(i)].push_back(i);\n\
    \t\tfor (int i = 0; i < _n; ++i) {\n\t\t\tif (!mem[i].empty()) res.emplace_back(mem[i]);\n\
    \t\t}\n\t\treturn res;\n\t}\n};\n};\n"
  code: "#pragma once\n\n#include <vector>\n\nnamespace cpstd {\n\n// Disjoint Set\
    \ Union\n// union by size + path compression\n\nclass Dsu {\n\tprivate:\n\tint\
    \ _n;\n\tstd::vector<int> tree;\n\n\tint _leader(int x) {\n\t\treturn tree[x]\
    \ < 0 ? x : tree[x] = _leader(tree[x]);\n\t}\n\n\tpublic:\n\tDsu() {}\n\texplicit\
    \ Dsu(int n) : _n(n), tree(n, -1) {}\n\n\t// `x` \u306E\u5C5E\u3059\u308B\u96C6\
    \u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\u3059\n\t// amortized O(\u03B1(N))\
    \ time\n\tint leader(int x) {\n\t\tassert(0 <= x && x < _n);\n\t\treturn tree[x]\
    \ ? x : _leader(tree[x]);\n\t}\n\n\t// `a`, `b` \u306E\u5C5E\u3059\u308B\u96C6\
    \u5408\u3092\u4F75\u5408\u3057\uFF0C\u5143\u3005\u7570\u306A\u308B\u96C6\u5408\
    \u306B\u5C5E\u3057\u3066\u3044\u305F\u304B\u3092\u8FD4\u3059\n\t// amortized O(\u03B1\
    (N)) time\n\tbool merge(int a, int b) {\n\t\tassert(0 <= a && a < _n);\n\t\tassert(0\
    \ <= b && b < _n);\n\t\ta = _leader(a), b = _leader(b);\n\t\tif (a == b) return\
    \ false;\n\t\tif (tree[a] > tree[b]) std::swap(a, b);\n\t\ttree[a] += tree[b];\n\
    \t\ttree[b] = a;\n\t\treturn true;\n\t}\n\n\t// `a` \u3068 `b` \u304C\u540C\u3058\
    \u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u8FD4\u3059\n\t// amoritized O(\u03B1\
    (N)) time\n\tbool same(int a, int b) {\n\t\tassert(0 <= a && a < _n);\n\t\tassert(0\
    \ <= b && b < _n);\n\t\treturn _leader(a) == _leader(b);\n\t}\n\n\t// `x` \u304C\
    \u5C5E\u3059\u308B\u96C6\u5408\u306E\u5927\u304D\u3055\u3092\u8FD4\u3059\n\t//\
    \ amortized O(\u03B1(N)) time\n\tint size(int x) {\n\t\tassert(0 <= x && x < _n);\n\
    \t\treturn -tree[_leader(x)];\n\t}\n\n\t// \u96C6\u5408\u3054\u3068\u306B\u914D\
    \u5217\u306B\u307E\u3068\u3081\u305F\u914D\u5217\u3092\u8FD4\u3059\n\t// O(N\u03B1\
    (N)) time\n\tstd::vector<std::vector<int>> groups() {\n\t\tstd::vector<std::vector<int>>\
    \ mem, res;\n\t\tfor (int i = 0; i < _n; ++i) mem[_leader(i)].push_back(i);\n\t\
    \tfor (int i = 0; i < _n; ++i) {\n\t\t\tif (!mem[i].empty()) res.emplace_back(mem[i]);\n\
    \t\t}\n\t\treturn res;\n\t}\n};\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/ds/Dsu.hpp
  requiredBy: []
  timestamp: '2025-07-27 21:21:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/lc-Union-Find-Dsu.test.cpp
documentation_of: cpstl/ds/Dsu.hpp
layout: document
title: Disjoint Set Union
---

## 概要
Disjoint Set Union (dsu) は集合族を管理するデータ構造．集合の併合 (merge) や指定した $2$ 要素が同じ集合に属するかの判定 (same) などが非常に高速に行える．

## 使い方
- `dsu(int N)`: 集合族を $\lbrace \lbrace 0 \rbrace, \lbrace 1 \rbrace, \dots, \lbrace N-1 \rbrace \rbrace$ で初期化する． $\Theta(N)$ time
- `int leader(int x)`: `x` の属する集合の代表元を返す．amoritzed  $\mathrm{O}(\alpha(N))$ time
- `bool merge(int a, int b)`: `a`, `b` の属する集合を併合し，元々異なる集合に属していたかを返す．amortized $\mathrm{O}(\alpha(N))$ time
- `bool same(int a, int b)`: `a` と `b` が同じ集合に属するか返す．amortized $\mathrm{O}(\alpha(N))$ time
- `int size(int x)`: `x` が属する集合の大きさを返す．amoritzed $\mathrm{O}(\alpha(N))$ time
- `std::vector<std::vector<int>> groups()`: 集合ごとに配列にまとめた配列を返す． $\mathrm{O}(N\alpha(N))$ time
