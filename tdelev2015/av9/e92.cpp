#include <iostream>
using namespace std;

void d() {
    int a = 5;
    int b = 0;
    if (b == 0) throw 1;
    cout << a / b << endl;
    cout << "d()" << endl;
}
void c() {
    d();
    cout << "c()" << endl;
}
void b() {
    c();
    cout << "b()" << endl;
}
void a() {
    b();
    cout << "a()" << endl;
}

int main() {
    try {
        a();
    }
    catch (int x) {
        cout << "Exception: " << x << endl;
        if(x == 1) {
            cout << "Division by zero" << endl;
        }
    }
    return 0;
}

