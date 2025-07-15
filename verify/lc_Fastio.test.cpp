#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include <bits/stdc++.h>
#include "cpstl/Fastio.hpp"

int main() {
	int T;
	cpstd::Cin >> T;
	__int128_t A, B;
	while (T--) {
		cpstd::Cin >> A >> B;
		cpstd::Cout << A + B << '\n';
	}
}
