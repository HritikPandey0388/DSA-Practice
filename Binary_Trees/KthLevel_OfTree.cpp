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

void helper(Node* root, int k, int currLevel){

    // Not found
    if(root==NULL){
        return;
    }

    // base case
    if(currLevel==k){                   
        cout << root->data << " ";      
        return ;                         
    }

    helper(root->left,k,currLevel+1);    // left subTree
    helper(root->right,k,currLevel+1);   // right subTree
}

void KthLevel(Node* root, int k){
    return helper(root,k,1);
    cout << endl;
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    int k =3;
    KthLevel(root,k);

    return 0;
}