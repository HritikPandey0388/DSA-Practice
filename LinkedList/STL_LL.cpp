#include<iostream>
#include<list>
using namespace std;

void PrintList(list<int> ll){

    list<int>::iterator itr;

    for(itr = ll.begin(); itr != ll.end(); ++itr){
        cout << *itr << "-->";
    }
    cout << "NULL" << endl;

}

int main(){
    list<int> ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    PrintList(ll);

    cout << "Size of list :-" << ll.size() << endl; 

    cout << "Head :- " << ll.front() << endl;
    cout << "Tail :- " << ll.back() << endl;

    ll.pop_back();
    PrintList(ll);

    return 0;
}
