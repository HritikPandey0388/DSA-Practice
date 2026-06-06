#include <iostream>
using namespace std;

long long MOD = 1e9 + 7;

// Binary Exponentiation
long long power(long long base, long long exp){

    long long result = 1;

    while(exp > 0){

        // If current bit is set, include this power
        if(exp & 1){
            result = (result * base) % MOD;
        }

        // Move to next power of base
        base = (base * base) % MOD;

        // Shift to next bit
        exp >>= 1;
    }

    return result;
}

int countGoodNumbers(long long n){

    // Number of even indices (0, 2, 4, ...)
    long long evenCount = (n + 1) / 2;

    // Number of odd indices (1, 3, 5, ...)
    long long oddCount = n / 2;

    // 5 choices for even indices
    long long evenWays = power(5, evenCount);

    // 4 choices for odd indices
    long long oddWays = power(4, oddCount);

    return (evenWays * oddWays) % MOD;
}

int main(){

    long long n = 806166225460393;

    cout << countGoodNumbers(n) << endl;

    return 0;
}