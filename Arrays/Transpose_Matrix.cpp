#include<iostream>
using namespace std;

void Rectangular(int arr[][3], int n, int m){

    int nums[m][n];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            nums[j][i]=arr[i][j];
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }

}

void Square(int arr[][3], int n, int m){

    for(int i=0;i<n;i++){
        for(int j=(i+1);j<m;j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

}

int main(){

    int arr[][3] = {{1,2,3},{4,5,6}};

    int rows = sizeof(arr)/sizeof(arr[0]);
    int col = sizeof(arr[0])/sizeof(arr[0][0]);

    if(rows==col){
        Square(arr,rows,col); 
    }
    else{
        Rectangular(arr,rows,col); 
    }

    return 0;
}