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

bool Search(Node* root, int val){

    // base case
    if(root==NULL){
        return false;
    }

    // ans found
    if(root->data==val){
        return true;
    }

    // ans exist in left subTree
    if(val<root->data){
        return Search(root->left,val);
    }
    // ans exist in right subTree
    else{
        return Search(root->right,val);
    }
}

int main(){

    int arr[6] = {5, 1, 3, 4, 2, 7};
    Node* root = BuildTree(arr,6);

    int target = 6;
    cout << Search(root,target) << endl;
    
    target = 5;
    cout << Search(root,target) << endl;

    return 0;
}