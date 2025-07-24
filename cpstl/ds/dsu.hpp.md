---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/lc_dsu.test.cpp
    title: verify/ds/lc_dsu.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"cpstl/ds/dsu.hpp\"\nnamespace cpstd {\n\n// Disjoint Set\
    \ Union\n// union by size + path compression\n\nclass dsu {\n\tprivate:\n\tint\
    \ _n;\n\tstd::vector<int> tree;\n\n\tint _leader(int x) {\n\t\treturn tree[x]\
    \ < 0 ? x : tree[x] = _leader(tree[x]);\n\t}\n\n\tpublic:\n\tdsu() {}\n\texplicit\
    \ dsu(int n) : _n(n), tree(n, -1) {}\n\n\t// `x` \u306E\u5C5E\u3059\u308B\u96C6\
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
  code: "#pragma once\nnamespace cpstd {\n\n// Disjoint Set Union\n// union by size\
    \ + path compression\n\nclass dsu {\n\tprivate:\n\tint _n;\n\tstd::vector<int>\
    \ tree;\n\n\tint _leader(int x) {\n\t\treturn tree[x] < 0 ? x : tree[x] = _leader(tree[x]);\n\
    \t}\n\n\tpublic:\n\tdsu() {}\n\texplicit dsu(int n) : _n(n), tree(n, -1) {}\n\n\
    \t// `x` \u306E\u5C5E\u3059\u308B\u96C6\u5408\u306E\u4EE3\u8868\u5143\u3092\u8FD4\
    \u3059\n\t// amortized O(\u03B1(N)) time\n\tint leader(int x) {\n\t\tassert(0\
    \ <= x && x < _n);\n\t\treturn tree[x] ? x : _leader(tree[x]);\n\t}\n\n\t// `a`,\
    \ `b` \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\u3057\uFF0C\u5143\
    \u3005\u7570\u306A\u308B\u96C6\u5408\u306B\u5C5E\u3057\u3066\u3044\u305F\u304B\
    \u3092\u8FD4\u3059\n\t// amortized O(\u03B1(N)) time\n\tbool merge(int a, int\
    \ b) {\n\t\tassert(0 <= a && a < _n);\n\t\tassert(0 <= b && b < _n);\n\t\ta =\
    \ _leader(a), b = _leader(b);\n\t\tif (a == b) return false;\n\t\tif (tree[a]\
    \ > tree[b]) std::swap(a, b);\n\t\ttree[a] += tree[b];\n\t\ttree[b] = a;\n\t\t\
    return true;\n\t}\n\n\t// `a` \u3068 `b` \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\
    \u3059\u308B\u304B\u8FD4\u3059\n\t// amoritized O(\u03B1(N)) time\n\tbool same(int\
    \ a, int b) {\n\t\tassert(0 <= a && a < _n);\n\t\tassert(0 <= b && b < _n);\n\t\
    \treturn _leader(a) == _leader(b);\n\t}\n\n\t// `x` \u304C\u5C5E\u3059\u308B\u96C6\
    \u5408\u306E\u5927\u304D\u3055\u3092\u8FD4\u3059\n\t// amortized O(\u03B1(N))\
    \ time\n\tint size(int x) {\n\t\tassert(0 <= x && x < _n);\n\t\treturn -tree[_leader(x)];\n\
    \t}\n\n\t// \u96C6\u5408\u3054\u3068\u306B\u914D\u5217\u306B\u307E\u3068\u3081\
    \u305F\u914D\u5217\u3092\u8FD4\u3059\n\t// O(N\u03B1(N)) time\n\tstd::vector<std::vector<int>>\
    \ groups() {\n\t\tstd::vector<std::vector<int>> mem, res;\n\t\tfor (int i = 0;\
    \ i < _n; ++i) mem[_leader(i)].push_back(i);\n\t\tfor (int i = 0; i < _n; ++i)\
    \ {\n\t\t\tif (!mem[i].empty()) res.emplace_back(mem[i]);\n\t\t}\n\t\treturn res;\n\
    \t}\n};\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/ds/dsu.hpp
  requiredBy: []
  timestamp: '2025-07-25 01:14:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/lc_dsu.test.cpp
documentation_of: cpstl/ds/dsu.hpp
layout: document
redirect_from:
- /library/cpstl/ds/dsu.hpp
- /library/cpstl/ds/dsu.hpp.html
title: cpstl/ds/dsu.hpp
---
