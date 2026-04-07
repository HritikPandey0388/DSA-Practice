#include<iostream>
#include<climits>
using namespace std;

void maxProfit(int *arr, int n){

    int BestBuy[n];
    BestBuy[0] = INT_MAX;

    for(int i=1;i<n;i++){
        BestBuy[i] = min(BestBuy[i-1],arr[i-1]);                // finding best price to buy for each day
    }

    int maxProfit = 0;

    for(int i=0;i<n;i++){
        int currProfit = arr[i]-BestBuy[i];                     // finding currprofit 
        maxProfit = max(maxProfit,currProfit);                  // updating profit with max of currProfit and maxProfit
    }

    cout << "Max Profit is : " << maxProfit << endl;

}

int main(){

    int arr[5] = {0,-5,2,1,4};
    int n = 5;

    maxProfit(arr,n);

    return 0;
}