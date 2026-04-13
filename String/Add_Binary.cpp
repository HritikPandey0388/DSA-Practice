#include<iostream>
#include<vector>
#include<string>
using namespace std;

void AddBinary(string &nums1, string &nums2){

    int carry=0;
    int i=nums1.size()-1, j=nums2.size()-1, idx=0;
    string ans = "";                                  // ans

    // Continue until both strings are exhausted AND no carry remains
    while(i>=0 || j>=0 || carry){
        
        int x=0, y=0, sum=0;

        if(i>=0){
            x = nums1[i]-'0';
        }

        if(j>=0){
            y = nums2[j]-'0';
        }

        sum = x + y + carry;                  // sum = 0,1,2
        ans = to_string(sum%2) + ans;         // finding last Bit(0,1)   
        carry = sum/2 ;                       // checking carry exist or not

        i--;
        j--;

    }

    // if a carry remains after both strings are processed
    if(carry){
        ans.insert(ans.begin(),1);
    }
    
    cout << "Addition of given to Binary Numbers is : " << ans << endl;

    return;

}

int main(){

    string nums1 = "1111";   // binary for 15
    string nums2 = "111";    // binary for 7

    AddBinary(nums1, nums2); // expected output: 10110 (binary for 22)

    return 0;
}