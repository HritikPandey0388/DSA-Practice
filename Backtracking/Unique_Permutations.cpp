#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<string> s;

// Generate all permutations
void getAllPermutations(vector<int>& nums, vector<vector<int>>& ans, int idx) {

    // Base case
    if(idx == nums.size()){

        string str;

        // Convert permutation to string
        for(int val : nums){
            str += to_string(val);
        }

        // Store only unique permutations
        if(s.find(str) == s.end()){

            s.insert(str);
            ans.push_back(nums);
        }

        return;
    }

    for(int i = idx; i < nums.size(); i++){

        // Choose
        swap(nums[idx], nums[i]);

        // Explore
        getAllPermutations(nums, ans, idx + 1);

        // Backtrack
        swap(nums[idx], nums[i]);
    }
}

// Return all unique permutations
vector<vector<int>> permuteUnique(vector<int>& nums) {

    vector<vector<int>> ans;

    getAllPermutations(nums, ans, 0);

    return ans;
}

int main(){

    vector<int> nums = {1, 1, 2};

    vector<vector<int>> ans = permuteUnique(nums);

    // Print permutations
    for(auto& perm : ans){

        for(int val : perm){
            cout << val << " ";
        }

        cout << endl;
    }

    return 0;
}