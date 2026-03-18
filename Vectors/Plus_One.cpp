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
    int idx=(n-1);

    while(idx>=0){
        
        if(nums[idx]==9){
            nums[idx] = 0;
        }
        else{
            nums[idx] += 1; 
            PrintVector(nums);
            return;
        }

        idx--;

    }

    nums.insert(nums.begin(), 1);
    PrintVector(nums);

    return;
}

int main(){

    vector<int> nums= {9,9};

    PlusOne(nums);

    return 0;
}