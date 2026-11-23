#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

template <typename T>
class GenericStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Cannot pop from an empty stack.");
        }
        data.pop_back();
    }

    T& top() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty; no top element.");
        }
        return data.back();
    }

    const T& top() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty; no top element.");
        }
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};

template <typename T>
void testStack(const std::string& label, T firstVal, T secondVal) {
    std::cout << "=== Testing " << label << " Stack ===\n";
    GenericStack<T> s;

    std::cout << "Initially empty? " << (s.isEmpty() ? "Yes" : "No") << "\n";

    // Test empty-container guard on pop()
    try {
        s.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught expected error on pop(): " << e.what() << "\n";
    }

    // Normal push and top
    s.push(firstVal);
    s.push(secondVal);
    std::cout << "Pushed two elements. Size: " << s.size() << ", Top: " << s.top() << "\n";

    // Pop one element
    s.pop();
    std::cout << "After one pop. Size: " << s.size() << ", Top: " << s.top() << "\n";

    // Pop remaining element and verify empty state
    s.pop();
    std::cout << "After second pop. Empty? " << (s.isEmpty() ? "Yes" : "No") << "\n\n";
}

int main() {
    testStack<int>("int", 10, 25);
    testStack<float>("float", 1.5f, 3.75f);
    testStack<std::string>("std::string", "Hello", "World");
    return 0;
}
