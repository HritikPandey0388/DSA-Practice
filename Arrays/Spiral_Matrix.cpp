#include<iostream>
using namespace std;

int helper(int arr[][4], int n, int m){

    int srow=0;
    int erow=(n-1);
    int scol=0;
    int ecol=(m-1);

    while(srow<=erow && scol<=ecol){
        
        //top
        for(int i=scol;i<=ecol;i++){
            cout << arr[srow][i] << " ";
        }

        //right
        for(int i=(srow+1);i<=erow;i++){
            cout << arr[i][ecol] << " ";
        }

        //bottom
        for(int i=(ecol-1);i>=scol;i--){
            if(srow==erow){                  //middle row already printed
                break;
            }
           cout << arr[erow][i] << " ";
        }

        //left
        for(int i=(erow-1);i>=(srow+1);i--){
            if(scol==ecol){                   //middle column already printed
                break;
            }
           cout << arr[i][scol] << " ";
        }

        srow++;
        ecol--;
        erow--;
        scol++;

    }

}

int main(){

    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    
    helper(arr,4,4); 

    return 0;
}