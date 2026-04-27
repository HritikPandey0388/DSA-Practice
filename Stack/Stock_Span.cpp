#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void StockSpan(vector<int> &Stock){

    int n = Stock.size();
    vector<int> span(n);
    span[0] = 1;

    stack<int> s;
    s.push(0);

    for(int i=1;i<n;i++){
        int currPrice = Stock[i];
        while(!s.empty() && Stock[s.top()]<=currPrice){
            s.pop();
        }

        if(s.empty()){
            span[i] = i+1;
        }
        else{
            int prevHigh = s.top();
            span[i] = i-prevHigh;
        }
        s.push(i);
    }

    for(int i=0;i<span.size();i++){
        cout << span[i] << " " ;
    }
    cout << endl;

}

int main(){

    vector<int> Stock = {100,80,60,70,60,85,100};

    StockSpan(Stock);
    
    return 0;
}