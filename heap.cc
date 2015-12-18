#include <iostream>
#include <climits>
using namespace std;

class HeapClass {
    private:
	int *arr;
	int size;
	int cursize;
    public:
	HeapClass() : arr(NULL), size(0), cursize(0) {}
	HeapClass(int *ptr, int sz) : arr(ptr), size(sz), cursize(sz) {}
	int deleteElem();
	int top();
	void insertElem(int);
	void heapify(int);
	void siftUp(int);
	void print();
	void sort(int sz);
};

void HeapClass::print() {
    for (int i=0;i<size;i++) {
	cout << arr[i] << " ";
    }
    cout << endl;
}

void HeapClass::heapify(int root) {
    if (root > cursize) return;
    int c1 = 2*root + 1;
    int c2 = 2*root + 2;
    int bigidx = 0;

    if (c1<cursize && c2<cursize) {
	bigidx = (arr[c1] >= arr[c2] ? c1 : c2);
	arr[root] = arr[root]^arr[bigidx]^(arr[bigidx] = arr[root]);
    } else if (c1 == cursize-1) {
	if (arr[c1] > arr[root]) {
	    arr[root] = arr[root]^arr[c1]^(arr[c1] = arr[root]);
	}
	return;
    } else {
	return;
    }
    heapify(bigidx);
}

void HeapClass::siftUp(int idx) {
    if (idx < 1) return;
    int p = (idx-1)/2;
    do {
	heapify(p);
	p--;
    } while(p>=0);
}

int HeapClass::deleteElem() {
    arr[0] = arr[0]^arr[cursize-1]^(arr[cursize-1] = arr[0]);
    cursize--;
    heapify(0);

}

int HeapClass::top() {
    return arr[0];
}

void HeapClass::insertElem(int elem) {
    if (cursize > size) {
	return;
    } else {
	arr[cursize] = elem;
	cursize++;
	siftUp(cursize-1);
    }
}

void HeapClass::sort(int sz) {
    for (int i=0; i<sz; i++) {
	deleteElem();
    }
}

int main() {
    int arr[][5] = {
			{2, 8, 10, 11, 12},
			{21, 4, 7, 9, 13},
			{13, 17, 18, 19, 20},
			{5, 3, 6, 14, 15}
    };

    int* harr = new int[5];
    for (int i=0; i<4; i++) {
	harr[i] = arr[i][0];
    }
    HeapClass Heap(harr, 4);
    Heap.print();
    Heap.siftUp(4-1);
    Heap.print();
    Heap.sort(4);
    Heap.print();
    return 0;
}
