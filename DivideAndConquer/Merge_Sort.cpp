#include<iostream>
#include<vector>
using namespace std;

// Utility function to print vector
void PrintVec(const vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

// Merge function
void Merge(vector<int> &nums, int st, int mid, int end){

    int i = st;
    int j = mid + 1;

    vector<int> temp;

    // Merge two sorted halves
    while(i <= mid && j <= end){
        if(nums[i] <= nums[j]){
            temp.push_back(nums[i]);
            i++;
        } else {
            temp.push_back(nums[j]);
            j++;
        }
    }

    // Remaining elements (left half)
    while(i <= mid){
        temp.push_back(nums[i]);
        i++;
    }

    // Remaining elements (right half)
    while(j <= end){
        temp.push_back(nums[j]);
        j++;
    }

    // Copy back to original array
    for(int idx = st, k = 0; idx <= end; idx++, k++){
        nums[idx] = temp[k];
    }
}

// Merge Sort function
void MergeSort(vector<int> &nums, int st, int end){

    if(st >= end){
        return;
    }

    int mid = st + (end - st) / 2;

    // Sort left half
    MergeSort(nums, st, mid);

    // Sort right half
    MergeSort(nums, mid + 1, end);

    // Merge both halves
    Merge(nums, st, mid, end);
}

int main(){

    vector<int> nums = {6, 3, 7, 5, 2, 4};

    MergeSort(nums, 0, nums.size() - 1);

    cout << "Sorted Array: ";
    PrintVec(nums);

    return 0;
}