#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int connectNRopes(vector<int>& ropes){

    // Min heap
    priority_queue<int, vector<int>, greater<int>> pq(ropes.begin(), ropes.end());

    int cost = 0;

    while(pq.size() > 1){

        // Take smallest rope
        int min1 = pq.top();
        pq.pop();

        // Take second smallest rope
        int min2 = pq.top();
        pq.pop();

        // Add their connection cost
        cost += (min1 + min2);

        // Push newly formed rope back into heap
        pq.push(min1 + min2);
    }

    // Final minimum cost
    return cost;
}

int main(){

    vector<int> ropes = {4, 3, 2, 6};

    int ans = connectNRopes(ropes);

    cout << ans << endl;

    return 0;
}