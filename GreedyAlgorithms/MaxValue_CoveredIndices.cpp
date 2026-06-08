#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long maxTotal(vector<int>& nums, string s){

    int n = nums.size();

    int i = 0;

    while(i < n){

        // skip all 0's
        if(s[i] == '0'){
            i++;
            continue;
        }

        // starting index of current block of 1's
        int l = i;

        // store index of minimum element in current block
        int minIdx = i;

        // traverse current consecutive 1's block
        while(i < n && s[i] == '1'){

            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }

            i++;
        }

        // if there is an element before the block
        if(l > 0){

            int prevIdx = l - 1;

            // cover previous index and uncover minimum index
            if(nums[prevIdx] > nums[minIdx]){

                s[prevIdx] = '1';
                s[minIdx] = '0';
            }
        }
    }

    // calculate answer
    long long sum = 0;

    for(int i = 0; i < n; i++){

        if(s[i] == '1'){
            sum += nums[i];
        }
    }

    return sum;
}

int main(){

    vector<int> nums = {10, 8, 1, 7};
    string s = "0111";

    cout << maxTotal(nums, s) << endl;

    return 0;
}