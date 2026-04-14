#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void PrintAns(vector<int> &ans){

    cout << "The number that occurs twice is : " << ans[0] << endl; 
    cout << "The missing value is : " << ans[1] << endl;

}

void setMismatch(vector<int>& nums){
    
    unordered_set<int> s;   // Tracks numbers we've already seen
    vector<int> ans;        // Stores [duplicate, missing]
        
    int n = nums.size();
    int sum = 0;             // actual sum

    for(int i = 0; i < n; i++) {

        // nums[i] already exists 
        if(s.find(nums[i]) != s.end()) {
            ans.push_back(nums[i]);   // Store duplicate as ans[0]
        }

        s.insert(nums[i]);   // Mark nums[i] as seen
        sum += nums[i];      // add to actual sum
    }

    // expected sum 
    int actualSum = n * (n + 1) / 2;

    int duplicate = ans[0];

    // missing Element
    int missing = actualSum - (sum - duplicate);

    ans.push_back(missing);   // Store missing as ans[1]

    PrintAns(ans);
}


int main(){

    vector<int> nums={1,2,3,4,5,5};
    setMismatch(nums);
    
    return 0;
}