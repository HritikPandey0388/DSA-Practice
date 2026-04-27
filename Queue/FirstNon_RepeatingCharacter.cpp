#include<iostream>
#include<queue>
using namespace std;

void FirstNonRepeatingChar(string &str){

    queue<char> q;          
    int freq[26] = {0};    // Frequency of all characters in string

    // Traverse the string
    for(int i = 0; i < str.size(); i++){
        char ch = str[i];

        // Update frequency of current character
        freq[ch - 'a']++;

        // Push current character into queue
        q.push(ch);

        // Remove all repeating characters from the front
        while(!q.empty() && freq[q.front() - 'a'] > 1){
            q.pop();
        }

        // If queue --> empty (no non-repeating character)
        if(q.empty()){
            cout << "-1" << " ";
        }
        else{
            // non repeating character --> front of queue 
            cout << q.front() << " ";
        }
    }

    cout << endl;

}

int main(){

    string str = "aabccxb";

    FirstNonRepeatingChar(str);

    return 0;
}
