#include<iostream>
using namespace std;

int findLargest(int *arr,int n){

    int largest = arr[0];   // assume first element is largest

    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];   // update if current element is greater
        }
    }

    return largest;   // return final largest element
}

int main(){
    
    int arr[6] = {-1,4,5,2,-7,0};
    int n = 6;
    
    int result = findLargest(arr,n);   // function call

    cout << "Largest element is : " << result << endl;
    
    return 0;
}