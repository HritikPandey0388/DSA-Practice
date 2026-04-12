#include<iostream>
using namespace std;

void Rectangular(int arr[][3], int n, int m){

    // New matrix to store transpose
    int nums[m][n];

    // Transpose logic: swap indices
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            nums[j][i] = arr[i][j];
        }
    }
    
    // Print transposed matrix
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
}

void Square(int arr[][3], int n, int m){

    // In-place transpose (only upper triangle)
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < m; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Print transposed matrix
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){

    int arr[][3] = {{1,2,3},{4,5,6}};

    int rows = sizeof(arr)/sizeof(arr[0]);
    int cols = sizeof(arr[0])/sizeof(arr[0][0]);

    if(rows==cols){
        Square(arr,rows,cols); 
    }
    else{
        Rectangular(arr,rows,cols); 
    }

    return 0;
}