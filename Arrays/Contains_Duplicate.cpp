#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

bool ContainsDuplicate(int *arr, int n){

    unordered_set<int> s;

    for(int i=0;i<n;i++){

        if(s.find(arr[i])==s.end()){
            s.insert(arr[i]);
        }
        else{
            return false;
        }
    }

    return true;

}

int main(){

    int arr[]= {1,2,1,4};
    int n = sizeof(arr)/sizeof(int);

    if(ContainsDuplicate(arr,n)){
        cout << "No dublicate elements." << endl;
    }
    else{
        cout << "Contains dublicate elements." << endl;
    }

    return 0;
}