
#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Student inherits from Person
class Student : public Person {
protected:
    int studentID;
    string course;

public:
    Student(string n, int a, int id, string c)
        : Person(n, a) {
        studentID = id;
        course = c;
    }

    void displayStudent() {
        displayPerson();
        cout << "Student ID: " << studentID << endl;
        cout << "Course: " << course << endl;
    }
};

// GraduateStudent inherits from Student
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string n, int a, int id,
                    string c, string topic)
        : Student(n, a, id, c) {
        researchTopic = topic;
    }

    void displayGraduateStudent() {
        displayStudent();
        cout << "Research Topic: "
             << researchTopic << endl;
    }
};

int main() {
    // Single inheritance
    cout << "----- STUDENT DETAILS -----" << endl;

    Student s1("Rahul", 20, 101, "Computer Science");
    s1.displayStudent();

    // Multilevel inheritance
    cout << "\n----- GRADUATE STUDENT DETAILS -----" << endl;

    GraduateStudent g1(
        "Priya", 24, 201,
        "Computer Science",
        "Artificial Intelligence"
    );

    g1.displayGraduateStudent();

    return 0;
}
