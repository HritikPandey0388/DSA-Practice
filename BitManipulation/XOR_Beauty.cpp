#include<iostream>
#include<vector>
using namespace std;

 int xorBeauty(vector<int>& nums) {

    int ans=0;

    for(int val:nums){
        ans^=val;
    }

    return ans;
        
}

int main(){

    vector<int> nums={1,4};
    cout << xorBeauty(nums) << endl;

    return 0;
}    