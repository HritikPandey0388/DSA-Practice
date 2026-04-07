#include<iostream>
#include<vector>
using namespace std;

int RatIn_Maze(vector<vector<char>> &maze,int r, int c, int n, int m, string ans){

    // index out of range
    if((c>=m || r>=n || c<0 || r<0 || maze[r][c]=='0') ){
        return 0;
    }

    // base case 
    if(r==(n-1) && c==(m-1)){
        cout << ans << endl;
        return 1;
    }

    // include 
    maze[r][c] = '0';

    // calling for each ways rat can traverse
    int right = RatIn_Maze(maze,r,c+1,n,m,ans+'R');
    int left = RatIn_Maze(maze,r,c-1,n,m,ans+'L');
    int down = RatIn_Maze(maze,r+1,c,n,m,ans+'D');
    int up = RatIn_Maze(maze,r-1,c,n,m,ans+'U');
    
    // exclude
    maze[r][c] = '1';

    return (right + down + left + up);

}

int main(){
    
    vector<vector<char>> maze = {{'1','0','0','0'},
                                 {'1','1','0','1'},
                                 {'1','1','0','0'},
                                 {'0','1','1','1'}
                                };

    int n = maze.size();                            
    string ans = "";

    int totalWays = RatIn_Maze(maze,0,0,n,n,ans);
    
    cout << "Number of Ways are : " << totalWays << endl;
    
    return 0;
}