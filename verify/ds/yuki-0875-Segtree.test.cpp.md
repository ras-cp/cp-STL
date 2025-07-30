---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpstl/ds/Segtree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: cpstl/other/Fastio.hpp
    title: Fast I/O
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/875
    links:
    - https://yukicoder.me/problems/no/875
  bundledCode: "#line 1 \"verify/ds/yuki-0875-Segtree.test.cpp\"\n#define PROBLEM\
    \ \"https://yukicoder.me/problems/no/875\"\n#include <bits/stdc++.h>\n#line 2\
    \ \"cpstl/other/Fastio.hpp\"\nnamespace cpstd {\n\n// Fast I/O\n\n// https://judge.yosupo.jp/submission/21623\n\
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
    \ Fastio::flush;\n\n};\n#line 2 \"cpstl/ds/Segtree.hpp\"\n\n#line 4 \"cpstl/ds/Segtree.hpp\"\
    \n\nnamespace cpstd {\n\n// Segment Tree\n\ntemplate <\n\ttypename S,\n\tauto\
    \ op,\n\tauto e\n>\nclass Segtree {\n\tprivate:\n\tstd::vector<S> dat;\n\tint\
    \ N, sz;\n\n\tpublic:\n\tSegtree() {}\n\texplicit Segtree(int n) : Segtree(std::vector<S>(n,\
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
    } while ((r & -r) != r);\n\t\treturn 0;\n\t}\n};\n};\n#line 5 \"verify/ds/yuki-0875-Segtree.test.cpp\"\
    \n\nint op(int a, int b) { return std::min(a, b); }\nint e() { return 100000000;\
    \ }\n\nint main() {\n\tint N, Q;\n\tcpstd::input(N, Q);\n\tstd::vector<int> A(N);\n\
    \tcpstd::input(A);\n\tcpstd::Segtree<int, op, e> sg(A);\n\tint t, l, r, lv;\n\t\
    while (Q--) {\n\t\tcpstd::input(t, l, r);\n\t\tif (t == 1) {\n\t\t\tlv = sg[--l];\n\
    \t\t\tsg.set(l, sg[--r]);\n\t\t\tsg.set(r, lv);\n\t\t}\n\t\telse {\n\t\t\tint\
    \ mini = sg.fold(--l, r);\n\t\t\tint a1 = sg.max_right(l, [&](int x) -> bool {\
    \ return x > mini; });\n\t\t\tint a2 = sg.min_left(r, [&](int x) -> bool { return\
    \ x > mini; });\n\t\t\t--a2;\n\t\t\tassert(a1 == a2);\n\t\t\tcpstd::print(a1 +\
    \ 1);\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/875\"\n#include <bits/stdc++.h>\n\
    #include \"cpstl/other/Fastio.hpp\"\n#include \"cpstl/ds/Segtree.hpp\"\n\nint\
    \ op(int a, int b) { return std::min(a, b); }\nint e() { return 100000000; }\n\
    \nint main() {\n\tint N, Q;\n\tcpstd::input(N, Q);\n\tstd::vector<int> A(N);\n\
    \tcpstd::input(A);\n\tcpstd::Segtree<int, op, e> sg(A);\n\tint t, l, r, lv;\n\t\
    while (Q--) {\n\t\tcpstd::input(t, l, r);\n\t\tif (t == 1) {\n\t\t\tlv = sg[--l];\n\
    \t\t\tsg.set(l, sg[--r]);\n\t\t\tsg.set(r, lv);\n\t\t}\n\t\telse {\n\t\t\tint\
    \ mini = sg.fold(--l, r);\n\t\t\tint a1 = sg.max_right(l, [&](int x) -> bool {\
    \ return x > mini; });\n\t\t\tint a2 = sg.min_left(r, [&](int x) -> bool { return\
    \ x > mini; });\n\t\t\t--a2;\n\t\t\tassert(a1 == a2);\n\t\t\tcpstd::print(a1 +\
    \ 1);\n\t\t}\n\t}\n\treturn 0;\n}\n"
  dependsOn:
  - cpstl/other/Fastio.hpp
  - cpstl/ds/Segtree.hpp
  isVerificationFile: true
  path: verify/ds/yuki-0875-Segtree.test.cpp
  requiredBy: []
  timestamp: '2025-07-29 00:18:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/yuki-0875-Segtree.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/yuki-0875-Segtree.test.cpp
- /verify/verify/ds/yuki-0875-Segtree.test.cpp.html
title: verify/ds/yuki-0875-Segtree.test.cpp
---
