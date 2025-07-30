#pragma once

#include <cstdint>
#include <cstdio>
#include <cstddef>
#include <string>
#include <type_traits>
#include <utility>
#include <tuple>
#include <array>
#include <vector>
#include <any>
#include <ios>
#include <iomanip>
#include "cpstl/math/StaticModint.hpp"

namespace cpstd {

// Fast I/O

// https://judge.yosupo.jp/submission/21623
// https://maspypy.com/library-checker-many-a-b

namespace Fastio {

static constexpr const uint32_t BUF_SIZE = 1 << 17;
char ibuf[BUF_SIZE], obuf[BUF_SIZE], out[100];
uint32_t pil = 0, pir = 0, por = 0;

struct Pre {
	char num[10000][4];

	constexpr Pre() : num() {
		for (int i = 0; i < 10000; ++i) {
			int n = i;
			for (int j = 3; j >= 0; --j) {
				num[i][j] = n % 10 | '0';
				n /= 10;
			}
		}
	}
} constexpr pre;

inline void load() {
	std::memcpy(ibuf, ibuf + pil, pir - pil);
	pir = pir - pil + std::fread(ibuf + pir - pil, 1, BUF_SIZE - pir + pil, stdin);
	pil = 0;
	if (pir < BUF_SIZE) ibuf[pir++] = '\n';
}

inline void flush() {
	fwrite(obuf, 1, por, stdout);
	por = 0;
}

void _input(char &dest) {
	do {
		if (pil + 1 > pir) load();
		dest = ibuf[pil++];
	} while (std::isspace(dest));
}

void _input(std::string &dest) {
	dest.clear();
	char c;
	do {
		if (pil + 1 > pir) load();
		c = ibuf[pil++];
	} while (std::isspace(c));
	do {
		dest += c;
		if (pil == pir) load();
		c = ibuf[pil++];
	} while (!std::isspace(c));
}

void _input(float &dest) {
	std::string s;
	_input(s);
	dest = std::stof(s);
}

void _input(double &dest) {
	std::string s;
	_input(s);
	dest = std::stod(s);
}

void _input(long double &dest) {
	std::string s;
	_input(s);
	dest = std::stold(s);
}

template <typename T>
void input_int(T &x) {
	if (pil + 100 > pir) load();
	char c;
	do {
		c = ibuf[pil++];
	} while (c < '-');
	bool minus = 0;
	if constexpr (std::is_signed<T>::value || std::is_same_v<T, __int128_t>) {
		if (c == '-') minus = 1, c = ibuf[pil++];
	}
	x = 0;
	while (c >= '0') x = x * 10 + (c & 15), c = ibuf[pil++];
	if constexpr (std::is_signed<T>::value || std::is_same_v<T, __int128_t>) {
		if (minus) x = -x;
	}
}

void _input(int &dest) { input_int(dest); }
void _input(unsigned int &dest) { input_int(dest); }
void _input(long long &dest) { input_int(dest); }
void _input(unsigned long long &dest) { input_int(dest); }
void _input(__int128 &dest) { input_int(dest); }
void _input(unsigned __int128 &dest) { input_int(dest); }

template <uint32_t m>
void _input(cpstd::StaticModint<m> &dest) { long long a; _input(a); dest = a; }

template <typename T, typename U>
void _input(std::pair<T, U> &dest) { _input(dest.first), _input(dest.second); }

template <std::size_t N = 0, typename T>
void input_tuple(T &t) {
	if constexpr (N < std::tuple_size<T>::value) {
		auto &x = std::get<N>(t);
		input(x);
		input_tuple<N + 1>(t);
	}
}

template <typename... T>
void _input(std::tuple<T...> &dest) { input_tuple(dest); }

template <std::size_t N = 0, typename T>
void _input(std::array<T, N> &dest) { for (auto &e : dest) _input(e); }

template <typename T>
void _input(std::vector<T> &dest) { for (auto &e : dest) _input(e); }

void input() {}

// 各引数に入力
template <typename H, typename... T>
void input(H &desth, T &... destt) { _input(desth), input(destt...); }

void _print(const char tg) {
	if (por == BUF_SIZE) flush();
	obuf[por++] = tg;
}

void _print(const std::string tg) { for (char c : tg) _print(c); }

void _print(const char *tg) {
	std::size_t len = std::strlen(tg);
	for (std::size_t i = 0; i < len; ++i) _print(tg[i]);
}

template <typename T>
void print_int(T x) {
	if (por > BUF_SIZE - 100) flush();
	if (x < 0) obuf[por++] = '-', x = -x;
	int outi;
	for (outi = 96; x >= 10000; outi -= 4) {
		std::memcpy(out + outi, pre.num[x % 10000], 4);
		x /= 10000;
	}
	if (x >= 1000) {
		std::memcpy(obuf + por, pre.num[x], 4);
		por += 4;
	}
	else if (x >= 100) {
		std::memcpy(obuf + por, pre.num[x] + 1, 3);
		por += 3;
	}
	else if (x >= 10) {
		int q = (x * 103) >> 10;
		obuf[por] = q | '0';
		obuf[por + 1] = (x - q * 10) | '0';
		por += 2;
	}
	else obuf[por++] = x | '0';
	std::memcpy(obuf + por, out + outi + 4, 96 - outi);
	por += 96 - outi;
}

template <typename T>
void print_real(T tg) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(15) << double(tg);
	std::string s = oss.str();
	_print(s);
}

void _print(int tg) { print_int(tg); }
void _print(unsigned int tg) { print_int(tg); }
void _print(long long tg) { print_int(tg); }
void _print(unsigned long long tg) { print_int(tg); }
void _print(__int128 tg) { print_int(tg); }
void _print(unsigned __int128 tg) { print_int(tg); }
void _print(float tg) { print_real(tg); }
void _print(double tg) { print_real(tg); }
void _print(long double tg) { print_real(tg); }

template <uint32_t m>
void _print(StaticModint<m> tg) { print_int(tg.val()); }

template <typename T, typename U>
void _print(const std::pair<T, U> tg) {
	_print(tg.first);
	_print(' ');
	_print(tg.second);
}

template <std::size_t N = 0, typename T>
void print_tuple(const T tg) {
	if constexpr (N < std::tuple_size<T>::value) {
		if constexpr (N > 0) _print(' ');
		const auto x = std::get<N>(tg);
		_print(x);
		print_tuple<N + 1>(tg);
	}
}

template <typename... T>
void _print(std::tuple<T...> tg) { print_tuple(tg); }

template <typename T, std::size_t N>
void _print(const std::array<T, N> tg) {
	auto len = tg.size();
	for (std::size_t i = 0; i < len; ++i) {
		if (i) _print(' ');
		_print(tg[i]);
	}
}

template <typename T>
void _print(const std::vector<T> tg) {
	auto  len = tg.size();
	for (std::size_t i = 0; i < len; ++i) {
		if (i) _print(' ');
		_print(tg[i]);
	}
}

void print() { _print('\n'); }

// 各引数を空白区切りで出力し改行
template <typename H, typename... T>
void print(H &&tgh, T &&... tgt) {
	_print(tgh);
	if (sizeof...(tgt)) _print(' ');
	print(std::forward<T>(tgt)...);
}

void __attribute__((destructor)) _d() { flush(); }

};

using Fastio::input;
using Fastio::print;
using Fastio::flush;

};
