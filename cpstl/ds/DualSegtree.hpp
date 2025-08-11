#pragma once

#include "cpstl/other/Template.hpp"

namespace cpstd {

// @brief Dual Segment Tree
// @see

template <
	typename F,
	auto composition,
	auto id
>
class DualSegtree {
	private:
	std::vector<F> lazy;
	int N, sz, log;

	void pushdown(int pos) {
		for (int i = log; i >= 1; --i) {
			int p = pos >> i;
			lazy[p << 1] = composition(lazy[p], lazy[p << 1]);
			lazy[p << 1 | 1] = composition(lazy[p], lazy[p << 1 | 1]);
			lazy[p] = id();
		}
	}

	public:
	DualSegtree() {}
	explicit DualSegtree(int n) : N(n) {
		sz = std::bit_ceil((unsigned int)(N));
		log = std::bit_width((unsigned int)(sz)) - 1;
		lazy.assign(sz << 1, id());
	}

	// [pos] への作用素を f にする
	// O(logN) time
	void set(int pos, const F &f) {
		assert(0 <= pos && pos < N);
		pos += sz;
		pushdown(pos);
		lazy[pos] = f;
	}

	// [pos] に f を作用させる
	// O(logN) time
	void apply(int pos, const F &f) {
		assert(0 <= pos && pos < N);
		pos += sz;
		pushdown(pos);
		lazy[pos] = composition(f, lazy[pos]);
	}

	// [l, r) に f を作用させる
	// O(logN) time
	void apply(int l, int r, const F &f) {
		assert(0 <= l && l <= r && r <= N);
		if (l == r) return;
		l += sz, r += sz;
		pushdown(l), pushdown(r - 1);
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) lazy[l] = composition(f, lazy[l]), ++l;
			if (r & 1) --r, lazy[r] = composition(f, lazy[r]);
		}
	}

	// [pos] の作用素を返す
	// O(logN) time
	F get(int pos) {
		assert(0 <= pos && pos < N);
		pos += sz;
		pushdown(pos);
		return lazy[pos];
	}

	// [pos] の作用素を返す
	// O(logN) time
	F operator[](int pos) noexcept {
		pos += sz;
		pushdown(pos);
		return lazy[pos];
	}
};
};
