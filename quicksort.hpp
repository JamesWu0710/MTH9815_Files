// quicksort.hpp
// James Wu

#include <vector>
#include <iostream>

int partition(std::vector<int>& arr, int l, int r) {
	// default pivot
	auto pivot = arr[r];
	auto i = l - 1;
	for (int j = l; j < r; ++j) {
		if (arr[j] <= pivot) {
			i++;

			// swap
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}

	// swap
	int temp = arr[i + 1];
	arr[i + 1] = arr[r];
	arr[r] = temp;
	return i + 1;
}

void _quicksort(std::vector<int>& arr, int l, int r) {
	if (l < r) {
		int pivot = partition(arr, l, r);
		_quicksort(arr, l, pivot - 1);
		_quicksort(arr, pivot + 1, r);
	}
}

void quicksort(std::vector<int>& arr) {
	int l = 0;
	int r = arr.size() - 1;
	_quicksort(arr, l, r);
}