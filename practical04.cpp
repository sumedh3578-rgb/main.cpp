
#include <iostream>
#include <memory>
using namespace std;

class Resource {
public:
    Resource() {
        cout << "Resource acquired." << endl;
    }

    ~Resource() {
        cout << "Resource released." << endl;
    }

    void display() {
        cout << "Resource is being used." << endl;
    }
};

int main() {
    cout << "--- UNIQUE POINTER ---" << endl;

    {
        // unique_ptr has only one owner
        unique_ptr<Resource> ptr1(new Resource());

        ptr1->display();

        // unique_ptr can also manage arrays
        unique_ptr<int[]> numbers(new int[3]{10, 20, 30});

        cout << "Array elements: ";
        for (int i = 0; i < 3; i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;

    } // Resources are automatically released here

    cout << "\n--- SHARED POINTER ---" << endl;

    {
        // shared_ptr allows multiple owners
        shared_ptr<Resource> ptr2 = make_shared<Resource>();

        {
            // Both pointers share ownership
            shared_ptr<Resource> ptr3 = ptr2;

            cout << "Number of owners: "
                 << ptr2.use_count() << endl;

            ptr3->display();
        }

        cout << "Number of owners after ptr3 is destroyed: "
             << ptr2.use_count() << endl;

    } // Resource is released when the last owner is destroyed

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
