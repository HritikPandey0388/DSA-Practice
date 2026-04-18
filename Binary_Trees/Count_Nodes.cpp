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

    Node* currNode = new Node(nodes[idx]);             
    currNode->left = BuildTree(nodes);                 
    currNode->right = BuildTree(nodes);                
    
    return currNode;
}

int Count(Node* root){
 
    if(root==NULL){                         // base case
        return 0;
    }

    int lcount = Count(root->left);      // call for left subtree count
    int rcount = Count(root->right);     // call for right subtree count   

    int currCount = (lcount + rcount + 1);   // including current Node count 
    return currCount;
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    cout << "Total Nodes of given Binary tree is :- " << Count(root) << endl;
    return 0;
}