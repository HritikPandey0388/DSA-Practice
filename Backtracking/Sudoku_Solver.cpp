#include<iostream>
#include<vector>

using namespace std;

void PrintSudoku(vector<vector<char>> &mat){
    
    int n = mat.size();

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            cout << mat[i][j] << " ";
        }

        cout << endl;
    }

}

bool isSafe(vector<vector<char>> mat, int row, int col, char ch){

    int n = mat.size();

    for(int i=0;i<n;i++){
        if(mat[row][i]==ch || mat[i][col]==ch){        // base case for is not safe 
            return false;
        }
    }

    int stRow = (row/3)*3;                 // finding row for 3x3 grid
    int stCol = (col/3)*3;                 // finding column for 3x3 grid

    for(int i=stRow;i<=stRow+2;i++){
        for(int j=stCol;j<=stCol+2;j++){
            if(mat[i][j]==ch){
                return false;
            }
        }
    }

    return true;                               // if false doesn't hit

}

void SudokuSolver(vector<vector<char>> &mat, int row, int col){

    int n = mat.size();

    if(row==n){                         // base case
        PrintSudoku(mat);
        return;
    }

    if(col==n){                        // udating curr row to next row 
        row = row+1;
        col = 0;
    }

    if(mat[row][col]=='.'){
        for(char ch='1';ch<='9';ch++){                // checking is safe for each character(1-9)
            if(isSafe(mat,row,col,ch)){
                mat[row][col] = ch;
                SudokuSolver(mat,row,col+1);          // if its safe calling for next column
                mat[row][col] = '.';                  // if its not safe excluding the placed character
            }
        }
    } 
    else{
        SudokuSolver(mat,row,col+1);                  // calling for next column 
    }

}

int main(){

    vector<vector<char>> mat{
        {'.','.','8','.','.','.','.','.','.'},
        {'4','9','.','1','5','7','.','.','2'},                             
        {'.','.','3','.','.','4','1','9','.'},
        {'1','8','5','.','6','.','.','2','.'},
        {'.','.','.','.','2','.','.','6','.'},
        {'9','6','.','4','.','5','3','.','.'},
        {'.','3','.','.','7','2','.','.','4'},
        {'.','4','9','.','3','.','.','5','7'},
        {'8','2','7','.','.','9','.','1','3'}
    };

    SudokuSolver(mat,0,0);

    return 0;
}