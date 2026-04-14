#include<iostream>
#include<vector>
using namespace std;

void Pairs(vector<int> &nums, int target){

    int n = nums.size();
    int st = 0 ,end = (n-1);  // starting and ending index 
    int currSum = 0;
    vector<int> ans;          // contains ans pair

    while(st<end){

        currSum = nums[st]+nums[end];

        // pairs obtained
        if(currSum==target){
            ans.push_back(st);
            ans.push_back(end);
            break;
        }
        // excluding nums[st]
        else if(currSum<target){
            st++;
        }
        // excluding nums[end]
        else{
            end--;
        }

    }

    cout << ans[0] << "," << ans[1] << endl;

}

int main(){

    vector<int> nums = {1,2,5,8};
    int target = 7;

    Pairs(nums,target);

    return 0;
}