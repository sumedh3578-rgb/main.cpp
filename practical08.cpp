
#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Base class
class Shape {
public:
    virtual void draw() = 0;

    virtual ~Shape() {}
};

// Circle class
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

// Rectangle class
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle" << endl;
    }
};

// Factory class
class ShapeFactory {
public:
    static unique_ptr<Shape> createShape(string type) {
        if (type == "Circle") {
            return unique_ptr<Shape>(new Circle());
        }
        else if (type == "Rectangle") {
            return unique_ptr<Shape>(new Rectangle());
        }
        else {
            return nullptr;
        }
    }
};

int main() {
    // Create Circle object using Factory
    unique_ptr<Shape> shape1 =
        ShapeFactory::createShape("Circle");

    if (shape1) {
        shape1->draw();
    }

    // Create Rectangle object using Factory
    unique_ptr<Shape> shape2 =
        ShapeFactory::createShape("Rectangle");

    if (shape2) {
        shape2->draw();
    }

    return 0;
}
