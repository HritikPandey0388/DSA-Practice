#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int MCM(vector<int>& arr, int i, int j){
    
    // base case --> 0 operations
    if(i == j){
        return 0;
    }

    int ans = INT_MAX;

    for(int k=i; k<j; k++){

        // (i,j)
        int cost1 = MCM(arr, i, k);
        
        // (k+1,j)
        int cost2 = MCM(arr, k+1, j);

        // current partition cost
        int totalCost = cost1 + cost2 + (arr[i-1] * arr[k] * arr[j]);
        ans = min(ans, totalCost);

    }

    return ans;
}

int main(){

    vector<int> arr = {1, 2, 3, 4, 3};   // n --> n-1 Matrices --> (1,n-1)
    int n = arr.size();

    cout << MCM(arr, 1, n-1) << endl; 

    return 0; 
}