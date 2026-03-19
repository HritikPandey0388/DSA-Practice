#include<iostream>
#include<climits>
using namespace std;

void MaxSubArrayProduct(int *arr, int n){

    int Prefix=1, Suffix=1;
    int ans=INT_MIN;

    for(int i=0;i<n;i++){

        if(Prefix == 0){ 
            Prefix = 1;
        }    
        if(Suffix == 0){ 
            Suffix = 1;
        }    

        Prefix *= arr[i];
        Suffix *= arr[n - i - 1];

        ans = max(ans, max(Prefix, Suffix));

    }

    cout << "Max SubArray Product is : " << ans << endl;

}

int main(){

    int arr[] = {2,3,-2,4,-1,-3};
    int n = sizeof(arr)/sizeof(int);

    MaxSubArrayProduct(arr,n);

    return 0;
}