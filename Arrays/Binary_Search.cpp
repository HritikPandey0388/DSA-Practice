#include<iostream>
using namespace std;

int BinarySearch(int *arr, int n, int key){

    int st = 0, end = (n-1);           

    while(st<=end){                                        // base case
          
        int mid = st + (end-st)/2;                        // finding mid for next call 

        if(arr[mid]==key){                                // ans found
            return mid;
        }

        else if(arr[mid]<key){                            // answer exist in right part of array
            st = mid+1;
        }

        else{
            end = mid-1;                                  // answer exist in left part of array 
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