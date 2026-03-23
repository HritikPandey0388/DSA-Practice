#include<iostream>
#include<string>
using namespace std;

void isValid(string &str1, string &str2){

    if(str1.size()!=str2.size()){
        cout << "Not Valid" << endl;
        return;
    }    

    int i=-1,j=-1;
    int count = 0;

    for(int k = 0; k < str1.size(); k++){
        if(str1[k] != str2[k]){
            count++;

            if(count == 1){
                i = k;
            } 
            else if(count == 2){
                j = k;
            }
            else{
                cout << "Not Valid" << endl;
                return;
            }
        }
    }

    // 0 mismatch → already equal
    if(count == 0){
        cout << "Valid" << endl;
        return;
    }

    // exactly 2 mismatch → check swap
    if(count == 2){
        swap(str2[i], str2[j]);

        if(str1 == str2){
            cout << "Valid" << endl;
            return;
        }
    }
    
}

int main(){

    string str1= "abcd";
    string str2= "abdc";

    isValid(str1,str2);

    return 0;
}