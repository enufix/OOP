#include <iostream>
using namespace std;

class Complex {
private:
    float a, b;
public:
    Complex(const float a = 0, const float b = 0) {
        this->a = a;
        this->b = b;
    }
    friend ostream &operator<<(ostream &x, const Complex &c) {
        x << c.a;
        if (c.b >= 0) {
            x << " +";
        }
        x << c.b << "j";
        return x;
    }
    Complex operator+(const Complex &c) {
        Complex res(a + c.a, b + c.b);
        return res;
    }

    Complex operator-(const Complex &c) {
        return Complex(a - c.a, b - c.b);
    }

    Complex operator*(const Complex &c) {
        return Complex(a * c.a - b * c.b, b * c.a - a * c.b);
    }

    Complex operator/(const Complex &c) {
        float m = c.a * c.a + c.b * c.b;
        float r = (a * c.a - b * c.b) / m;
        return Complex(r, (b * c.a + b * c.b) / m);
    }

    Complex &operator+=(const Complex &c) {
        a += c.a;
        b += c.b;
        return *this;
    }

    Complex &operator-=(const Complex &c) {
        a -= c.a;
        b -= c.b;
        return *this;
    }
    Complex &operator*=(const Complex &c) {
        a = a * c.a - b * c.b;
        b = b * c.a - a * c.b;
        return *this;
    }
    Complex &operator/=(const Complex &c) {
        *this = *this / c;
        return *this;
    }
    bool operator==(const Complex &c) {
        return a == c.a && b == c.b;
    }

    float getA() const {
        return a;
    }
    float getB() const {
        return b;
    }
};

int main() {
    Complex c1(2, -6);
    Complex c2(3, 5);
    Complex c = c1 + c2;
    cout << c1 << " + " << c2 << " = " << c << endl;
    c = c1 - c2;
    cout << c1 << " - " << c2 << " = " << c << endl;
    c = c1 * c2;
    cout << c1 << " * " << c2 << " = " << c << endl;
    c = c1 / c2;
    cout << c1 << " / " << c2 << " = " << c << endl;
    if (c == c1) {
        cout << "Numbers are equal" << endl;
    }
    return 0;
}
