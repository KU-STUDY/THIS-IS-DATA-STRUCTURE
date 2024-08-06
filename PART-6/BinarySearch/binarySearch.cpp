#include <iostream>

using namespace std;

int BinarySearch(int arr[], int size, int data) {
    int start = 0;
    int end = size - 1;

    while(start <= end) {
        int mid = (start + end) / 2;
        if(data > arr[mid]) start = mid + 1;
        
        else if(data < arr[mid]) end = mid - 1;
        
        else if(data == arr[mid]) return mid;
    }

    return -1;
}

int main(void) {
    int arr[5] = {1,2,3,4,5};
    int arr2[6] = {1,2,3,4,5,6};

    cout << BinarySearch(arr, 5, 0);
}