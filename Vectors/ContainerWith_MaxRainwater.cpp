#include<iostream>
#include<vector>
using namespace std;

void MaxArea(vector<int> &height){

    int maxWater=0;
    int lp=0;
    int rp=(height.size()-1);

    while(lp<rp){

        int w=rp-lp;
        int ht=min(height[lp],height[rp]);
            
        int currentWater=w*ht;
            
        maxWater=max(maxWater,currentWater);
            
        height[lp]<height[rp] ? lp++ : rp--;
    }
    
    cout << "Container With max Water is : " << maxWater << endl;

}

int main(){

    vector<int> height= {1,8,6,2,5,4,8,3,7};

    MaxArea(height);

    return 0;
}