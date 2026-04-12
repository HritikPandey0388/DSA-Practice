#include<iostream>
using namespace std;

void PrintSubArray(int *arr, int n){

    // Loop to fix starting index
    for(int start = 0; start < n; start++){
        
        // Loop to fix ending index
        for(int end = start; end < n; end++){
            
            // Loop to print elements from start to end
            for(int i = start; i <= end; i++){
                cout << arr[i];
            }

            cout << ",";
        }

        cout << endl;
    }
}

int main(){

    int arr[5] = {0,1,2,3,4};
    int n = 5;

    PrintSubArray(arr,n);

    return 0;
}