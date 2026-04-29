#include<iostream>
using namespace std;

class Node{
public:

    int data;
    Node* left;
    Node* right;
    
    Node(int val){
        left = right = NULL;
        data = val;
    }
};

Node* Insert(Node* root, int val) {
    if (root == NULL) {
        root = new Node(val);
        return root;
    }

    if (val < root->data) {
        root->left = Insert(root->left, val);
    } else {
        root->right = Insert(root->right, val);
    }

    return root;
}

Node* BuildTree(int arr[], int size) {

    Node* root = NULL;
    
    for (int i = 0; i < size; i++) {
        root = Insert(root, arr[i]);
    }

    return root;
}

void Inorder(Node* root){

    if(root==NULL){
        return ;
    }

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);

}

Node* getInorderSuccessor(Node* root){

    // Inorder Succcessor --> LeftMost Node
    while(root->left!=NULL){
        root = root->left;
    }

    return root;

}

Node* delNode(Node* root, int val){

    if(root==NULL){
        return NULL;
    }

    // Search and delete in Left SubTree
    if(val<root->data){
        root->left = delNode(root->left,val);
    }
    // Search and delete in right SubTree
    else if(val>root->data){
        root->right = delNode(root->right,val);
    }

    // Found Node to Delete
    else{

        // Case 1 --> 0 Children
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // Case 2 --> 1 Children
        if(root->left==NULL || root->right==NULL){
            return root->left==NULL ? root->right : root->left;
        }

        // Case 3 --> 2 Children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right,IS->data);
        
        return root;

    }

}

int main(){

    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
    Node* root = BuildTree(arr,9);

    int target = 8;
    delNode(root,target);

    Inorder(root);

    return 0;
}