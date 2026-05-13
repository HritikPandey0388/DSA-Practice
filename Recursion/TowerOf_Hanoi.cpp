#include<iostream>
using namespace std;

void TowerOfHanoi(int n, char source, char helper, char destination){
    
    // base case:
    if(n==0){
        return;
    }

    // move top (n-1) disks from source to helper using destination
    TowerOfHanoi(n-1, source, destination, helper);

    // move nth disk from source to destination
    cout << source << "-->" << destination << endl;

    // move (n-1) disks from helper to destination using source 
    TowerOfHanoi(n-1, helper, source, destination);

}

int main(){

    int n = 3;
    TowerOfHanoi(n,'A','B','C');
    return 0;
}