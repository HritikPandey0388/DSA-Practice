#include<iostream>
#include<vector>
using namespace std;

void Occurances(vector<int> &nums, int key, int Idx){

    // base case
    if(Idx==nums.size()){
        return;
    }

    // index found where key is prensent
    if(nums[Idx]==key){
        cout << Idx << " ";
    }

    // calling for next sub Array
    Occurances(nums,key,Idx+1);
    
}

int main(){

    vector<int> nums = {1,3,9,7,9,8,9};
    int key = 9;

    Occurances(nums,key,0);

    return 0;
}