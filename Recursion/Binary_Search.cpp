#include<iostream>
#include<vector>
using namespace std;

int BinarySearch(vector<int> &nums, int st, int end, int target){

    if(st<end){

        int mid = st + (end-st)/2;

        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            return BinarySearch(nums,mid+1,end,target);
        }
        else{
            return BinarySearch(nums,st,mid-1,target);
        }

    }

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