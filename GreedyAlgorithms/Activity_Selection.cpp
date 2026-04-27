#include<iostream>
#include<vector>
using namespace std;

int MaxActivity(vector<int> start, vector<int> end){

    // Selection 1st Activity
    cout << "Selection A0 Activity." << endl;
    int currEndTime = end[0];
    int count = 1;

    for(int i=1;i<start.size();i++){

        if(currEndTime<=start[i]){
            cout << "Selection A"<< i << "Activity." << endl;
            currEndTime = end[i];
            count++;
        }
    }

    return count;
}

int main(){
    
    vector<int> start = {1,3,0,5,8,5};
    vector<int> end = {2,4,6,7,9,9};

    cout << MaxActivity(start,end) << endl;

    return 0;
}