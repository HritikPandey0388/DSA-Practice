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
    
    bool startWith(string prefix){

        // Start from root
        Node* temp = root;

        // Traverse prefix characters
        for(int i=0; i<prefix.size(); i++){

            // Prefix character not found
            if(temp->children.find(prefix[i]) == temp->children.end()){
                return false;
            }

            // Move to next node
            temp = temp->children[prefix[i]];
        } 

        // All prefix characters found
        return true;
    }

};

int main(){

    vector<string> words = {"apple", "app", "mango", "man", "woman"};
    string prefix1 = "app";
    string prefix2 = "moon";

    Trie trie;
    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout << trie.startWith(prefix1) << endl;
    cout << trie.startWith(prefix2) << endl;

    return 0;
}