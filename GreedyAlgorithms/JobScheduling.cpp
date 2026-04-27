#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Job{
public:
    int idx;
    int profit;
    int deadLine;
    
    Job(int idx, int deadLine, int profit){
        this->idx = idx;
        this->deadLine = deadLine;
        this->profit = profit;
    }
};

void maxProfit(vector<pair<int,int>> pairs){

    int n = pairs.size();
    vector<Job> jobs;

    for(int i=0;i<n;i++){
        jobs.emplace_back(i,pairs[i].first,pairs[i].second);
    }

    sort(jobs.begin(),jobs.end(), [](Job &a, Job &b){
        return a.profit > b.profit;
    });

    cout << "Selecting Job " << jobs[0].idx << endl;
    int profit = jobs[0].profit;
    int safeDeadLine = 2;

    for(int i=1;i<n;i++){
        if(jobs[i].deadLine >= safeDeadLine){
            cout << "Selecting Job " << jobs[i].idx << endl;
            profit += jobs[i].profit;
            safeDeadLine = jobs[i].deadLine;
        }
    }

    cout << "MaxProfit is :- " << profit << endl;

    return;

}

int main(){

    vector<int> days = {4,1,1,1};
    vector<int> profit = {20,10,40,30};

    int n = days.size();
    vector<pair<int,int>> jobs (n,make_pair(0,0)); 
    
    for(int i=0;i<n;i++){
        jobs[i] = make_pair(days[i],profit[i]);
    }

    maxProfit(jobs);
    
    return 0;
}
