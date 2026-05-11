#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int> &nums, int st, int end, int target){

    if(st<end){

        // find mid
        int mid = st + (end-st)/2;

        // target found
        if(nums[mid]==target){
            return mid;
        }
        // target exist in RHS
        else if(nums[mid]<target){
            return BinarySearch(nums,mid+1,end,target);
        }
        // target exist in LHS
        else{
            return BinarySearch(nums,st,mid-1,target);
        }

    }

    // doesn't exist
    return -1;
}

int main(){

    vector<int> nums = {1,3,4,7,8};
    int target = 9;

    int ans = BinarySearch(nums,0,nums.size()-1,target);

    if(ans==-1){
        cout << "Not Found" << endl;
    }
    else{
        cout << " Founded at " << ans << "th Index" << endl;
    }
    return 0;
}