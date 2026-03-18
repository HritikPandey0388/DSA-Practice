/*
    Problem: Linear Search in an Array
    Author: Hritik Pandey
    Description:
    This program takes n numbers and a key as input,
    and searches for the key in the array using linear search.
    It prints the index if found, or -1 if not found.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

int findKey(int arr[], int n, int key){

    for(int i=0;i<n;i++){
        
        if(arr[i]==key){
            return i;
        }

    }

    return -1;
}

int main(){
    
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    int key;

    cout << "Enter key to search : ";
    cin >> key;

    int arr[n];

    cout << "Enter elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int result = findKey(arr,n,key);

    cout << "Given Key is in : " << result << "th Index" << endl;
    
    return 0;

}
