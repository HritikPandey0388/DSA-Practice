#include<iostream>
#include<vector>
using namespace std;

vector<int> MajorityElement(vector<int>& nums){

    int n = nums.size();

    int candidate1 = 0;
    int candidate2 = 0;

    int frequency1 = 0;
    int frequency2 = 0;

    for(int i = 0; i < n; i++){

        // Current element matches first candidate
        if(nums[i] == candidate1){
            frequency1++;
        }

        // Current element matches second candidate
        else if(nums[i] == candidate2){
            frequency2++;
        }

        // Choose new first candidate
        else if(frequency1 == 0){
            candidate1 = nums[i];
            frequency1 = 1;
        }

        // Choose new second candidate
        else if(frequency2 == 0){
            candidate2 = nums[i];
            frequency2 = 1;
        }

        // Cancel one occurrence of both candidates
        else{
            frequency1--;
            frequency2--;
        }
    }

    // Verify actual frequencies of candidates
    frequency1 = 0;
    frequency2 = 0;

    for(int i = 0; i < n; i++){

        if(nums[i] == candidate1){
            frequency1++;
        }

        else if(nums[i] == candidate2){
            frequency2++;
        }
    }

    vector<int> ans;

    // Check if first candidate occurs more than n/3 times
    if(frequency1 > n/3){
        ans.push_back(candidate1);
    }

    // Check if second candidate occurs more than n/3 times
    if(frequency2 > n/3){
        ans.push_back(candidate2);
    }

    return ans;
}

int main(){

    vector<int> nums = {3, 2, 3, 2};

    vector<int> ans = MajorityElement(nums);

    cout << "Majority Elements : ";

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }

    return 0;
}
