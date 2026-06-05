#include <iostream>
#include <string>
using namespace std;

int helper(long long num) {

    string str = to_string(num);

    int n = str.size();
    int cnt = 0;

    int i = 1;
    int j = n - 2;

    while (i <= j) {

        // Peak at i
        if (str[i - 1] < str[i] && str[i] > str[i + 1]) {
            cnt++;
        }

        // Valley at i
        if (str[i - 1] > str[i] && str[i] < str[i + 1]) {
            cnt++;
        }

        // Peak at j
        if (i != j &&
            str[j - 1] < str[j] &&
            str[j] > str[j + 1]) {
            cnt++;
        }

        // Valley at j
        if (i != j &&
            str[j - 1] > str[j] &&
            str[j] < str[j + 1]) {
            cnt++;
        }

        i++;
        j--;
    }

    return cnt;
}

int totalWaviness(long long num1, long long num2) {

    int ans = 0;

    for (long long i = num1; i <= num2; i++) {

        if (i >= 100) {
            ans += helper(i);
        }
    }

    return ans;
}

int main() {

    long long num1 = 120, num2 = 130;

    cout << totalWaviness(num1, num2);

    return 0;
}