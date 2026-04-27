#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long merge(vector<int>& arr, int l, int m, int r) {
        vector<int> temp;
        int i = l;
        int j = m + 1;
        long long invCount = 0;

        while (i <= m && j <= r) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                invCount += (m - i + 1);  // key idea
                j++;
            }
        }

        while (i <= m) {
            temp.push_back(arr[i]);
            i++;
        }

        while (j <= r) {
            temp.push_back(arr[j]);
            j++;
        }

        for (int k = l; k <= r; k++) {
            arr[k] = temp[k - l];
        }

        return invCount;
    }

    long long mergeSort(vector<int>& arr, int l, int r) {
        long long invCount = 0;

        if (l >= r) return 0;

        int m = l + (r - l) / 2;

        invCount += mergeSort(arr, l, m);
        invCount += mergeSort(arr, m + 1, r);
        invCount += merge(arr, l, m, r);

        return invCount;
    }

    long long inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};

    Solution obj;
    cout << obj.inversionCount(arr) << endl;

    return 0;
}