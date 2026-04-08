#include<iostream>
using namespace std;

int helper(int arr[][3], int n){

    int sum = 0;

    for(int i=0;i<n;i++){

        sum += arr[i][i];                     // adding (i,i) diagonal elements in sum
        if(i!=(n-i-1)){                       // excluding common diagonal element 
            sum += arr[i][n-i-1];             // adding (i,n-i-1) diagonal elements in sum that are not 
        }

    }

    cout << " Diagonal Sum is : " << sum << endl;

}

int main(){

    int arr[][3] = {{1,2,3},{4,5,6},{7,8,9}};

    int rows = sizeof(arr[0])/sizeof(arr[0][0]);
    
    helper(arr,rows); 

    return 0;
}