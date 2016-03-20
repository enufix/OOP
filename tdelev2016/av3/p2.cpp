#include <iostream>
#include <cstring>
using namespace std;

enum Position {
    employee,
    manager,
    owner
};

class Employee {
private:
    char name[100];
    int sallary;
    Position position;
public:
    Employee() {
        //cout << "default constructor" << endl;
    }
    Employee(const char* name, int sallary, Position position) {
        init(name, sallary, position);
    }

    void print() {
        cout << "Name: " << name << endl;
        cout << "Sallary: " << sallary << endl;
        cout << "Position: " << position << endl;
    }

    void init(const char* name, int sallary, Position position) {
        strcpy(this->name, name);
        this->sallary = sallary;
        this->position = position;
    }

    int compareTo(Employee &e) {
        if(this->sallary > e.sallary) return 1;
        else if(this->sallary < e.sallary) return -1;
        else return 0;
    }

};

void sort(Employee *e, int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - 1 - i; ++j) {
            if(e[j].compareTo(e[j + 1]) < 0) {
                Employee tmp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = tmp;
            }
        }
    }
}



int main() {
    Employee e[10];
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        char name[100];
        int sallary;
        Position position;
        int p;
        cin >> name;
        cin >> sallary;
        cin >> p;
        e[i].init(name, sallary, (Position)p);
    }
    sort(e, n);
    for(int i = 0; i < n; ++i) {
        cout << i + 1 << endl;
        e[i].print();
    }
    return 0;
}