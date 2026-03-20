#include<iostream>
#include<vector>
using namespace std;

void PrintVector(vector<int> &nums){

    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }

}

void Sort(vector<int> &nums){

    int n = nums.size();
    
    for(int i=0;i<n;i++){

        bool isSwap = false;

        for(int j=0;j<n-1-i;j++){
            
            if(nums[j]>nums[j+1]){
                swap(nums[j],nums[j+1]);
                isSwap = true;
            }

        }
        
        if(isSwap==false){
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