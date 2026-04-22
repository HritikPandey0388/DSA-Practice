#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {

    int ans = 0;  

    for(int value : nums){
        ans ^= value;          // Duplicate numbers will cancel each other
    }
    
    return ans; 
}

int main(){
    
    vector<int> nums = {1,2,2,3,3,4,4};   // only works when all numbers are 2 times present
    cout << singleNumber(nums) << endl;

    return 0;
}