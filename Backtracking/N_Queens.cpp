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

    // checking if it is safe to put Q at board[row][col]
    for(int i=0;i<n;i++){
        if(board[row][i]=='Q' || board[i][col]=='Q'){                
            return false;          
        }
    }

    int i=row,j=col;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }

    i=row,j=col;
    while(i>=0 && j<n){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }

    // if false does't hit that means it's safe to put
    return true;

}

void nQueens(vector<vector<char>> board, int row){

    int n = board.size();

    if(row==n){
        PrintBoard(board);               // base case solution found
        return;
    }    

    for(int j=0;j<n;j++){
        if(isSafe(board,row,j)){
            board[row][j] = 'Q';           // placing Q at (row,col)
            nQueens(board,row+1);          // calling for next row
            board[row][j] = '.';           // removing the prev Q placed
        }
    }
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

    nQueens(board,0);

    return 0;
}