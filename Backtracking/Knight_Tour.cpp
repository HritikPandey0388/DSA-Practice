#include<iostream>
#include<vector>

using namespace std;

void PrintBoard(vector<vector<int>> board){
    
    int n = board.size();

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}

bool isSafe(vector<vector<int>> &board, int row, int col){

    int n = board.size();

    if(row>=0 && col>=0 && row<n && col<n && board[row][col]==-1){
        return true;
    }

    return false;

}

void KnightTour(vector<vector<int>> &board, int row, int col, int count){

    int n = board.size();

    if(!(isSafe(board,row,col))){        // checking for placed index is out of scope or not       
        return;
    }

    board[row][col] = count;         // marked as travelled 

    if(count == (n*n)-1){            // base case
        PrintBoard(board);
        return ;
    }
        
    // calling for each ways knight can move
    KnightTour(board,row+1,col+2,count+1);
    KnightTour(board,row+2,col+1,count+1);
    KnightTour(board,row-1,col-2,count+1);
    KnightTour(board,row-2,col-1,count+1);
    KnightTour(board,row+1,col-2,count+1);
    KnightTour(board,row+2,col-1,count+1);
    KnightTour(board,row-1,col+2,count+1);
    KnightTour(board,row-1,col+2,count+1);

    // this will hit that means knight has no way to move forward 
    // knight did't took a right move 
    board[row][col] = -1;

}

int main(){

    vector<vector<int>> board;
    int n = 5;

    for(int i=0;i<n;i++){
        
        vector<int> temp;
        for(int j=0;j<n;j++){
            temp.push_back(-1);
        }

        board.push_back(temp);

    }

    KnightTour(board,0,0,0);

    return 0;
}