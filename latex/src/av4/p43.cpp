dd#include <iostream>
#include <cstring>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date (const int d = 0, const int m = 0, const int y = 0) {
        day = d;
        month = m;
        year = y;
    }

    int compare(const Date date) {
        if (year > date.year) return 1;
        else if (year < date.year) return -1;
        else if (month > date.month) return 1;
        else if (month < date.month) return -1;
        else if (day > date.day) return 1;
        else if (day < date.day) return -1;
        else return 0;
    }

};

class Employee {
private:
    char name[20];
    float salary;
    Date date_of_birth;
public:

    Employee(const char *n = "", const float s = 0, const Date d = Date()) {
        strcpy(name, n);
        salary = s;
        date_of_birth = d;
    }
    float get_salary() {
        return salary;
    }

    Date get_dateOfBirth() {
        return date_of_birth;
    }

    void print() {
        cout << name << " " << salary << endl;
    }

};


Employee highestsalary (Employee *e, int n) {
    Employee max = e[0];
    for (int i = 1; i < n; i++) {
        if (e[i].get_salary() > max.get_salary())
            max = e[i];
    }
    return max;
}

Employee youngest (Employee *e, int n) {
    Employee min = e[0];
    for (int i = 1; i < n; i++) {
        if (e[i].get_dateOfBirth().compare(min.get_dateOfBirth()) == 1)
            min = e[i];
    }
    return min;
}

int main() {
    Employee employee[10];
    employee[0] = Employee("Jack", 1234, Date(12, 12, 2014));
    employee[1] = Employee("John", 2457, Date(11, 10, 2013));
    employee[2] = Employee("Peter", 3076, Date(7, 5, 1980));
    Employee x = highestsalary(employee, 3);
    Employee y = youngest(employee, 3);
    x.print();
    y.print();
    return 0;
}