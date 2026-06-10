#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

    // value -> node mapping
    unordered_map<int, TreeNode*> m;

    // stores all child nodes
    unordered_set<int> children;

    // create nodes and build tree
    for(vector<int>& vec : descriptions) {

        int parent = vec[0];
        int child = vec[1];
        int isLeft = vec[2];

        // create parent node if not present
        if(m.find(parent) == m.end()) {
            m[parent] = new TreeNode(parent);
        }

        // create child node if not present
        if(m.find(child) == m.end()) {
            m[child] = new TreeNode(child);
        }

        // connect parent and child
        if(isLeft == 1) {
            m[parent]->left = m[child];
        }
        else {
            m[parent]->right = m[child];
        }

        // mark child
        children.insert(child);
    }

    // root never appears as a child
    for(auto& p : m) {
        if(children.find(p.first) == children.end()) {
            return p.second;
        }
    }

    return NULL;
}

int main() {

    vector<vector<int>> descriptions = {
        {20,15,1},
        {20,17,0},
        {15,10,1}
    };

    TreeNode* root = createBinaryTree(descriptions);

    cout << root->val << endl;

    return 0;
}
