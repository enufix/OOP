#include <iostream>
using namespace std;

template <typename T>
T abs(T x) {
    if(x < 0) {
        return -x;
    }
    return x;
}

int main() {
    int a = -15;
    float b = 25;
    double c = -2;
    cout << abs(a) << endl;
    cout << abs(b) << endl;
    cout << abs(c) << endl;
    cout << abs("abc") << endl;
    return 0;
}