#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Class --> car
class Car{
public:
    int idx;      // Car index
    int distSq;   // Distance from origin

    // Constructor
    Car(int idx, int distSq){
        this->idx = idx;
        this->distSq = distSq;
    }

    // min-heap based on distSq.
    bool operator < (const Car &obj) const{
        return this->distSq > obj.distSq;
    }
};

void nearbyCars(vector<pair<int,int>> pos, int k){

    vector<Car> cars;

    // Creating Car object
    for(int i = 0; i < pos.size(); i++){
        int distSq = pos[i].first * pos[i].first +
                     pos[i].second * pos[i].second;

        cars.push_back(Car(i, distSq));
    }

    // Create a min-heap using the custom comparator
    priority_queue<Car> pq(cars.begin(), cars.end());

    // Extract k closest cars
    for(int i = 0; i < k; i++){
        cout << "Car" << pq.top().idx << endl;
        pq.pop();
    }
}

int main(){

    vector<pair<int,int>> pos;

    // Coordinates of cars
    pos.push_back(make_pair(3,3));   // Car 0
    pos.push_back(make_pair(5,-1));  // Car 1
    pos.push_back(make_pair(-2,4));  // Car 2

    int k = 2;

    // Print 2 nearest cars
    nearbyCars(pos, k);

    return 0;
}