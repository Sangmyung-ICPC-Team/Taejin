// Baekjoon02042_SegmentTree.cpp
// https://www.acmicpc.net/problem/2042
#include <iostream>

using namespace std;

typedef long long ll;

class SegmentTree {
	ll* tree;
	int minIdx, maxIdx;

	class Range {
	public:
		int start, end;
		Range(int s, int e): start(s), end(e) { }
		int getMid() {
			return (start + end) / 2;
		}
	};

public:
	SegmentTree(ll arr[], int size) {
		tree = new ll[size * 4];
		fill(tree, tree + size * 4, 0);
		minIdx = 0, maxIdx = size - 1;

		makeTree(1, Range(minIdx, maxIdx), arr);
	}

	~SegmentTree() {
		delete[] tree;
	}

	void makeTree(int treeIdx, Range curr, ll arr[]) {
		if (curr.start == curr.end)
			tree[treeIdx] = arr[curr.start];
		else {
			int left = treeIdx * 2, right = treeIdx * 2 + 1;
			makeTree(left, Range(curr.start, curr.getMid()), arr);
			makeTree(right, Range(curr.getMid() + 1, curr.end), arr);

			tree[treeIdx] = tree[left] + tree[right];
		}
	}

	ll getSum(int start, int end) {
		return getSum(1, Range(minIdx, maxIdx), Range(start, end));
	}

	ll getSum(int treeIdx, Range curr, Range target) {
		if (target.start <= curr.start && curr.end <= target.end)
			return tree[treeIdx];
		else if (curr.end < target.start || target.end < curr.start)
			return 0ll;
		else {
			return (
				getSum(treeIdx * 2, Range(curr.start, curr.getMid()), target) +
				getSum(treeIdx * 2 + 1, Range(curr.getMid() + 1, curr.end), target)
			);
		}
	}

	void update(int targetIdx, ll value) {
		update(1, Range(minIdx, maxIdx), targetIdx, value);
	}

	void update(int treeIdx, Range curr, int target, ll value) {
		if (curr.start == curr.end && curr.start == target)
			tree[treeIdx] = value;
		else if (curr.start <= target && target <= curr.end) {
			int left = treeIdx * 2, right = treeIdx * 2 + 1;
			update(left, Range(curr.start, curr.getMid()), target, value);
			update(right, Range(curr.getMid() + 1, curr.end), target, value);

			tree[treeIdx] = tree[left] + tree[right];
		}
	}
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	ll arr[1'000'000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	SegmentTree segTree(arr, n);
	for (int i = 0; i < m + k; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int idx; ll value;
			cin >> idx >> value;
			segTree.update(idx - 1, value);
		} else {
			int start, end;
			cin >> start >> end;
			cout << segTree.getSum(start - 1, end - 1) << '\n';
		}
	}

	return 0;
}