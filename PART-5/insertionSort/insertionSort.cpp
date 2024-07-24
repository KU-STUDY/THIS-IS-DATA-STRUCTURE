#include <iostream>
#include <vector>

using namespace std;
void print(vector<int> arr);
void insertionSort(vector <int> arr) {
    for(int i=1; i<arr.size(); i++) {
        int j = i-1;
        int tmp = arr[i];
        for(j; arr[j] > tmp && j>=0; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = tmp;
    }
    print(arr);
}

void print(vector <int> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main(void) {
    vector <int> arr = {2,3,1,5,4};
    insertionSort(arr);
}