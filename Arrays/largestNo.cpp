/*
    Problem: Find the Largest Element in an Array
    Author: Hritik Pandey
    Description:
    This program takes n numbers as input and finds
    the largest element in the array.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

int findLargest(int arr[],int n){

    int largest = arr[0];

    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }

    return largest;
}

int main(){
    
    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    int arr[n];

    cout << "Enter elements : ";
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    int result = findLargest(arr,n);

    cout << "Largest element is : " << result << endl;
    
    return 0;
}