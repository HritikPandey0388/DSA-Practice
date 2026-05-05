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

Node* LCA(Node* root, int n1, int n2){

    // base case
    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    // check Node exist in right or left Subtree
    Node* leftLCA = LCA(root->left,n1,n2);
    Node* rightLCA = LCA(root->right,n1,n2);

    // n1 and n2 found for Current Root
    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }

    // Node exist in only one subTree (right ot left)
    return leftLCA==NULL ? rightLCA : leftLCA;

}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    Node* Ancestor = LCA(root,4,3);
    cout << Ancestor->data << endl;

    return 0;
}