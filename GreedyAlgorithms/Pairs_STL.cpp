#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Print(vector<pair<int,int>> act, int n){
    for(int i=0;i<n;i++){
        cout << "A" << i << " : " << act[i].first << " , " << act[i].second << endl;
    }
}

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second<p2.second;
}

int main(){

    vector<int> start = {0,1,2};
    vector<int> end = {9,2,4};

    int n = start.size();

    vector<pair<int,int>> act(n,make_pair(0,0));

    cout << "Before Sorted :-" << endl;
    for(int i=0;i<start.size();i++){
        act[i] = make_pair(start[i],end[i]);
    }
    Print(act,n);

    cout << "After Sorted :-" << endl;
    sort(act.begin(),act.end(),compare);
    Print(act,n);

    return 0;
}