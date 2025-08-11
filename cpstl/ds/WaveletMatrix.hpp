#pragma once

#include "cpstl/other/Template.hpp"
#include "cpstl/ds/BitVector.hpp"

namespace cpstd {

// @brief Wavelet Matrix
// @see https://miti-7.hatenablog.com/entry/2018/04/28/152259
// @see https://takeda25.hatenablog.jp/entry/20130303/1362301095
// @see https://drken1215.hatenablog.com/entry/2023/10/19/220215

template <typename T>
class WaveletMatrix {
	private:
	static_assert(std::is_integral_v<T>, "template parameter T must be integral type");
	std::vector<cpstd::BitVector> bv;
	std::vector<std::vector<T>> sum;
	std::vector<T> dat;
	int N, lgm;

	public:
	WaveletMatrix() {}
	explicit WaveletMatrix(int _N) : N(_N), dat(_N, 0) {}
	explicit WaveletMatrix(const std::vector<T> &v) : N((int)v.size()), dat(v) { build(); }

	// [pos] ← x で更新
	// O(1) time
	void set(int pos, T &x) {
		assert(0 <= pos && pos < N && x >= 0);
		dat[pos] = x;
	}

	// データ構造を構築する
	// O(NlogM) time (M = max [i])
	void build() {
		T maxi = 1;
		for (auto val : dat) maxi = std::max(maxi, val);
		lgm = std::bit_width((unsigned int)(maxi));
		std::vector<int> left(N), right(N), ord(N);
		std::iota(ord.begin(), ord.end(), 0);
		bv.assign(lgm, BitVector(N));
		sum.assign(lgm + 1, std::vector<T>(N + 1, 0));
		for (int pos = lgm - 1; pos >= 0; --pos) {
			int l = 0, r = 0;
			for (int i = 0; i < N; ++i) {
				if ((dat[ord[i]] >> pos) & 1) {
					bv[pos].set(i);
					right[r++] = ord[i];
				}
				else left[l++] = ord[i];
			}
			bv[pos].build();
			ord.swap(left);
			for (int i = 0; i < r; ++i) ord[i + l] = right[i];
			for (int i = 0; i < N; ++i) sum[pos][i + 1] = sum[pos][i] + dat[ord[i]];
		}
	}

	// [pos] を返す
	// O(logM) time
	T get(int pos) const {
		assert(0 <= pos && pos < N);
		return operator[](pos);
	}

	// [pos] を返す (assert なし)
	// O(logN) time
	T operator[](int pos) const noexcept {
		T res = 0;
		for (int b = lgm - 1; b >= 0; --b) {
			int z = bv[b].rank_0(pos);
			if (bv[b].get(pos)) {
				pos += bv[b].rank_0() - z;
				res |= T(1) << b;
			}
			else pos = z;
		}
		return res;
	}

	// [l, r) に含まれる x の個数を返す
	// O(logN) time
	int freq(int l, int r, T x) const {
		assert(0 <= l && l <= r && r <= N);
		for (int pos = lgm - 1; pos >= 0; --pos) {
			int l0 = bv[pos].rank_0(l), r0 = bv[pos].rank_0(r);
			if ((x >> pos) & 1) {
				l += bv[pos].rank_0() - l0;
				r += bv[pos].rank_0() - r0;
			}
			else l = l0, r = r0;
		}
		return r - l;
	}

	// [l, r) に含まれる ub 未満の値の個数を返す
	// O(logM) time
	int range_freq(int l, int r, T ub) const {
		assert(0 <= l && l <= r && r <= N);
		int res = 0;
		for (int pos = lgm - 1; pos >= 0; --pos) {
			int l0 = bv[pos].rank_0(l), r0 = bv[pos].rank_0(r);
			if ((ub >> pos) & 1) {
				l += bv[pos].rank_0() - l0;
				r += bv[pos].rank_0() - r0;
				res += r0 - l0;
			}
			else l = l0, r = r0;
		}
		return res;
	}

	// [l, r) に含まれる lb 以上 ub 未満の値の個数を返す
	// O(logM) time
	int range_freq(int l, int r, T lb, T ub) const { return range_freq(l, r, ub) - range_freq(l, r, lb); }

	// [l, r) をソートしたときの k 番目の要素 (0-indexed) を返す
	// O(logM) time
	T quantile(int l, int r, int k) const {
		assert(0 <= l && l <= r && r <= N);
		T res = 0;
		for (int pos = lgm - 1; pos >= 0; --pos) {
			int l0 = bv[pos].rank_0(l), r0 = bv[pos].rank_0(r);
			if (r0 - l0 <= k) {
				l += bv[pos].rank_0() - l0;
				r += bv[pos].rank_0() - r0;
				k -= r0 - l0;
				res |= T(1) << pos;
			}
			else l = l0, r = r0;
		}
		return res;
	}

	// [l, r) の降順上位 k 個の積を返す
	T top_k_fold(int l, int r, int k) const {
		assert(0 <= l && l <= r && r <= N);
		if (l == r) return 0;
		T res = 0, val = 0;
		for (int pos = lgm - 1; pos >= 0; --pos) {
			int l0 = bv[pos].rank_0(l), r0 = bv[pos].rank_0(r);
			if (r0 - l0 <= k) {
				l += bv[pos].rank_0() - l0;
				r += bv[pos].rank_0() - r0;
				k -= r0 - l0;
				val = T(1) << pos;
				res += sum[pos][r0] - sum[pos][l0];
			}
			else l = l0, r = r0;
		}
		res += val * k;
		return res;
	}

	// [l, r) に含まれる x 未満最大の要素 (存在しなければ -1) を返す
	// O(logM) time
	T pred(int l, int r, T x) const {
		assert(0 <= l && l <= r && r <= N);
		int f = range_freq(l, r, x);
		return f ? quantile(l, r, f - 1) : T(-1);
	}

	// [l, r) に含まれる x 以上最小の要素 (存在しなければ -1) を返す
	// O(logM) time
	T succ(int l, int r, T x) const {
		assert(0 <= l && l <= r && r <= N);
		int f = range_freq(l, r, x);
		return f != r - l ? quantile(l, r, f) : T(-1);
	}
};
};
