#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int MaxAreaInHistogram(vector<int> &height){

    int n = height.size();

    if(n == 0){
        return 0;
    } 

    
    stack<int> s;
    vector<int> nsl(n);
    vector<int> nsr(n);

    nsl[0] = -1;
    s.push(0);

    //next smaller left (nsl)
    for(int i=1;i<n;i++){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsl[i] = -1;
        }
        else{
            nsl [i] = s.top();
        }
        s.push(i);
    }

    while(!s.empty()){
        s.pop();
    }

    s.push(n-1);
    nsr[n-1] = n;

    //next smaller right (nsr)
    for(int i=(n-2);i>=0;i--){
        int curr = height[i];
        while(!s.empty() && curr<=height[s.top()]){
            s.pop();
        }
        if(s.empty()){
            nsr[i] = n;
        }
        else{
            nsr[i] = s.top();
        }
        s.push(i);
    }

    int maxArea = 0;
    for(int i=0;i<n;i++){
        int ht = height[i];                 // height
        int wid = nsr[i]-nsl[i]-1;          // width 
        int area = ht*wid;                  // Area = height*width 
        maxArea = max(maxArea,area);        // updating maxArea
    }

    return maxArea;

}

int main(){

    vector<int> height = {2,1,2,6,5,3};

    int ans = MaxAreaInHistogram(height);

    cout << "Max Area of the Histogram is :- " << ans << endl;

    return 0;
}
