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
    // O(logN) time\n\ttemplate <auto f>\n\tint max_right(int l) const { return max_right(l,\
    \ [](const S& x) -> bool { return f(x); }); }\n\n\ttemplate <typename F>\n\tint\
    \ max_right(int l, const F& f) const {\n\t\tassert(0 <= l && l <= N);\n\t\tassert(f(e()));\n\
    \t\tif (l == N) return N;\n\t\tl += sz;\n\t\tS s = e();\n\t\tdo {\n\t\t\twhile\
    \ (!(l & 1)) l >>= 1;\n\t\t\tif (!f(op(s, dat[l]))) {\n\t\t\t\twhile (l < sz)\
    \ {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t\tif (f(op(s, dat[l]))) s = op(s, dat[l++]);\n\
    \t\t\t\t}\n\t\t\t\treturn l - sz;\n\t\t\t}\n\t\t\ts = op(s, dat[l++]);\n\t\t}\
    \ while ((l & -l) != l);\n\t\treturn N;\n\t}\n\n\t// `l = r` \u307E\u305F\u306F\
    \ `f(op[l, r)) = true`\n\t// `l = 0` \u307E\u305F\u306F `f(op[l - 1, r)) = false`\n\
    \t// \u3053\u308C\u3089\u3092\u4E21\u65B9\u6E80\u305F\u3059 `l` \u3092\u8FD4\u3059\
    \ (`f` \u304C\u5358\u8ABF\u306A\u3089 `f(op[l, r)) = true` \u3068\u306A\u308B\u6700\
    \u5C0F\u306E `l`)\n\t// O(logN) time\n\ttemplate <auto f>\n\tint min_left(int\
    \ r) const { return min_left(r, [](S x) -> bool { return f(x); }); }\n\n\ttemplate\
    \ <typename F>\n\tint min_left(int r, F f) const {\n\t\tassert(0 <= r && r <=\
    \ N);\n\t\tassert(f(e()));\n\t\tif (r == 0) return 0;\n\t\tr += sz;\n\t\tS s =\
    \ e();\n\t\tdo {\n\t\t\t--r;\n\t\t\twhile (r > 1 && (r & 1)) r >>= 1;\n\t\t\t\
    if (!f(op(dat[r], s))) {\n\t\t\t\twhile (r < sz) {\n\t\t\t\t\tr = r << 1 | 1;\n\
    \t\t\t\t\tif (f(op(dat[r], s))) s = op(dat[r--], s);\n\t\t\t\t}\n\t\t\t\treturn\
    \ r + 1 - sz;\n\t\t\t}\n\t\t\ts = op(dat[r], s);\n\t\t} while ((r & -r) != r);\n\
    \t\treturn 0;\n\t}\n};\n};\n"
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
    \ \u3068\u306A\u308B\u6700\u5927\u306E `r`)\n\t// O(logN) time\n\ttemplate <auto\
    \ f>\n\tint max_right(int l) const { return max_right(l, [](const S& x) -> bool\
    \ { return f(x); }); }\n\n\ttemplate <typename F>\n\tint max_right(int l, const\
    \ F& f) const {\n\t\tassert(0 <= l && l <= N);\n\t\tassert(f(e()));\n\t\tif (l\
    \ == N) return N;\n\t\tl += sz;\n\t\tS s = e();\n\t\tdo {\n\t\t\twhile (!(l &\
    \ 1)) l >>= 1;\n\t\t\tif (!f(op(s, dat[l]))) {\n\t\t\t\twhile (l < sz) {\n\t\t\
    \t\t\tl <<= 1;\n\t\t\t\t\tif (f(op(s, dat[l]))) s = op(s, dat[l++]);\n\t\t\t\t\
    }\n\t\t\t\treturn l - sz;\n\t\t\t}\n\t\t\ts = op(s, dat[l++]);\n\t\t} while ((l\
    \ & -l) != l);\n\t\treturn N;\n\t}\n\n\t// `l = r` \u307E\u305F\u306F `f(op[l,\
    \ r)) = true`\n\t// `l = 0` \u307E\u305F\u306F `f(op[l - 1, r)) = false`\n\t//\
    \ \u3053\u308C\u3089\u3092\u4E21\u65B9\u6E80\u305F\u3059 `l` \u3092\u8FD4\u3059\
    \ (`f` \u304C\u5358\u8ABF\u306A\u3089 `f(op[l, r)) = true` \u3068\u306A\u308B\u6700\
    \u5C0F\u306E `l`)\n\t// O(logN) time\n\ttemplate <auto f>\n\tint min_left(int\
    \ r) const { return min_left(r, [](S x) -> bool { return f(x); }); }\n\n\ttemplate\
    \ <typename F>\n\tint min_left(int r, F f) const {\n\t\tassert(0 <= r && r <=\
    \ N);\n\t\tassert(f(e()));\n\t\tif (r == 0) return 0;\n\t\tr += sz;\n\t\tS s =\
    \ e();\n\t\tdo {\n\t\t\t--r;\n\t\t\twhile (r > 1 && (r & 1)) r >>= 1;\n\t\t\t\
    if (!f(op(dat[r], s))) {\n\t\t\t\twhile (r < sz) {\n\t\t\t\t\tr = r << 1 | 1;\n\
    \t\t\t\t\tif (f(op(dat[r], s))) s = op(dat[r--], s);\n\t\t\t\t}\n\t\t\t\treturn\
    \ r + 1 - sz;\n\t\t\t}\n\t\t\ts = op(dat[r], s);\n\t\t} while ((r & -r) != r);\n\
    \t\treturn 0;\n\t}\n};\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/ds/Segtree.hpp
  requiredBy: []
  timestamp: '2025-07-27 21:31:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/yuki-0875-Segtree.test.cpp
  - verify/ds/lc-Point-Add-Range-Sum-Segtree.test.cpp
documentation_of: cpstl/ds/Segtree.hpp
layout: document
redirect_from:
- /library/cpstl/ds/Segtree.hpp
- /library/cpstl/ds/Segtree.hpp.html
title: cpstl/ds/Segtree.hpp
---
