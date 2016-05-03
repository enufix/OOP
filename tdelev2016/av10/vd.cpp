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

int main() {
    float x[] = {1.2, 15, 13};
    Base *b = new D(15, x, 3);
    cout << "SUM: " << b->sum() << endl;
    delete b;
    return 0;
}
