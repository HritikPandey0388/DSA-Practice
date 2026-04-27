#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int Count(vector<int> &nums, int st, int end){

    int n = end-st+1;

    

    return count;
}

int InversionCount(vector<int> &nums, int st, int end){

    if(st==end){
        return 0;
    }

    int mid = st + (end-st)/2;
    
    InversionCount(nums,st,mid);
    InversionCount(nums,mid+1,end);

    return Count(nums,st,mid)+Count(nums,mid+1,end);
}

int main(){

    vector<int> nums={5,4,2,3,6};
    int n = nums.size()-1;
    int ans = InversionCount(nums,0,n);

    cout << ans << endl;

    return 0;
}