#include<iostream>
#include<vector>
using namespace std;

int LastOccur(vector<int> &nums, int idx, int target){

    // single variable for whole recursion stack
    static int lastIdx = -1;

    // Base case:
    if(idx==nums.size()){
        return lastIdx;
    }

    // If current element --> target,
    // update last occurrence index
    if(nums[idx]==target){
        lastIdx = idx;
    }

    // Move to next occurance
    return LastOccur(nums,idx+1,target);

}

int main(){

    vector<int> nums = {1,2,3,4,3,5,3};
    int target = 3;
    
    int ans = LastOccur(nums,0,target);

    if(ans==-1){
        cout << "Does't exist." << endl;
    }
    else{
        cout << "Last occurance exist at " << ans << "th index." << endl;
    }

    return 0;
}