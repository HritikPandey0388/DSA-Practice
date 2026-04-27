#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
    
};

static int idx = -1;

Node* BuildTree(vector<int> nodes){
    
    idx++;

    if(nodes[idx]==-1){
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);             // creating new node
    currNode->left = BuildTree(nodes);                 // left subTree
    currNode->right = BuildTree(nodes);                // right subTree
    
    return currNode;
}

int height(Node* root){
 
    if(root==NULL){                         // base case
        return 0;
    }

    int lheight = height(root->left);      // call for left subtree height
    int rheight = height(root->right);     // call for right subtree height   

    int currHeight = max(lheight,rheight) + 1;   // including current Node height 
    return currHeight;
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    cout << "Height of given Binary tree is :- " << height(root) << endl;
    return 0;
}
