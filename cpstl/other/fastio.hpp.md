---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lc_fastio.test.cpp
    title: verify/lc_fastio.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://judge.yosupo.jp/submission/21623
    - https://maspypy.com/library-checker-many-a-b
  bundledCode: "#line 2 \"cpstl/other/fastio.hpp\"\nnamespace cpstd {\n\n// https://judge.yosupo.jp/submission/21623\n\
    // https://maspypy.com/library-checker-many-a-b\n\nnamespace fastio {\n\nstatic\
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
    \ (auto &e : dest) _input(e); }\n\nvoid input() {}\n\ntemplate <typename H, typename...\
    \ T>\nvoid input(H &desth, T &... destt) { _input(desth), input(destt...); }\n\
    \nvoid _print(const char tg) {\n\tif (por == BUF_SIZE) flush();\n\tobuf[por++]\
    \ = tg;\n}\n\nvoid _print(const std::string tg) { for (char c : tg) _print(c);\
    \ }\n\nvoid _print(const char *tg) {\n\tstd::size_t len = std::strlen(tg);\n\t\
    for (std::size_t i = 0; i < len; ++i) _print(tg[i]);\n}\n\ntemplate <typename\
    \ T>\nvoid print_int(T x) {\n\tif (por > BUF_SIZE - 100) flush();\n\tif (x < 0)\
    \ obuf[por++] = '-', x = -x;\n\tint outi;\n\tfor (outi = 96; x >= 10000; outi\
    \ -= 4) {\n\t\tstd::memcpy(out + outi, pre.num[x % 10000], 4);\n\t\tx /= 10000;\n\
    \t}\n\tif (x >= 1000) {\n\t\tstd::memcpy(obuf + por, pre.num[x], 4);\n\t\tpor\
    \ += 4;\n\t}\n\telse if (x >= 100) {\n\t\tstd::memcpy(obuf + por, pre.num[x] +\
    \ 1, 3);\n\t\tpor += 3;\n\t}\n\telse if (x >= 10) {\n\t\tint q = (x * 103) >>\
    \ 10;\n\t\tobuf[por] = q | '0';\n\t\tobuf[por + 1] = (x - q * 10) | '0';\n\t\t\
    por += 2;\n\t}\n\telse obuf[por++] = x | '0';\n\tstd::memcpy(obuf + por, out +\
    \ outi + 4, 96 - outi);\n\tpor += 96 - outi;\n}\n\ntemplate <typename T>\nvoid\
    \ print_real(T tg) {\n\tstd::ostringstream oss;\n\toss << std::fixed << std::setprecision(15)\
    \ << double(tg);\n\tstd::string s = oss.str();\n\t_print(s);\n}\n\nvoid _print(int\
    \ tg) { print_int(tg); }\nvoid _print(unsigned int tg) { print_int(tg); }\nvoid\
    \ _print(long long tg) { print_int(tg); }\nvoid _print(unsigned long long tg)\
    \ { print_int(tg); }\nvoid _print(__int128 tg) { print_int(tg); }\nvoid _print(unsigned\
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
    \nvoid print() { _print('\\n'); }\n\ntemplate <typename H, typename... T>\nvoid\
    \ print(H &&tgh, T &&... tgt) {\n\t_print(tgh);\n\tif (sizeof...(tgt)) _print('\
    \ ');\n\tprint(std::forward<T>(tgt)...);\n}\n\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\n\n};\n\nusing fastio::input;\nusing fastio::print;\nusing\
    \ fastio::flush;\n\n};\n"
  code: "#pragma once\nnamespace cpstd {\n\n// https://judge.yosupo.jp/submission/21623\n\
    // https://maspypy.com/library-checker-many-a-b\n\nnamespace fastio {\n\nstatic\
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
    \ (auto &e : dest) _input(e); }\n\nvoid input() {}\n\ntemplate <typename H, typename...\
    \ T>\nvoid input(H &desth, T &... destt) { _input(desth), input(destt...); }\n\
    \nvoid _print(const char tg) {\n\tif (por == BUF_SIZE) flush();\n\tobuf[por++]\
    \ = tg;\n}\n\nvoid _print(const std::string tg) { for (char c : tg) _print(c);\
    \ }\n\nvoid _print(const char *tg) {\n\tstd::size_t len = std::strlen(tg);\n\t\
    for (std::size_t i = 0; i < len; ++i) _print(tg[i]);\n}\n\ntemplate <typename\
    \ T>\nvoid print_int(T x) {\n\tif (por > BUF_SIZE - 100) flush();\n\tif (x < 0)\
    \ obuf[por++] = '-', x = -x;\n\tint outi;\n\tfor (outi = 96; x >= 10000; outi\
    \ -= 4) {\n\t\tstd::memcpy(out + outi, pre.num[x % 10000], 4);\n\t\tx /= 10000;\n\
    \t}\n\tif (x >= 1000) {\n\t\tstd::memcpy(obuf + por, pre.num[x], 4);\n\t\tpor\
    \ += 4;\n\t}\n\telse if (x >= 100) {\n\t\tstd::memcpy(obuf + por, pre.num[x] +\
    \ 1, 3);\n\t\tpor += 3;\n\t}\n\telse if (x >= 10) {\n\t\tint q = (x * 103) >>\
    \ 10;\n\t\tobuf[por] = q | '0';\n\t\tobuf[por + 1] = (x - q * 10) | '0';\n\t\t\
    por += 2;\n\t}\n\telse obuf[por++] = x | '0';\n\tstd::memcpy(obuf + por, out +\
    \ outi + 4, 96 - outi);\n\tpor += 96 - outi;\n}\n\ntemplate <typename T>\nvoid\
    \ print_real(T tg) {\n\tstd::ostringstream oss;\n\toss << std::fixed << std::setprecision(15)\
    \ << double(tg);\n\tstd::string s = oss.str();\n\t_print(s);\n}\n\nvoid _print(int\
    \ tg) { print_int(tg); }\nvoid _print(unsigned int tg) { print_int(tg); }\nvoid\
    \ _print(long long tg) { print_int(tg); }\nvoid _print(unsigned long long tg)\
    \ { print_int(tg); }\nvoid _print(__int128 tg) { print_int(tg); }\nvoid _print(unsigned\
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
    \nvoid print() { _print('\\n'); }\n\ntemplate <typename H, typename... T>\nvoid\
    \ print(H &&tgh, T &&... tgt) {\n\t_print(tgh);\n\tif (sizeof...(tgt)) _print('\
    \ ');\n\tprint(std::forward<T>(tgt)...);\n}\n\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\n\n};\n\nusing fastio::input;\nusing fastio::print;\nusing\
    \ fastio::flush;\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/other/fastio.hpp
  requiredBy: []
  timestamp: '2025-07-21 03:20:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lc_fastio.test.cpp
documentation_of: cpstl/other/fastio.hpp
layout: document
title: fastio
---

## fastio
高速入出力．`pair` や `tuple`, `vector` も直接入出力が可能 (出力は空白区切りとなる)．また，128bit 整数の入出力にも対応．
`cpstd::print` での出力では改行が入るが，`cpstd::_print` を使えば一応改行なしで出力できる．ただし，`cpstd::print` と違い可変長引数に対応していないため注意．
