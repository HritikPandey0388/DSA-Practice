#include<iostream>
#include<climits>
using namespace std;

void maxSubArraySum(int *arr, int n){

    int maxSum = INT_MIN;   // stores maximum subarray sum
    int currSum = 0;        // stores current running sum

    for(int i=0;i<n;i++){
        
        currSum += arr[i];              // extend current subarray
        maxSum = max(maxSum,currSum);   // update maximum if needed

        if(currSum<0){
            currSum = 0;                // reset if sum becomes negative (start fresh)
        }

    }

    cout << "Max subArray sum is : " << maxSum << endl; 

}

int main(){

    int arr[5] = {0,-5,2,1,4};  
    int n = 5;                  

    maxSubArraySum(arr,n);

    return 0;
}