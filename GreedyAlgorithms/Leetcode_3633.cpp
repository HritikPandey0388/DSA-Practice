#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration){

    int n = landStartTime.size();
    int m = waterStartTime.size();

    // Earliest land ride finish time
    int minLandEnd = INT_MAX;

    for(int i = 0; i < n; i++){
        minLandEnd = min(minLandEnd, landStartTime[i] + landDuration[i]);
    }

    int ans = INT_MAX;

    // Land -> Water
    for(int i = 0; i < m; i++){

        int currTime = max(minLandEnd, waterStartTime[i]);

        currTime += waterDuration[i];

        ans = min(ans, currTime);
    }

    // Earliest water ride finish time
    int minWaterEnd = INT_MAX;

    for(int i = 0; i < m; i++){
        minWaterEnd = min(minWaterEnd, waterStartTime[i] + waterDuration[i]);
    }

    // Water -> Land
    for(int i = 0; i < n; i++){

        int currTime = max(minWaterEnd, landStartTime[i]);

        currTime += landDuration[i];

        ans = min(ans, currTime);
    }

    return ans;
}

int main(){

    vector<int> landStartTime = {2, 8};
    vector<int> landDuration = {4, 1};

    vector<int> waterStartTime = {6};
    vector<int> waterDuration = {3};

    cout << earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);

    return 0;
}