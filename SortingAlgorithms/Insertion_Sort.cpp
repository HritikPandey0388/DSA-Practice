#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void PrintVector(vector<int> &nums){

    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }

}

void Sort(vector<int> &nums){

    int n = nums.size();
    
    // start with 2nd element
    for(int i = 1; i < n; i++){

        // Current element to insert
        int CurrNo = nums[i];

        int j = i - 1;

        // Shift elements greater than CurrNo
        // one position ahead
        while(j >= 0 && nums[j] > CurrNo){

            nums[j + 1] = nums[j];
            j--;
        }

        // Place CurrNo at correct position
        nums[j + 1] = CurrNo;

    }

}

int main(){

    vector<int> nums = {3,1,2,5,6,4};

    Sort(nums);

    PrintVector(nums);

    return 0;
}