#include "MaxHeap.hpp"
#include "quicksort.hpp"


int main() {

	std::cout << "Testing quick sort:\n";
	std::vector<int> testArr{ 3,5,1,2,6,4 };
	for (auto& v : testArr) {
		std::cout << v << " ";
	}
	std::cout << std::endl;
	quicksort(testArr);
	// after
	for (auto& v : testArr) {
		std::cout << v << " ";
	}
	std::cout << std::endl;

	std::cout << "Testing max heap:\n";


	MaxHeap heap;
	heap.Add(5);
	heap.Add(8);
	heap.Add(2);
	heap.Add(1);
	heap.Add(4);
	heap.Add(7);
	heap.print();
	// good, a tree-like structure.

	// remove is not done yet..
	heap.remove(2);
	heap.print();
	heap.remove(1);
	heap.print();
}