/*
    Problem: Linear Search in an Array
    Author: Hritik Pandey
    Description:
    This program takes n numbers and a key as input,
    and searches for the key in the array using Binary search.
    It prints the index if found, or -1 if not found.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

int BinarySearch(int *arr, int n, int key){

    int st = 0, end = (n-1);

    while(st<=end){
         
        int mid = st + (end-st)/2;

        if(arr[mid]==key){
            return mid;
        }

        else if(arr[mid]<key){
            st = mid+1;
        }

        else{
            end = mid-1;
        }
    }

    return -1;
}

int main(){
    
    int arr[7] = {1,5,6,9,11,16,20};
    int key = 16;
    int n = sizeof(arr)/sizeof(int);

    int result = BinarySearch(arr,n,key);

    if(result==-1){
        cout << "Key not found" << endl;
    }
    
    else{
        cout << "Given Key is in : " << result << endl;
    } 
    
    return 0;

}