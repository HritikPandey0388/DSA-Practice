#include<iostream>
#include<queue>
using namespace std;

int main(){

    // initializing STL queue
    queue<int> q;

    // push
    for(int i=0;i<5;i++){
        q.push(i);
    }

    // accessing each element
    while(!q.empty()){
        cout << q.front() << "-->";
        q.pop();
    }
    cout << "End" << endl;
    
    return 0;
}