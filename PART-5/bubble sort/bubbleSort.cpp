#include <iostream>
#include <vector>

using namespace std;

void BubbleSort(vector<int> arr){
    int size = arr.size();
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-(i+1); j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
     for (int i = 0; i<size; i++) {
        cout << arr[i] << " ";
    }
}

int main(void){
    vector <int> arr = {5, 3, 2, 4, 1};
    BubbleSort(arr);
}