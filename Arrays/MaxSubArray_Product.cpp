#include<iostream>
#include<climits>
using namespace std;

void MaxSubArrayProduct(int *arr, int n){

    int Prefix=1, Suffix=1;   // track product from left and right
    int ans=INT_MIN;          // store maximum product

    for(int i=0;i<n;i++){

        if(Prefix == 0){ 
            Prefix = 1;       // reset if prefix becomes 0
        }    
        if(Suffix == 0){ 
            Suffix = 1;       // reset if suffix becomes 0
        }    

        Prefix *= arr[i];             // multiply from left
        Suffix *= arr[n - i - 1];     // multiply from right

        ans = max(ans, max(Prefix, Suffix));   // update max product

    }

    cout << "Max SubArray Product is : " << ans << endl;

}

int main(){

    int arr[] = {2,3,-2,4,-1,-3};
    int n = sizeof(arr)/sizeof(int);

    MaxSubArrayProduct(arr,n);

    return 0;
}