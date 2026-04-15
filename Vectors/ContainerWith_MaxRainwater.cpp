#include<iostream>
#include<vector>
using namespace std;

void MaxArea(vector<int> &height){

    int maxWater = 0;

    int lp = 0;                        // left pointer
    int rp = height.size() - 1;        // right pointer

    while(lp < rp){

        int width = rp - lp;                           // width
        int ht = min(height[lp], height[rp]);          // height
            
        int currentWater = width * ht;                 // area
            
        maxWater = max(maxWater, currentWater);        // update max
            
        // Move the pointer with smaller height
        if(height[lp] < height[rp]){
            lp++;
        } else {
            rp--;
        }
    }
    
    cout << "Container With max Water is : " << maxWater << endl;
}

int main(){

    vector<int> height= {1,8,6,2,5,4,8,3,7};

    MaxArea(height);

    return 0;
}