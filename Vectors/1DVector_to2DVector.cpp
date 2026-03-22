#include<iostream>
#include<vector>
using namespace std;

void PrintVector(vector<vector<int>> &ans){

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

}

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    
        if((m*n)!=original.size()){
            cout << "Cannot Implement 2D Array" << endl;
        }
        
        vector<vector<int>> ans(m,(vector<int>(n)));
        int idx=0; 

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=original[idx];
                idx++;
            }
        }

        PrintVector(ans);

    }

int main(){

    vector<int> original = {1,2,3,4,5,6,7,8,9,10};
    int rows=5,cols=2;

    construct2DArray(original,rows,cols);

    return 0;
}
