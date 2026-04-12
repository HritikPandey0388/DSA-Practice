#include<iostream>
using namespace std;

void ReverseArray(int* arr, int n){

    int st=0, end=(n-1);                 

    while(st<end){

        // reversing arr[st] and arr[end]
        int temp = arr[st];               
        arr[st] = arr[end];
        arr[end] = temp;

        // updating 
        st++;       // st(-->) 
        end--;      // end(<--)
    }

}

int PrintArray(int* arr, int n){

    for(int i=0;i<n;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;

    return 0;

}

int main(){
    
    int arr[5] = {1,2,3,4,5};
    int n = 5;  

    cout << " Given Array is : " ;
    PrintArray(arr,n);

    ReverseArray(arr,n);

    cout << " Reverse Array is : " ;
    PrintArray(arr,n);
    
    return 0;

}