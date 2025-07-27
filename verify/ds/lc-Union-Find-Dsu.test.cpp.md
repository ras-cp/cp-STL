---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: cpstl/ds/Dsu.hpp
    title: cpstl/ds/Dsu.hpp
  - icon: ':question:'
    path: cpstl/other/Fastio.hpp
    title: cpstl/other/Fastio.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/ds/lc-Union-Find-Dsu.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <bits/stdc++.h>\n\
    #line 2 \"cpstl/other/Fastio.hpp\"\nnamespace cpstd {\n\n// Fast I/O\n\n// https://judge.yosupo.jp/submission/21623\n\
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
    \ Fastio::flush;\n\n};\n#line 2 \"cpstl/ds/Dsu.hpp\"\n\n#line 4 \"cpstl/ds/Dsu.hpp\"\
    \n\nnamespace cpstd {\n\n// Disjoint Set Union\n// union by size + path compression\n\
    \nclass Dsu {\n\tprivate:\n\tint _n;\n\tstd::vector<int> tree;\n\n\tint _leader(int\
    \ x) {\n\t\treturn tree[x] < 0 ? x : tree[x] = _leader(tree[x]);\n\t}\n\n\tpublic:\n\
    \tDsu() {}\n\texplicit Dsu(int n) : _n(n), tree(n, -1) {}\n\n\t// `x` \u306E\u5C5E\
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
    \t\t}\n\t\treturn res;\n\t}\n};\n};\n#line 6 \"verify/ds/lc-Union-Find-Dsu.test.cpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcpstd::input(N, Q);\n\tcpstd::Dsu dsu(N);\n\t\
    int t, u, v;\n\twhile (Q--) {\n\t\tcpstd::input(t, u, v);\n\t\tif (t == 0) dsu.merge(u,\
    \ v);\n\t\telse cpstd::print((dsu.same(u, v) ? \"1\" : \"0\"));\n\t}\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <bits/stdc++.h>\n#include \"cpstl/other/Fastio.hpp\"\n#include \"cpstl/ds/Dsu.hpp\"\
    \n\nint main() {\n\tint N, Q;\n\tcpstd::input(N, Q);\n\tcpstd::Dsu dsu(N);\n\t\
    int t, u, v;\n\twhile (Q--) {\n\t\tcpstd::input(t, u, v);\n\t\tif (t == 0) dsu.merge(u,\
    \ v);\n\t\telse cpstd::print((dsu.same(u, v) ? \"1\" : \"0\"));\n\t}\n}\n"
  dependsOn:
  - cpstl/other/Fastio.hpp
  - cpstl/ds/Dsu.hpp
  isVerificationFile: true
  path: verify/ds/lc-Union-Find-Dsu.test.cpp
  requiredBy: []
  timestamp: '2025-07-27 21:24:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/lc-Union-Find-Dsu.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/lc-Union-Find-Dsu.test.cpp
- /verify/verify/ds/lc-Union-Find-Dsu.test.cpp.html
title: verify/ds/lc-Union-Find-Dsu.test.cpp
---
