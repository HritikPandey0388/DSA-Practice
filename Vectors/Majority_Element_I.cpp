#include<iostream>
#include<vector>
using namespace std;

int MajorityElement(vector<int>& nums){

    int frequency = 0;
    int candidate = 0;

    for(int i = 0; i < nums.size(); i++){

        // If frequency becomes 0, choose a new candidate
        if(frequency == 0){
            candidate = nums[i];
        }

        // Increase frequency if current element matches candidate
        if(candidate == nums[i]){
            frequency++;
        }

        // Otherwise decrease frequency
        else{
            frequency--;
        }
    }

    // Final candidate is the majority element
    return candidate;
}

int main(){

    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Majority Element : " << MajorityElement(nums);

    return 0;
}