#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node{
public:
    
    unordered_map<char, Node*> children;   // stores children character and Node address for each children node  
    bool endOfWord;    
    int freq;                    // end of word

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node* root;         // NULL

public:
    
    Trie(){
        root = new Node();
        root->freq = -1;
    }

    void insert(string key){
        
        Node* temp = root;
        for(int i=0; i<key.size(); i++){
            
            // if character of key not exist --> add 
            if(temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
                temp->children[key[i]]->freq = 1;
            }
            else{
                temp->children[key[i]]->freq++;
            }
            // point temp to next character child
            temp = temp->children[key[i]];
        }

        // end of current key(Word)
        temp->endOfWord = true;
    }

    string getPrefix(string key){

        Node* temp = root;

        string prefix = "";

        // Traverse each character of the word
        for(int i=0; i<key.size(); i++){

            // Add current character to prefix
            prefix += key[i];

            // If frequency becomes 1,
            // this prefix is unique
            if(temp->children[key[i]]->freq == 1){
                break;
            }

            // Move to next node
            temp = temp->children[key[i]];
        }

        return prefix;
    }  

};

void PrefixProblem(vector<string>& dict){
    Trie trie;

    for(int i=0; i<dict.size(); i++){
        trie.insert(dict[i]);
    }

    // unique prefix for every word
    for(int i=0; i<dict.size(); i++){
        cout << trie.getPrefix(dict[i]) << " ";
    }
    cout << endl;
}

int main(){

    vector<string> dict = {"zebra", "dog", "duck", "dove"};

    PrefixProblem(dict);
    return 0;
}