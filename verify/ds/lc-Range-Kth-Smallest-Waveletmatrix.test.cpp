#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include "cpstl/other/Template.hpp"
#include "cpstl/ds/WaveletMatrix.hpp"

int main() {
	int N, Q;
	cpstd::input(N, Q);
	std::vector<int> A(N);
	cpstd::input(A);
	cpstd::WaveletMatrix<int> wm(A);
	while (Q--) {
		int l, r, k;
		cpstd::input(l, r, k);
		cpstd::print(wm.quantile(l, r, k));
	}
}
