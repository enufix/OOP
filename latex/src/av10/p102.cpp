#include <iostream>
using namespace std;
template<typename T>
T abs(T value) {
    T result;
    result = (value >= 0) ? value : -value;
    return result;
}
int main() {
    int i = -5;
    cout << abs(i) << endl;
    double d = -55.5;
    cout << abs(d) << endl;
    float f = -555.5f;
    cout << abs(f) << endl;
    char x = 100;
    cout << abs(x) << endl;
    return 0;
}