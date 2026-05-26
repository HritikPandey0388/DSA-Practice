#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node{
public:
    unordered_map<char, Node *> children; // stores children character and Node address for each children node
    bool endOfWord;                       // end of word

    Node(){
        endOfWord = false;
    }
};

class Trie{
    Node *root; // NULL

public:
    Trie(){
        root = new Node();
    }

    void insert(string key){

        Node *temp = root;
        for (int i = 0; i < key.size(); i++){

            // if character of key not exist --> add
            if (temp->children.count(key[i]) == 0){
                temp->children[key[i]] = new Node();
            }
            // point temp to next character child
            temp = temp->children[key[i]];
        }

        // end of current key(Word)
        temp->endOfWord = true;
    }

    bool search(string key){

        Node *temp = root;
        for (int i = 0; i < key.size(); i++){
            if (temp->children.count(key[i]) == 0){
                return false;
            }
            temp = temp->children[key[i]];
        }

        return temp->endOfWord;
    }

    void longestHelper(Node *root, string &ans, string temp){

        // Traverse all children of current node
        for (pair<char, Node *> child : root->children){

            // We only continue if current prefix forms a valid word
            if (child.second->endOfWord){

                // Add current character to temporary string
                temp += child.first;

                // Update answer if:
                // 1. temp length is greater than ans length
                // 2. lengths are same but temp is lexicographically smaller
                if ((temp.size() == ans.size() && temp < ans) || temp.size() > ans.size()){

                    ans = temp;
                }

                // Recursively explore further children
                longestHelper(child.second, ans, temp);

                // remove last character before moving to next child
                temp = temp.substr(0, temp.size() - 1);
            }
        }
    }

    string longestStringWithEOW(){

        string ans = "";

        // Start DFS traversal from root
        longestHelper(root, ans, "");

        return ans;
    }
};

string longestString(vector<string> &dict)
{
    Trie trie;

    for (int i = 0; i < dict.size(); i++){
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}

int main()
{

    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << longestString(dict) << endl;
    return 0;
}