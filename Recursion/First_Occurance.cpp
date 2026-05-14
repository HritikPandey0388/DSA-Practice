#include<iostream>
#include<vector>
using namespace std;

int FirstOccur(vector<int> &nums, int idx, int target){

    // base case
    if(idx==nums.size()){
        return -1;
    }

    // first occurance found
    if(nums[idx]==target){
        return idx;
    }

    // checking occurance in next subArray
    return FirstOccur(nums,idx+1,target);

}

int main(){

    vector<int> nums = {1,2,3,4,3,5};
    int target = 3;
    
    int ans = FirstOccur(nums,0,target);

    if(ans==-1){
        cout << "Does't exist." << endl;
    }
    else{
        cout << "First occurance exist at " << ans << "th index." << endl;
    }

    return 0;
}