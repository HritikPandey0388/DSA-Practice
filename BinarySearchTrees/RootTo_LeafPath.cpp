#include<iostream>
#include<vector>
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

void PrintPath(vector<int>& path){

    int n = path.size();

    for(int i=0;i<n;i++){
        cout << path[i] << " ";
    }
    cout << endl;
}

void RootToLeaf(Node* root, vector<int>& path){

    // base case
    if(root==NULL){
        return;
    }

    // pushing current Node data
    path.push_back(root->data);

    // Leaf found 
    if(root->left==NULL && root->right==NULL){

        // Print Path
        PrintPath(path);

        // pop Leaf data from path
        path.pop_back();
        
        return; 
    }

    // calling for left and right leaf path
    RootToLeaf(root->left,path);
    RootToLeaf(root->right,path);

    // backtracking step
    path.pop_back();

}

int main(){

    int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = BuildTree(arr,9);

    vector<int> path;
    RootToLeaf(root,path);
    return 0;
}