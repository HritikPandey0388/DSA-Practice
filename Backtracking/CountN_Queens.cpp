#include<iostream>
#include<vector>

using namespace std;

void PrintBoard(vector<vector<char>> board){
    
    int n = board.size();

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    cout << "-----------------" << endl;

}

bool isSafe(vector<vector<char>> board, int row, int col){

    int n = board.size();


    for(int i=0;i<n;i++){
        if(board[row][i]=='Q' || board[i][col]=='Q'){             // checking for current row and column
            return false;
        }
    }

    int i=row,j=col;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){                                      // checking for left upper diagonals
            return false;
        }
        i--;
        j--;
    }

    i=row,j=col;
    while(i>=0 && j<n){
        if(board[i][j]=='Q'){                                       // checking for right upper diagonals
            return false;
        }
        i--;
        j++;
    }

    return true;                      // returning true if no false condition hits 

}

int nQueens(vector<vector<char>> board, int row){

    int n = board.size();

    if(row==n){                                    // base case
        PrintBoard(board);                         // Print board and return 
        return 1;
    }    

    int count = 0;
    for(int j=0;j<n;j++){                         // keeping Q on each column
        if(isSafe(board,row,j)){                  // checking for isSafe to keep on that column
            board[row][j] = 'Q';
            count += nQueens(board,row+1);        // if its safe then calling for next row
            board[row][j] = '.';                  // if this hits that means not safe  
        }
    }

    return count;
}

int main(){

    vector<vector<char>> board;
    int n =4;

    for(int i=0;i<n;i++){
        
        vector<char> temp;
        for(int j=0;j<n;j++){
            temp.push_back('.');
        }

        board.push_back(temp);

    }

    int count  = nQueens(board,0);

    cout << "Count : " << count << endl;

    return 0;
}