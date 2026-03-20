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
    
    for(int i=0;i<n-1;i++){

        int SmallestIdx = i;

        for(int j=i+1;j<n;j++){
            
            if(nums[j] < nums[SmallestIdx]){
                SmallestIdx = j;
            }

        }
        
        swap(nums[i],nums[SmallestIdx]);

    }

}

int main(){

    vector<int> nums = {5,4,3,2,1};

    Sort(nums);

    PrintVector(nums);

    return 0;
}