#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node{

    int child[26];
    int idx;

    Node(){

        // Best matching word index for this suffix
        idx = -1;

        for(int i = 0; i < 26; i++){
            child[i] = -1;
        }
    }
};

vector<Node> trie;

// Update best index at current node
void updateIndex(int node, vector<string>& wordsContainer, int wordIdx){

    if(trie[node].idx == -1){
        trie[node].idx = wordIdx;
        return;
    }

    int prevIdx = trie[node].idx;

    // Prefer shorter word
    if(wordsContainer[wordIdx].size() < wordsContainer[prevIdx].size()){
        trie[node].idx = wordIdx;
    }

    // If lengths are same, prefer smaller index
    else if(wordsContainer[wordIdx].size() == wordsContainer[prevIdx].size() &&
            wordIdx < prevIdx){
        trie[node].idx = wordIdx;
    }
}

// Insert reversed word into trie
void insert(string word, int wordIdx, vector<string>& wordsContainer){

    reverse(word.begin(), word.end());

    int node = 0;

    // Update root node
    updateIndex(node, wordsContainer, wordIdx);

    for(char ch : word){

        int c = ch - 'a';

        // Create node if it doesn't exist
        if(trie[node].child[c] == -1){

            trie[node].child[c] = trie.size();
            trie.push_back(Node());
        }

        node = trie[node].child[c];

        updateIndex(node, wordsContainer, wordIdx);
    }
}

// Find longest matching suffix
int helper(string word){

    reverse(word.begin(), word.end());

    int node = 0;

    for(char ch : word){

        int c = ch - 'a';

        // Suffix match ends here
        if(trie[node].child[c] == -1){
            break;
        }

        node = trie[node].child[c];
    }

    return trie[node].idx;
}

vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery){

    // Create root node
    trie.push_back(Node());

    // Build trie
    for(int i = 0; i < wordsContainer.size(); i++){
        insert(wordsContainer[i], i, wordsContainer);
    }

    vector<int> ans;

    // Process all queries
    for(string &q : wordsQuery){
        ans.push_back(helper(q));
    }

    return ans;
}

int main(){

    vector<string> wordsContainer = {"abcd", "bcd", "xbcd"};
    vector<string> wordsQuery = {"cd", "bcd", "xyz"};

    vector<int> ans = stringIndices(wordsContainer, wordsQuery);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}