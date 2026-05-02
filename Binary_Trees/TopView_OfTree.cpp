#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void TopView(Node* root){

    // Queue stores pair of (node, horizontal distance)
    queue<pair<Node*,int>> q;

    // Map -> (Horizontal distance, Node val)
    map<int,int> m;

    // Pushing root with horizontal distance 0 
    q.push(make_pair(root,0));

    // Level Order Traversal (BFS)
    while(!q.empty()){

        // store current Pair and pop it
        pair<Node*,int> curr = q.front();
        q.pop();

        // store current Pair Node and Horizontal distance
        Node* currNode = curr.first;              // Current Node
        int currHD = curr.second;                 // Current Node Horizontal Distance(HD) 

        // Only push in map if it is first Occurance
        if(m.count(currHD)==0){
            m[currHD] = currNode->data;
        }

        // Pushing Pair for Left Child
        if(currNode->left!=NULL){
            pair<Node*,int> left = make_pair(currNode->left,currHD-1); 
            q.push(left);
        }

        // Pushing Pair for Right Child
        if(currNode->right!=NULL){
            pair<Node*,int> right = make_pair(currNode->right,currHD+1); 
            q.push(right);
        }

    }

    // Print Top View (Stored in map)
    for(auto it:m){
        cout << it.second << " " ;
    }

    cout << endl;
    
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    TopView(root);

    return 0;
}