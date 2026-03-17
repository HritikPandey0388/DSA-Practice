#include<iostream>
#include<climits>
using namespace std;

void maxSubArraySum(int *arr, int n){

    int maxSum = INT_MIN;
    int currSum = 0;

    for(int i=0;i<n;i++){
        
        currSum += arr[i];
        maxSum = max(maxSum,currSum);

        if(currSum<0){
            currSum = 0;
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