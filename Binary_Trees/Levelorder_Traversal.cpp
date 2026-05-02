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
        
        // storing Current Node
        Node* curr = q.front();
        q.pop();

        // current --> NULL (switch to next line)
        if (curr == NULL) {
            cout << endl;

            // stack != empty push NULL 
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else{

            // Print current Node value
            cout << curr->data << " ";

            // Push left child
            if(curr->left!=NULL){
                q.push(curr->left);
            }

            // Push right child
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }

    }

    cout << endl;

}

int main(){
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node* root = BuildTree(nodes);

    LevelOrder(root);

    return 0;
}