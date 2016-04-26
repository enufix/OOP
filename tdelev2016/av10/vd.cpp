#include <iostream>
#include <cstdlib>
using namespace std;

class Base {
protected:
    int x;
public:
    Base(int _x) : x(_x) {};

    virtual int sum() = 0;

    virtual ~Base() {
        cout << "destructor Base" << endl;
    }
};
class D : public Base {
private:
    float *f;
    int n;
public:
    D(int x, float y[], int _n) : Base(x) {
        n = _n;
        f = new float[n];
        for (int i = 0; i < n; ++i) {
            f[i] = y[i];
        }
    }
    int sum() {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += f[i];
        }
        return s;
    }

    ~D() {
        cout << "destructor D" << endl;
        delete [] f;
    }
};
class A {
    int x[5];
public:
    A() {
        for (int i = 0; i < 5; ++i) {
            x[i] = 15;
        }
    }
    void print() {
        for (int i = 0; i < 5; ++i) {
            cout << x[i] << endl;
        }   
    }
    void change() {
        x[0] = 50;
    }
};

int main() {
    /*float x[] = {1.2, 15, 13};
    Base *b = new D(15, x, 3);
    cout << "SUM: " << b->sum() << endl;
    delete b;*/
    A a;
    A b;
    b = a;
    a.change();
    a.print();
    b.print();
    return 0;
}