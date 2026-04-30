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
    }
    else {
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

bool Validate(Node* root, Node* min, Node* max){

    // base case
    if(root==NULL){
        return true;
    }

    // Invalid BST
    if(min!=NULL && root->data<min->data){
        return false;
    }

    // Inavlid BST
    if(max!=NULL && root->data>max->data){
        return false;
    }

    // if false doesn't hit we call for left and right subTree
    return Validate(root->left,min,root) && Validate(root->right,root,max);


}

int main(){

    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = BuildTree(arr,6);
    cout << Validate(root,NULL,NULL) << endl;

    return 0;
}