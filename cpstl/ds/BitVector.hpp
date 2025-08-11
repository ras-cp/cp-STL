#pragma once

#include "cpstl/other/Template.hpp"

namespace cpstd {

// @brief Succint Bit Vector

struct BitVector {
	private:
	using u32 = unsigned int;
	using u64 = unsigned long long;
	std::vector<u64> block;
	std::vector<u32> cnt;
	u32 N, zero, sz;

	public:
	BitVector() {}
	explicit BitVector(u32 _N) : N(_N), sz(((_N + 1) >> 6) + 1) {
		block.resize(sz);
		cnt.resize(sz);
	}

	// [pos] を x の i-th bit で更新
	// O(1) time
	void set(u32 i, u64 x = 1ULL) {
		assert((i >> 6) < sz);
		block[i >> 6] |= (x << (i & 63));
	}

	// データ構造を構築する
	// O(N) time
	void build() {
		for (u32 i = 1; i < sz; ++i) cnt[i] = cnt[i - 1] + std::popcount(block[i - 1]);
		zero = rank_0(N);
	}

	// [0, i) に含まれる 1 の数を返す
	// O(1) time
	u32 rank_1(u32 i) const {
		assert((i >> 6) < sz);
		return cnt[i >> 6] + std::popcount(block[i >> 6] & ((1ULL << (i & 63)) - 1ULL));
	}

	// [l, r) に含まれる 1 の数を返す
	// O(1) time
	u32 rank_1(u32 l, u32 r) const { return rank_1(r) - rank_1(l); }

	// [0, i) に含まれる 0 の数を返す
	// O(1) time
	u32 rank_0(u32 i) const { return i - rank_1(i); }

	// [l, r) に含まれる 0 の数を返す
	// O(1) time
	u32 rank_0(u32 l, u32 r) const { return rank_0(r) - rank_0(l); }

	// [0, N) に含まれる 0 の数を返す
	// O(1) time
	u32 rank_0() const { return zero; }

	// [pos] を返す
	// O(1) time
	u32 get(u32 i) const {
		assert((i >> 6) < sz);
		return (u32)(block[i >> 6] >> (i & 63)) & 1;
	}

	// [pos] を返す (assert なし)
	// O(1) time
	u32 operator[](u32 i) const noexcept { return (u32)(block[i >> 6] >> (i & 63)) & 1; }
};

};
