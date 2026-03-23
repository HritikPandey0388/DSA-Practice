#include<iostream>
#include<string>
using namespace std;

void isAnagram(string &str1, string &str2){
    
    if(str1.length()!=str2.length()){
        cout << "Not a Valid Anagram" << endl;
        return;
    }

    int count[26]={0};

    for(int i=0;i<str1.length();i++){
        count[str1[i]-'a']++;
    }

    for(int i=0;i<str2.length();i++){
        
        if(count[str2[i]-'a']==0){
            cout << "Not a Valid Anagram" << endl;
            return;
        }
        count[str2[i]-'a']--;
        
    }
    
    cout << "Valid Anagram" << endl;
}

int main(){

    string str1= "racecar";
    string str2= "carrace";

    isAnagram(str1,str2);

    return 0;
}