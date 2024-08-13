#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "student.h"
using namespace std;


vector<string> Names;
vector<string> Ids;
vector<double> Gpas;

vector<Student> readStudentsFromFile(const string& filename){
    ifstream file(filename);
    vector<Student> students;
    string line;
    int numStudents;

    if (file.is_open()) {
        getline(file, line);
        numStudents = stoi(line);

        while (getline(file, line)) {
            string name = line;
            Names.push_back(name);
            getline(file, line);
            string id = line;
            Ids.push_back(id);
            getline(file, line);
            double gpa = stod(line);
            Gpas.push_back(gpa);
            students.push_back(Student(name, id, gpa));
        }
    }
    return students;
}
template <typename T>
void writeResult(const string& filename, const vector<Student>& sortedStudents, const string& sortName, const string numOfComparisons ,const T& Time){
    ofstream file;
    file.open(filename, std::ios_base::app);
    file << "Algorithm:" << sortName << endl;
    file << "Number of comparisons: " << numOfComparisons << endl;
    file << "Running Time:" << Time.count()/100.0 << " milliseconds"<< endl;
    file << endl;
    for (const auto& elem : sortedStudents) {
        file << elem.getName() << endl;
        file << elem.getId() << endl;
        file << elem.getGpa() << endl;
    }
    file << endl;
}
#endif // FUNCTIONS_H_INCLUDED
