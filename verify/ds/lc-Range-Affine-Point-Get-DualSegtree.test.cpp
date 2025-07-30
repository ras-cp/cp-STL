#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include <bits/stdc++.h>
#include "cpstl/math/StaticModint.hpp"
#include "cpstl/other/Fastio.hpp"
#include "cpstl/ds/DualSegtree.hpp"

using mint = cpstd::Modint998244353;
using F = std::pair<mint, mint>;
F composition(F g, F f) { return {f.first * g.first, f.second * g.first + g.second}; }
F id() { return {1, 0}; }

int main() {
	int N, Q;
	cpstd::input(N, Q);
	std::vector<mint> A(N);
	cpstd::input(A);
	cpstd::DualSegtree<F, composition, id> sg(N);
	int t, l, r, p;
	mint b, c;
	while (Q--) {
		cpstd::input(t);
		if (t == 0) {
			cpstd::input(l, r, b, c);
			sg.apply(l, r, {b, c});
		}
		else {
			cpstd::input(p);
			F act = sg[p];
			cpstd::print(act.first * A[p] + act.second);
		}
	}
	return 0;
}
