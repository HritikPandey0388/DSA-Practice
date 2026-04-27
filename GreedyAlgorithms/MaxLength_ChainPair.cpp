#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second < p2.second;
}

int MaxLengthChain(vector<pair<int,int>>& P, int n){

    // selecting 1st chain Length
    int ans = 1;
    int currEnd = P[0].second;

    for(int i=1;i<n;i++){
 
        // selecting next chains....
        if(currEnd<P[i].first){
            ans++;
            currEnd = P[i].second;
        }
    }
    
    return ans;
}

int main(){
    vector<int> A = {5,39,5,27,50};
    vector<int> B = {24,60,28,40,90};

    int n = A.size();

    // making pairs of A and B
    vector<pair<int,int>> P(n,make_pair(0,0));

    for(int i=0;i<n;i++){
        P[i] = make_pair(A[i],B[i]);
    }

    // sorting vector of pair
    sort(P.begin(),P.end(),compare);

    cout << MaxLengthChain(P,n) << endl;

    return 0;
}
