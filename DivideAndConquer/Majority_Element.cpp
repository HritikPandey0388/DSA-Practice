#include<iostream>
#include<vector>
using namespace std;

int countMajority(vector<int> &nums, int st, int end, int left, int right){

    int freq1 = 0; // frequency of left candidate
    int freq2 = 0; // frequency of right candidate

    // Count occurrences of both candidates in current range
    for(int i = st; i <= end; i++){
        if(nums[i] == left){
            freq1++;
        }
        else if(nums[i] == right){
            freq2++;
        }
    }

    // Returns candidate with higher frequency
    return (freq1 >= freq2) ? left : right;
}

int findMajority(vector<int> &nums, int st, int end){

    // Base case
    if(st == end){
        return nums[st];
    }

    // Divide the array into two halves
    int mid = st + (end - st) / 2;

    // Find majority candidate in left half
    int left = findMajority(nums, st, mid);

    // Find majority candidate in right half
    int right = findMajority(nums, mid + 1, end);

    // If both halves agree → return directly
    if(left == right){
        return left;
    }

    // Otherwise count both candidates in full range and decide
    return countMajority(nums, st, end, left, right);
}

int main(){

    vector<int> nums = {2, 2, 1, 3, 3, 3, 3};

    int candidate = findMajority(nums, 0, nums.size() - 1);

    // Verifying if it is actually in majority
    int count = 0;
    for(int num : nums){
        if(num == candidate){
            count++;
        }
    }

    if(count > nums.size() / 2){
        cout << "Majority Element: " << candidate;
    } else {
        cout << "No Majority Element";
    }

    return 0;
}