#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int> &nums, int idx, int size){

    if(idx==(size-1)){
        return true;
    }

    if(nums[idx]>nums[idx+1]){
        return false;
    }

    return isSorted(nums,idx+1,size);

}

int main(){

    vector<int> nums = {1,2,3,4,5};
    int n = nums.size();
    
    int ans = isSorted(nums,0,n);

    if(ans){
        cout << "Sorted" << endl;
    }
    else{
        cout << "Not Sorted" << endl;
    }

    return 0;
}