#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

// min Heap comparator
struct ComparePair{

    bool operator () (pair<string,int> &p1, pair<string,int> &p2){
        return p1.second > p2.second;
    }
};

int main(){

    // Min-heap 
    priority_queue<pair<string,int>, vector<pair<string,int>>, ComparePair> pq;

    // Insert name-score pairs into the priority queue
    pq.push(make_pair("Hritik",100));
    pq.push(make_pair("Anurag",245));
    pq.push(make_pair("Prachi",167));
    pq.push(make_pair("Chirag",670));

    // Printing PQ
    while(!pq.empty()){

        cout << "Top :- "
             << pq.top().first << " , "
             << pq.top().second << endl;

        pq.pop();
    }

    return 0;
}