
#include <iostream>
using namespace std;

// Abstract base class
class Shape {
public:
    virtual double area() = 0;

    virtual ~Shape() {}
};

// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double area() override {
        return 3.14 * radius * radius;
    }
};

// Rectangle class
class Rectangle : public Shape {
private:
    double length, breadth;

public:
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }

    double area() override {
        return length * breadth;
    }
};

// Triangle class
class Triangle : public Shape {
private:
    double base, height;

public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }

    double area() override {
        return 0.5 * base * height;
    }
};

int main() {
    Circle c(5);
    Rectangle r(10, 4);
    Triangle t(6, 8);

    Shape* s;

    s = &c;
    cout << "Area of Circle: " << s->area() << endl;

    s = &r;
    cout << "Area of Rectangle: " << s->area() << endl;

    s = &t;
    cout << "Area of Triangle: " << s->area() << endl;

    return 0;
}
