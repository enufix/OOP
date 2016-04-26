#include <iostream>
using namespace std;

template <typename T>
class Complex {
private:
    T real, imag;
public:
    Complex(T r, T i) {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex &c) {
        Complex res(this->real + c.real, this->imag + c.imag);
        return res;
    }

    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real;
        if(c.imag >= 0) {
            out << "+";
        }
        out << c.imag << "j";
        return out;
    }
};

int main() {
    Complex<float> c1(5, 15);
    cout << c1 << endl;
    Complex<float> c2(12.1, -13.5);
    cout << c2 << endl;
    Complex<float> c3 = c1 + c2;
    cout << c3 << endl;
    return 0;
}