#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Mate {
private:
    char name[100];
    int age;
    bool isFemale;
public:
    Mate(const char *name = "noname", const int age = 0,
         const bool isFemale = true) {
        strcpy(this->name, name);
        this->age = age;
        this->isFemale = isFemale;
    }

    void print() {
        cout << (isFemale ? "Girl: " : "Boy: ") << " " << name;
        cout << " " << age << endl;
    }

    int getAge() {
        return age;
    }

    char *getName() {
        return name;
    }

};

class Date {
private:
    Mate mate1, mate2;
public:
    Date(const Mate mate1 = Mate(), const Mate mate2 = Mate()) {
        this->mate1 = mate1;
        this->mate2 = mate2;
    }
    void print() {
        cout << "Date: " << endl;
        mate1.print();
        mate2.print();
    }

    bool areMatch() {
        return abs(mate1.getAge() - mate2.getAge()) <= 10 &&
               (strlen(mate1.getName()) + strlen(mate2.getName())) % 2 == 0;
    }
};

int main() {
    char name[100];
    int age;
    int isFemale;
    cin >> name;
    cin >> age;
    cin >> isFemale;
    Mate mate1(name, age, isFemale == 1);
    cin >> name;
    cin >> age;
    cin >> isFemale;
    Mate mate2(name, age, isFemale == 1);
    Date d(mate1, mate2);
    d.print();
    if (d.areMatch()) {
        cout << "Good match." << endl;
    } else {
        cout << "Ooops, not a good match..." << endl;
    }
    return 0;
}