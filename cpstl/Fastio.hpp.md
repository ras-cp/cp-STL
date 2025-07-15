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
  bundledCode: "#line 2 \"cpstl/Fastio.hpp\"\nnamespace cpstd {\nstatic constexpr\
    \ const int BUF_SIZE = 1 << 19;\n\nclass Cinstream {\n\tprivate:\n\tunsigned int\
    \ p = BUF_SIZE;\n\tstatic char Q[BUF_SIZE];\n\n\tpublic:\n\tchar seekchar() {\n\
    \t\tif (p == BUF_SIZE) {\n\t\t\tsize_t len = fread(Q, 1, BUF_SIZE, stdin);\n\t\
    \t\tif (len != BUF_SIZE) Q[len] = '\\0';\n\t\t\tp = 0;\n\t\t}\n\t\treturn Q[p];\n\
    \t}\n\n\tvoid skipspace() {\n\t\twhile (isspace(seekchar())) ++p;\n\t}\n\n\tuint32_t\
    \ nextu32() {\n\t\tskipspace();\n\t\tuint32_t res = 0;\n\t\twhile (true) {\n\t\
    \t\tchar tmp = seekchar();\n\t\t\tif ('9' < tmp || tmp < '0') break;\n\t\t\tres\
    \ = res * 10 + (tmp - '0');\n\t\t\t++p;\n\t\t}\n\t\treturn res;\n\t}\n\n\tint32_t\
    \ nexti32() {\n\t\tskipspace();\n\t\tif (seekchar() == '-') {\n\t\t\t++p;\n\t\t\
    \treturn (int32_t)(-nextu32());\n\t\t}\n\t\treturn (int32_t)nextu32();\n\t}\n\n\
    \tuint64_t nextu64() {\n\t\tskipspace();\n\t\tuint64_t res = 0;\n\t\twhile (true)\
    \ {\n\t\t\tchar tmp = seekchar();\n\t\t\tif ('9' < tmp || tmp < '0') break;\n\t\
    \t\tres = res * 10 + (tmp - '0');\n\t\t\t++p;\n\t\t}\n\t\treturn res;\n\t}\n\n\
    \tint64_t nexti64() {\n\t\tskipspace();\n\t\tif (seekchar() == '-') {\n\t\t\t\
    ++p;\n\t\t\treturn (int64_t)(-nextu64());\n\t\t}\n\t\treturn (int64_t)nextu64();\n\
    \t}\n\n\t__uint128_t nextu128() {\n\t\tskipspace();\n\t\t__uint128_t res = 0;\n\
    \t\twhile (true) {\n\t\t\tchar tmp = seekchar();\n\t\t\tif ('9' < tmp || tmp <\
    \ '0') break;\n\t\t\tres = res * 10 + (tmp - '0');\n\t\t\t++p;\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\t__int128_t nexti128() {\n\t\tskipspace();\n\t\tif (seekchar()\
    \ == '-') {\n\t\t\t++p;\n\t\t\treturn (__int128_t)(-nextu128());\n\t\t}\n\t\t\
    return (__int128_t)nextu128();\n\t}\n\n\tlong double nextld() {\n\t\tskipspace();\n\
    \t\tbool nega = false;\n\t\tif (seekchar() == '-') {\n\t\t\t++p;\n\t\t\tchar tmp\
    \ = seekchar();\n\t\t\tif ('9' < tmp || tmp < '0') {\n\t\t\t\treturn 0;\n\t\t\t\
    }\n\t\t\tnega = true;\n\t\t}\n\t\tlong double res = nextu64();\n\t\tif (seekchar()\
    \ == '.') {\n\t\t\t++p;\n\t\t\tunsigned long long frac = 0, div = 1;\n\t\t\twhile\
    \ (true) {\n\t\t\t\tchar tmp = seekchar();\n\t\t\t\tif ('9' < tmp || tmp < '0')\
    \ break;\n\t\t\t\tfrac = frac * 10 + (tmp - '0');\n\t\t\t\tdiv *= 10;\n\t\t\t\t\
    ++p;\n\t\t\t}\n\t\t\tres += static_cast<long double>(frac) / div;\n\t\t}\n\t\t\
    return nega ? -res : res;\n\t}\n\n\tchar nextchar() {\n\t\tskipspace();\n\t\t\
    char res = seekchar();\n\t\t++p;\n\t\treturn res;\n\t}\n\n\tstd::string nexttoken()\
    \ {\n\t\tskipspace();\n\t\tstd::string res;\n\t\twhile (true) {\n\t\t\tchar ch\
    \ = seekchar();\n\t\t\tif (isspace(ch) || ch == '\\0') break;\n\t\t\tres.push_back(ch);\n\
    \t\t\t++p;\n\t\t}\n\t\treturn res;\n\t}\n\n\tCinstream& operator>>(unsigned int&\
    \ dest) {\n\t\tdest = nextu32();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(int&\
    \ dest) {\n\t\tdest = nexti32();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(unsigned\
    \ long& dest) {\n\t\tdest = nextu64();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(long&\
    \ dest) {\n\t\tdest = nexti64();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(unsigned\
    \ long long& dest) {\n\t\tdest = nextu64();\n\t\treturn *this;\n\t}\n\tCinstream&\
    \ operator>>(long long& dest) {\n\t\tdest = nexti64();\n\t\treturn *this;\n\t\
    }\n\tCinstream& operator>>(unsigned __int128& dest) {\n\t\tdest = nextu128();\n\
    \t\treturn *this;\n\t}\n\tCinstream& operator>>(__int128& dest) {\n\t\tdest =\
    \ nexti128();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(double& dest) {\n\
    \t\tdest = (double)nextld();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(long\
    \ double& dest) {\n\t\tdest = nextld();\n\t\treturn *this;\n\t}\n\tCinstream&\
    \ operator>>(std::string& dest) {\n\t\tdest = nexttoken();\n\t\treturn *this;\n\
    \t}\n\tCinstream& operator>>(char& dest) {\n\t\tdest = nextchar();\n\t\treturn\
    \ *this;\n\t}\n\ttemplate <typename T>\n\tCinstream& operator>>(std::vector<T>&\
    \ dest) {\n\t\tfor (T& e : dest) (*this) >> e;\n\t\treturn *this;\n\t}\n\ttemplate\
    \ <\n\t\ttypename T,\n\t\ttypename U\n\t>\n\tCinstream& operator>>(std::pair<T,\
    \ U>& dest) {\n\t\t(*this) >> dest.first >> dest.second;\n\t\treturn *this;\n\t\
    }\n} Cin;\n\nstruct FastOutputTable {\n\tpublic:\n\tchar LZ[1000][4] = {}, NLZ[1000][4]\
    \ = {};\n\tconstexpr FastOutputTable() {\n\t\tusing u32 = uint_fast32_t;\n\t\t\
    for (u32 d = 0; d < 1000; ++d) {\n\t\t\tLZ[d][0] = ('0' + d / 100 % 10);\n\t\t\
    \tLZ[d][1] = ('0' + d / 10 % 10);\n\t\t\tLZ[d][2] = ('0' + d % 10);\n\t\t\tLZ[d][3]\
    \ = '\\0';\n\t\t}\n\t\tfor (u32 d = 0, i = 0; d < 1000; ++d, i = 0) {\n\t\t\t\
    if (d >= 100) NLZ[d][i++] = ('0' + d / 100 % 10);\n\t\t\tif (d >= 10) NLZ[d][i++]\
    \ = ('0' + d / 10 % 10);\n\t\t\tif (d >= 1) NLZ[d][i++] = ('0' + d % 10);\n\t\t\
    \tNLZ[d][i++] = '\\0';\n\t\t}\n\t}\n};\n\nclass Coutstream {\n\tprivate:\n\tusing\
    \ u32 = uint32_t;\n\tusing u64 = uint64_t;\n\tusing u128 = __uint128_t;\n\tstatic\
    \ char Q[BUF_SIZE];\n\tstatic inline constexpr FastOutputTable TB = FastOutputTable();\n\
    \tu32 p = 0;\n\tstatic constexpr u32 P10[] = {\n\t\t1UL,\n\t\t10UL,\n\t\t100UL,\n\
    \t\t1000UL,\n\t\t10000UL,\n\t\t100000UL,\n\t\t1000000UL,\n\t\t10000000UL,\n\t\t\
    100000000UL,\n\t\t1000000000UL,\n\t};\n\tstatic constexpr u64 P10L[] = {\n\t\t\
    1ULL,\n\t\t10ULL,\n\t\t100ULL,\n\t\t1000ULL,\n\t\t10000ULL,\n\t\t100000ULL,\n\t\
    \t1000000ULL,\n\t\t10000000ULL,\n\t\t100000000ULL,\n\t\t1000000000ULL,\n\t\t10000000000ULL,\n\
    \t\t100000000000ULL,\n\t\t1000000000000ULL,\n\t\t10000000000000ULL,\n\t\t100000000000000ULL,\n\
    \t\t1000000000000000ULL,\n\t\t10000000000000000ULL,\n\t\t100000000000000000ULL,\n\
    \t\t1000000000000000000ULL\n\t};\n\tstatic constexpr std::array<u128, 37> P10T\
    \ = [] {\n\t\tstd::array<u128, 37> p10t{};\n\t\tp10t[0] = 1;\n\t\tfor (int i =\
    \ 1; i <= 36; ++i) p10t[i] = p10t[i - 1] * 10;\n\t\treturn p10t;\n\t}();\n\n\t\
    template <typename T, typename U>\n\tstatic void fil(T& m, U& l, U x) noexcept\
    \ {\n\t\tm = l / x;\n\t\tl -= m * x;\n\t}\n\n\tvoid next_dig9(u32 x) {\n\t\tu32\
    \ y;\n\t\tfil(y, x, P10[6]);\n\t\tnextcstr(TB.LZ[y]);\n\t\tfil(y, x, P10[3]);\n\
    \t\tnextcstr(TB.LZ[y]);\n\t\tnextcstr(TB.LZ[x]);\n\t}\n\n\tpublic:\n\tvoid nextchar(char\
    \ c) {\n\t\tQ[p++] = c;\n\t\tif (p == BUF_SIZE) {\n\t\t\tfwrite(Q, p, 1, stdout);\n\
    \t\t\tp = 0;\n\t\t}\n\t}\n\n\tvoid nexteoln() {\n\t\tnextchar('\\n');\n\t}\n\n\
    \tvoid nextcstr(const char *s) {\n\t\twhile (*s) nextchar(*(s++));\n\t}\n\n\t\
    void nextu32(uint32_t x) {\n\t\tu32 y = 0;\n\t\tif (x >= P10[9]) {\n\t\t\tfil(y,\
    \ x, P10[9]);\n\t\t\tnextcstr(TB.NLZ[y]);\n\t\t\tnext_dig9(x);\n\t\t}\n\t\telse\
    \ if (x >= P10[6]) {\n\t\t\tfil(y, x, P10[6]);\n\t\t\tnextcstr(TB.NLZ[y]);\n\t\
    \t\tfil(y, x, P10[3]);\n\t\t\tnextcstr(TB.LZ[y]);\n\t\t\tnextcstr(TB.LZ[x]);\n\
    \t\t}\n\t\telse if (x >= P10[3]) {\n\t\t\tfil(y, x, P10[3]);\n\t\t\tnextcstr(TB.NLZ[y]);\n\
    \t\t\tnextcstr(TB.LZ[x]);\n\t\t}\n\t\telse if (x >= 1) nextcstr(TB.NLZ[x]);\n\t\
    \telse nextchar('0');\n\t}\n\n\tvoid nexti32(int32_t x) {\n\t\tif (x >= 0) nextu32(x);\n\
    \t\telse {\n\t\t\tnextchar('-');\n\t\t\tnextu32((u32)-x);\n\t\t}\n\t}\n\n\tvoid\
    \ nextu64(uint64_t x) {\n\t\tu32 y = 0;\n\t\tif (x >= P10L[18]) {\n\t\t\tfil(y,\
    \ x, P10L[18]);\n\t\t\tnextu32(y);\n\t\t\tfil(y, x, P10L[9]);\n\t\t\tnext_dig9(y);\n\
    \t\t\tnext_dig9(x);\n\t\t}\n\t\telse if (x >= P10L[9]) {\n\t\t\tfil(y, x, P10L[9]);\n\
    \t\t\tnextu32(y);\n\t\t\tnext_dig9(x);\n\t\t}\n\t\telse nextu32(x);\n\t}\n\n\t\
    void nexti64(int64_t x) {\n\t\tif (x >= 0) nextu64(x);\n\t\telse {\n\t\t\tnextchar('-');\n\
    \t\t\tnextu64((u64)-x);\n\t\t}\n\t}\n\n\tvoid nextu128(__uint128_t x) {\n\t\t\
    u32 y = 0;\n\t\tif (x >= P10T[36]) {\n\t\t\tfil(y, x, P10T[36]);\n\t\t\tnextu32(y);\n\
    \t\t\tfil(y, x, P10T[27]);\n\t\t\tnext_dig9(y);\n\t\t\tfil(y, x, P10T[18]);\n\t\
    \t\tnext_dig9(y);\n\t\t\tfil(y, x, P10T[9]);\n\t\t\tnext_dig9(y);\n\t\t\tnext_dig9(x);\n\
    \t\t}\n\t\telse if (x >= P10T[27]) {\n\t\t\tfil(y, x, P10T[27]);\n\t\t\tnextu32(y);\n\
    \t\t\tfil(y, x, P10T[18]);\n\t\t\tnext_dig9(y);\n\t\t\tfil(y, x, P10T[9]);\n\t\
    \t\tnext_dig9(y);\n\t\t\tnext_dig9(x);\n\t\t}\n\t\telse if (x >= P10T[18]) {\n\
    \t\t\tfil(y, x, P10T[18]);\n\t\t\tnextu32(y);\n\t\t\tfil(y, x, P10T[9]);\n\t\t\
    \tnext_dig9(y);\n\t\t\tnext_dig9(x);\n\t\t}\n\t\telse nextu64(x);\n\t}\n\n\tvoid\
    \ nexti128(__int128_t x) {\n\t\tif (x >= 0) nextu128(x);\n\t\telse {\n\t\t\tnextchar('-');\n\
    \t\t\tnextu128((u128)-x);\n\t\t}\n\t}\n\n\tvoid nextld(long double x) {\n\t\t\
    if (x < 0) nextchar('-'), x = -x;\n\t\tunsigned long long integer = static_cast<unsigned\
    \ long long>(x);\n\t\tnextu64(integer);\n\t\tunsigned long long fractional = static_cast<unsigned\
    \ long long>((x - integer) * 1e18);\n\t\tnextchar('.');\n\t\tnext_dig9(fractional\
    \ / 1000000000ULL);\n\t\tnext_dig9(fractional % 1000000000ULL);\n\t}\n\n\tvoid\
    \ writetofile(bool flush = false) {\n\t\tfwrite(Q, p, 1, stdout);\n\t\tif (flush)\
    \ fflush(stdout);\n\t\tp = 0;\n\t}\n\n\tCoutstream() {\n\t\tQ[0] = 0;\n\t}\n\t\
    ~Coutstream() {\n\t\twritetofile();\n\t}\n\n\tCoutstream& operator<<(unsigned\
    \ int tg) {\n\t\tnextu32(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(unsigned\
    \ long tg) {\n\t\tnextu64(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(unsigned\
    \ long long tg) {\n\t\tnextu64(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(unsigned\
    \ __int128 tg) {\n\t\tnextu128(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(int\
    \ tg) {\n\t\tnexti32(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(long\
    \ tg) {\n\t\tnexti64(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(long\
    \ long tg) {\n\t\tnexti64(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(__int128_t\
    \ tg) {\n\t\tnexti128(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(double\
    \ tg) {\n\t\tnextld(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(long\
    \ double tg) {\n\t\tnextld(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(const\
    \ std::string& tg) {\n\t\tnextcstr(tg.c_str());\n\t\treturn *this;\n\t}\n\tCoutstream&\
    \ operator<<(const char *tg) {\n\t\tnextcstr(tg);\n\t\treturn *this;\n\t}\n\t\
    Coutstream& operator<<(char tg) {\n\t\tnextchar(tg);\n\t\treturn *this;\n\t}\n\
    \ttemplate <typename T>\n\tCoutstream& operator<<(std::vector<T>& tg) {\n\t\t\
    for (int i = 0; i < (int)tg.size(); ++i) {\n\t\t\tif (i > 0) nextchar(' ');\n\t\
    \t\t(*this) << tg[i];\n\t\t}\n\t\treturn *this;\n\t}\n\ttemplate <\n\t\ttypename\
    \ T,\n\t\ttypename U\n\t>\n\tCoutstream& operator<<(std::pair<T, U>& tg) {\n\t\
    \t(*this) << tg.first << ' ' << tg.second;\n\t\treturn *this;\n\t}\n} Cout;\n\n\
    char Cinstream::Q[BUF_SIZE], Coutstream::Q[BUF_SIZE];\n};\n"
  code: "#pragma once\nnamespace cpstd {\nstatic constexpr const int BUF_SIZE = 1\
    \ << 19;\n\nclass Cinstream {\n\tprivate:\n\tunsigned int p = BUF_SIZE;\n\tstatic\
    \ char Q[BUF_SIZE];\n\n\tpublic:\n\tchar seekchar() {\n\t\tif (p == BUF_SIZE)\
    \ {\n\t\t\tsize_t len = fread(Q, 1, BUF_SIZE, stdin);\n\t\t\tif (len != BUF_SIZE)\
    \ Q[len] = '\\0';\n\t\t\tp = 0;\n\t\t}\n\t\treturn Q[p];\n\t}\n\n\tvoid skipspace()\
    \ {\n\t\twhile (isspace(seekchar())) ++p;\n\t}\n\n\tuint32_t nextu32() {\n\t\t\
    skipspace();\n\t\tuint32_t res = 0;\n\t\twhile (true) {\n\t\t\tchar tmp = seekchar();\n\
    \t\t\tif ('9' < tmp || tmp < '0') break;\n\t\t\tres = res * 10 + (tmp - '0');\n\
    \t\t\t++p;\n\t\t}\n\t\treturn res;\n\t}\n\n\tint32_t nexti32() {\n\t\tskipspace();\n\
    \t\tif (seekchar() == '-') {\n\t\t\t++p;\n\t\t\treturn (int32_t)(-nextu32());\n\
    \t\t}\n\t\treturn (int32_t)nextu32();\n\t}\n\n\tuint64_t nextu64() {\n\t\tskipspace();\n\
    \t\tuint64_t res = 0;\n\t\twhile (true) {\n\t\t\tchar tmp = seekchar();\n\t\t\t\
    if ('9' < tmp || tmp < '0') break;\n\t\t\tres = res * 10 + (tmp - '0');\n\t\t\t\
    ++p;\n\t\t}\n\t\treturn res;\n\t}\n\n\tint64_t nexti64() {\n\t\tskipspace();\n\
    \t\tif (seekchar() == '-') {\n\t\t\t++p;\n\t\t\treturn (int64_t)(-nextu64());\n\
    \t\t}\n\t\treturn (int64_t)nextu64();\n\t}\n\n\t__uint128_t nextu128() {\n\t\t\
    skipspace();\n\t\t__uint128_t res = 0;\n\t\twhile (true) {\n\t\t\tchar tmp = seekchar();\n\
    \t\t\tif ('9' < tmp || tmp < '0') break;\n\t\t\tres = res * 10 + (tmp - '0');\n\
    \t\t\t++p;\n\t\t}\n\t\treturn res;\n\t}\n\n\t__int128_t nexti128() {\n\t\tskipspace();\n\
    \t\tif (seekchar() == '-') {\n\t\t\t++p;\n\t\t\treturn (__int128_t)(-nextu128());\n\
    \t\t}\n\t\treturn (__int128_t)nextu128();\n\t}\n\n\tlong double nextld() {\n\t\
    \tskipspace();\n\t\tbool nega = false;\n\t\tif (seekchar() == '-') {\n\t\t\t++p;\n\
    \t\t\tchar tmp = seekchar();\n\t\t\tif ('9' < tmp || tmp < '0') {\n\t\t\t\treturn\
    \ 0;\n\t\t\t}\n\t\t\tnega = true;\n\t\t}\n\t\tlong double res = nextu64();\n\t\
    \tif (seekchar() == '.') {\n\t\t\t++p;\n\t\t\tunsigned long long frac = 0, div\
    \ = 1;\n\t\t\twhile (true) {\n\t\t\t\tchar tmp = seekchar();\n\t\t\t\tif ('9'\
    \ < tmp || tmp < '0') break;\n\t\t\t\tfrac = frac * 10 + (tmp - '0');\n\t\t\t\t\
    div *= 10;\n\t\t\t\t++p;\n\t\t\t}\n\t\t\tres += static_cast<long double>(frac)\
    \ / div;\n\t\t}\n\t\treturn nega ? -res : res;\n\t}\n\n\tchar nextchar() {\n\t\
    \tskipspace();\n\t\tchar res = seekchar();\n\t\t++p;\n\t\treturn res;\n\t}\n\n\
    \tstd::string nexttoken() {\n\t\tskipspace();\n\t\tstd::string res;\n\t\twhile\
    \ (true) {\n\t\t\tchar ch = seekchar();\n\t\t\tif (isspace(ch) || ch == '\\0')\
    \ break;\n\t\t\tres.push_back(ch);\n\t\t\t++p;\n\t\t}\n\t\treturn res;\n\t}\n\n\
    \tCinstream& operator>>(unsigned int& dest) {\n\t\tdest = nextu32();\n\t\treturn\
    \ *this;\n\t}\n\tCinstream& operator>>(int& dest) {\n\t\tdest = nexti32();\n\t\
    \treturn *this;\n\t}\n\tCinstream& operator>>(unsigned long& dest) {\n\t\tdest\
    \ = nextu64();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(long& dest) {\n\
    \t\tdest = nexti64();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(unsigned\
    \ long long& dest) {\n\t\tdest = nextu64();\n\t\treturn *this;\n\t}\n\tCinstream&\
    \ operator>>(long long& dest) {\n\t\tdest = nexti64();\n\t\treturn *this;\n\t\
    }\n\tCinstream& operator>>(unsigned __int128& dest) {\n\t\tdest = nextu128();\n\
    \t\treturn *this;\n\t}\n\tCinstream& operator>>(__int128& dest) {\n\t\tdest =\
    \ nexti128();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(double& dest) {\n\
    \t\tdest = (double)nextld();\n\t\treturn *this;\n\t}\n\tCinstream& operator>>(long\
    \ double& dest) {\n\t\tdest = nextld();\n\t\treturn *this;\n\t}\n\tCinstream&\
    \ operator>>(std::string& dest) {\n\t\tdest = nexttoken();\n\t\treturn *this;\n\
    \t}\n\tCinstream& operator>>(char& dest) {\n\t\tdest = nextchar();\n\t\treturn\
    \ *this;\n\t}\n\ttemplate <typename T>\n\tCinstream& operator>>(std::vector<T>&\
    \ dest) {\n\t\tfor (T& e : dest) (*this) >> e;\n\t\treturn *this;\n\t}\n\ttemplate\
    \ <\n\t\ttypename T,\n\t\ttypename U\n\t>\n\tCinstream& operator>>(std::pair<T,\
    \ U>& dest) {\n\t\t(*this) >> dest.first >> dest.second;\n\t\treturn *this;\n\t\
    }\n} Cin;\n\nstruct FastOutputTable {\n\tpublic:\n\tchar LZ[1000][4] = {}, NLZ[1000][4]\
    \ = {};\n\tconstexpr FastOutputTable() {\n\t\tusing u32 = uint_fast32_t;\n\t\t\
    for (u32 d = 0; d < 1000; ++d) {\n\t\t\tLZ[d][0] = ('0' + d / 100 % 10);\n\t\t\
    \tLZ[d][1] = ('0' + d / 10 % 10);\n\t\t\tLZ[d][2] = ('0' + d % 10);\n\t\t\tLZ[d][3]\
    \ = '\\0';\n\t\t}\n\t\tfor (u32 d = 0, i = 0; d < 1000; ++d, i = 0) {\n\t\t\t\
    if (d >= 100) NLZ[d][i++] = ('0' + d / 100 % 10);\n\t\t\tif (d >= 10) NLZ[d][i++]\
    \ = ('0' + d / 10 % 10);\n\t\t\tif (d >= 1) NLZ[d][i++] = ('0' + d % 10);\n\t\t\
    \tNLZ[d][i++] = '\\0';\n\t\t}\n\t}\n};\n\nclass Coutstream {\n\tprivate:\n\tusing\
    \ u32 = uint32_t;\n\tusing u64 = uint64_t;\n\tusing u128 = __uint128_t;\n\tstatic\
    \ char Q[BUF_SIZE];\n\tstatic inline constexpr FastOutputTable TB = FastOutputTable();\n\
    \tu32 p = 0;\n\tstatic constexpr u32 P10[] = {\n\t\t1UL,\n\t\t10UL,\n\t\t100UL,\n\
    \t\t1000UL,\n\t\t10000UL,\n\t\t100000UL,\n\t\t1000000UL,\n\t\t10000000UL,\n\t\t\
    100000000UL,\n\t\t1000000000UL,\n\t};\n\tstatic constexpr u64 P10L[] = {\n\t\t\
    1ULL,\n\t\t10ULL,\n\t\t100ULL,\n\t\t1000ULL,\n\t\t10000ULL,\n\t\t100000ULL,\n\t\
    \t1000000ULL,\n\t\t10000000ULL,\n\t\t100000000ULL,\n\t\t1000000000ULL,\n\t\t10000000000ULL,\n\
    \t\t100000000000ULL,\n\t\t1000000000000ULL,\n\t\t10000000000000ULL,\n\t\t100000000000000ULL,\n\
    \t\t1000000000000000ULL,\n\t\t10000000000000000ULL,\n\t\t100000000000000000ULL,\n\
    \t\t1000000000000000000ULL\n\t};\n\tstatic constexpr std::array<u128, 37> P10T\
    \ = [] {\n\t\tstd::array<u128, 37> p10t{};\n\t\tp10t[0] = 1;\n\t\tfor (int i =\
    \ 1; i <= 36; ++i) p10t[i] = p10t[i - 1] * 10;\n\t\treturn p10t;\n\t}();\n\n\t\
    template <typename T, typename U>\n\tstatic void fil(T& m, U& l, U x) noexcept\
    \ {\n\t\tm = l / x;\n\t\tl -= m * x;\n\t}\n\n\tvoid next_dig9(u32 x) {\n\t\tu32\
    \ y;\n\t\tfil(y, x, P10[6]);\n\t\tnextcstr(TB.LZ[y]);\n\t\tfil(y, x, P10[3]);\n\
    \t\tnextcstr(TB.LZ[y]);\n\t\tnextcstr(TB.LZ[x]);\n\t}\n\n\tpublic:\n\tvoid nextchar(char\
    \ c) {\n\t\tQ[p++] = c;\n\t\tif (p == BUF_SIZE) {\n\t\t\tfwrite(Q, p, 1, stdout);\n\
    \t\t\tp = 0;\n\t\t}\n\t}\n\n\tvoid nexteoln() {\n\t\tnextchar('\\n');\n\t}\n\n\
    \tvoid nextcstr(const char *s) {\n\t\twhile (*s) nextchar(*(s++));\n\t}\n\n\t\
    void nextu32(uint32_t x) {\n\t\tu32 y = 0;\n\t\tif (x >= P10[9]) {\n\t\t\tfil(y,\
    \ x, P10[9]);\n\t\t\tnextcstr(TB.NLZ[y]);\n\t\t\tnext_dig9(x);\n\t\t}\n\t\telse\
    \ if (x >= P10[6]) {\n\t\t\tfil(y, x, P10[6]);\n\t\t\tnextcstr(TB.NLZ[y]);\n\t\
    \t\tfil(y, x, P10[3]);\n\t\t\tnextcstr(TB.LZ[y]);\n\t\t\tnextcstr(TB.LZ[x]);\n\
    \t\t}\n\t\telse if (x >= P10[3]) {\n\t\t\tfil(y, x, P10[3]);\n\t\t\tnextcstr(TB.NLZ[y]);\n\
    \t\t\tnextcstr(TB.LZ[x]);\n\t\t}\n\t\telse if (x >= 1) nextcstr(TB.NLZ[x]);\n\t\
    \telse nextchar('0');\n\t}\n\n\tvoid nexti32(int32_t x) {\n\t\tif (x >= 0) nextu32(x);\n\
    \t\telse {\n\t\t\tnextchar('-');\n\t\t\tnextu32((u32)-x);\n\t\t}\n\t}\n\n\tvoid\
    \ nextu64(uint64_t x) {\n\t\tu32 y = 0;\n\t\tif (x >= P10L[18]) {\n\t\t\tfil(y,\
    \ x, P10L[18]);\n\t\t\tnextu32(y);\n\t\t\tfil(y, x, P10L[9]);\n\t\t\tnext_dig9(y);\n\
    \t\t\tnext_dig9(x);\n\t\t}\n\t\telse if (x >= P10L[9]) {\n\t\t\tfil(y, x, P10L[9]);\n\
    \t\t\tnextu32(y);\n\t\t\tnext_dig9(x);\n\t\t}\n\t\telse nextu32(x);\n\t}\n\n\t\
    void nexti64(int64_t x) {\n\t\tif (x >= 0) nextu64(x);\n\t\telse {\n\t\t\tnextchar('-');\n\
    \t\t\tnextu64((u64)-x);\n\t\t}\n\t}\n\n\tvoid nextu128(__uint128_t x) {\n\t\t\
    u32 y = 0;\n\t\tif (x >= P10T[36]) {\n\t\t\tfil(y, x, P10T[36]);\n\t\t\tnextu32(y);\n\
    \t\t\tfil(y, x, P10T[27]);\n\t\t\tnext_dig9(y);\n\t\t\tfil(y, x, P10T[18]);\n\t\
    \t\tnext_dig9(y);\n\t\t\tfil(y, x, P10T[9]);\n\t\t\tnext_dig9(y);\n\t\t\tnext_dig9(x);\n\
    \t\t}\n\t\telse if (x >= P10T[27]) {\n\t\t\tfil(y, x, P10T[27]);\n\t\t\tnextu32(y);\n\
    \t\t\tfil(y, x, P10T[18]);\n\t\t\tnext_dig9(y);\n\t\t\tfil(y, x, P10T[9]);\n\t\
    \t\tnext_dig9(y);\n\t\t\tnext_dig9(x);\n\t\t}\n\t\telse if (x >= P10T[18]) {\n\
    \t\t\tfil(y, x, P10T[18]);\n\t\t\tnextu32(y);\n\t\t\tfil(y, x, P10T[9]);\n\t\t\
    \tnext_dig9(y);\n\t\t\tnext_dig9(x);\n\t\t}\n\t\telse nextu64(x);\n\t}\n\n\tvoid\
    \ nexti128(__int128_t x) {\n\t\tif (x >= 0) nextu128(x);\n\t\telse {\n\t\t\tnextchar('-');\n\
    \t\t\tnextu128((u128)-x);\n\t\t}\n\t}\n\n\tvoid nextld(long double x) {\n\t\t\
    if (x < 0) nextchar('-'), x = -x;\n\t\tunsigned long long integer = static_cast<unsigned\
    \ long long>(x);\n\t\tnextu64(integer);\n\t\tunsigned long long fractional = static_cast<unsigned\
    \ long long>((x - integer) * 1e18);\n\t\tnextchar('.');\n\t\tnext_dig9(fractional\
    \ / 1000000000ULL);\n\t\tnext_dig9(fractional % 1000000000ULL);\n\t}\n\n\tvoid\
    \ writetofile(bool flush = false) {\n\t\tfwrite(Q, p, 1, stdout);\n\t\tif (flush)\
    \ fflush(stdout);\n\t\tp = 0;\n\t}\n\n\tCoutstream() {\n\t\tQ[0] = 0;\n\t}\n\t\
    ~Coutstream() {\n\t\twritetofile();\n\t}\n\n\tCoutstream& operator<<(unsigned\
    \ int tg) {\n\t\tnextu32(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(unsigned\
    \ long tg) {\n\t\tnextu64(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(unsigned\
    \ long long tg) {\n\t\tnextu64(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(unsigned\
    \ __int128 tg) {\n\t\tnextu128(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(int\
    \ tg) {\n\t\tnexti32(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(long\
    \ tg) {\n\t\tnexti64(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(long\
    \ long tg) {\n\t\tnexti64(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(__int128_t\
    \ tg) {\n\t\tnexti128(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(double\
    \ tg) {\n\t\tnextld(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(long\
    \ double tg) {\n\t\tnextld(tg);\n\t\treturn *this;\n\t}\n\tCoutstream& operator<<(const\
    \ std::string& tg) {\n\t\tnextcstr(tg.c_str());\n\t\treturn *this;\n\t}\n\tCoutstream&\
    \ operator<<(const char *tg) {\n\t\tnextcstr(tg);\n\t\treturn *this;\n\t}\n\t\
    Coutstream& operator<<(char tg) {\n\t\tnextchar(tg);\n\t\treturn *this;\n\t}\n\
    \ttemplate <typename T>\n\tCoutstream& operator<<(std::vector<T>& tg) {\n\t\t\
    for (int i = 0; i < (int)tg.size(); ++i) {\n\t\t\tif (i > 0) nextchar(' ');\n\t\
    \t\t(*this) << tg[i];\n\t\t}\n\t\treturn *this;\n\t}\n\ttemplate <\n\t\ttypename\
    \ T,\n\t\ttypename U\n\t>\n\tCoutstream& operator<<(std::pair<T, U>& tg) {\n\t\
    \t(*this) << tg.first << ' ' << tg.second;\n\t\treturn *this;\n\t}\n} Cout;\n\n\
    char Cinstream::Q[BUF_SIZE], Coutstream::Q[BUF_SIZE];\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: cpstl/Fastio.hpp
  requiredBy: []
  timestamp: '2025-07-16 00:54:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: cpstl/Fastio.hpp
layout: document
redirect_from:
- /library/cpstl/Fastio.hpp
- /library/cpstl/Fastio.hpp.html
title: cpstl/Fastio.hpp
---
