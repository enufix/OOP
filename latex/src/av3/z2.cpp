#include <iostream>
#include <string.h>
using namespace std;

enum position {
    employee, manager, owner
};

class Person {
private:
    char name[100];
    int sallary;
    position pos;
public:
    // Constructors
    Person() {
    }

    Person(char *name, int sallary, position pos) {
        strcpy(this->name, name);
        this->sallary = sallary;
        this->pos = pos;
    }
    // Destruktor
    ~Person() {
    }

    void setName(char const *name) {
        strcpy(this->name, name);
    }
    void setSallary(int const sallary) {
        this->sallary = sallary;
    }
    void setPosition(position p) {
        pos = p;
    }
    char const *getName() {
        return name;
    }
    int const getSallary() {
        return sallary;
    }
    position const getPosition() {
        return pos;
    }
};

void sort(Person a[], int n) {
    int i, j;
    Person p;
    for (i = 0; i < n - 1; i++)
        for (j = i; j < n; j++)
            if (a[i].getSallary() < a[j].getSallary()) {
                p = a[j];
                a[j] = a[i];
                a[i] = p;
            }
}

int main() {
    Person employees[100];
    float sallary;
    int n, pos;
    char name[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> sallary;
        cin >> pos;
        employees[i].setName(name);
        employees[i].setSallary(sallary);
        employees[i].setPosition((position) pos);
    }
    sort(employees, n);
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << employees[i].getName() << "\t"
             << employees[i].getSallary() << "\t"
             << employees[i].getPosition() << endl;
    }
    return 0;
}

