#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main(){

    vector<int> A = {2,4,3,7};
    vector<int> B = {1,5,8,9};

    // sorting A,B so that pair A[i]-B[i] is minimum
    sort(A.begin(),A.end());                   
    sort(A.begin(),A.end());

    int absDif = 0;
    for(int i=0;i<A.size();i++){
        absDif += abs(A[i]-B[i]);
    }

    cout << "Min Abs Diff is :- " << absDif << endl;

    return 0;

}
