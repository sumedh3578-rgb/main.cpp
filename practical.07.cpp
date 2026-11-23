
#include <iostream>
using namespace std;

// Function overloading
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

// Complex Number class
class ComplexNumber {
private:
    float real;
    float imaginary;

public:
    ComplexNumber(float r, float i) {
        real = r;
        imaginary = i;
    }

    // Operator overloading (+)
    ComplexNumber operator+(ComplexNumber c) {
        ComplexNumber temp(
            real + c.real,
            imaginary + c.imaginary
        );

        return temp;
    }

    void display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    // Function overloading
    cout << "Function Overloading:" << endl;

    cout << "Addition of integers: "
         << add(10, 20) << endl;

    cout << "Addition of decimals: "
         << add(5.5, 4.5) << endl;

    // Operator overloading
    cout << "\nOperator Overloading:" << endl;

    ComplexNumber c1(3, 4);
    ComplexNumber c2(2, 5);

    cout << "First Complex Number: ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    ComplexNumber c3 = c1 + c2;

    cout << "Addition of Complex Numbers: ";
    c3.display();

    return 0;
}
