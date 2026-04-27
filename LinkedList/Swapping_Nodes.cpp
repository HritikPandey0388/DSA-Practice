#include <iostream>
#include <list>
using namespace std;

void Swap(list<int> &ll, int x, int y){

    auto it1 = ll.begin();
    auto it2 = ll.begin();

    // Find x
    while(it1 != ll.end() && *it1 != x){
        ++it1;
    }

    // Find y
    while(it2 != ll.end() && *it2 != y){
        ++it2;
    }

    // if one or both of them not found
    if(it1 == ll.end() || it2 == ll.end()){
        return;
    }

    // Swap values
    swap(*it1, *it2);

}

int main(){

    list<int> ll = {1,2,3,4,5,6,7,8};

    int n = 2, m = 8;

    cout << "Before: ";
    for(int x : ll){
        cout << x << "-->";
    }
    cout << "NULL" << endl;

    Swap(ll, n, m);

    cout << "After: ";
    for(int x : ll){
        cout << x << "-->";
    }
    cout << "NULL" << endl;

    return 0;

}