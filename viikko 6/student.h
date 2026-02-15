#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;


class Student
{
public:
    Student(string s, int);
    void setAge(int);
    void setName(string);
    string getName();
    int getAge();
    void printStudentinfo();


private:
    string Name;
    int Age;

};

#endif // STUDENT_H
