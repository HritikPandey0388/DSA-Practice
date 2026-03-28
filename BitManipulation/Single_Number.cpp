#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {

    int ans=0;

    for(int value : nums){
        ans^=value;
    }
    
    return ans;
}

int main(){
    
    vector<int> nums = {1,2,2,3,3,3,4,4};
    cout << singleNumber(nums) << endl;

    return 0;
}