#include <iostream>
using namespace std;

class FatGuy {
private:
    int a[10];
public:
    FatGuy(){
        //cout << "constructing FatGuy" << endl;
        for(int i = 0; i < 10; ++i) {
            a[i] = 5;
        }
    }
    int sum() {
        int s = 0;
        for(int i = 0; i < 10; ++i) {
            s += a[i];
        }
        return s;   
    }

};

int main() {
    int n;
    cin >> n;
    FatGuy *f = new FatGuy[n];
    int sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += f->sum();
    }
    cout << "SUM: " << sum << endl;
    cin >> n;
    delete [] f;
    return 0;
}