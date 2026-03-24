#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void PrintAns(vector<int> &ans){

    cout << "The number that occurs twice is : " << ans[0] << endl; 
    cout << "The missing value is : " << ans[1] << endl;

}

void setMismatch(vector<int>& nums){
    
    unordered_set<int> s;
    vector<int> ans;
        
    int n = nums.size();
    int sum = 0;

    for(int i = 0; i < n; i++) {
        if(s.find(nums[i]) != s.end()) {
            ans.push_back(nums[i]); // duplicate
        }
        s.insert(nums[i]);
        sum += nums[i];
    }

        
    int actualSum = n * (n + 1) / 2;

    int duplicate = ans[0];
    int missing = actualSum - (sum - duplicate);

    ans.push_back(missing);

    PrintAns(ans);
    
}


int main(){

    vector<int> nums={1,2,3,4,5,5};
    setMismatch(nums);
    
    return 0;
}