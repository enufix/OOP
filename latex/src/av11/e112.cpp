#include <iostream>
using namespace std;
class Base {
public:
    Base() {
        cout << "Constructing object from Base\n";
    }
    // the destructor
    virtual ~Base() {
        cout << "Destroying object from Base\n";
    }
};
class Derived : public Base {
public:
    Derived() {
        cout << "Constructing object from Derived\n";
    }            ~Derived() {
        cout << "Destroying object from Derived\n";
    }
};
int main() {
    Base *basePointer = new Derived();
    delete basePointer;
}