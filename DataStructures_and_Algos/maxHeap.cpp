#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

class maxHeap {
    private: 
        int _size{};
        vector<int> vect = {-1}; // First number must be something we just won't ever touch

        // Helper Functions
        int parent(int i) {return i>>1;};           // i / 2
        int left(int i) {return i<<1;};             // i * 2
        int right(int i) {return (i<<1) + 1;};       // i * 2 + 1

    public:
        bool isEmpty() const {return _size == 0;};
        int getMax() const {return vect[1];};
        void insertItem(int val);
        void shiftUp(int i);
        void shiftDown(int i);
        int extractMax();
};

void maxHeap::shiftUp(int i) {
	if (i > _size) return;
	if (i == 1) return;						// Base Case for Recursion
	if (vect[i] > vect[parent(i)]) {
		std::swap(vect[parent(i)], vect[i]);	// Swap Parent with Child
	}
	shiftUp(parent(i));
}

void maxHeap::insertItem(int val) {
    if (_size + 1 >= vect.size()) {
        vect.push_back(0);
    }
    vect[++_size] = val;
    shiftUp(_size);
    return;
}

void maxHeap::shiftDown(int i) {
	if (i > _size) return;

	int swapId = i;
	
	if (left(i) < _size && vect[i] < vect[left(i)]) {
		swapId = left(i);
	}

	if (right(i) < _size && vect[swapId] < vect[right(i)]) {
		swapId = right(i);
	}

	if (swapId != i) {
		std::swap(vect[i], vect[swapId]);
		shiftDown(swapId);
	}

	return;
}

int maxHeap::extractMax(){
	int maxNumber = vect[1];
	std::swap(vect[1], vect[_size--]);
	shiftDown(1);
	return maxNumber;
}

int main(){
	maxHeap* PriorityQueue = new maxHeap();
	if (PriorityQueue->isEmpty()) {
		cout << "Yes this is the correct answer" << endl;
	} else {
		cout << "We have a problem with our isEmpty function. " << endl;
	}

	PriorityQueue->insertItem(10);
	PriorityQueue->insertItem(120);
	PriorityQueue->insertItem(34);
	PriorityQueue->insertItem(41);
	PriorityQueue->insertItem(5);

	cout << PriorityQueue->getMax() << endl;
	PriorityQueue->extractMax();
	cout << PriorityQueue->getMax() << endl;

	if (PriorityQueue->isEmpty()) {
		cout << "Yes this is the correct answer" << endl;
	} else {
		cout << "We have a problem with our isEmpty function. " << endl;
	}
}