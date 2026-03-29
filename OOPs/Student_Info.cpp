#include<iostream>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(int age, string name){
        this->name = name;
        this->age = age;
    }

};

class Student : public Person{
public:
    string StudentId;

    Student(int age, string name, string StudentId) : Person(age,name){
        this->StudentId = StudentId;
    }

    void getInfo(){
        cout << "Student's Informartion :- " << endl;
        cout << "Name : " << this->name << endl;
        cout << "Age : " << this->age << endl;
        cout << "StudentId : " << this->StudentId << endl;
    }

};

int main(){
    Student s1(20,"Hritik Pandey","0246CS241140");
    s1.getInfo();
    return 0;
}