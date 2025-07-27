#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
#include "cpstl/other/Fastio.hpp"
#include "cpstl/ds/Dsu.hpp"

int main() {
	int N, Q;
	cpstd::input(N, Q);
	cpstd::Dsu dsu(N);
	int t, u, v;
	while (Q--) {
		cpstd::input(t, u, v);
		if (t == 0) dsu.merge(u, v);
		else cpstd::print((dsu.same(u, v) ? "1" : "0"));
	}
}
