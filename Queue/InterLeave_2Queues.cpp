#include<iostream>
#include<queue>
using namespace std;

void InterLeaf(queue<int> &Org){

    int n = Org.size();
    queue<int> q;

    for(int i=0;i<n/2;i++){
        q.push(Org.front());
        Org.pop();
    }

    while(!q.empty()){
        Org.push(q.front());
        q.pop();
        Org.push(Org.front());
        Org.pop();
    }
}

int main(){
    queue<int> Org;

    for(int i=1;i<=10;i++){
        Org.push(i);
    }

    InterLeaf(Org);

    for(int i=1;i<=10;i++){
        cout << Org.front() << " ";
        Org.pop();
    }
    cout << endl;
    
    return 0;
}
