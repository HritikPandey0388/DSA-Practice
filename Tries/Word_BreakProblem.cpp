#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
public:
    
    unordered_map<char, Node*> children;   // stores children character and Node address for each children node  
    bool endOfWord;                        // end of word

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;         // NULL

public:
    
    Trie(){
        root = new Node();
    }

    void insert(string key){
        
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            
            // if character of key not exist --> add 
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            // point temp to next character child
            temp = temp->children[key[i]];
        }

        // end of current key(Word)
        temp->endOfWord = true;
    }

    bool search(string key){

        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            if(temp->children.count(key[i]) == 0){
                return false;
            }
            temp = temp->children[key[i]];
        } 

        return temp->endOfWord;
          
    }

};

bool helper(Trie& trie, string key){

    // base case
    if(key.size() == 0){
        return true;
    }

    // break key in 2 parts for each idx
    for(int i=0; i<key.size(); i++){
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        // first exist --> check for second
        if(trie.search(first) && helper(trie, second)){
            return true;
        }
    }

    // not exist
    return false;

}

bool wordBreak(vector<string> dict, string key){

    Trie trie;

    // build trie from dict
    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    // check key exist in trie
    return helper(trie, key);
}

int main(){

    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};
    string key = "ilikesamsung";
    
    cout << wordBreak(dict, key) << endl; 

    return 0;
}