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

    if(root==NULL){
        return NULL;
    }

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* leftLCA = LCA(root->left,n1,n2);
    Node* rightLCA = LCA(root->right,n1,n2);

    if(leftLCA!=NULL && rightLCA!=NULL){
        return root;
    }

    return leftLCA==NULL ? rightLCA : leftLCA;

}

int dist(Node* root, int n){

    // base case
    if(root==NULL){
        return -1;
    }

    if(root->data==n){
        return 0;
    }

    // find distance in left subTree
    int leftDist = dist(root->left,n);

    // n found in left subTree 
    if(leftDist!=-1){
        return leftDist + 1;   // return left Distance
    }

    // find Distance in right subTree
    int rightDist = dist(root->right,n);

    // n found in right subTree
    if(rightDist!=-1){
        return rightDist + 1;     // return right Distance
    }

    // n not found
    return -1;
}

int minDist(Node* root, int n1, int n2){

    // Find LCA for n1,n2
    Node* lca = LCA(root,n1,n2);

    int dist1 = dist(lca,n1);          // distance from LCA to n1
    int dist2 = dist(lca,n2);          // distance from LCA to n2  

    return dist1 + dist2;              // ans  
} 

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    int ans = minDist(root,4,3);
    cout << ans << endl;

    return 0;
}