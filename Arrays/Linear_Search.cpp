#include<iostream>
using namespace std;

int findKey(int *arr, int n, int key){

    for(int i=0;i<n;i++){
        
        if(arr[i]==key){
            return i;   // return index when key is found
        }

    }

    return -1;   // return -1 if key not present
}

int main(){

    int arr[7] = {1,5,3,-4,0,8,9};
    int key = 9;
    int n = 7;
    int result = findKey(arr,n,key);

    cout << "Given Key is in : " << result << "th Index" << endl;
    
    return 0;

}
