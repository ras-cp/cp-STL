#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <bits/stdc++.h>
#include "cpstl/other/Fastio.hpp"
#include "cpstl/math/StaticModint.hpp"
#include "cpstl/ds/LazySegtree.hpp"

using mint = cpstd::Modint998244353;
using S = std::pair<mint, mint>;
S op(S a, S b) { return {a.first + b.first, a.second + b.second}; }
S e() { return {0, 0}; }
S mapping(S f, S x) { return {f.first * x.first + x.second * f.second, x.second}; }
S composition(S g, S f) { return {g.first * f.first, g.first * f.second + g.second}; }
S id() { return {1, 0}; }

int main() {
	int N, Q;
	cpstd::input(N, Q);
	std::vector<S> A(N);
	for (auto &a : A) cpstd::input(a.first), a.second = 1;
	cpstd::LazySegtree<S, op, e, S, mapping, composition, id> sg(A);
	while (Q--) {
		int t, l, r;
		cpstd::input(t, l, r);
		if (t == 0) {
			int b, c;
			cpstd::input(b, c);
			sg.apply(l, r, {b, c});
		}
		else cpstd::print(sg.fold(l, r).first);
	}
	return 0;
}
