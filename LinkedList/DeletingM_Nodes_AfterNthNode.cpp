#include <iostream>
#include <list>
using namespace std;

void Delete(list<int> &list, int n, int m){

    if(list.empty() || m == 0){
        return;
    }

    if(n == 0){
        list.clear();
        return;
    }

    auto it = list.begin();

    while(it != list.end()){

        // Skip n-1 nodes
        for(int i = 1; i < n && it != list.end(); i++){
            ++it;
        }

        if(it == list.end()){
            break;
        } 

        // Delete next m nodes
        auto temp = next(it);

        for(int i = 0; i < m && temp != list.end(); i++){
            temp = list.erase(temp);  // erase returns next iterator
        }

        // Move forward
        it = temp;
    }
}

int main(){

    list<int> ll = {1,2,3,4,5,6,7,8};

    int n = 2, m = 2;

    cout << "Before: ";
    for(int x : ll){
        cout << x << "-->";
    }
    cout << "NULL" << endl;

    Delete(ll, n, m);

    cout << "After: ";
    for(int x : ll){
        cout << x << "-->";
    }
    cout << "NULL" << endl;

    return 0;

}