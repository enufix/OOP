#include <iostream>
using namespace std;

class Cuboid {
private:
    float a, b, c;
    void init(float a, float b, float c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
public:
    Cuboid() {
        cout << "this is the constructor" << endl;
        a = 10;
        b = 20;
        c = 30;
    }
    Cuboid(float x) {
        a = x;
        b = x;
        c = x;
    }
    Cuboid(float a, float b, float c) {
        this->init(a, b, c);
    }

    float getA() {
        return a;
    }
    void setC(float x) {
        c = x;
    }
    float volume() {
        return a * b * c;
    } 
    bool isLarger(Cuboid &c) {
        return this->volume() > c.volume();
    }
};

int main() {
    Cuboid c;
    cout << c.getA() << endl;
    cout << "The volume is: " << c.volume() << endl;
    Cuboid x(8);
    Cuboid y(5, 6, 8);
    cout << "The volume is: " << x.volume() << endl;
    if(c.isLarger(x)) {
        cout << "C is larger" << endl;
    } else {
        cout << "X is larger" << endl;
    }
    return 0;
}

