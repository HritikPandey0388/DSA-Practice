#include <iostream>
#include <vector>
using namespace std;

int mergeCount(vector<int>& arr, int st, int mid, int end){

    int i = st, j = mid + 1;
    int count = 0;
    
    vector<int> temp;

    while(i <= mid  && j <= end){

        if(arr[i] < arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            count += (mid - i + 1);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx = st; idx <= end; idx++){
        arr[idx] = temp[idx-st];
    }
    

    return count;

}

int inversionCount(vector<int>& arr, int st, int end){

    if(st >= end){
        return 0;
    }

    int count = 0;

    int mid = st + (end - st)/2;

    count += inversionCount(arr, st, mid);
    count += inversionCount(arr, mid + 1, end);

    count += mergeCount(arr, st, mid, end);

    return count;

}

int main() {
    
    vector<int> arr = {2, 4, 1, 3, 5};
    int n = arr.size();

    cout << inversionCount(arr, 0, n-1) << endl;

    return 0;
}