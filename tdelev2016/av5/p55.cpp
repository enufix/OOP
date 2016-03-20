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

    void setName(const char *n) {
        delete [] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    Student operator++(int) {
        Student c(*this);
        ++year;
        cout << "Student++" << endl;
        return c;
    }
    Student& operator++() {
        ++year;
        cout << "++Student" << endl;
        return *this;
    }

    bool operator>(const Student &s) {
        return average > s.average;
    }
    bool operator>(float average) {
        return this->average > average;
    }

    friend ostream& operator<<(ostream&, const Student&);
    friend bool operator>(float, const Student &);

};

ostream& operator<<(ostream &x, const Student &s) {
    x << s.name << endl;
    x << s.average << endl;
    x << s.year << endl;
    return x;
}

bool operator>(float average, const Student &s) {
    return average > s.average;
}

class Group {
private:
    Student *students;
    int size;
    void copy(const Group &g) {
        students = new Student[g.size];
        for(int i = 0; i < g.size; ++i) {
            students[i] = g.students[i];
        }
        size = g.size;
    }
public:
    Group(Student *s = NULL, int size = 0) {
        students = new Student[size];
        for(int i = 0; i < size; ++i) {
            students[i] = s[i];
        }
        this->size = size;
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

    Group& operator+=(Student s) {
        Student* temp = students;
        students = new Student[size + 1];
        for(int i = 0; i < size; ++i) {
            students[i] = temp[i];
        }
        students[size] = s;
        ++size;
        delete [] temp;
        return *this;
    }

    friend ostream& operator<<(ostream &o, const Group& g) {
        o << "Group with: " << g.size << " studnets" << endl;
        for(int i = 0; i < g.size; ++i) {
            o << g.students[i];
        }
        return o;
    }

    void reward() {
        for(int i = 0; i < size; ++i) {
            if(students[i] > 7) {
                cout << "Reward: " << endl;
                cout << students[i];
            }
        }
    }

    Student highestAverage() {
        Student max = students[0];
        for(int i = 0; i < size; ++i) {
            if(students[i] > max) {
                max = students[i];
            }
        }
        return max;
    }

    ~Group() {
        delete [] students;
    }
};

int main() {
    Student s("Jane", 8.5, 3);
    cout << s;
    Student copy(s);
    s.setName("Some very long name");
    cout << s;
    cout << copy;
    Student x;
    x = copy;
    copy.setName("This is the copy");
    cout << copy;
    cout << x;
    cout << x++;
    cout << x;
    cout << ++x;
    if(x > copy) {
        cout << "X is smarter!" << endl;
    } else {
        cout << "Copy is smarter!" << endl;
    }
    if(x > 9) {
        cout << "X has greater average than 9" << endl;
    }
    
    Group g;
    g += s;
    g += x;
    g += copy;
    cout << g;
    g.reward();
    Student top = g.highestAverage();
    cout << "Highest average" << endl;
    cout << top;

    return 0;
}
