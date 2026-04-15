#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printVector(vector<vector<int>> &ans){

    int n = ans.size();
    int m = ans[0].size();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}
        

void threeSum(vector<int>& nums){
    
    int n = nums.size();
    vector<vector<int>> ans;

    // Sorting the array
    sort(nums.begin(), nums.end());
        
    for(int i = 0; i < n; i++){

        // Skip duplicate values for i
        if(i > 0 && nums[i] == nums[i - 1]){
            continue;
        }

        int j = i + 1;
        int k = n - 1;

        // Two-pointer search
        while(j < k){

            int sum = nums[i] + nums[j] + nums[k];
                
            if(sum < 0){
                j++; // Need larger sum
            }
            else if(sum > 0){
                k--; // Need smaller sum
            }
            else{
                // Found valid triplet
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;

                // Skipping duplicates for j
                while(j < k && nums[j] == nums[j - 1]){
                    j++;
                }

                // Skipping duplicates for k
                while(j < k && nums[k] == nums[k + 1]){
                    k--;
                }
            }    
        }
    }

    // Print result
    printVector(ans);
}


int main(){
    vector<int> nums={-1,0,1,2,-1,-4};
    threeSum(nums);
    return 0;
}