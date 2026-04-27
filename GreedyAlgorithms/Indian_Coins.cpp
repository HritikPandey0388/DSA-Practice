#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int getMinCoins(vector<int>& coins, int amount){

    int n = coins.size();

    int ans = 0;
    for(int i=(n-1);i>=0 && amount!=0 ;i--){
        if(coins[i]<=amount){
            ans += amount/coins[i];
            amount = amount%coins[i];
        }
    }

    cout << "Min coins needed are :- " ;

    return ans;
}

int main(){

    vector<int> coins = {500,2000,200,100,2,1,50,10,20,5};
    int amount = 590;

    // sorting so that we start from big amount
    sort(coins.begin(),coins.end());

    cout << getMinCoins(coins,amount) << endl;

    return 0;
}