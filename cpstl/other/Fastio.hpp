#pragma once
namespace cpstd {
static constexpr const int BUF_SIZE = 1 << 19;

class Cinstream {
	private:
	unsigned int p = BUF_SIZE;
	static char Q[BUF_SIZE];

	public:
	char seekchar() {
		if (p == BUF_SIZE) {
			size_t len = fread(Q, 1, BUF_SIZE, stdin);
			if (len != BUF_SIZE) Q[len] = '\0';
			p = 0;
		}
		return Q[p];
	}

	void skipspace() {
		while (isspace(seekchar())) ++p;
	}

	uint32_t nextu32() {
		skipspace();
		uint32_t res = 0;
		while (true) {
			char tmp = seekchar();
			if ('9' < tmp || tmp < '0') break;
			res = res * 10 + (tmp - '0');
			++p;
		}
		return res;
	}

	int32_t nexti32() {
		skipspace();
		if (seekchar() == '-') {
			++p;
			return (int32_t)(-nextu32());
		}
		return (int32_t)nextu32();
	}

	uint64_t nextu64() {
		skipspace();
		uint64_t res = 0;
		while (true) {
			char tmp = seekchar();
			if ('9' < tmp || tmp < '0') break;
			res = res * 10 + (tmp - '0');
			++p;
		}
		return res;
	}

	int64_t nexti64() {
		skipspace();
		if (seekchar() == '-') {
			++p;
			return (int64_t)(-nextu64());
		}
		return (int64_t)nextu64();
	}

	__uint128_t nextu128() {
		skipspace();
		__uint128_t res = 0;
		while (true) {
			char tmp = seekchar();
			if ('9' < tmp || tmp < '0') break;
			res = res * 10 + (tmp - '0');
			++p;
		}
		return res;
	}

	__int128_t nexti128() {
		skipspace();
		if (seekchar() == '-') {
			++p;
			return (__int128_t)(-nextu128());
		}
		return (__int128_t)nextu128();
	}

	long double nextld() {
		skipspace();
		bool nega = false;
		if (seekchar() == '-') {
			++p;
			char tmp = seekchar();
			if ('9' < tmp || tmp < '0') {
				return 0;
			}
			nega = true;
		}
		long double res = nextu64();
		if (seekchar() == '.') {
			++p;
			unsigned long long frac = 0, div = 1;
			while (true) {
				char tmp = seekchar();
				if ('9' < tmp || tmp < '0') break;
				frac = frac * 10 + (tmp - '0');
				div *= 10;
				++p;
			}
			res += static_cast<long double>(frac) / div;
		}
		return nega ? -res : res;
	}

	char nextchar() {
		skipspace();
		char res = seekchar();
		++p;
		return res;
	}

	std::string nexttoken() {
		skipspace();
		std::string res;
		while (true) {
			char ch = seekchar();
			if (isspace(ch) || ch == '\0') break;
			res.push_back(ch);
			++p;
		}
		return res;
	}

	Cinstream& operator>>(unsigned int& dest) {
		dest = nextu32();
		return *this;
	}
	Cinstream& operator>>(int& dest) {
		dest = nexti32();
		return *this;
	}
	Cinstream& operator>>(unsigned long& dest) {
		dest = nextu64();
		return *this;
	}
	Cinstream& operator>>(long& dest) {
		dest = nexti64();
		return *this;
	}
	Cinstream& operator>>(unsigned long long& dest) {
		dest = nextu64();
		return *this;
	}
	Cinstream& operator>>(long long& dest) {
		dest = nexti64();
		return *this;
	}
	Cinstream& operator>>(unsigned __int128& dest) {
		dest = nextu128();
		return *this;
	}
	Cinstream& operator>>(__int128& dest) {
		dest = nexti128();
		return *this;
	}
	Cinstream& operator>>(double& dest) {
		dest = (double)nextld();
		return *this;
	}
	Cinstream& operator>>(long double& dest) {
		dest = nextld();
		return *this;
	}
	Cinstream& operator>>(std::string& dest) {
		dest = nexttoken();
		return *this;
	}
	Cinstream& operator>>(char& dest) {
		dest = nextchar();
		return *this;
	}
	template <typename T>
	Cinstream& operator>>(std::vector<T>& dest) {
		for (T& e : dest) (*this) >> e;
		return *this;
	}
	template <
		typename T,
		typename U
	>
	Cinstream& operator>>(std::pair<T, U>& dest) {
		(*this) >> dest.first >> dest.second;
		return *this;
	}
} Cin;

struct FastOutputTable {
	public:
	char LZ[1000][4] = {}, NLZ[1000][4] = {};
	constexpr FastOutputTable() {
		using u32 = uint_fast32_t;
		for (u32 d = 0; d < 1000; ++d) {
			LZ[d][0] = ('0' + d / 100 % 10);
			LZ[d][1] = ('0' + d / 10 % 10);
			LZ[d][2] = ('0' + d % 10);
			LZ[d][3] = '\0';
		}
		for (u32 d = 0, i = 0; d < 1000; ++d, i = 0) {
			if (d >= 100) NLZ[d][i++] = ('0' + d / 100 % 10);
			if (d >= 10) NLZ[d][i++] = ('0' + d / 10 % 10);
			if (d >= 1) NLZ[d][i++] = ('0' + d % 10);
			NLZ[d][i++] = '\0';
		}
	}
};

class Coutstream {
	private:
	using u32 = uint32_t;
	using u64 = uint64_t;
	using u128 = __uint128_t;
	static char Q[BUF_SIZE];
	static inline constexpr FastOutputTable TB = FastOutputTable();
	u32 p = 0;
	static constexpr u32 P10[] = {
		1UL,
		10UL,
		100UL,
		1000UL,
		10000UL,
		100000UL,
		1000000UL,
		10000000UL,
		100000000UL,
		1000000000UL,
	};
	static constexpr u64 P10L[] = {
		1ULL,
		10ULL,
		100ULL,
		1000ULL,
		10000ULL,
		100000ULL,
		1000000ULL,
		10000000ULL,
		100000000ULL,
		1000000000ULL,
		10000000000ULL,
		100000000000ULL,
		1000000000000ULL,
		10000000000000ULL,
		100000000000000ULL,
		1000000000000000ULL,
		10000000000000000ULL,
		100000000000000000ULL,
		1000000000000000000ULL
	};
	static constexpr std::array<u128, 37> P10T = [] {
		std::array<u128, 37> p10t{};
		p10t[0] = 1;
		for (int i = 1; i <= 36; ++i) p10t[i] = p10t[i - 1] * 10;
		return p10t;
	}();

	template <typename T, typename U>
	static void fil(T& m, U& l, U x) noexcept {
		m = l / x;
		l -= m * x;
	}

	void next_dig9(u32 x) {
		u32 y;
		fil(y, x, P10[6]);
		nextcstr(TB.LZ[y]);
		fil(y, x, P10[3]);
		nextcstr(TB.LZ[y]);
		nextcstr(TB.LZ[x]);
	}

	public:
	void nextchar(char c) {
		Q[p++] = c;
		if (p == BUF_SIZE) {
			fwrite(Q, p, 1, stdout);
			p = 0;
		}
	}

	void nexteoln() {
		nextchar('\n');
	}

	void nextcstr(const char *s) {
		while (*s) nextchar(*(s++));
	}

	void nextu32(uint32_t x) {
		u32 y = 0;
		if (x >= P10[9]) {
			fil(y, x, P10[9]);
			nextcstr(TB.NLZ[y]);
			next_dig9(x);
		}
		else if (x >= P10[6]) {
			fil(y, x, P10[6]);
			nextcstr(TB.NLZ[y]);
			fil(y, x, P10[3]);
			nextcstr(TB.LZ[y]);
			nextcstr(TB.LZ[x]);
		}
		else if (x >= P10[3]) {
			fil(y, x, P10[3]);
			nextcstr(TB.NLZ[y]);
			nextcstr(TB.LZ[x]);
		}
		else if (x >= 1) nextcstr(TB.NLZ[x]);
		else nextchar('0');
	}

	void nexti32(int32_t x) {
		if (x >= 0) nextu32(x);
		else {
			nextchar('-');
			nextu32((u32)-x);
		}
	}

	void nextu64(uint64_t x) {
		u32 y = 0;
		if (x >= P10L[18]) {
			fil(y, x, P10L[18]);
			nextu32(y);
			fil(y, x, P10L[9]);
			next_dig9(y);
			next_dig9(x);
		}
		else if (x >= P10L[9]) {
			fil(y, x, P10L[9]);
			nextu32(y);
			next_dig9(x);
		}
		else nextu32(x);
	}

	void nexti64(int64_t x) {
		if (x >= 0) nextu64(x);
		else {
			nextchar('-');
			nextu64((u64)-x);
		}
	}

	void nextu128(__uint128_t x) {
		u32 y = 0;
		if (x >= P10T[36]) {
			fil(y, x, P10T[36]);
			nextu32(y);
			fil(y, x, P10T[27]);
			next_dig9(y);
			fil(y, x, P10T[18]);
			next_dig9(y);
			fil(y, x, P10T[9]);
			next_dig9(y);
			next_dig9(x);
		}
		else if (x >= P10T[27]) {
			fil(y, x, P10T[27]);
			nextu32(y);
			fil(y, x, P10T[18]);
			next_dig9(y);
			fil(y, x, P10T[9]);
			next_dig9(y);
			next_dig9(x);
		}
		else if (x >= P10T[18]) {
			fil(y, x, P10T[18]);
			nextu32(y);
			fil(y, x, P10T[9]);
			next_dig9(y);
			next_dig9(x);
		}
		else nextu64(x);
	}

	void nexti128(__int128_t x) {
		if (x >= 0) nextu128(x);
		else {
			nextchar('-');
			nextu128((u128)-x);
		}
	}

	void nextld(long double x) {
		if (x < 0) nextchar('-'), x = -x;
		unsigned long long integer = static_cast<unsigned long long>(x);
		nextu64(integer);
		unsigned long long fractional = static_cast<unsigned long long>((x - integer) * 1e18);
		nextchar('.');
		next_dig9(fractional / 1000000000ULL);
		next_dig9(fractional % 1000000000ULL);
	}

	void writetofile(bool flush = false) {
		fwrite(Q, p, 1, stdout);
		if (flush) fflush(stdout);
		p = 0;
	}

	Coutstream() {
		Q[0] = 0;
	}
	~Coutstream() {
		writetofile();
	}

	Coutstream& operator<<(unsigned int tg) {
		nextu32(tg);
		return *this;
	}
	Coutstream& operator<<(unsigned long tg) {
		nextu64(tg);
		return *this;
	}
	Coutstream& operator<<(unsigned long long tg) {
		nextu64(tg);
		return *this;
	}
	Coutstream& operator<<(unsigned __int128 tg) {
		nextu128(tg);
		return *this;
	}
	Coutstream& operator<<(int tg) {
		nexti32(tg);
		return *this;
	}
	Coutstream& operator<<(long tg) {
		nexti64(tg);
		return *this;
	}
	Coutstream& operator<<(long long tg) {
		nexti64(tg);
		return *this;
	}
	Coutstream& operator<<(__int128_t tg) {
		nexti128(tg);
		return *this;
	}
	Coutstream& operator<<(double tg) {
		nextld(tg);
		return *this;
	}
	Coutstream& operator<<(long double tg) {
		nextld(tg);
		return *this;
	}
	Coutstream& operator<<(const std::string& tg) {
		nextcstr(tg.c_str());
		return *this;
	}
	Coutstream& operator<<(const char *tg) {
		nextcstr(tg);
		return *this;
	}
	Coutstream& operator<<(char tg) {
		nextchar(tg);
		return *this;
	}
	template <typename T>
	Coutstream& operator<<(std::vector<T>& tg) {
		for (int i = 0; i < (int)tg.size(); ++i) {
			if (i > 0) nextchar(' ');
			(*this) << tg[i];
		}
		return *this;
	}
	template <
		typename T,
		typename U
	>
	Coutstream& operator<<(std::pair<T, U>& tg) {
		(*this) << tg.first << ' ' << tg.second;
		return *this;
	}
} Cout;

char Cinstream::Q[BUF_SIZE], Coutstream::Q[BUF_SIZE];
};
