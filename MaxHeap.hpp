// implementation of the max heap,by James Wu

#include <vector>
#include <iostream>

class MaxHeap {
private:
	std::vector<int> arr;
	int size;

	// fetch the childs and parent
	int left(int idx) {
		return 2 * idx;
	}

	int right(int idx) {
		return 2 * idx + 1;
	}

	int parent(int idx) {
		return idx / 2;
	}

	void swap(int x, int y) {
		int tmp = arr[x];
		arr[x] = arr[y];
		arr[y] = tmp;
	}

	// the required function for elementing the remove
	void heapify(int x) {
		int l, r, mx;
		l = left(x);
		r = right(x);
		if (l <= size && arr[l] > arr[x]) {
			mx = l;
		}
		else {
			mx = x;
		}
		if (r <= size && arr[r] > arr[mx]) {
			mx = r;
		}
		// track the largest index.
		if (mx != x) {
			swap(x, mx);
			heapify(mx);
		}
	}

public:
	MaxHeap() {
		size = 0;
	}

	void Add(int x) {
		// store the element
		arr.push_back(x);
		size++;

		// record the index
		int cur = size - 1;
		int p_idx = parent(cur);

		// need to swap!
		while (cur && arr[cur] > arr[p_idx]) {
			swap(cur, p_idx);

			// find the new index
			cur = p_idx;
			p_idx = parent(cur);
		}
	}

	void print() {
		for (auto& i : arr) {
			std::cout << i << ", ";
		}
		std::cout<<std::endl;
	}

	void remove(int idx) {
		if (size == 0 || idx >= size) {
			std::cout << "No removal done.\n";
		}
		int tmp = arr[idx];
		arr[idx] = arr[size - 1];
		size--;
		arr.pop_back();
		heapify(idx);
	}
};