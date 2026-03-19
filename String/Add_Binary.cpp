#include<iostream>
#include<vector>
#include<string>
using namespace std;

void AddBinary(string &nums1, string &nums2){

    int carry=0;
    int i=nums1.size()-1, j=nums2.size()-1, idx=0;
    string ans = "";

    while(i>=0 || j>=0 || carry){
        
        int x=0, y=0, sum=0;

        if(i>=0){
            x = nums1[i]-'0';
        }

        if(j>=0){
            y = nums2[j]-'0';
        }

        sum = x + y + carry;
        ans = to_string(sum%2) + ans;
        carry = sum/2 ;

        i--;
        j--;

    }

    if(carry){
        ans.insert(ans.begin(),1);
    }
    
    cout << "Addition of given to Binary Numbers is : " << ans << endl;

    return;

}

int main(){

    string nums1= "1111";
    string nums2= "111";

    AddBinary(nums1,nums2);

    return 0;
}