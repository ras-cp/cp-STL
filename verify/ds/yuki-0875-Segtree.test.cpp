#define PROBLEM "https://yukicoder.me/problems/no/875"
#include <bits/stdc++.h>
#include "cpstl/other/Fastio.hpp"
#include "cpstl/ds/Segtree.hpp"

int op(int a, int b) { return std::min(a, b); }
int e() { return 100000000; }

int main() {
	int N, Q;
	cpstd::input(N, Q);
	std::vector<int> A(N);
	cpstd::input(A);
	cpstd::Segtree<int, op, e> sg(A);
	int t, l, r, lv;
	while (Q--) {
		cpstd::input(t, l, r);
		if (t == 1) {
			lv = sg[--l];
			sg.set(l, sg[--r]);
			sg.set(r, lv);
		}
		else {
			int mini = sg.fold(--l, r);
			int a1 = sg.max_right(l, [&](int x) -> bool { return x > mini; });
			int a2 = sg.min_left(r, [&](int x) -> bool { return x > mini; });
			--a2;
			assert(a1 == a2);
			cpstd::print(a1 + 1);
		}
	}
	return 0;
}
