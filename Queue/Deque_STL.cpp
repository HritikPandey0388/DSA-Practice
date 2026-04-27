#include<iostream>
#include<deque>
using namespace std;

int main(){
    
    deque<int> deq;

    // 1 2
    deq.push_front(2);
    deq.push_front(1);

    // 1 2 3 4
    deq.push_back(3);
    deq.push_back(4);

    // 2 3 4
    deq.pop_front();

    // 2 3
    deq.pop_back();

    cout << "Front :- " << deq.front() << endl;
    cout << "Back :- " << deq.back() << endl;

    return 0;
}