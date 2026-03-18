#include<iostream>
#include<vector>
using namespace std;

void PrintVector(vector<int> &nums){

    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " ";
    }

    return;

}

void MoveZeros(vector<int> &nums){

    int n = nums.size();
    int idx=0;                   //index to maintain same order of given vector

    for(int i=0;i<n;i++){
        if(nums[i]!=0){
            nums[idx]=nums[i];
            idx++;
        }
    }

    for(int i=idx;i<n;i++){     
        nums[i]=0;              // Pushes all zero's to the right
    }
    
    PrintVector(nums);

    return;
}

int main(){

    vector<int> nums= {9,0,1,2,3,0,6,0};

    MoveZeros(nums);

    return 0;
}