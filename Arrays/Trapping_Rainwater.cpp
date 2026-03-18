#include<iostream>
#include<climits>
using namespace std;

void TrappingRainwater(int *arr, int n){

    int lMax[n];
    lMax[0] = arr[0];
    int rMax[n];
    rMax[n-1] = arr[n-1];              // Avoiding end cases for

    for(int i=1;i<n;i++){
        lMax[i] = max(lMax[i-1],arr[i-1]);            //findind largest element on left of arr[i]
    }

    for(int i=(n-2);i>=0;i--){
        rMax[i] = max(rMax[i+1],arr[i+1]);    //findind largest element on right of arr[i]
    }

    int WaterTrapped = 0;

    for(int i=0;i<n;i++){
        
        int currWater = min(lMax[i],rMax[i])-arr[i];

        if(currWater>0){
            WaterTrapped += currWater;
        }

    }

    cout << "Max Water trapped is : " << WaterTrapped << endl; 

}

int main(){

    int arr[] = {4,2,0,6,3,2,5};
    int n = sizeof(arr)/sizeof(int);

    TrappingRainwater(arr,n);

    return 0;
}