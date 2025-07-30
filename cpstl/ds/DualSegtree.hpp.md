---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpstl/ds/DualSegtree.hpp
layout: document
redirect_from:
- /library/cpstl/ds/DualSegtree.hpp
- /library/cpstl/ds/DualSegtree.hpp.html
title: cpstl/ds/DualSegtree.hpp
---
