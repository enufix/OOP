#include <iostream>
#include <cmath>
using namespace std;
template <typename T>
void mySwap(T &a, T &b) {
     cout << "Template" << endl;
    T temp;
    temp = a;
    a = b;
    b = temp;
}
template <typename T>
bool equal(T a, T b) {
     return a == b;
}
template <>
bool equal(double a, double b) {
     return fabs(a - b) < 0.001;
}

/*template <>
void mySwap<int>(int &a, int &b) {
    cout << "Specialization" << endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void mySwap(int &a, int &b) {
    cout << "Basic function" << endl;
    int temp;
    temp = a;
    a = b;
    b = temp;
}*/

int main() {
    double d1 = 1,
           d2 = 2;
    mySwap(d1, d2); // template
    int i1 = 1,
        i2 = 2;
    mySwap(i1, i2); // spacialization
    cout << equal(1, 5) << endl;
     cout << equal(3.333, 10.0 / 3) << endl;



    return 0;
}
