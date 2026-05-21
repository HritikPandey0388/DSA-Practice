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

            for(int i = 0; i < key.size(); i++){

            // If current character does not exist in Trie --> word not exist
            if(temp->children.count(key[i]) == 0){
                return false;
            }

            // Move to next character node
            temp = temp->children[key[i]];
        } 

        // Return true only if current node marks end of a word
        return temp->endOfWord;
      
    }

};

int main(){

    vector<string> words = {"the", "a", "there", "any", "thee"};
    Trie trie;

    for(int i=0; i<words.size(); i++){
        trie.insert(words[i]);
    }

    cout << trie.search("their") << endl;
    cout << trie.search("there") << endl;

    return 0;
}