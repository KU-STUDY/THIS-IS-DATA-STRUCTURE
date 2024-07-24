#include <iostream>
#include <vector>

using namespace std;

void swap(int q1[], int q2[]) {
    int tmp = *q1;
    *q1 = *q2;
    *q2 = tmp;
}
void quickSort(int arr[], int start, int end) {
    if(start >= end) return;
    int pivot = start;
    int qStart = start + 1;
    int qEnd = end;

    while(qStart <= qEnd) {

        while(arr[qStart] < arr[pivot] && qStart < end) {
            qStart++;
        }

        while(arr[qEnd] > arr[pivot] && start <= qEnd) {
            qEnd--;
        }

        if(qStart < qEnd) {
            swap(arr[qStart], arr[qEnd]);
        }
        else {
            swap(arr[qEnd], arr[pivot]);
        }
    }
        quickSort(arr, start, pivot-1);
        quickSort(arr, pivot+1, end);

}

int main(void) {
    int arr[7] = {1,3,2,5,4,7,6};

    quickSort(arr, 0, 6);
    
    for(int i=0; i<7; i++) {
        cout << arr[i] << ' ';
    }
}