#include<iostream>
#include<vector>
using namespace std;

void PrintVector(vector<int> &nums){

    for(int i=0;i<nums.size();i++){
        cout << nums[i];
    }

    return;

}

void PlusOne(vector<int> &nums){

    int n = nums.size();
    int idx = (n - 1);   // Start from the last digit (units place)

    while(idx >= 0){

        if(nums[idx] == 9){
            // Current digit is 9 → becomes 0, carry propagates to the left
            nums[idx] = 0;
        }
        else{
            // No carry needed → just increment this digit and we're done
            nums[idx] += 1;
            PrintVector(nums);
            return;
        }

        idx--;   // Move to the next digit on the left
    }

    // carry exist 
    nums.insert(nums.begin(), 1);
    PrintVector(nums);

    return;
}

int main(){

    vector<int> nums= {9,9};

    PlusOne(nums);      // returns 100

    return 0;
}