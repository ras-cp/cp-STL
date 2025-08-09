---
data:
  _extendedDependsOn:
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
    document_title: Segment Tree
    links: []
  bundledCode: "#line 2 \"cpstl/ds/Segtree.hpp\"\n\n#line 2 \"cpstl/other/Template.hpp\"\
    \n\n#include <immintrin.h>\n#include <algorithm>\n#include <array>\n#include <bit>\n\
    #include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cfenv>\n#include\
    \ <charconv>\n#include <chrono>\n#include <cinttypes>\n#include <climits>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <deque>\n#include <fstream>\n#include <functional>\n#include <initializer_list>\n\
    #include <iomanip>\n#include <ios>\n#include <iostream>\n#include <istream>\n\
    #include <iterator>\n#include <limits>\n#include <list>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <streambuf>\n#include <string>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <vector>\n\n#line 2 \"cpstl/math/StaticModint.hpp\"\n\n#line 7 \"cpstl/math/StaticModint.hpp\"\
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
    \n\n#line 12 \"cpstl/other/Fastio.hpp\"\n#include <any>\n#line 16 \"cpstl/other/Fastio.hpp\"\
    \n\nnamespace cpstd {\n\n// Fast I/O\n\n// https://judge.yosupo.jp/submission/21623\n\
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
    \ Fastio::flush;\n\n};\n#line 4 \"cpstl/ds/Segtree.hpp\"\n\nnamespace cpstd {\n\
    \n// @brief Segment Tree\n\ntemplate <\n\ttypename S,\n\tauto op,\n\tauto e\n\
    >\nclass Segtree {\n\tprivate:\n\tstd::vector<S> dat;\n\tint N, sz;\n\n\tpublic:\n\
    \tSegtree() {}\n\texplicit Segtree(int n) : Segtree(std::vector<S>(n, e())) {}\n\
    \texplicit Segtree(int n, const S &init) : Segtree(std::vector<S>(n, init)) {}\n\
    \texplicit Segtree(const std::vector<S> &v) : N((int)v.size()) {\n\t\tsz = 1;\n\
    \t\twhile (sz < N) sz <<= 1;\n\t\tdat.assign(sz << 1, e());\n\t\tfor (int i =\
    \ 0; i < N; ++i) dat[i + sz] = v[i];\n\t\tfor (int i = sz - 1; i >= 1; --i) dat[i]\
    \ = op(dat[i << 1], dat[i << 1 | 1]);\n\t}\n\ttemplate <class Inputit>\n\tSegtree(Inputit\
    \ first, Inputit last) : Segtree(std::vector<S>(first, last)) {}\n\n\t// A[pos]\
    \ \u2190 x \u3067\u66F4\u65B0\n\t// O(logN) time\n\tvoid set(int pos, const S\
    \ &x) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tdat[pos] = x;\n\
    \t\twhile (pos > 1) {\n\t\t\tpos >>= 1;\n\t\t\tdat[pos] = op(dat[pos << 1], dat[pos\
    \ << 1 | 1]);\n\t\t}\n\t}\n\n\t// A[pos] \u2190 A[pos] + x \u3067\u66F4\u65B0\n\
    \t// O(logN) time\n\tvoid add(int pos, const S &x) {\n\t\tassert(0 <= pos && pos\
    \ < N);\n\t\tpos += sz;\n\t\tdat[pos] += x;\n\t\twhile (pos > 1) {\n\t\t\tpos\
    \ >>= 1;\n\t\t\tdat[pos] = op(dat[pos << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\
    \n\t// A[pos] \u2190 mapping(f, A[pos]) \u3067\u66F4\u65B0\n\t// O(logN) time\n\
    \ttemplate <\n\t\ttypename F,\n\t\tauto mapping\n\t>\n\tvoid set(int pos, const\
    \ F &f) {\n\t\tassert(0 <= pos && pos < N);\n\t\tpos += sz;\n\t\tdat[pos] = mapping(f,\
    \ dat[pos]);\n\t\twhile (pos > 1) {\n\t\t\tpos >>= 1;\n\t\t\tdat[pos] = op(dat[pos\
    \ << 1], dat[pos << 1 | 1]);\n\t\t}\n\t}\n\n\t// A[pos] \u3092\u8FD4\u3059\n\t\
    // O(1) time\n\tconst S& get(int pos) const {\n\t\tassert(0 <= pos && pos < N);\n\
    \t\treturn dat[pos + sz];\n\t}\n\n\t// A[pos] \u3092\u8FD4\u3059 (assert \u306A\
    \u3057)\n\t// O(1) time\n\tconst S& operator[](int pos) const noexcept { return\
    \ dat[pos + sz]; }\n\n\t// op[l, r) \u3092\u8FD4\u3059\n\t// O(logN) time\n\t\
    S fold(int l, int r) const {\n\t\tassert(0 <= l && l <= r && r <= N);\n\t\tif\
    \ (l == r) return e();\n\t\tS resl = e(), resr = e();\n\t\tfor (l += sz, r +=\
    \ sz; l < r; l >>= 1, r >>= 1) {\n\t\t\tif (l & 1) resl = op(resl, dat[l++]);\n\
    \t\t\tif (r & 1) resr = op(dat[--r], resr);\n\t\t}\n\t\treturn op(resl, resr);\n\
    \t}\n\n\t// op[1, N] \u3092\u8FD4\u3059\n\t// O(1) time\n\tS all_fold() const\
    \ { return dat[1]; }\n\n\t// `r = l` \u307E\u305F\u306F `f(op[l, r)) = true`\n\
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
  code: "#pragma once\n\n#include \"cpstl/other/Template.hpp\"\n\nnamespace cpstd\
    \ {\n\n// @brief Segment Tree\n\ntemplate <\n\ttypename S,\n\tauto op,\n\tauto\
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
    \u3059\n\t// O(1) time\n\tconst S& get(int pos) const {\n\t\tassert(0 <= pos &&\
    \ pos < N);\n\t\treturn dat[pos + sz];\n\t}\n\n\t// A[pos] \u3092\u8FD4\u3059\
    \ (assert \u306A\u3057)\n\t// O(1) time\n\tconst S& operator[](int pos) const\
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
  dependsOn:
  - cpstl/other/Template.hpp
  - cpstl/math/StaticModint.hpp
  - cpstl/other/Fastio.hpp
  isVerificationFile: false
  path: cpstl/ds/Segtree.hpp
  requiredBy: []
  timestamp: '2025-08-10 02:51:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/lc-Point-Add-Range-Sum-Segtree.test.cpp
  - verify/ds/yuki-0875-Segtree.test.cpp
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
