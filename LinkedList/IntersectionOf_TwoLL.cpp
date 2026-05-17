#include <iostream>
#include <list>
using namespace std;

void PrintLL(list<int> &list){
    for(int x : list){
        cout << x << "-->";
    }
    cout << endl;
}

int Intersection(list<int> &L1, list<int> &L2){

    // slow pointer --> beginning of first list
    auto slow = L1.begin();

    // fast pointer --> beginning of second list
    auto fast = L2.begin();
    
    // Continue until slow = fast
    while(*slow != *fast){

        // slow --> +1 step
        ++slow;

        // If end --> end
        // end --> beginning
        if(slow == L1.end()){
            slow = L1.begin();
        }

        // fast --> +2 steps
        ++(++fast);

        // If fast --> end
        // fast --> beginning
        if(fast == L2.end()){
            fast = L2.begin();
        }
    }

    // Return the common/intersection value
    return *slow;
}

int main(){

    list<int> L1 = {1,2,3,4,5,6,7,8};
    list<int> L2 = {4,5,6,7,8};

    cout << "Given LL's are:- ";
    PrintLL(L1);
    PrintLL(L2);

    int ans = Intersection(L1,L2);

    cout << "Interection point is :- " << ans << endl;

    return 0;

}