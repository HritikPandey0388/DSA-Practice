#include<iostream>
#include<vector>
using namespace std;

// Function to maintain heap property
void Heapify(int i, vector<int>& arr, int n){

    // Left and right child indices
    int leftIdx = 2*i + 1;
    int rightIdx = 2*i + 2;

    // current index --> smallest
    int maxIdx = i;

    // if left child --> smaller
    if(leftIdx < n && arr[leftIdx] < arr[maxIdx]){
        maxIdx = leftIdx;
    }

    // if right child --> smaller
    if(rightIdx < n && arr[rightIdx] < arr[maxIdx]){
        maxIdx = rightIdx;
    }

    // If smallest element is not parent
    // swap and heapify again
    if(maxIdx != i){
        swap(arr[maxIdx], arr[i]);
        Heapify(maxIdx, arr, n);
    }
}

// Heap Sort function
void HeapSort(vector<int>& arr, int n){

    // Build Min Heap
    for(int i = n/2; i >= 0; i--){
        Heapify(i, arr, n);
    }

    // Move smallest element to end one by one
    for(int i = n-1; i >= 0; i--){

        // Put root element at correct position
        swap(arr[0], arr[i]);

        // Heapify remaining heap
        Heapify(0, arr, i);
    }
}

int main(){

    vector<int> arr = {1,4,2,5,3};

    int n = arr.size();

    HeapSort(arr, n);

    // Print sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}