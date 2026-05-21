#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node
{
public:
    unordered_map<char, Node *> children; // stores children character and Node address for each children node
    bool endOfWord;                       // end of word

    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
    Node *root; // NULL

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string key)
    {

        Node *temp = root;
        for (int i = 0; i < key.size(); i++)
        {

            // if character of key not exist --> add
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
            }
            // point temp to next character child
            temp = temp->children[key[i]];
        }

        // end of current key(Word)
        temp->endOfWord = true;
    }

    bool search(string key)
    {

        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {

            // If current character does not exist in Trie --> word not exist
            if (temp->children.count(key[i]) == 0)
            {
                return false;
            }

            // Move to next character node
            temp = temp->children[key[i]];
        }

        // Return true only if current node marks end of a word
        return temp->endOfWord;
    }

    int countHelper(Node *root)
    {
        // Count current node
        int ans = 0;

        // Traverse all children of current node
        for (pair<char, Node *> child : root->children)
        {
            // Recursively count nodes in child subtree
            ans += countHelper(child.second);
        }

        // +1 for current node itself
        return ans + 1;
    }

    int countNodes()
    {
        // Start counting from root node
        return countHelper(root);
    }
};

int countUniqueSubstring(string str)
{
    // Create Trie
    Trie trie;

    // Insert all suffixes of string into Trie
    for (int i = 0; i < str.size(); i++)
    {
        trie.insert(str.substr(i));
    }

    // Total Trie nodes = unique substrings + root node
    return trie.countNodes();
}

int main()
{

    string str = "ababa";

    cout << countUniqueSubstring(str);

    return 0;
}