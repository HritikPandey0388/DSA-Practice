#include <iostream>
#include <climits>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

bool validate(TreeNode* root, long long minVal, long long maxVal) {

    // base case
    if(root == NULL){
        return true;
    }

    // current node should lie in valid range
    if(root->val <= minVal || root->val >= maxVal){
        return false;
    }

    // check left and right subtree
    return validate(root->left, minVal, root->val) &&
           validate(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {

    return validate(root, LLONG_MIN, LLONG_MAX);
}

int main() {

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(6);

    if(isValidBST(root)){
        cout << "Valid BST";
    }
    else{
        cout << "Not a Valid BST";
    }

    return 0;
}