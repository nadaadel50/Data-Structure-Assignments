#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;

class Student{
private:
    string name;
    string id;
    double gpa;
public:
    Student(string name, string id, double gpa);
    string getName() const;
    string getId()const;
    double getGpa()const;
    void setName(string name);
    void setId(string id);
    void setGpa(double gpa);
    void display();
    bool operator < (const Student& other) const;
    friend bool operator<(const Student& a, const Student& b);
};

Student::Student(string name, string id, double gpa){
    this->name = name;
    this->id = id;
    this->gpa = gpa;
}
string Student:: getName() const{
    return name;
}
string Student:: getId() const{
    return id;
}
double Student:: getGpa() const{
    return gpa;
}
void Student:: setName(string name){
    this->name = name;
}
void Student:: setId(string id){
    this->id = id;
}
void Student:: setGpa(double gpa){
    this->gpa = gpa;
}

bool Student:: operator < (const Student& other) const {
    return name < other.name;
}

void Student:: display(){
    cout << "Name: " << name << endl;
    cout << "Id: " << id << endl;
    cout << "Gpa: " << gpa << endl;
}


bool operator < (const Student& a, const Student& b) {
    return a.getGpa() < b.getGpa();
}
struct CompareByName {
    bool operator()(const Student& a, const Student& b)  {
        return (a.getName() < b.getName());
    }
};

struct CompareByGPA {
    bool operator()(const Student& a, const Student& b) {
        return (a.getGpa() > b.getGpa());
    }
};



#endif // STUDENT_H_INCLUDED
