#include<iostream>
#include<vector>
using namespace std;

void PrintVector(vector<int> &nums){

    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }

}

// Bubble Sort Function
void Sort(vector<int> &nums){

    int n = nums.size();
    
    for(int i = 0; i < n - 1; i++){

        // If no swapping happens --> already sorted
        bool isSwap = false;

        // largest element moves to the end
        for(int j = 0; j < n - 1 - i; j++){
            
            // Swap if current element > next element
            if(nums[j] > nums[j + 1]){

                swap(nums[j], nums[j + 1]);

                // swap done --> unsorted
                isSwap = true;
            }

        }
        
        // sorted
        if(isSwap == false){
            return;
        }

    }

}

int main(){

    vector<int> nums = {5,4,3,2,1};

    Sort(nums);

    PrintVector(nums);

    return 0;
}