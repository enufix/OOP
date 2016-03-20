#include <iostream>
#include <cstring>
using namespace std;

class Student {
private:
    char *name;
    float average;
    int year;
    void copy(const Student &s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        average = s.average;
        year = s.year;
    }
public:
    Student(const char *n = "unknown", float a = 0, int y = 0) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        average = a;
        year = y;
    }
    // copy constructor
    Student(const Student &s) {
        copy(s);
    }
    // = operator
    Student& operator=(const Student &s) {
        if(this == &s) return *this;
        delete [] name;
        copy(s);
        return *this;
    }
    // destructor
    ~Student() {
        delete [] name;
    }

    friend ostream& operator<<(ostream &x, const Student &s) {
        x << s.name << " ";
        x << s.average << " ";
        x << s.year << endl;
        return x;
    }

    void setName(const char *name) {
        delete [] this->name;
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    bool operator>(const Student &s) {
        return average > s.average;
    }

    bool operator>(int a) {
        return average > a;
    }
    // ++s
    Student& operator++() {
        ++year;
        return *this;
    }
    // s++
    Student operator++(int) {
        Student c(*this);
        ++year;
        return c;
    }

    float getAverage() {
        return average;
    }

    friend bool operator<(int,const Student&);
};
bool operator<(int x, const Student &s) {
    return x < s.average;
}

class Group {
private:
    Student *students;
    int n;
    void copy(const Group &g) {
        n = g.n;
        students = new Student[n];
        for(int i = 0; i < n; ++i) {
            students[i] = g.students[i];
        }
    }
public:
    Group(Student *s = NULL, int nn = 0) {
        n = nn;
        students = new Student[n];
        for(int i = 0; i < n; ++i) {
            students[i] = s[i];
        }
    }

    Group(const Group &g) {
        copy(g);
    }

    Group& operator=(const Group &g) {
        if(this == &g) return *this;
        delete [] students;
        copy(g);
        return *this;
    }

    ~Group(){
        delete [] students;
    }

    Group& operator+=(Student s) {
        
        return *this;
    }

    friend ostream& operator<<(ostream &x, const Group &g) {
        x << "Group with " << g.n << " students" << endl;
        for(int i = 0; i < g.n; ++i) {
            x << g.students[i];
        } 
        return x;
    }

    Group& operator++(){
        for(int i = 0; i < n; ++i) {
            ++students[i];
        }
        return *this;
    }

    void price() {
        for(int i = 0; i < n; ++i) {
            if(students[i].getAverage() == 10) {
                cout << students[i];
            }
        }
    }

    Student highestAverage() {
        Student max = students[0];
        for(int i = 1; i < n; ++i) {
            if(students[i] > max) {
                max = students[i];
            }
        }
        return max;
    }

};




int main() {
    Student s("The name of the student", 6.0f, 1);
    Student copy(s);
    Student x("Student x", 10, 1);
    cout << ++x;
    cout << x++;
    cout << x;
    if(x > s) {
        cout << x;
        cout << "is bigger" << endl;
    }
    if(x > 9) {
        cout << "Average greater then 9" << endl;
    }
    if(9 < x) {

    }
    s.setName("New name");
    cout << s;
    cout << copy;
    copy = s;
    cout << copy;

    Group g;
    g += s;
    g += copy;
    g += x;
    cout << g;
    ++g;
    cout << g;
    g.price();
    Student max = g.highestAverage();
    cout << "Highest average" << endl;
    cout << max;
    return 0;
}