#include<iostream>
#include<queue>
using namespace std;

int main(){

    // Descending --> priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    // Push
    pq.push(5);
    pq.push(10);
    pq.push(9);
    pq.push(7);
    pq.push(3);

    while(!pq.empty()){                             // Empty
        cout << "Top :- " << pq.top() << endl;      // Top Element
        pq.pop();                                   // Pop
    }

    return 0;
}