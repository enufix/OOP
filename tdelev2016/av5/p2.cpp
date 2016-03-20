#include <iostream>
using namespace std;

class Array {
private:
    int *elements;
    int size;
    int n;
    void copy(const Array &a) {
        size = a.size;
        n = a.n;
        elements = new int[a.size];
        for(int i = 0; i < n; ++i) {
            elements[i] = a.elements[i];
        }

    }
public:
    Array(){
        n = 0;
        size = 5;
        elements = new int[size];
    }
    // copy constructor
    Array(const Array &a) {
        copy(a);
    }
    // = operator
    Array& operator=(const Array& a) {
        if(this == &a) return *this;
        delete [] elements;
        copy(a);
        return *this;
    }

    void add(int a) {
        if(n == size) {
            int *p = elements;
            elements = new int[size * 2];
            for(int i = 0; i < size; ++i) {
                elements[i] = p[i];
            }
            delete [] p;
            size = size * 2;
            cout << "expanding size: " << size << endl;
        }
        elements[n] = a;
        ++n;
    }

    void print() {
        for(int i = 0; i < n; ++i) {
            cout << elements[i];
            cout << " ";
        }
        cout << endl;
    }
    /*Array& operator+=(int x) {
        add(x);
        return *this;
    }*/

    friend Array& operator+=(Array& a, int x);

    Array& operator/(int b) {
        cout << "jas sum opertaor /" << endl;
        return *this;
    }
    int getSize() {
        return size;
    }
    int& operator[](const int index) {
        return elements[index];
    }

    friend bool operator==(Array &a, Array &b);

    ~Array() {
        cout << "destructor" << endl;
        delete [] elements;
    }

};

bool operator==(Array &a, Array &b) {
    return a.size == b.size;
}

Array& operator+=(Array& a, int x) {
    a.add(x);
    return a;
}

int main() {
    Array a;
    int size;
    cin >> size;
    for(int i = 0; i < size; ++i) {
        //a.add(i * 2);
        a += i * 2;
    }
    Array b = a; // Array b(a);
    for(int i = 0; i < b.getSize(); ++i) {
        b[i] = 56;
        cout << b[i] << endl;
    }
    a.print();
    b.print();
    if(a == b) {
        cout << "Ednakvi" << endl;
    }
    return 0;
}





