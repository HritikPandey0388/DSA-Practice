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

bool isIdentical(Node* root, Node* subRoot){

    if(subRoot==NULL && root==NULL){
        return true;
    }
    else if(root==NULL || subRoot==NULL){
        return false;
    }

    if(root->data != subRoot->data){
        return false;
    }

    return (isIdentical(root->left,subRoot->left) && isIdentical(root->right,subRoot->right));

}

bool isSubTree(Node* root, Node* SubRoot){

    if(root==NULL && SubRoot==NULL){
        return true;
    }
    else if(root==NULL || SubRoot==NULL){
        return false;
    }

    if(root->data==SubRoot->data){
        if(isIdentical(root,SubRoot)){
            return true;
        }    
    }  
    
    int isLeftSubTee =  isSubTree(root->left,SubRoot);
    if(!isLeftSubTee){
        return isSubTree(root->right,SubRoot);
    }

    return true;
}

int main(){
    vector<int> Tree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    vector<int> SubTree = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root1 = BuildTree(Tree);
    idx = -1;
    Node* root2 = BuildTree(SubTree);

    cout << isSubTree(root1,root2) << endl;

    return 0;
}