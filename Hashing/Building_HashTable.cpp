#include<iostream>
#include<vector>
#include<string>
using namespace std;

// Node of linked list
class Node{
public:

    string key;      // key
    int val;         // value associated with key
    Node* next;      // next node pointer
    
    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    // recursively delete remaining chain
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

class HashTable{

    // converts string key into table index
    int HashFunction(string key){
        int idx = 0;

        for(int i=0;i<key.size();i++){
            idx += ((key[i] * key[i]) % totalSize);
        }

        return idx % totalSize;
    }

    // doubles table size and re-inserts all elements
    void rehash(){

        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize = 2 * totalSize;

        // create new larger table
        table = new Node*[totalSize];

        for(int i=0;i<totalSize;i++){
            table[i] = NULL;
        }

        currSize = 0;

        // insert all old nodes into new table
        for(int i=0;i<oldSize;i++){

            Node* temp = oldTable[i];

            while(temp != NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            // delete old linked list
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        delete [] oldTable;
    }

public:

    int totalSize;   // total buckets
    int currSize;    // current elements
    Node** table;    // array of linked list heads

    HashTable(int size = 10){

        totalSize = size;
        currSize = 0;

        table = new Node*[totalSize];

        for(int i=0;i<totalSize;i++){
            table[i] = NULL;
        }
    }

    // insert key-value pair
    void insert(string key, int val){

        int idx = HashFunction(key);

        Node* newNode = new Node(key,val);

        // insert at head (separate chaining)
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        // load factor
        double lambda = currSize / (double)totalSize;

        // rehash when table becomes crowded
        if(lambda > 1){
            rehash();
        }
    }

    // check whether key exists
    bool exists(string key){

        int idx = HashFunction(key);

        Node* temp = table[idx];

        while(temp != NULL){

            if(temp->key == key){
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    // return value corresponding to key
    int search(string key){

        int idx = HashFunction(key);

        Node* temp = table[idx];

        while(temp != NULL){

            if(temp->key == key){
                return temp->val;
            }

            temp = temp->next;
        }

        return -1; // key not found
    }

    // remove a key from hash table
    void remove(string key){
        int idx = HashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;

        while(temp != NULL){

            if(temp->key == key){

                // deleting first node
                if(prev == temp){
                    table[idx] = temp->next;
                }
                else{
                    prev->next = temp->next;
                }

                break;
            }

            prev = temp;
            temp = temp->next;
        }

        // prevent recursive deletion of remaining chain
        temp->next = NULL;
        delete temp;
    }

    // print complete hash table
    void PrintTable(){
        for(int i=0;i<totalSize;i++){

            cout << "idx" << i << "-->";

            Node* temp = table[i];

            while(temp != NULL){
                cout << "(" << temp->key << "," << temp->val << ") -->";
                temp = temp->next; 
            }

            cout << "NULL" << endl;
        }
    }

};

int main(){

    HashTable ht;

    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",20);
    ht.insert("Nepal",10);
    ht.insert("UK",20);

    ht.PrintTable();

    ht.remove("China");

    ht.PrintTable();

    return 0;
}