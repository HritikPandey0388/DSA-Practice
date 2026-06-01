#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimumCost(vector<int>& cost) {

    // Sort in descending order
    sort(cost.begin(), cost.end(), greater<int>());

    int ans = 0;

    for(int i = 0; i < cost.size(); i++) {

        // Every 3rd candy is free
        if(i % 3 != 2) {
            ans += cost[i];
        }
    }

    return ans;
}

int main() {

    vector<int> cost = {6, 5, 7, 9, 2, 2};

    cout << minimumCost(cost) << endl;

    return 0;
}