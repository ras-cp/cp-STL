#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb_128bit"

#include <bits/stdc++.h>
#include "cpstl/other/fastio.hpp"

int main() {
	int T;
	cpstd::input(T);
	__int128 A, B;
	while (T--) {
		cpstd::input(A, B);
		cpstd::print(A + B);
	}
}
