
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
    
    for(int i=1;i<n;i++){

        int CurrNo=nums[i];

        for(int j=(i-1);j>=0;j--){

            if(nums[j]>CurrNo){
                swap(nums[j+1],nums[j]);
            }

        }

    }

}

int main(){

    vector<int> nums = {3,1,2,5,6,4};

    Sort(nums);

    PrintVector(nums);

    return 0;
}