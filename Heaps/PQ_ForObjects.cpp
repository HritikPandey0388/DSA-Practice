#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

// Class --> student
class Student{
public:
    
    string name; // name
    int rank;    // rank

    // Constructor
    Student(string name, int rank){
        this->name = name;
        this->rank = rank;
    }

    // min-heap based on rank
    bool operator < (const Student &obj) const {
        return this->rank > obj.rank;
    }
};

int main(){

    // Priority queue --> Student objects with smallest rank
    priority_queue<Student> pq;

    // Insert students into the heap
    pq.push(Student("Hritik", 100));
    pq.push(Student("Anurag", 245));
    pq.push(Student("Prachi", 167));
    pq.push(Student("Chirag", 670));

    // Print students (smallest rank)
    while(!pq.empty()){

        cout << "Top :- "
             << pq.top().name
             << " , "
             << pq.top().rank
             << endl;

        // Remove --> top student
        pq.pop();
    }

    return 0;
}