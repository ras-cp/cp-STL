#pragma once

#include <vector>
#include <cassert>
#include <bit>

namespace cpstd {

// Lazy Segment Tree

template <
	typename S,
	auto op,
	auto e,
	typename F,
	auto mapping,
	auto composition,
	auto id
>
class LazySegtree {
	private:
	std::vector<S> dat;
	std::vector<F> lazy;
	int N, sz, log;

	void propagate(int pos, const F &f) {
		dat[pos] = mapping(f, dat[pos]);
		if (pos < sz) lazy[pos] = composition(f, lazy[pos]);
	}

	void pushdown(int pos) {
		if (lazy[pos] == id()) return;
		propagate(pos << 1, lazy[pos]);
		propagate(pos << 1 | 1, lazy[pos]);
		lazy[pos] = id();
	}

	void pushup(int pos) { dat[pos] = op(dat[pos << 1], dat[pos << 1 | 1]); }

	public:
	LazySegtree() {}
	explicit LazySegtree(int n) : LazySegtree(std::vector<S>(n, e())) {}
	explicit LazySegtree(int n, const S &init) : LazySegtree(std::vector<S>(n, init)) {}
	explicit LazySegtree(const std::vector<S> &v) : N((int)v.size()) {
		sz = std::bit_ceil((unsigned int)(N));
		log = std::bit_width((unsigned int)(sz) - 1);
		dat.assign(sz << 1, e());
		lazy.assign(sz << 1, id());
		for (int i = 0; i < N; ++i) dat[i + sz] = v[i];
		for (int i = sz - 1; i >= 1; --i) pushup(i);
	}
	template <class InputIt>
	LazySegtree(InputIt first, InputIt last) : LazySegtree(std::vector<S>(first, last)) {}

	// A[pos] ← x で更新
	// O(logN) time
	void set(int pos, const S &x) {
		assert(0 <= pos && pos < N);
		pos += sz;
		for (int i = log; i >= 1; --i) pushdown(pos >> i);
		dat[pos] = x;
		for (pos >>= 1; pos >= 1; pos >>= 1) pushup(pos);
	}

	// A[pos] ← A[pos] + x で更新
	// O(logN) time
	void add(int pos, const S &x) {
		assert(0 <= pos && pos < N);
		pos += sz;
		for (int i = log; i >= 1; --i) pushdown(pos >> i);
		dat[pos] += x;
		for (pos >>= 1; pos >= 1; pos >>= 1) pushup(pos);
	}

	// A[pos] ← mapping(f, A[pos]) で更新
	// O(logN) time
	void apply(int pos, const F &f) {
		assert(0 <= pos && pos < N);
		pos += sz;
		for (int i = log; i >= 1; --i) pushdown(pos >> i);
		dat[pos] = mapping(f, dat[pos]);
		for (pos >>= 1; pos >= 1; pos >>= 1) pushup(pos);
	}

	// A[l, r) に f を作用させる
	// O(logN) time
	void apply(int l, int r, const F &f) {
		assert(0 <= l && l <= r && r <= N);
		if (l == r) return;
		l += sz, r += sz;
		for (int i = log; i >= 1; --i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown((r - 1) >> i);
		}
		for (int l2 = l, r2 = r; l2 < r2; l2 >>= 1, r2 >>= 1) {
			if (l2 & 1) propagate(l2++, f);
			if (r2 & 1) propagate(--r2, f);
		}
		for (int i = 1; i <= log; ++i) {
			if (((l >> i) << i) != l) pushup(l >> i);
			if (((r >> i) << i) != r) pushup((r - 1) >> i);
		}
	}

	// A[pos] を返す
	// O(logN) time
	S& get(int pos) {
		assert(0 <= pos && pos < N);
		pos += sz;
		for (int i = log; i >= 1; --i) pushdown(pos >> i);
		return dat[pos];
	}

	// A[pos] を返す (assert なし)
	// O(logN) time
	S& operator[](int pos) noexcept {
		pos += sz;
		for (int i = log; i >= 1; --i) pushdown(pos >> i);
		return dat[pos];
	}

	// op[l, r) を返す
	// O(logN) time
	S fold(int l, int r) {
		assert(0 <= l && l <= r && r <= N);
		if (l == r) return e();
		l += sz, r += sz;
		for (int i = log; i >= 1; --i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown((r - 1) >> i);
		}
		S resl = e(), resr = e();
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) resl = op(resl, dat[l++]);
			if (r & 1) resr = op(dat[--r], resr);
		}
		return op(resl, resr);
	}

	// op[1, N] を返す
	// O(1) time
	S all_fold() const { return dat[1]; }

	// `r = l` または `g(op[l, r)) = true`
	// `r = n` または `g(op[l, r]) = false`
	// これらを両方満たす `r` を返す (`g` が単調なら `g(op[l, r)) = true` となる最大の `r`)
	// O(logN) time
	template <auto g>
	int max_right(int l) {
		return max_right(l, [](const S& x) -> bool { return g(x); });
	}
	template <typename G>
	int max_right(int l, const G& g) {
		assert(0 <= l && l <= N);
		assert(g(e()));
		if (l == N) return N;
		l += sz;
		for (int i = log; i >= 1; --i) pushdown(l >> i);
		S s = e();
		do {
			while (!(l & 1)) l >>= 1;
			if (!g(op(s, dat[l]))) {
				while (l < sz) {
					pushdown(l);
					l <<= 1;
					if (g(op(s, dat[l]))) s = op(s, dat[l++]);
				}
				return l - sz;
			}
			s = op(s, dat[l++]);
		} while ((l & -l) != l);
		return N;
	}

	// `l = r` または `g(op[l, r)) = true`
	// `l = 0` または `g(op[l - 1, r)) = false`
	// これらを両方満たす `l` を返す (`g` が単調なら `g(op[l, r)) = true` となる最小の `l`)
	// O(logN) time
	template <auto g>
	int min_left(int r) {
		return min_left(r, [](const S& x) -> bool { return g(x); });
	}
	template <typename G>
	int min_left(int r, const G& g) {
		assert(0 <= r && r <= N);
		assert(g(e()));
		if (r == 0) return 0;
		r += sz;
		for (int i = log; i >= 1; --i) pushdown((r - 1) >> i);
		S s = e();
		do {
			--r;
			while (r > 1 && (r & 1)) r >>= 1;
			if (!g(op(dat[r], s))) {
				while (r < sz) {
					pushdown(r);
					r = r << 1 | 1;
					if (g(op(dat[r], s))) s = op(dat[r--], s);
				}
				return r + 1 - sz;
			}
			s = op(dat[r], s);
		} while ((r & -r) != r);
		return 0;
	}
};
};
