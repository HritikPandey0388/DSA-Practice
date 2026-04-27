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

pair<int,int> Diameter(Node* root){

    if(root==NULL){
        return make_pair(0,0);
    }

    // (Diameter,Height) 
    pair<int,int> leftInfo = Diameter(root->left);      // (LD,LH) 
    pair<int,int> rightInfo = Diameter(root->right);    // (RD,RH)

    int currDiam = leftInfo.second + rightInfo.second + 1;               // LH + RH + 1     
    int finalDiam = max(currDiam,max(leftInfo.first,rightInfo.first));   // max (current Node diameter, max(Left Node Diameter,Right Node Diameter)) 
    int finalHeight = max(leftInfo.second,rightInfo.second) + 1;         //  

    return make_pair(finalDiam,finalHeight);
}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    pair<int,int> ans = Diameter(root);

    cout << "Diameter of given Binary tree is :- " << ans.first << endl;
    return 0;
}
