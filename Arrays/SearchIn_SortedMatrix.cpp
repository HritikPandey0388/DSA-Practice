#include<iostream>
using namespace std;

void Search(int arr[][4], int n, int m, int key){

    int row=0, col=(m-1);                 //strating comparation with rightMost element of 1st row 

    while(row<n && col>=0){

        if(key==arr[row][col]){
            cout << "Found at (" << row << "," << col << ")" << endl;
            return ;
        }

        else if(key>arr[row][col]){
            row++;
        }

        else{
            col--;
        }

    }

}

int main(){

    int arr[4][4] = {{10,20,30,40},{15,25,35,45},{27,29,37,48},{32,33,39,50}};
    
    Search(arr,4,4,33); 

    return 0;
}