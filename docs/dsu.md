---
title: Disjoint Set Union
documentation_of: //cpstl/ds/dsu.hpp
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
