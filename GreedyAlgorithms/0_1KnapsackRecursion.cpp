#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>& val, vector<int>& wt, int W, int n){

    // Base case:
    if(W == 0 || n == 0){
        return 0;
    }

    // Weight --> current item
    int itemWt = wt[n - 1];

    // Value --> current item
    int itemVal = val[n - 1];

    if(itemWt <= W){

        // Include current item
        int ans1 = knapsack(val, wt, W - itemWt, n - 1) + itemVal;

        // Exclude current item
        int ans2 = knapsack(val, wt, W, n - 1);

        // Return maximum profit of both choices
        return max(ans1, ans2);
    }
    else{
        // cannot be included
        return knapsack(val, wt, W, n - 1);
    }
}

int main(){
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n= 5 ;

    cout << knapsack(val, wt, W, n) << endl;

    return 0;
}