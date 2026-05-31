#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool asteroidsDestroyed(int mass, vector<int>& asteroids){

    sort(asteroids.begin(), asteroids.end());
    int n = asteroids.size();

    long long sum = mass;

    for(int i = 0; i < n; i++){

        if(sum >= asteroids[i]){
            sum += asteroids[i];
        }
        else{
            return false;
        }
    }

    return true;
}

int main(){

    int mass = 10;
    vector<int> asteroids = {3, 9, 19, 5, 21};

    cout << asteroidsDestroyed(mass, asteroids) << endl;

    return 0;
}