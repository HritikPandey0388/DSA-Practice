#include<iostream>
using namespace std;

int main(){
    
    int rows, cols;

    cout << "Enter Rows: ";
    cin >> rows;

    cout << "Enter Columns: ";
    cin >> cols;

    // Allocating array of row pointers
    int** matrix = new int*[rows];

    // Allocating each row dynamically
    for(int i = 0; i < rows; i++){
        matrix[i] = new int[cols];
    }

    int x = 1;     // Element to store at each index

    // Filling the matrix
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = x++;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Deleting dynamically allocated memory
    for(int i = 0; i < rows; i++){
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}