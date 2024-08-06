#include <iostream>
#include <stdexcept>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class PriorityQueue {
    private:
        vector<int> heap;

    public: 
        void heapifyUp(int index) {
            int parent = (index - 1) / 2;
            while(index > 0 && heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
                parent = (index - 1) / 2;
            }
        }

        void heapifyDown(int index) {
            int size = heap.size();
            int leftChild = (2 * index) + 1;
            int rightChild = (2 * index) + 2;
            int largest = index;

            if(leftChild < size && heap[largest] < heap[leftChild]) largest = leftChild;
            if(rightChild < size && heap[largest] < heap[rightChild]) largest = rightChild;

            if(largest != index) {
                swap(heap[index], heap[largest]);
                heapifyDown(largest);
            } 
        }

        bool isEmpty() {
            return heap.empty();
        }

        int size() {
            return heap.size();
        }

        int top() {
            if(!isEmpty()) return heap.front();
        }

        void pop() {
            if(!isEmpty()) {
                heap[0] = heap.back();
                heap.pop_back();
                heapifyDown(0);
            }
        }

        void push(int value) {
            heap.push_back(value);
            heapifyUp(heap.size() - 1);
        }
        
        void print() {
            for(int i=0; i<heap.size(); i++) {
                cout << "인덱스 " << i << ": " << heap[i] << "\n";
            }
        }
};

int main(void) {
    PriorityQueue pq;
    srand(time(NULL));

    for(int i=0; i<100; i++) pq.push(rand() % 100 + 1);

    pq.print();

    for(int i=0; i<100; i++) {
        cout << "최대 값: " << pq.top() << "\n";
        pq.pop();
    }
    
    return 0;
}