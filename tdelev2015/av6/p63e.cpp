#include <iostream>
using namespace std;

class Complex {
private:
    float r, i;
public:
    Complex(float rr = 0, float ii = 0) {
        r = rr;
        i = ii;
    }
    friend ostream& operator<<(ostream& o, const Complex &c) {
        o << c.r;
        if(c.i >= 0) {
            o << " +";
        }
        o << c.i << "j";
        return o;
    }

    Complex& operator++() {
        ++r;
        ++i;
        return *this;
    }

    Complex operator++(int a){
        Complex orig(*this);
        ++(*this);
        return orig;
    }

    Complex operator+(const Complex &c) {
        Complex res(r + c.r, i + c.i);
        return res;
    }

    Complex& operator+=(const Complex &c) {
        r += c.r;
        i += c.i;
        return (*this);
    }

};

int main() {
    Complex c1(2, 5);
    Complex c2(1, 3);
    cout << "C1: " << c1++ << endl;
    cout << "C1: " << c1 << endl;
    cout << "C1 + C2: " << (c1 + c2) << endl;
    c1 += c2;
    cout << "+= " << c1 << endl;
    return 0;
}
