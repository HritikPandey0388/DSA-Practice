#include<iostream>
#include<set>
using namespace std;

int main(){

    set<int> s;

    // insert
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(2);

    // Size
    cout << s.size() << endl;
    
    // search
    if(s.find(2) != s.end()){
        cout << "2 Exist" << endl;
    }
    else{
        cout << "2 does't exist" << endl;
    }

    // accessing each key
    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    // delete
    s.erase(2);

    for(auto it : s){
        cout << it << " ";
    }
    cout << endl;

    return 0;
}