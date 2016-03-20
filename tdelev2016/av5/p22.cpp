#include <iostream>
using namespace std;

class Array {
private:
    int *elements;
    int n;
    int size;
    void copy(const Array &a) {
        size = a.size;
        n = a.n;
        elements = new int[size];
        for(int i = 0; i < n; ++i) {
            elements[i] = a.elements[i];
        }
    }
public:
    Array() {
        n = 0;
        size = 5;
        elements = new int[size];
    }

    Array(const Array &a) {
        cout << "copy constructor" << endl;
        copy(a);
    }

    Array& operator=(const Array &a) {
        cout << "operator = " << endl;
        delete [] elements;
        copy(a);
        return *this;
    }

    Array& operator+=(int x) {
        add(x);
        return *this;
    }

    void add(int x) {
        if(n == size) {
            cout << "new size: " << size * 2 << endl;
            int *p = elements;
            elements = new int[size * 2];
            size = size * 2;
            for(int i = 0; i < n; ++i) {
                elements[i] = p[i];
            }
            delete [] p;
        }

        elements[n] = x;
        ++n;
    }

    bool operator==(const Array &a) const {
        if(size != a.size || n != a.n) {
            return false;
        }
        for(int i = 0; i < n; ++i) {
            if(elements[i] != a.elements[i]) {
                return false;
            }
        }
        return true;
    }

    int getSize() const {
        return size;
    }

    int& operator[](int i) const {
        return elements[i];
    }

    void print() {
        cout << "Size: " << size << endl;
        for(int i = 0; i < n; ++i) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
    friend bool operator==(const int a, const Array &b);

    ~Array(){
        cout << "destructor" << endl;
        delete [] elements;
    }
};

bool operator!=(const Array& a, const Array &b) {
    return !(a == b);
}

bool operator==(const int a, const Array &b) {
    return a == b.size;
}

ostream& operator<<(ostream &x, const Array &a) {
    x << "Size: " << a.getSize() << endl;
    for(int i = 0; i < a.getSize(); ++i) {
        x << a[i] << " ";
    }
    return x;
}

int main() {
    Array a;
   // Array b;
    int n; 
    cin >> n;
    for(int i = 0; i < n; ++i) {
        //a.add(7);
        a += 7;
        cout << "i: " << a[i] << endl;
    }
    Array b = a; // Array b(a);
    a.print();
    //cout << a;
    b[5] = 10;
    b.print();
    if(n == a) {
        cout << "Object a has size: " << n << endl;
    }
    cout << a;
    if(a == b) {
        cout << "Arrays are equal" << endl;
    } else {
        cout << "Not equal" << endl;
    }
    return 0;
}
