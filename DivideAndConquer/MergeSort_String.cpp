#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PrintVec(const vector<string> &nums){
    for(int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

void Merge(vector<string> &nums, int st, int mid, int end){

    int i = st;        
    int j = mid + 1;   

    vector<string> temp;  // temporary array to store sorted elements

    // Compare elements from both halves and pick smaller one
    while(i <= mid && j <= end){
        if(nums[i] <= nums[j]){      
            temp.push_back(nums[i]); 
            i++;
        }
        else{
            temp.push_back(nums[j]); // take from right
            j++;
        }
    }

    // Copy remaining elements from left half (if any)
    while(i <= mid){
        temp.push_back(nums[i]);
        i++;
    }

    // Copy remaining elements from right half (if any)
    while(j <= end){
        temp.push_back(nums[j]);
        j++;
    }

    // Copy sorted elements back to original array
    for(int idx = st, k = 0; idx <= end; idx++, k++){
        nums[idx] = temp[k];
    }
}

void MergeSort(vector<string> &nums, int st, int end){

    if(st >= end){   // base case
        return;
    }

    int mid = st + (end - st) / 2;   // divide array into two halves

    MergeSort(nums, st, mid);        // sort left half
    MergeSort(nums, mid + 1, end);   // sort right half

    Merge(nums, st, mid, end);       // merge sorted halves
}

int main(){

    vector<string> nums = {"sun", "earth", "mars", "mercury"};

    MergeSort(nums, 0, nums.size() - 1);

    PrintVec(nums);

    return 0;
}