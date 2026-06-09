#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long maximumScore(vector<int>& nums){

    int n = nums.size();

    // prefixSum[i] = sum of elements from 0 to i
    vector<long long> prefixSum(n, 0);
    prefixSum[0] = nums[0];

    for(int i = 1; i < n; i++){
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    // suffixMin[i] = minimum element present after index i
    vector<int> suffixMin(n, 0);
    suffixMin[n - 1] = nums[n - 1];

    for(int i = n - 2; i >= 0; i--){
        suffixMin[i] = min(suffixMin[i + 1], nums[i + 1]);
    }

    // store maximum score
    long long score = LLONG_MIN;

    for(int i = 0; i < n - 1; i++){

        // score = prefix sum till i - minimum element after i
        score = max(score, prefixSum[i] - suffixMin[i]);
    }

    return score;
}

int main(){

    vector<int> nums = {2, -1, 0, 1, -3, 3};

    cout << maximumScore(nums) << endl;

    return 0;
}