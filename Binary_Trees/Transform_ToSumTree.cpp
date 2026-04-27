#include<iostream>
#include<vector>
#include<queue>
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

void LevelOrder(Node* root){

    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    cout << "Level order Traversal is :- " << endl;

    while(!q.empty()){
        
        Node* curr = q.front();
        q.pop();

        if(curr == NULL){
            cout << endl;

            // Only push NULL if more nodes exist
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << curr->data << " ";

            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }

    cout << endl;

}

int SumTree(Node* root){

    if(root==NULL){
        return 0;
    }

    int leftOld = SumTree(root->left);
    int rightOld = SumTree(root->right);

    int currOld = root->data;

    root->data = leftOld + rightOld;

    if(root->left!=NULL){
        root->data += root->left->data;
    }

    if(root->right!=NULL){
        root->data += root->right->data;
    }

    return currOld;

}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    SumTree(root);

    LevelOrder(root);

    return 0;
}