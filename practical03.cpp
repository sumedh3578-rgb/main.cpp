
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

class DynamicArray
{
private:
    int *arr;
    int size;

public:

    // 1. Default Constructor
    DynamicArray()
    {
        size = 0;
        arr = nullptr;
        cout << "Default Constructor Called" << endl;
    }

    // 2. Parameterized Constructor
    DynamicArray(int s)
    {
        size = s;
        arr = new int[size]();

        cout << "Parameterized Constructor Called" << endl;
    }

    // 3. Copy Constructor (Deep Copy)
    DynamicArray(const DynamicArray &obj)
    {
        size = obj.size;
        arr = (size > 0) ? new int[size] : nullptr;

        for (int i = 0; i < size; i++)
        {
            arr[i] = obj.arr[i];
        }

        cout << "Copy Constructor Called" << endl;
    }

    // 4. Copy Assignment Operator
    DynamicArray& operator=(const DynamicArray &obj)
    {
        if (this != &obj)
        {
            int *temp = (obj.size > 0)
                        ? new int[obj.size]
                        : nullptr;

            for (int i = 0; i < obj.size; i++)
            {
                temp[i] = obj.arr[i];
            }

            delete[] arr;

            arr = temp;
            size = obj.size;
        }

        cout << "Copy Assignment Called" << endl;
        return *this;
    }

    // 5. Move Constructor
    DynamicArray(DynamicArray &&obj) noexcept
    {
        size = obj.size;
        arr = obj.arr;

        obj.arr = nullptr;
        obj.size = 0;

        cout << "Move Constructor Called" << endl;
    }

    // 6. Move Assignment Operator
    DynamicArray& operator=(DynamicArray &&obj) noexcept
    {
        if (this != &obj)
        {
            delete[] arr;

            arr = obj.arr;
            size = obj.size;

            obj.arr = nullptr;
            obj.size = 0;
        }

        cout << "Move Assignment Called" << endl;
        return *this;
    }

    // 7. Destructor
    ~DynamicArray()
    {
        delete[] arr;
        cout << "Destructor Called" << endl;
    }

    // Function to insert elements
    void insert()
    {
        cout << "Enter " << size << " elements: ";

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    // Function to display elements
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    // Default constructor
    DynamicArray a;

    // Parameterized constructor
    DynamicArray b(3);

    cout << "\nEnter array elements:" << endl;
    b.insert();

    cout << "\nOriginal Array: ";
    b.display();

    // Copy constructor
    DynamicArray c = b;

    cout << "Copied Array: ";
    c.display();

    // Copy assignment
    DynamicArray d;
    d = b;

    cout << "Copy Assignment Array: ";
    d.display();

    // Move constructor
    DynamicArray e = move(b);

    cout << "Moved Array: ";
    e.display();

    // Move assignment
    DynamicArray f;
    f = move(e);

    cout << "Move Assignment Array: ";
    f.display();

    return 0;
}
