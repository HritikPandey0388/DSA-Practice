#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Prints maximum element of every window of size k
void SlidingWindow(vector<int>& arr, int k){

    // {value, index}
    // max heap based on value
    priority_queue<pair<int,int>> pq;

    // insert first window elements
    for(int i=0;i<k;i++){
        pq.push(make_pair(arr[i],i));
    }

    // maximum of first window
    cout << "Output : " << pq.top().first << " ";

    // process remaining windows
    for(int i=k;i<arr.size();i++){

        // remove elements that are outside current window
        while(!pq.empty() && pq.top().second <= i-k){
            pq.pop();
        }

        // add new element entering the window
        pq.push(make_pair(arr[i],i));

        // top of heap gives maximum element
        cout << pq.top().first << " ";
    }

    cout << endl;
}

int main(){

    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    SlidingWindow(arr,k);

    return 0;
}