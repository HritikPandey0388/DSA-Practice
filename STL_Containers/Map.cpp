#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){

    // Insertion
    map<int,string> m;

    // Creation
    m[1] = "Laptop";
    m[2] = "Earphones";
    m[3] = "Headphones";
    m[4] = "Mobile";
    m[5] = "TV";

    // count keys
    m.count(2);

    // accessing
    cout << m[4] << endl;
    
    // updation
    m[3] = "Smartwatch";

    // loop
    for(auto it:m){
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}