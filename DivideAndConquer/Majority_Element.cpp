#include<iostream>
#include<vector>
using namespace std;

// Function to count frequency and decide majority
int Merge(vector<int> &nums, int st, int end, int left, int right){

    int freq1 = 0;
    int freq2 = 0;

    for(int i = st; i <= end; i++){
        if(nums[i] == left){
            freq1++;
        }
        else if(nums[i] == right){
            freq2++;
        }
    }

    if(freq1 >= freq2){
        return left;
    }
    return right;
}

// Recursive function
int MergeSort(vector<int> &nums, int st, int end){

    if(st == end){
        return nums[st];
    }

    int mid = st + (end - st) / 2;

    int left = MergeSort(nums, st, mid);
    int right = MergeSort(nums, mid + 1, end);

    // If both halves agree
    if(left == right){
        return left;
    }

    // Otherwise count and decide
    return Merge(nums, st, end, left, right);
}

int main(){

    vector<int> nums = {2, 2, 1, 3, 3, 3, 3};

    int ans = MergeSort(nums, 0, nums.size() - 1);

    cout << "Majority Element: " << ans;

    return 0;
}