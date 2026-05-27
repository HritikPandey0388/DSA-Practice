#include<iostream>
#include<vector>
using namespace std;

class Heap{

    // Vector used to store heap elements
    vector<int> vec;

public:
    
    // Insert a new value into the heap
    void push(int val){

        // Add element at the end
        vec.push_back(val);

        // Child index = last inserted element
        int childIdx = vec.size()-1;

        // Parent index formula
        int parentIdx = (childIdx-1)/2;
        
        // Up-heapify (Bubble Up)
        // Move element upward until heap property is satisfied
        while(parentIdx>=0 && vec[childIdx]>vec[parentIdx]){

            // Swap child with parent
            swap(vec[childIdx], vec[parentIdx]);

            // Update indices after swap
            childIdx = parentIdx;
            parentIdx = (childIdx-1)/2;
        }
    }

    // Heapify function to maintain max-heap property
    void heapify(int idx){
 
        // Base case
        if(idx>=vec.size()){
            return;
        }

        // Left child index
        int leftIdx = 2*idx + 1;

        // Right child index
        int rightIdx = 2*idx + 2;

        // current index has maximum value
        int maxIdx = idx;

        // Check left child
        if(leftIdx<vec.size() && vec[leftIdx]>vec[maxIdx]){
            maxIdx = leftIdx;
        }

        // Check right child
        if(rightIdx<vec.size() && vec[rightIdx]>vec[maxIdx]){
            maxIdx = rightIdx;
        }

        // child > parent
        if(maxIdx!=idx){

            // Swap parent with larger child
            swap(vec[maxIdx],vec[idx]);

            // Recursively heapify affected subtree
            heapify(maxIdx);
        }

    }

    // Remove top element from heap
    void pop(){

        // Move last element to root
        swap(vec[0],vec[vec.size()-1]);

        // Remove last element
        vec.pop_back();

        // Restore heap property
        heapify(0);

    }

    // top (maximum) element
    int top(){
        return vec[0];
    }

    // heap --> empty or not
    bool empty(){
        return vec.size()==0;
    }
};

int main(){

    Heap heap;
    
    // Insert elements 1 to 9
    for(int i=1;i<10;i++){
        heap.push(i);
    }

    // Build Heap
    while(!heap.empty()){

        cout << "Top of Heap :- " << heap.top() << endl;

        heap.pop();
    }

    return 0;
}