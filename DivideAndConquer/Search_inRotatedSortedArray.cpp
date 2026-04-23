#include<iostream>
#include<vector>
using namespace std;

int Search(vector<int> &nums, int st, int end, int target){

    // target does't exist
    if(st > end){
        return -1;
    }

    // Find middle index
    int mid = st + (end - st) / 2;

    // If target found at mid
    if(nums[mid] == target){
        return mid;
    }

    // Check if left half is sorted
    if(nums[st] <= nums[mid]){

        if(nums[st] <= target && target <= nums[mid]){               // target lies in left sorted half
            return Search(nums, st, mid - 1, target);
        }
        else{
            return Search(nums, mid + 1, end, target);               // target lies in right sorted half
        }
    }
    // Right half is sorted
    else{

        if(nums[mid] <= target && target <= nums[end]){              // target lies in right sorted half
            return Search(nums, mid + 1, end, target);
        }
        else{
            return Search(nums, st, mid - 1, target);                // target lies in left sorted half
        }
    }
}

int main(){

    vector<int> nums = {4,5,6,7,0,1,2,3};
    int n = nums.size();
    int target = 2;

    int ans = Search(nums,0,n-1,target);

    if(ans==-1){
        cout << "Not Found." << endl;
    }
    else{
        cout << "Found at " << ans << "th index." << endl;
    }

    return 0;
}
