---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpstl/ds/LazySegtree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: cpstl/math/StaticModint.hpp
    title: Static Modint
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Fastio.hpp
    title: Fast I/O
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Template.hpp
    title: cpstl/other/Template.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#include <bits/stdc++.h>\n#line 2 \"cpstl/other/Fastio.hpp\"\n\n#line 2 \"cpstl/other/Template.hpp\"\
    \n\n#include <immintrin.h>\n#line 6 \"cpstl/other/Template.hpp\"\n#include <bit>\n\
    #line 11 \"cpstl/other/Template.hpp\"\n#include <charconv>\n#line 26 \"cpstl/other/Template.hpp\"\
    \n#include <initializer_list>\n#line 47 \"cpstl/other/Template.hpp\"\n#include\
    \ <type_traits>\n#line 53 \"cpstl/other/Template.hpp\"\n\n#line 2 \"cpstl/math/StaticModint.hpp\"\
    \n\n#line 4 \"cpstl/math/StaticModint.hpp\"\n\nnamespace cpstd {\n\n// @brief\
    \ Static Modint\n\n// @see https://hackmd.io/@tatyam-prime/rkVCOcwQn\n\ntemplate\
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
    \ operator\"\"_M(unsigned long long x) { return x; }\n};\n#line 4 \"cpstl/other/Fastio.hpp\"\
    \n\nnamespace cpstd {\n\n// @brief Fast I/O\n// @see https://judge.yosupo.jp/submission/21623\n\
    // @see https://maspypy.com/library-checker-many-a-b\n\nnamespace Fastio {\n\n\
    static constexpr const uint32_t BUF_SIZE = 1 << 17;\nchar ibuf[BUF_SIZE], obuf[BUF_SIZE],\
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
    \ }\nvoid _input(unsigned __int128 &dest) { input_int(dest); }\n\ntemplate <uint32_t\
    \ m>\nvoid _input(cpstd::StaticModint<m> &dest) { long long a; _input(a); dest\
    \ = a; }\n\ntemplate <typename T, typename U>\nvoid _input(std::pair<T, U> &dest)\
    \ { _input(dest.first), _input(dest.second); }\n\ntemplate <std::size_t N = 0,\
    \ typename T>\nvoid input_tuple(T &t) {\n\tif constexpr (N < std::tuple_size<T>::value)\
    \ {\n\t\tauto &x = std::get<N>(t);\n\t\tinput(x);\n\t\tinput_tuple<N + 1>(t);\n\
    \t}\n}\n\ntemplate <typename... T>\nvoid _input(std::tuple<T...> &dest) { input_tuple(dest);\
    \ }\n\ntemplate <std::size_t N = 0, typename T>\nvoid _input(std::array<T, N>\
    \ &dest) { for (auto &e : dest) _input(e); }\n\ntemplate <typename T>\nvoid _input(std::vector<T>\
    \ &dest) { for (auto &e : dest) _input(e); }\n\nvoid input() {}\n\n// \u5404\u5F15\
    \u6570\u306B\u5165\u529B\ntemplate <typename H, typename... T>\nvoid input(H &desth,\
    \ T &... destt) { _input(desth), input(destt...); }\n\nvoid _print(const char\
    \ tg) {\n\tif (por == BUF_SIZE) flush();\n\tobuf[por++] = tg;\n}\n\nvoid _print(const\
    \ std::string tg) { for (char c : tg) _print(c); }\n\nvoid _print(const char *tg)\
    \ {\n\tstd::size_t len = std::strlen(tg);\n\tfor (std::size_t i = 0; i < len;\
    \ ++i) _print(tg[i]);\n}\n\ntemplate <typename T>\nvoid print_int(T x) {\n\tif\
    \ (por > BUF_SIZE - 100) flush();\n\tif (x < 0) obuf[por++] = '-', x = -x;\n\t\
    int outi;\n\tfor (outi = 96; x >= 10000; outi -= 4) {\n\t\tstd::memcpy(out + outi,\
    \ pre.num[x % 10000], 4);\n\t\tx /= 10000;\n\t}\n\tif (x >= 1000) {\n\t\tstd::memcpy(obuf\
    \ + por, pre.num[x], 4);\n\t\tpor += 4;\n\t}\n\telse if (x >= 100) {\n\t\tstd::memcpy(obuf\
    \ + por, pre.num[x] + 1, 3);\n\t\tpor += 3;\n\t}\n\telse if (x >= 10) {\n\t\t\
    int q = (x * 103) >> 10;\n\t\tobuf[por] = q | '0';\n\t\tobuf[por + 1] = (x - q\
    \ * 10) | '0';\n\t\tpor += 2;\n\t}\n\telse obuf[por++] = x | '0';\n\tstd::memcpy(obuf\
    \ + por, out + outi + 4, 96 - outi);\n\tpor += 96 - outi;\n}\n\ntemplate <typename\
    \ T>\nvoid print_real(T tg) {\n\tstd::ostringstream oss;\n\toss << std::fixed\
    \ << std::setprecision(15) << double(tg);\n\tstd::string s = oss.str();\n\t_print(s);\n\
    }\n\nvoid _print(int tg) { print_int(tg); }\nvoid _print(unsigned int tg) { print_int(tg);\
    \ }\nvoid _print(long long tg) { print_int(tg); }\nvoid _print(unsigned long long\
    \ tg) { print_int(tg); }\nvoid _print(__int128 tg) { print_int(tg); }\nvoid _print(unsigned\
    \ __int128 tg) { print_int(tg); }\nvoid _print(float tg) { print_real(tg); }\n\
    void _print(double tg) { print_real(tg); }\nvoid _print(long double tg) { print_real(tg);\
    \ }\n\ntemplate <uint32_t m>\nvoid _print(cpstd::StaticModint<m> tg) { print_int(tg.val());\
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
    \ Fastio::flush;\n\n};\n#line 2 \"cpstl/ds/LazySegtree.hpp\"\n\n#line 6 \"cpstl/ds/LazySegtree.hpp\"\
    \n\nnamespace cpstd {\n\n// Lazy Segment Tree\n\ntemplate <\n\ttypename S,\n\t\
    auto op,\n\tauto e,\n\ttypename F,\n\tauto mapping,\n\tauto composition,\n\tauto\
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
    s = op(dat[r], s);\n\t\t} while ((r & -r) != r);\n\t\treturn 0;\n\t}\n};\n};\n\
    #line 7 \"verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp\"\n\nusing\
    \ mint = cpstd::Modint998244353;\nusing S = std::pair<mint, mint>;\nS op(S a,\
    \ S b) { return {a.first + b.first, a.second + b.second}; }\nS e() { return {0,\
    \ 0}; }\nS mapping(S f, S x) { return {f.first * x.first + x.second * f.second,\
    \ x.second}; }\nS composition(S g, S f) { return {g.first * f.first, g.first *\
    \ f.second + g.second}; }\nS id() { return {1, 0}; }\n\nint main() {\n\tint N,\
    \ Q;\n\tcpstd::input(N, Q);\n\tstd::vector<S> A(N);\n\tfor (auto &a : A) cpstd::input(a.first),\
    \ a.second = 1;\n\tcpstd::LazySegtree<S, op, e, S, mapping, composition, id> sg(A);\n\
    \twhile (Q--) {\n\t\tint t, l, r;\n\t\tcpstd::input(t, l, r);\n\t\tif (t == 0)\
    \ {\n\t\t\tint b, c;\n\t\t\tcpstd::input(b, c);\n\t\t\tsg.apply(l, r, {b, c});\n\
    \t\t}\n\t\telse cpstd::print(sg.fold(l, r).first);\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <bits/stdc++.h>\n#include \"cpstl/other/Fastio.hpp\"\n#include \"\
    cpstl/math/StaticModint.hpp\"\n#include \"cpstl/ds/LazySegtree.hpp\"\n\nusing\
    \ mint = cpstd::Modint998244353;\nusing S = std::pair<mint, mint>;\nS op(S a,\
    \ S b) { return {a.first + b.first, a.second + b.second}; }\nS e() { return {0,\
    \ 0}; }\nS mapping(S f, S x) { return {f.first * x.first + x.second * f.second,\
    \ x.second}; }\nS composition(S g, S f) { return {g.first * f.first, g.first *\
    \ f.second + g.second}; }\nS id() { return {1, 0}; }\n\nint main() {\n\tint N,\
    \ Q;\n\tcpstd::input(N, Q);\n\tstd::vector<S> A(N);\n\tfor (auto &a : A) cpstd::input(a.first),\
    \ a.second = 1;\n\tcpstd::LazySegtree<S, op, e, S, mapping, composition, id> sg(A);\n\
    \twhile (Q--) {\n\t\tint t, l, r;\n\t\tcpstd::input(t, l, r);\n\t\tif (t == 0)\
    \ {\n\t\t\tint b, c;\n\t\t\tcpstd::input(b, c);\n\t\t\tsg.apply(l, r, {b, c});\n\
    \t\t}\n\t\telse cpstd::print(sg.fold(l, r).first);\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - cpstl/other/Fastio.hpp
  - cpstl/other/Template.hpp
  - cpstl/math/StaticModint.hpp
  - cpstl/ds/LazySegtree.hpp
  isVerificationFile: true
  path: verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
  requiredBy: []
  timestamp: '2025-08-12 03:21:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
- /verify/verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp.html
title: verify/ds/lc-Range-Affine-Range-Sum-LazySegtree.test.cpp
---
