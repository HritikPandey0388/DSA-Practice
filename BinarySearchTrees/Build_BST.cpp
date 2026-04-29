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

int main(){

    int arr[6] = {5, 1, 3, 4, 2, 7};

    Node* root = BuildTree(arr,6);
    Inorder(root);
    return 0;
}