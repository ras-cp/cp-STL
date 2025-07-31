---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
    title: verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"cpstl/ds/LazySegtree.hpp\"\n\n#include <vector>\n#include\
    \ <cassert>\n#include <bit>\n\nnamespace cpstd {\n\n// Lazy Segment Tree\n\ntemplate\
    \ <\n\ttypename S,\n\tauto op,\n\tauto e,\n\ttypename F,\n\tauto mapping,\n\t\
    auto composition,\n\tauto id\n>\nclass LazySegtree {\n\tprivate:\n\tstd::vector<S>\
    \ dat;\n\tstd::vector<F> lazy;\n\tint N, sz, log;\n\n\tvoid propagate(int pos,\
    \ const F &f) {\n\t\tdat[pos] = mapping(f, dat[pos]);\n\t\tif (pos < sz) lazy[pos]\
    \ = composition(f, lazy[pos]);\n\t}\n\n\tvoid pushdown(int pos) {\n\t\tif (lazy[pos]\
    \ == id()) return;\n\t\tpropagate(pos << 1, lazy[pos]);\n\t\tpropagate(pos <<\
    \ 1 | 1, lazy[pos]);\n\t\tlazy[pos] = id();\n\t}\n\n\tvoid pushup(int pos) { dat[pos]\
    \ = op(dat[pos << 1], dat[pos << 1 | 1]); }\n\n\tpublic:\n\tLazySegtree() {}\n\
    \texplicit LazySegtree(int n) : LazySegtree(std::vector<S>(n, e())) {}\n\texplicit\
    \ LazySegtree(int n, const S &init) : LazySegtree(std::vector<S>(n, init)) {}\n\
    \texplicit LazySegtree(const std::vector<S> &v) : N((int)v.size()) {\n\t\tsz =\
    \ std::bit_ceil((unsigned int)(N));\n\t\tlog = std::bit_width((unsigned int)(sz)\
    \ - 1);\n\t\tdat.assign(sz << 1, e());\n\t\tlazy.assign(sz << 1, id());\n\t\t\
    for (int i = 0; i < N; ++i) dat[i + sz] = v[i];\n\t\tfor (int i = sz - 1; i >=\
    \ 1; --i) pushup(i);\n\t}\n\ttemplate <class InputIt>\n\tLazySegtree(InputIt first,\
    \ InputIt last) : LazySegtree(std::vector<S>(first, last)) {}\n\n\t// A[pos] \u2190\
    \ x \u3067\u66F4\u65B0\n\t// O(logN) time\n\tvoid set(int pos, const S &x) {\n\
    \t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tfor (int i = log; i >= 1;\
    \ --i) pushdown(pos >> i);\n\t\tdat[pos] = x;\n\t\tfor (pos >>= 1; pos >= 1; pos\
    \ >>= 1) pushup(pos);\n\t}\n\n\t// A[pos] \u2190 A[pos] + x \u3067\u66F4\u65B0\
    \n\t// O(logN) time\n\tvoid add(int pos, const S &x) {\n\t\tassert(0 <= pos &&\
    \ pos < N);\n\t\tpos += sz;\n\t\tfor (int i = log; i >= 1; --i) pushdown(pos >>\
    \ i);\n\t\tdat[pos] += x;\n\t\tfor (pos >>= 1; pos >= 1; pos >>= 1) pushup(pos);\n\
    \t}\n\n\t// A[pos] \u2190 mapping(f, A[pos]) \u3067\u66F4\u65B0\n\t// O(logN)\
    \ time\n\tvoid apply(int pos, const F &f) {\n\t\tassert(0 <= pos && pos < N);\n\
    \t\tpos += sz;\n\t\tfor (int i = log; i >= 1; --i) pushdown(pos >> i);\n\t\tdat[pos]\
    \ = mapping(f, dat[pos]);\n\t\tfor (pos >>= 1; pos >= 1; pos >>= 1) pushup(pos);\n\
    \t}\n\n\t// A[l, r) \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B\n\t// O(logN)\
    \ time\n\tvoid apply(int l, int r, const F &f) {\n\t\tassert(0 <= l && l <= r\
    \ && r <= N);\n\t\tif (l == r) return;\n\t\tl += sz, r += sz;\n\t\tfor (int i\
    \ = log; i >= 1; --i) {\n\t\t\tif (((l >> i) << i) != l) pushdown(l >> i);\n\t\
    \t\tif (((r >> i) << i) != r) pushdown((r - 1) >> i);\n\t\t}\n\t\tfor (int l2\
    \ = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {\n\t\t\tif (l2 & 1) propagate(l2++,\
    \ f);\n\t\t\tif (r2 & 1) propagate(--r2, f);\n\t\t}\n\t\tfor (int i = 1; i <=\
    \ log; ++i) {\n\t\t\tif (((l >> i) << i) != l) pushup(l >> i);\n\t\t\tif (((r\
    \ >> i) << i) != r) pushup((r - 1) >> i);\n\t\t}\n\t}\n\n\t// A[pos] \u3092\u8FD4\
    \u3059\n\t// O(logN) time\n\tS& get(int pos) {\n\t\tassert(0 <= pos && pos < N);\n\
    \t\tpos += sz;\n\t\tfor (int i = log; i >= 1; --i) pushdown(pos >> i);\n\t\treturn\
    \ dat[pos];\n\t}\n\n\t// A[pos] \u3092\u8FD4\u3059 (assert \u306A\u3057)\n\t//\
    \ O(logN) time\n\tS& operator[](int pos) noexcept {\n\t\tpos += sz;\n\t\tfor (int\
    \ i = log; i >= 1; --i) pushdown(pos >> i);\n\t\treturn dat[pos];\n\t}\n\n\t//\
    \ op[l, r) \u3092\u8FD4\u3059\n\t// O(logN) time\n\tS fold(int l, int r) {\n\t\
    \tassert(0 <= l && l <= r && r <= N);\n\t\tif (l == r) return e();\n\t\tl += sz,\
    \ r += sz;\n\t\tfor (int i = log; i >= 1; --i) {\n\t\t\tif (((l >> i) << i) !=\
    \ l) pushdown(l >> i);\n\t\t\tif (((r >> i) << i) != r) pushdown((r - 1) >> i);\n\
    \t\t}\n\t\tS resl = e(), resr = e();\n\t\tfor (; l < r; l >>= 1, r >>= 1) {\n\t\
    \t\tif (l & 1) resl = op(resl, dat[l++]);\n\t\t\tif (r & 1) resr = op(dat[--r],\
    \ resr);\n\t\t}\n\t\treturn op(resl, resr);\n\t}\n\n\t// op[1, N] \u3092\u8FD4\
    \u3059\n\t// O(1) time\n\tS all_fold() const { return dat[1]; }\n\n\t// `r = l`\
    \ \u307E\u305F\u306F `g(op[l, r)) = true`\n\t// `r = n` \u307E\u305F\u306F `g(op[l,\
    \ r]) = false`\n\t// \u3053\u308C\u3089\u3092\u4E21\u65B9\u6E80\u305F\u3059 `r`\
    \ \u3092\u8FD4\u3059 (`g` \u304C\u5358\u8ABF\u306A\u3089 `g(op[l, r)) = true`\
    \ \u3068\u306A\u308B\u6700\u5927\u306E `r`)\n\t// O(logN) time\n\ttemplate <auto\
    \ g>\n\tint max_right(int l) {\n\t\treturn max_right(l, [](const S& x) -> bool\
    \ { return g(x); });\n\t}\n\ttemplate <typename G>\n\tint max_right(int l, const\
    \ G& g) {\n\t\tassert(0 <= l && l <= N);\n\t\tassert(g(e()));\n\t\tif (l == N)\
    \ return N;\n\t\tl += sz;\n\t\tfor (int i = log; i >= 1; --i) pushdown(l >> i);\n\
    \t\tS s = e();\n\t\tdo {\n\t\t\twhile (!(l & 1)) l >>= 1;\n\t\t\tif (!g(op(s,\
    \ dat[l]))) {\n\t\t\t\twhile (l < sz) {\n\t\t\t\t\tpushdown(l);\n\t\t\t\t\tl <<=\
    \ 1;\n\t\t\t\t\tif (g(op(s, dat[l]))) s = op(s, dat[l++]);\n\t\t\t\t}\n\t\t\t\t\
    return l - sz;\n\t\t\t}\n\t\t\ts = op(s, dat[l++]);\n\t\t} while ((l & -l) !=\
    \ l);\n\t\treturn N;\n\t}\n\n\t// `l = r` \u307E\u305F\u306F `g(op[l, r)) = true`\n\
    \t// `l = 0` \u307E\u305F\u306F `g(op[l - 1, r)) = false`\n\t// \u3053\u308C\u3089\
    \u3092\u4E21\u65B9\u6E80\u305F\u3059 `l` \u3092\u8FD4\u3059 (`g` \u304C\u5358\u8ABF\
    \u306A\u3089 `g(op[l, r)) = true` \u3068\u306A\u308B\u6700\u5C0F\u306E `l`)\n\t\
    // O(logN) time\n\ttemplate <auto g>\n\tint min_left(int r) {\n\t\treturn min_left(r,\
    \ [](const S& x) -> bool { return g(x); });\n\t}\n\ttemplate <typename G>\n\t\
    int min_left(int r, const G& g) {\n\t\tassert(0 <= r && r <= N);\n\t\tassert(g(e()));\n\
    \t\tif (r == 0) return 0;\n\t\tr += sz;\n\t\tfor (int i = log; i >= 1; --i) pushdown((r\
    \ - 1) >> i);\n\t\tS s = e();\n\t\tdo {\n\t\t\t--r;\n\t\t\twhile (r > 1 && (r\
    \ & 1)) r >>= 1;\n\t\t\tif (!g(op(dat[r], s))) {\n\t\t\t\twhile (r < sz) {\n\t\
    \t\t\t\tpushdown(r);\n\t\t\t\t\tr = r << 1 | 1;\n\t\t\t\t\tif (g(op(dat[r], s)))\
    \ s = op(dat[r--], s);\n\t\t\t\t}\n\t\t\t\treturn r + 1 - sz;\n\t\t\t}\n\t\t\t\
    s = op(dat[r], s);\n\t\t} while ((r & -r) != r);\n\t\treturn 0;\n\t}\n};\n};\n"
  code: "#pragma once\n\n#include <vector>\n#include <cassert>\n#include <bit>\n\n\
    namespace cpstd {\n\n// Lazy Segment Tree\n\ntemplate <\n\ttypename S,\n\tauto\
    \ op,\n\tauto e,\n\ttypename F,\n\tauto mapping,\n\tauto composition,\n\tauto\
    \ id\n>\nclass LazySegtree {\n\tprivate:\n\tstd::vector<S> dat;\n\tstd::vector<F>\
    \ lazy;\n\tint N, sz, log;\n\n\tvoid propagate(int pos, const F &f) {\n\t\tdat[pos]\
    \ = mapping(f, dat[pos]);\n\t\tif (pos < sz) lazy[pos] = composition(f, lazy[pos]);\n\
    \t}\n\n\tvoid pushdown(int pos) {\n\t\tif (lazy[pos] == id()) return;\n\t\tpropagate(pos\
    \ << 1, lazy[pos]);\n\t\tpropagate(pos << 1 | 1, lazy[pos]);\n\t\tlazy[pos] =\
    \ id();\n\t}\n\n\tvoid pushup(int pos) { dat[pos] = op(dat[pos << 1], dat[pos\
    \ << 1 | 1]); }\n\n\tpublic:\n\tLazySegtree() {}\n\texplicit LazySegtree(int n)\
    \ : LazySegtree(std::vector<S>(n, e())) {}\n\texplicit LazySegtree(int n, const\
    \ S &init) : LazySegtree(std::vector<S>(n, init)) {}\n\texplicit LazySegtree(const\
    \ std::vector<S> &v) : N((int)v.size()) {\n\t\tsz = std::bit_ceil((unsigned int)(N));\n\
    \t\tlog = std::bit_width((unsigned int)(sz) - 1);\n\t\tdat.assign(sz << 1, e());\n\
    \t\tlazy.assign(sz << 1, id());\n\t\tfor (int i = 0; i < N; ++i) dat[i + sz] =\
    \ v[i];\n\t\tfor (int i = sz - 1; i >= 1; --i) pushup(i);\n\t}\n\ttemplate <class\
    \ InputIt>\n\tLazySegtree(InputIt first, InputIt last) : LazySegtree(std::vector<S>(first,\
    \ last)) {}\n\n\t// A[pos] \u2190 x \u3067\u66F4\u65B0\n\t// O(logN) time\n\t\
    void set(int pos, const S &x) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos +=\
    \ sz;\n\t\tfor (int i = log; i >= 1; --i) pushdown(pos >> i);\n\t\tdat[pos] =\
    \ x;\n\t\tfor (pos >>= 1; pos >= 1; pos >>= 1) pushup(pos);\n\t}\n\n\t// A[pos]\
    \ \u2190 A[pos] + x \u3067\u66F4\u65B0\n\t// O(logN) time\n\tvoid add(int pos,\
    \ const S &x) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tfor (int\
    \ i = log; i >= 1; --i) pushdown(pos >> i);\n\t\tdat[pos] += x;\n\t\tfor (pos\
    \ >>= 1; pos >= 1; pos >>= 1) pushup(pos);\n\t}\n\n\t// A[pos] \u2190 mapping(f,\
    \ A[pos]) \u3067\u66F4\u65B0\n\t// O(logN) time\n\tvoid apply(int pos, const F\
    \ &f) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tfor (int i = log;\
    \ i >= 1; --i) pushdown(pos >> i);\n\t\tdat[pos] = mapping(f, dat[pos]);\n\t\t\
    for (pos >>= 1; pos >= 1; pos >>= 1) pushup(pos);\n\t}\n\n\t// A[l, r) \u306B\
    \ f \u3092\u4F5C\u7528\u3055\u305B\u308B\n\t// O(logN) time\n\tvoid apply(int\
    \ l, int r, const F &f) {\n\t\tassert(0 <= l && l <= r && r <= N);\n\t\tif (l\
    \ == r) return;\n\t\tl += sz, r += sz;\n\t\tfor (int i = log; i >= 1; --i) {\n\
    \t\t\tif (((l >> i) << i) != l) pushdown(l >> i);\n\t\t\tif (((r >> i) << i) !=\
    \ r) pushdown((r - 1) >> i);\n\t\t}\n\t\tfor (int l2 = l, r2 = r; l2 < r2; l2\
    \ >>= 1, r2 >>= 1) {\n\t\t\tif (l2 & 1) propagate(l2++, f);\n\t\t\tif (r2 & 1)\
    \ propagate(--r2, f);\n\t\t}\n\t\tfor (int i = 1; i <= log; ++i) {\n\t\t\tif (((l\
    \ >> i) << i) != l) pushup(l >> i);\n\t\t\tif (((r >> i) << i) != r) pushup((r\
    \ - 1) >> i);\n\t\t}\n\t}\n\n\t// A[pos] \u3092\u8FD4\u3059\n\t// O(logN) time\n\
    \tS& get(int pos) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tfor\
    \ (int i = log; i >= 1; --i) pushdown(pos >> i);\n\t\treturn dat[pos];\n\t}\n\n\
    \t// A[pos] \u3092\u8FD4\u3059 (assert \u306A\u3057)\n\t// O(logN) time\n\tS&\
    \ operator[](int pos) noexcept {\n\t\tpos += sz;\n\t\tfor (int i = log; i >= 1;\
    \ --i) pushdown(pos >> i);\n\t\treturn dat[pos];\n\t}\n\n\t// op[l, r) \u3092\u8FD4\
    \u3059\n\t// O(logN) time\n\tS fold(int l, int r) {\n\t\tassert(0 <= l && l <=\
    \ r && r <= N);\n\t\tif (l == r) return e();\n\t\tl += sz, r += sz;\n\t\tfor (int\
    \ i = log; i >= 1; --i) {\n\t\t\tif (((l >> i) << i) != l) pushdown(l >> i);\n\
    \t\t\tif (((r >> i) << i) != r) pushdown((r - 1) >> i);\n\t\t}\n\t\tS resl = e(),\
    \ resr = e();\n\t\tfor (; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) resl =\
    \ op(resl, dat[l++]);\n\t\t\tif (r & 1) resr = op(dat[--r], resr);\n\t\t}\n\t\t\
    return op(resl, resr);\n\t}\n\n\t// op[1, N] \u3092\u8FD4\u3059\n\t// O(1) time\n\
    \tS all_fold() const { return dat[1]; }\n\n\t// `r = l` \u307E\u305F\u306F `g(op[l,\
    \ r)) = true`\n\t// `r = n` \u307E\u305F\u306F `g(op[l, r]) = false`\n\t// \u3053\
    \u308C\u3089\u3092\u4E21\u65B9\u6E80\u305F\u3059 `r` \u3092\u8FD4\u3059 (`g` \u304C\
    \u5358\u8ABF\u306A\u3089 `g(op[l, r)) = true` \u3068\u306A\u308B\u6700\u5927\u306E\
    \ `r`)\n\t// O(logN) time\n\ttemplate <auto g>\n\tint max_right(int l) {\n\t\t\
    return max_right(l, [](const S& x) -> bool { return g(x); });\n\t}\n\ttemplate\
    \ <typename G>\n\tint max_right(int l, const G& g) {\n\t\tassert(0 <= l && l <=\
    \ N);\n\t\tassert(g(e()));\n\t\tif (l == N) return N;\n\t\tl += sz;\n\t\tfor (int\
    \ i = log; i >= 1; --i) pushdown(l >> i);\n\t\tS s = e();\n\t\tdo {\n\t\t\twhile\
    \ (!(l & 1)) l >>= 1;\n\t\t\tif (!g(op(s, dat[l]))) {\n\t\t\t\twhile (l < sz)\
    \ {\n\t\t\t\t\tpushdown(l);\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif (g(op(s, dat[l])))\
    \ s = op(s, dat[l++]);\n\t\t\t\t}\n\t\t\t\treturn l - sz;\n\t\t\t}\n\t\t\ts =\
    \ op(s, dat[l++]);\n\t\t} while ((l & -l) != l);\n\t\treturn N;\n\t}\n\n\t// `l\
    \ = r` \u307E\u305F\u306F `g(op[l, r)) = true`\n\t// `l = 0` \u307E\u305F\u306F\
    \ `g(op[l - 1, r)) = false`\n\t// \u3053\u308C\u3089\u3092\u4E21\u65B9\u6E80\u305F\
    \u3059 `l` \u3092\u8FD4\u3059 (`g` \u304C\u5358\u8ABF\u306A\u3089 `g(op[l, r))\
    \ = true` \u3068\u306A\u308B\u6700\u5C0F\u306E `l`)\n\t// O(logN) time\n\ttemplate\
    \ <auto g>\n\tint min_left(int r) {\n\t\treturn min_left(r, [](const S& x) ->\
    \ bool { return g(x); });\n\t}\n\ttemplate <typename G>\n\tint min_left(int r,\
    \ const G& g) {\n\t\tassert(0 <= r && r <= N);\n\t\tassert(g(e()));\n\t\tif (r\
    \ == 0) return 0;\n\t\tr += sz;\n\t\tfor (int i = log; i >= 1; --i) pushdown((r\
    \ - 1) >> i);\n\t\tS s = e();\n\t\tdo {\n\t\t\t--r;\n\t\t\twhile (r > 1 && (r\
    \ & 1)) r >>= 1;\n\t\t\tif (!g(op(dat[r], s))) {\n\t\t\t\twhile (r < sz) {\n\t\
    \t\t\t\tpushdown(r);\n\t\t\t\t\tr = r << 1 | 1;\n\t\t\t\t\tif (g(op(dat[r], s)))\
    \ s = op(dat[r--], s);\n\t\t\t\t}\n\t\t\t\treturn r + 1 - sz;\n\t\t\t}\n\t\t\t\
    s = op(dat[r], s);\n\t\t} while ((r & -r) != r);\n\t\treturn 0;\n\t}\n};\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/ds/LazySegtree.hpp
  requiredBy: []
  timestamp: '2025-08-01 01:53:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
documentation_of: cpstl/ds/LazySegtree.hpp
layout: document
redirect_from:
- /library/cpstl/ds/LazySegtree.hpp
- /library/cpstl/ds/LazySegtree.hpp.html
title: cpstl/ds/LazySegtree.hpp
---
