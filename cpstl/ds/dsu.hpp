#pragma once
namespace cpstd {

// Disjoint Set Union
// union by size + path compression

class dsu {
	private:
	int _n;
	std::vector<int> tree;

	int _leader(int x) {
		return tree[x] < 0 ? x : tree[x] = _leader(tree[x]);
	}

	public:
	dsu() {}
	explicit dsu(int n) : _n(n), tree(n, -1) {}

	// `x` の属する集合の代表元を返す
	// amortized O(α(N)) time
	int leader(int x) {
		assert(0 <= x && x < _n);
		return tree[x] ? x : _leader(tree[x]);
	}

	// `a`, `b` の属する集合を併合し，元々異なる集合に属していたかを返す
	// amortized O(α(N)) time
	bool merge(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		a = _leader(a), b = _leader(b);
		if (a == b) return false;
		if (tree[a] > tree[b]) std::swap(a, b);
		tree[a] += tree[b];
		tree[b] = a;
		return true;
	}

	// `a` と `b` が同じ集合に属するか返す
	// amoritized O(α(N)) time
	bool same(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		return _leader(a) == _leader(b);
	}

	// `x` が属する集合の大きさを返す
	// amortized O(α(N)) time
	int size(int x) {
		assert(0 <= x && x < _n);
		return -tree[_leader(x)];
	}

	// 集合ごとに配列にまとめた配列を返す
	// O(Nα(N)) time
	std::vector<std::vector<int>> groups() {
		std::vector<std::vector<int>> mem, res;
		for (int i = 0; i < _n; ++i) mem[_leader(i)].push_back(i);
		for (int i = 0; i < _n; ++i) {
			if (!mem[i].empty()) res.emplace_back(mem[i]);
		}
		return res;
	}
};
};
