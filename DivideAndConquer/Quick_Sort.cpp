#include<iostream>
#include<vector>
using namespace std;

void PrintVec(vector<int> &nums){

    for(int i=0;i<nums.size();i++){
        cout << nums[i] << " " ;
    }
}

int Partitions(vector<int> &nums, int st, int end){

    int i = st-1;
    int Pivot = nums[end];

    // finding pivot index
    for(int j=st;j<end;j++){
        if(nums[j]<=Pivot){
            i++;
            swap(nums[i],nums[j]);
        }
    }

    i++;
    swap(nums[i],nums[end]);              // Bringing Pivot to correct position

    // Pivot Index =i
    return i;

}

void QuickSort(vector<int> &nums, int st, int end){

    if(st>=end){
        return ;
    }

    int PivotIdx = Partitions(nums,st,end);       // Getting Pivot Index 

    QuickSort(nums,st,PivotIdx-1);                // Left Half
    QuickSort(nums,PivotIdx+1,end);               // Right half

}

int main(){

    vector<int> nums={6,3,7,5,2,4};
    int n = nums.size()-1;
    QuickSort(nums,0,n);

    PrintVec(nums);

    return 0;
}