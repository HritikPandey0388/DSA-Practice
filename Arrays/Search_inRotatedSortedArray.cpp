#include<iostream>
#include<climits>
using namespace std;

int Search(int *arr, int n, int target){

    int st=0,end=(n-1);
    
    while(st<=end){

        int mid= st + (end-st)/2;

        if(arr[mid]==target){
            return mid;
        }

        if(arr[st]<=arr[mid]){             //left sorted
            
            if(arr[st]<=target && target<=arr[mid]){
                end = mid-1;
            }
            else{
                st = mid+1;
            }  

        }
        else{                              //right sorted

            if(arr[mid]<=target && target<=arr[end]){
                st = mid+1;
            }
            else{
                end = mid-1;
            }

        }

    }

    return -1;

}

int main(){

    int arr[] = {4,5,6,7,0,1,2};
    int n = sizeof(arr)/sizeof(int);
    int target = 6;

    cout << "Founded given target at : " << Search(arr,n,target) << endl;

    return 0;
}