#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>

using namespace std;

//HEAP은 배열의 인덱스가 1부터 시작한다.
#define HEAP_SIZE 256


class maxHeap {

    private:
        int heap[HEAP_SIZE];
        int heapCount;
        int chooseChild(int leftChild, int rightChild, int childNum);
    public:
        maxHeap() {
            heapCount = 0;
        }
        void swap(int *a, int *b);
        void push(int data);
        int pop();
};

void maxHeap::push(int data) {
    heap[++heapCount] = data;

    int child = heapCount;
    int parent = child / 2;
    while(child > 1 && heap[parent] < heap[child]) {
        swap(&heap[parent], &heap[child]);
        child = parent;
        parent = child / 2;
    }
}
void maxHeap::swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int maxHeap::pop() {
    int result = heap[1];
    swap(&heap[1], &heap[heapCount]);
    heapCount--;

    int parent = 1;
    int child = parent * 2;
    if(child + 1 <= heapCount) child = chooseChild(heap[child], heap[child+1], child);

    while(child <= heapCount && heap[parent] < heap[child]) {
        swap(&heap[parent], &heap[child]);

        parent = child;
        child = child * 2;
        if(child + 1 <= heapCount) child = chooseChild(heap[child], heap[child+1], child);
    }
    return result;
}

int maxHeap::chooseChild(int leftChild, int rightChild, int childNum) {
    return leftChild > rightChild ? childNum : childNum + 1; 
}

int main(void) {
    maxHeap heap;
    srand(time(NULL));

    for(int i=0; i<50; i++) {
        heap.push(rand() % 50 + 1);
    }
    
    for(int i=0; i<50; i++) {
        cout << heap.pop() << '\n';
    }

    return 0;
}