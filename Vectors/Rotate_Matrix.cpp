#include<iostream>
#include<vector>
using namespace std;

void PrintMatrix(vector<vector<int>>& matrix){

    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

}

void swapColums(vector<vector<int>>& matrix){

    int i=0;
    int j=matrix[0].size()-1;

    while(i<j){

        for(int k=0;k<matrix.size();k++){
            swap(matrix[k][i],matrix[k][j]);
        }

        i++;
        j--;

    }

}

void Transpose(vector<vector<int>>& matrix){

    int m =matrix.size();
    int n =matrix[0].size();

    for(int i=0;i<m;i++){
        for(int j=(i+1);j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    return swapColums(matrix);

}

int main(){

    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Transpose(matrix);

    PrintMatrix(matrix);

    return 0;

} 
