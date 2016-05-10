#include<iostream>
#include<string.h>
using namespace std;

class IndexOutOfBoundsException : public exception {

};

class CourseMember {
protected:
    char name[30];
    int finalPoints;
    bool extra;
public:
    CourseMember(char* name, int finalPoints) {
        strcpy(this->name, name);
        this->finalPoints = finalPoints;
        this->extra = false;
    }
    friend ostream& operator<<(ostream &out, const CourseMember &cm) {
        out << cm.name << " - " << cm.points();
        return out;
    }
    virtual int points() const {
        return finalPoints;
    }
    virtual bool hasExtra() const {
        return false;
    }

    bool operator==(const char *n) {
        return strcmp(name, n) == 0;
    }

    // finish the class
};


// implment here ExtraCourseMember

class ExtraCourseMember : public CourseMember {
private:
    int extraActivities;
    int *extraPoints;
    void copy(const ExtraCourseMember &ecm) {
        extraActivities = ecm.extraActivities;
        extraPoints = new int[extraActivities];
        for(int i = 0; i < extraActivities; ++i) {
            extraPoints[i] = ecm.extraPoints[i];
        }
    }
public:
    static const int M = 5;
    ExtraCourseMember(char* name, int finalPoints) :
        CourseMember(name, finalPoints) {
            extraActivities = 0;
            extraPoints = NULL;
        }

    int points() const {
        int total = 80 * finalPoints / 100;
        for(int i = 0; i < extraActivities; ++i) {
            total += extraPoints[i];
        }
        return total;
    }

    bool hasExtra() const {
        return true;
    }

    ExtraCourseMember& operator+=(int p) {
        if(extraActivities == ExtraCourseMember::M) {
            throw IndexOutOfBoundsException();
        }
        ++extraActivities;
        int *temp = extraPoints;
        extraPoints = new int[extraActivities];
        for(int i = 0; i < extraActivities - 1; ++i) {
            extraPoints[i] = temp[i];
        }
        extraPoints[extraActivities - 1] = p;
        delete [] temp;
        return *this;
    }

    ExtraCourseMember(const ExtraCourseMember &ecm)
    : CourseMember(ecm) {
        copy(ecm);
    }
    ExtraCourseMember& operator=(const ExtraCourseMember &ecm) {
        if(this == &ecm) return *this;
        delete [] extraPoints;
        *this = ecm;
        copy(ecm);
        return *this;
    }

    ~ExtraCourseMember() {
        delete [] extraPoints;
    }
};




class Course {
private:
    char name[30];
    CourseMember *ucesnici[10];
    int broj;
    static int P;
public:
    Course(char *name, CourseMember** ucesnici, int broj ) {
        strcpy(this->name, name);
        for (int i = 0; i < broj; i++) {
            //ako ucesnikot ima dopolnitelni aktivnosti
            if (ucesnici[i]->hasExtra()) {
                this->ucesnici[i] = new ExtraCourseMember(*dynamic_cast<ExtraCourseMember*>(ucesnici[i]));
            }
            else this->ucesnici[i] = new CourseMember(*ucesnici[i]);
        }
        this->broj = broj;
    }
    ~Course() {
        for (int i = 0; i < broj; i++) delete ucesnici[i];
    }

    static void setP(int p) {
        Course::P = p;
    }

    // finish the class
    void printMembers() {
        cout << "The course ";
        cout << name;
        cout << " is passed from:" << endl;
        for(int i = 0; i < broj; ++i) {
            if(ucesnici[i]->points() > Course::P) {
                cout << *ucesnici[i] << endl;
            }
        }
    }

    void addPointsForExtraActivity(char *name, int points) {
        for(int i = 0; i < broj; ++i) {
            if(*ucesnici[i] == name) {
                (*ucesnici) += points;
            }
        }
    }
};
int Course::P = 50;

int main() {

    CourseMember **members;
    int n, m, points;
    char name[10];
    bool hasExtraActivity;
    cin >> n;
    members = new CourseMember*[n];
    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> points;
        cin >> hasExtraActivity;
        if (!hasExtraActivity)
            members[i] = new CourseMember(name, points);
        else
            members[i] = new ExtraCourseMember(name, points);
    }

    Course programming("Programiranje", members, n);
    for (int i = 0; i < n; i++) delete members[i];
    delete [] members;

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> name >> points;
        programming.addPointsForExtraActivity(name, points);
    }

    Course::setP(60);

    programming.printMembers();

}
