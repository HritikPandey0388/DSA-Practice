#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Find k weakest rows in the matrix
void weakestSoldier(vector<vector<int>>& matrix, int k) {

    // Min Heap
    // {soldierCount, rowIndex}
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Count soldiers in each row
    for (int i = 0; i < matrix.size(); i++) {

        int count = 0;

        // Soldiers (1s) always appear before civilians (0s)
        for (int j = 0; j < matrix[i].size() && matrix[i][j] == 1; j++) {
            count++;
        }

        pq.push({count, i});
    }

    // Print k weakest rows
    for (int i = 0; i < k; i++) {

        cout << "Row " << pq.top().second << endl;

        pq.pop();
    }
}

int main() {

    vector<vector<int>> matrix = {{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};

    int k = 2;

    weakestSoldier(matrix, k);

    return 0;
}