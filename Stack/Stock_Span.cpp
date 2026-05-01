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

        // current Price
        int currPrice = Stock[i];

        // pop until stack top less than current Price
        while(!s.empty() && Stock[s.top()]<=currPrice){
            s.pop();
        }

        // No Previous high
        if(s.empty()){
            span[i] = i+1;
        }
        else{
            // update Previous high and span for current index
            int prevHigh = s.top();
            span[i] = i-prevHigh;
        }

        // pushing current index
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