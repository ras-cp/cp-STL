#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <bits/stdc++.h>
#include "cpstl/other/fastio.hpp"
#include "cpstl/ds/dsu.hpp"

int main() {
	int N, Q;
	cpstd::input(N, Q);
	cpstd::dsu uf(N);
	int t, u, v;
	while (Q--) {
		cpstd::input(t, u, v);
		if (t == 0) uf.merge(u, v);
		else cpstd::print((uf.same(u, v) ? "1" : "0"));
	}
}
