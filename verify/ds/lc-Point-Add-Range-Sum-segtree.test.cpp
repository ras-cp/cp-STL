#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <bits/stdc++.h>
#include "cpstl/other/fastio.hpp"
#include "cpstl/ds/segtree.hpp"

long long op(long long a, long long b) { return a + b; }
long long e() { return 0; }

int main() {
	int N, Q;
	cpstd::input(N, Q);
	std::vector<long long> A(N);
	cpstd::input(A);
	cpstd::segtree<long long, op, e> sg(A);
	int t;
	while (Q--) {
		cpstd::input(t);
		if (t == 0) {
			int p;
			long long x;
			cpstd::input(p, x);
			sg.add(p, x);
		}
		else {
			int l, r;
			cpstd::input(l, r);
			cpstd::print(sg.fold(l, r));
		}
	}
	return 0;
}
