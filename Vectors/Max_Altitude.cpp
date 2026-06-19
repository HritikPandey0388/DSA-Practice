#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestAltitude(vector<int>& gain) {

    int ans = 0;                
    int currSum = 0;              // Prefix Sum

    // track maximum altitude
    for (int val : gain) {
        currSum += val;
        ans = max(ans, currSum);
    }

    return ans;
}

int main() {
    vector<int> gain = {-5, 1, 5, 0, -7};

    cout << largestAltitude(gain) << endl;

    return 0;
}