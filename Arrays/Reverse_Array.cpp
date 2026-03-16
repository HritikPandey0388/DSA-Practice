/*
    Problem: Reverse an Array
    Author: Hritik Pandey
    Description:
    This program takes n numbers as input and reverses
    the array in-place. It then prints the reversed array.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include<iostream>
using namespace std;

void ReverseArray(int arr[], int n){

    int st=0, end=(n-1);

    while(st<end){

        int temp = arr[st];
        arr[st] = arr[end];
        arr[end] = temp;

        st++;
        end--;
    }

}

int PrintArray(int arr[], int n){

    for(int i=0;i<n;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;

    return 0;

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

    cout << " Given Array is : " ;
    PrintArray(arr,n);

    ReverseArray(arr,n);

    cout << " Reverse Array is : " ;
    PrintArray(arr,n);
    
    return 0;

}