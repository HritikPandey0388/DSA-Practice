#include<iostream>
using namespace std;

void TowerOfHanoi(int n,char source, char helper, char destination){
    
    if(n==0){
        return;
    }

    TowerOfHanoi(n-1,source,destination,helper);
    cout << source << "-->" << destination << endl;
    TowerOfHanoi(n-1,helper,source,destination);

}

int main(){

    int n = 3;
    TowerOfHanoi(n,'A','B','C');
    return 0;
}