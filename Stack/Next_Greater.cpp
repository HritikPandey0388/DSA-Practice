#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void NextGreater(vector<int> &nums){

    int n = nums.size();
    stack<int> s;
    
    vector<int> ans(n);

    for(int i=(n-1);i>=0;i--){

        // pop until greater element encounters
        while(!s.empty() && nums[i]>=s.top()){
            s.pop();
        }

        // stack --> empty (next greater does't exist)
        if(s.empty()){
            ans[i]=-1;
        }
        // ans --> top element of stack
        else{
            ans[i] = s.top();
        }

        // pushing current element
        s.push(nums[i]); 

    }

    for(int i=0;i<n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;

}

int main(){
    
    vector<int> nums = {6,8,0,1,3};

    NextGreater(nums);

    return 0;
}