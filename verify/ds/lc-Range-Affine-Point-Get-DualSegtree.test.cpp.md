---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: cpstl/ds/DualSegtree.hpp
    title: cpstl/ds/DualSegtree.hpp
  - icon: ':x:'
    path: cpstl/math/StaticModint.hpp
    title: cpstl/math/StaticModint.hpp
  - icon: ':question:'
    path: cpstl/other/Fastio.hpp
    title: Fast I/O
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_point_get
    links:
    - https://judge.yosupo.jp/problem/range_affine_point_get
  bundledCode: "#line 1 \"verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\n\
    \n#include <bits/stdc++.h>\n#line 2 \"cpstl/math/StaticModint.hpp\"\n\n#line 5\
    \ \"cpstl/math/StaticModint.hpp\"\n#include <type_traits>\n#line 7 \"cpstl/math/StaticModint.hpp\"\
    \n\nnamespace cpstd {\n\n// Static Modint\n\n// https://hackmd.io/@tatyam-prime/rkVCOcwQn\n\
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
    \ operator\"\"_M(unsigned long long x) { return x; }\n};\n#line 2 \"cpstl/other/Fastio.hpp\"\
    \nnamespace cpstd {\n\n// Fast I/O\n\n// https://judge.yosupo.jp/submission/21623\n\
    // https://maspypy.com/library-checker-many-a-b\n\nnamespace Fastio {\n\nstatic\
    \ constexpr const uint32_t BUF_SIZE = 1 << 17;\nchar ibuf[BUF_SIZE], obuf[BUF_SIZE],\
    \ out[100];\nuint32_t pil = 0, pir = 0, por = 0;\n\nstruct Pre {\n\tchar num[10000][4];\n\
    \n\tconstexpr Pre() : num() {\n\t\tfor (int i = 0; i < 10000; ++i) {\n\t\t\tint\
    \ n = i;\n\t\t\tfor (int j = 3; j >= 0; --j) {\n\t\t\t\tnum[i][j] = n % 10 | '0';\n\
    \t\t\t\tn /= 10;\n\t\t\t}\n\t\t}\n\t}\n} constexpr pre;\n\ninline void load()\
    \ {\n\tstd::memcpy(ibuf, ibuf + pil, pir - pil);\n\tpir = pir - pil + std::fread(ibuf\
    \ + pir - pil, 1, BUF_SIZE - pir + pil, stdin);\n\tpil = 0;\n\tif (pir < BUF_SIZE)\
    \ ibuf[pir++] = '\\n';\n}\n\ninline void flush() {\n\tfwrite(obuf, 1, por, stdout);\n\
    \tpor = 0;\n}\n\nvoid _input(char &dest) {\n\tdo {\n\t\tif (pil + 1 > pir) load();\n\
    \t\tdest = ibuf[pil++];\n\t} while (std::isspace(dest));\n}\n\nvoid _input(std::string\
    \ &dest) {\n\tdest.clear();\n\tchar c;\n\tdo {\n\t\tif (pil + 1 > pir) load();\n\
    \t\tc = ibuf[pil++];\n\t} while (std::isspace(c));\n\tdo {\n\t\tdest += c;\n\t\
    \tif (pil == pir) load();\n\t\tc = ibuf[pil++];\n\t} while (!std::isspace(c));\n\
    }\n\nvoid _input(float &dest) {\n\tstd::string s;\n\t_input(s);\n\tdest = std::stof(s);\n\
    }\n\nvoid _input(double &dest) {\n\tstd::string s;\n\t_input(s);\n\tdest = std::stod(s);\n\
    }\n\nvoid _input(long double &dest) {\n\tstd::string s;\n\t_input(s);\n\tdest\
    \ = std::stold(s);\n}\n\ntemplate <typename T>\nvoid input_int(T &x) {\n\tif (pil\
    \ + 100 > pir) load();\n\tchar c;\n\tdo {\n\t\tc = ibuf[pil++];\n\t} while (c\
    \ < '-');\n\tbool minus = 0;\n\tif constexpr (std::is_signed<T>::value || std::is_same_v<T,\
    \ __int128_t>) {\n\t\tif (c == '-') minus = 1, c = ibuf[pil++];\n\t}\n\tx = 0;\n\
    \twhile (c >= '0') x = x * 10 + (c & 15), c = ibuf[pil++];\n\tif constexpr (std::is_signed<T>::value\
    \ || std::is_same_v<T, __int128_t>) {\n\t\tif (minus) x = -x;\n\t}\n}\n\nvoid\
    \ _input(int &dest) { input_int(dest); }\nvoid _input(unsigned int &dest) { input_int(dest);\
    \ }\nvoid _input(long long &dest) { input_int(dest); }\nvoid _input(unsigned long\
    \ long &dest) { input_int(dest); }\nvoid _input(__int128 &dest) { input_int(dest);\
    \ }\nvoid _input(unsigned __int128 &dest) { input_int(dest); }\n\ntemplate <typename\
    \ T, typename U>\nvoid _input(std::pair<T, U> &dest) { return _input(dest.first),\
    \ _input(dest.second); }\n\ntemplate <std::size_t N = 0, typename T>\nvoid input_tuple(T\
    \ &t) {\n\tif constexpr (N < std::tuple_size<T>::value) {\n\t\tauto &x = std::get<N>(t);\n\
    \t\tinput(x);\n\t\tinput_tuple<N + 1>(t);\n\t}\n}\n\ntemplate <typename... T>\n\
    void _input(std::tuple<T...> &dest) { input_tuple(dest); }\n\ntemplate <std::size_t\
    \ N = 0, typename T>\nvoid _input(std::array<T, N> &dest) { for (auto &e : dest)\
    \ _input(e); }\n\ntemplate <typename T>\nvoid _input(std::vector<T> &dest) { for\
    \ (auto &e : dest) _input(e); }\n\nvoid input() {}\n\n// \u5404\u5F15\u6570\u306B\
    \u5165\u529B\ntemplate <typename H, typename... T>\nvoid input(H &desth, T &...\
    \ destt) { _input(desth), input(destt...); }\n\nvoid _print(const char tg) {\n\
    \tif (por == BUF_SIZE) flush();\n\tobuf[por++] = tg;\n}\n\nvoid _print(const std::string\
    \ tg) { for (char c : tg) _print(c); }\n\nvoid _print(const char *tg) {\n\tstd::size_t\
    \ len = std::strlen(tg);\n\tfor (std::size_t i = 0; i < len; ++i) _print(tg[i]);\n\
    }\n\ntemplate <typename T>\nvoid print_int(T x) {\n\tif (por > BUF_SIZE - 100)\
    \ flush();\n\tif (x < 0) obuf[por++] = '-', x = -x;\n\tint outi;\n\tfor (outi\
    \ = 96; x >= 10000; outi -= 4) {\n\t\tstd::memcpy(out + outi, pre.num[x % 10000],\
    \ 4);\n\t\tx /= 10000;\n\t}\n\tif (x >= 1000) {\n\t\tstd::memcpy(obuf + por, pre.num[x],\
    \ 4);\n\t\tpor += 4;\n\t}\n\telse if (x >= 100) {\n\t\tstd::memcpy(obuf + por,\
    \ pre.num[x] + 1, 3);\n\t\tpor += 3;\n\t}\n\telse if (x >= 10) {\n\t\tint q =\
    \ (x * 103) >> 10;\n\t\tobuf[por] = q | '0';\n\t\tobuf[por + 1] = (x - q * 10)\
    \ | '0';\n\t\tpor += 2;\n\t}\n\telse obuf[por++] = x | '0';\n\tstd::memcpy(obuf\
    \ + por, out + outi + 4, 96 - outi);\n\tpor += 96 - outi;\n}\n\ntemplate <typename\
    \ T>\nvoid print_real(T tg) {\n\tstd::ostringstream oss;\n\toss << std::fixed\
    \ << std::setprecision(15) << double(tg);\n\tstd::string s = oss.str();\n\t_print(s);\n\
    }\n\nvoid _print(int tg) { print_int(tg); }\nvoid _print(unsigned int tg) { print_int(tg);\
    \ }\nvoid _print(long long tg) { print_int(tg); }\nvoid _print(unsigned long long\
    \ tg) { print_int(tg); }\nvoid _print(__int128 tg) { print_int(tg); }\nvoid _print(unsigned\
    \ __int128 tg) { print_int(tg); }\nvoid _print(float tg) { print_real(tg); }\n\
    void _print(double tg) { print_real(tg); }\nvoid _print(long double tg) { print_real(tg);\
    \ }\n\ntemplate <typename T, typename U>\nvoid _print(const std::pair<T, U> tg)\
    \ {\n\t_print(tg.first);\n\t_print(' ');\n\t_print(tg.second);\n}\n\ntemplate\
    \ <std::size_t N = 0, typename T>\nvoid print_tuple(const T tg) {\n\tif constexpr\
    \ (N < std::tuple_size<T>::value) {\n\t\tif constexpr (N > 0) _print(' ');\n\t\
    \tconst auto x = std::get<N>(tg);\n\t\t_print(x);\n\t\tprint_tuple<N + 1>(tg);\n\
    \t}\n}\n\ntemplate <typename... T>\nvoid _print(std::tuple<T...> tg) { print_tuple(tg);\
    \ }\n\ntemplate <typename T, std::size_t N>\nvoid _print(const std::array<T, N>\
    \ tg) {\n\tauto len = tg.size();\n\tfor (std::size_t i = 0; i < len; ++i) {\n\t\
    \tif (i) _print(' ');\n\t\t_print(tg[i]);\n\t}\n}\n\ntemplate <typename T>\nvoid\
    \ _print(const std::vector<T> tg) {\n\tauto  len = tg.size();\n\tfor (std::size_t\
    \ i = 0; i < len; ++i) {\n\t\tif (i) _print(' ');\n\t\t_print(tg[i]);\n\t}\n}\n\
    \nvoid print() { _print('\\n'); }\n\n// \u5404\u5F15\u6570\u3092\u7A7A\u767D\u533A\
    \u5207\u308A\u3067\u51FA\u529B\u3057\u6539\u884C\ntemplate <typename H, typename...\
    \ T>\nvoid print(H &&tgh, T &&... tgt) {\n\t_print(tgh);\n\tif (sizeof...(tgt))\
    \ _print(' ');\n\tprint(std::forward<T>(tgt)...);\n}\n\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\n\n};\n\nusing Fastio::input;\nusing Fastio::print;\nusing\
    \ Fastio::flush;\n\n};\n#line 2 \"cpstl/ds/DualSegtree.hpp\"\n\n#line 4 \"cpstl/ds/DualSegtree.hpp\"\
    \n#include <bit>\n\nnamespace cpstd {\n\n// Dual Segment Tree\n\ntemplate <\n\t\
    typename F,\n\tauto composition,\n\tauto id\n>\nclass DualSegtree {\n\tprivate:\n\
    \tstd::vector<F> lazy;\n\tint N, sz, log;\n\n\tvoid pushdown(int pos) {\n\t\t\
    for (int i = log; i >= 1; --i) {\n\t\t\tint p = pos >> i;\n\t\t\tlazy[p << 1]\
    \ = composition(lazy[p], lazy[p << 1]);\n\t\t\tlazy[p << 1 | 1] = composition(lazy[p],\
    \ lazy[p << 1 | 1]);\n\t\t\tlazy[p] = id();\n\t\t}\n\t}\n\n\tpublic:\n\tDualSegtree()\
    \ {}\n\texplicit DualSegtree(int n) : N(n) {\n\t\tsz = std::bit_ceil((unsigned\
    \ int)(N));\n\t\tlog = std::bit_width((unsigned int)(sz)) - 1;\n\t\tlazy.assign(sz\
    \ << 1, id());\n\t}\n\n\t// A[pos] \u3078\u306E\u4F5C\u7528\u7D20\u3092 f \u306B\
    \u3059\u308B\n\t// O(logN) time\n\tvoid set(int pos, const F &f) {\n\t\tassert(0\
    \ <= pos && pos < N);\n\t\tpos += sz;\n\t\tpushdown(pos);\n\t\tlazy[pos] = f;\n\
    \t}\n\n\t// A[pos] \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B\n\t// O(logN)\
    \ time\n\tvoid apply(int pos, const F &f) {\n\t\tassert(0 <= pos && pos < N);\n\
    \t\tpos += sz;\n\t\tpushdown(pos);\n\t\tlazy[pos] = composition(f, lazy[pos]);\n\
    \t}\n\n\t// A[l, r) \u306B f \u3092\u4F5C\u7528\u3055\u305B\u308B\n\t// O(logN)\
    \ time\n\tvoid apply(int l, int r, const F &f) {\n\t\tassert(0 <= l && l <= r\
    \ && r <= N);\n\t\tif (l == r) return;\n\t\tl += sz, r += sz;\n\t\tpushdown(l),\
    \ pushdown(r - 1);\n\t\tfor (; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) lazy[l]\
    \ = composition(f, lazy[l]), ++l;\n\t\t\tif (r & 1) --r, lazy[r] = composition(f,\
    \ lazy[r]);\n\t\t}\n\t}\n\n\t// A[pos] \u306E\u4F5C\u7528\u7D20\u3092\u8FD4\u3059\
    \n\t// O(logN) time\n\tF get(int pos) {\n\t\tassert(0 <= pos && pos < N);\n\t\t\
    pos += sz;\n\t\tpushdown(pos);\n\t\treturn lazy[pos];\n\t}\n\n\t// A[pos] \u306E\
    \u4F5C\u7528\u7D20\u3092\u8FD4\u3059\n\t// O(logN) time\n\tF operator[](int pos)\
    \ noexcept {\n\t\tpos += sz;\n\t\tpushdown(pos);\n\t\treturn lazy[pos];\n\t}\n\
    };\n};\n#line 7 \"verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp\"\n\
    \nusing mint = cpstd::Modint998244353;\nusing F = std::pair<mint, mint>;\nF composition(F\
    \ g, F f) { return {f.first * g.first, f.second * g.first + g.second}; }\nF id()\
    \ { return {1, 0}; }\n\nint main() {\n\tint N, Q;\n\tcpstd::input(N, Q);\n\tstd::vector<mint>\
    \ A(N);\n\tcpstd::input(A);\n\tcpstd::DualSegtree<F, composition, id> sg(N);\n\
    \tint t, l, r, p;\n\tmint b, c;\n\twhile (Q--) {\n\t\tcpstd::input(t);\n\t\tif\
    \ (t == 0) {\n\t\t\tcpstd::input(l, r, b, c);\n\t\t\tsg.apply(l, r, {b, c});\n\
    \t\t}\n\t\telse {\n\t\t\tcpstd::input(p);\n\t\t\tF act = sg[p];\n\t\t\tcpstd::print(act.first\
    \ * A[p] + act.second);\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_point_get\"\
    \n\n#include <bits/stdc++.h>\n#include \"cpstl/math/StaticModint.hpp\"\n#include\
    \ \"cpstl/other/Fastio.hpp\"\n#include \"cpstl/ds/DualSegtree.hpp\"\n\nusing mint\
    \ = cpstd::Modint998244353;\nusing F = std::pair<mint, mint>;\nF composition(F\
    \ g, F f) { return {f.first * g.first, f.second * g.first + g.second}; }\nF id()\
    \ { return {1, 0}; }\n\nint main() {\n\tint N, Q;\n\tcpstd::input(N, Q);\n\tstd::vector<mint>\
    \ A(N);\n\tcpstd::input(A);\n\tcpstd::DualSegtree<F, composition, id> sg(N);\n\
    \tint t, l, r, p;\n\tmint b, c;\n\twhile (Q--) {\n\t\tcpstd::input(t);\n\t\tif\
    \ (t == 0) {\n\t\t\tcpstd::input(l, r, b, c);\n\t\t\tsg.apply(l, r, {b, c});\n\
    \t\t}\n\t\telse {\n\t\t\tcpstd::input(p);\n\t\t\tF act = sg[p];\n\t\t\tcpstd::print(act.first\
    \ * A[p] + act.second);\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - cpstl/math/StaticModint.hpp
  - cpstl/other/Fastio.hpp
  - cpstl/ds/DualSegtree.hpp
  isVerificationFile: true
  path: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
  requiredBy: []
  timestamp: '2025-07-30 22:35:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
- /verify/verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp.html
title: verify/ds/lc-Range-Affine-Point-Get-DualSegtree.test.cpp
---
