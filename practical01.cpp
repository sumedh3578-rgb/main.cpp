
#include <iostream>
using namespace std;

int main()
{
    // Declaring variables
    int age;
    float marks;
    double salary;

    // Declaring constant
    const float PI = 3.14;

    // Taking input from user
    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your marks: ";
    cin >> marks;

    cout << "Enter your salary: ";
    cin >> salary;

    // Displaying values
    cout << "\n----- Student Details -----" << endl;
    cout << "Age: " << age << endl;
    cout << "Marks: " << marks << endl;
    cout << "Salary: " << salary << endl;

    // Arithmetic operators
    cout << "\n----- Arithmetic Operators -----" << endl;
    cout << "Addition: " << age + marks << endl;
    cout << "Subtraction: " << age - marks << endl;
    cout << "Multiplication: " << age * marks << endl;

    // Relational operator
    cout << "\n----- Relational Operator -----" << endl;
    cout << "Age greater than 18: " << (age > 18) << endl;

    // Logical operator
    cout << "\n----- Logical Operator -----" << endl;
    cout << "Age above 18 and marks above 40: "
         << (age > 18 && marks > 40) << endl;

    // Constant demonstration
    cout << "\nValue of PI: " << PI << endl;

    return 0;
}
