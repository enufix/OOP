#include <iostream>
#include <cstring>
using namespace std;

class Publication {
private:
    char name[100];
protected:
    int year;
    char *getName() {
        return name;
    }
public:
    int getYear() {
        return year;
    }
    void print() {
        cout << "Publication: " << name << " - " << year << endl;
    }
    Publication(char *name, int year) {
        strcpy(this->name, name);
        this->year = year;
    }
};
// public inheritance
class Book: public Publication {
private:
    int pages;
public:
    Book(char *name, int year, int pages): Publication(name, year) {
        this->pages = pages;
    }
    void printYear() {
        cout << year;  //accessing protected variable year
    }
    void printName() {
        cout << getName(); //access to getName(), name cannot be accessed because is private
    }
    void printPages() {
        cout << pages;
    }
};

// protected inheritance
class NewsPaper: protected Publication {
private:
    int number;
public:
    NewsPaper(char *name, int year, int number): Publication(name, year) {
        this->number = number;
    }
    void printYear() {
        cout << getYear();  //access to public getYear(), which in this class has protected access
    }
    void printName() {
        cout << getName(); //access to getName(), name cannot be accessed because is private
    }
    void printNumber() {
        cout << number;
    }

};
//private inheritance
class DailyNewsPaper: private NewsPaper {
private:
    int day;
    int month;
public:
    DailyNewsPaper(char *name, int day, int month, int year, int number): NewsPaper(name, year, number) {
        this->day = day;
        this->month = month;
    }
    using NewsPaper::print;  // function print from Publication becomes public for DailyNewsPaper
    using NewsPaper::printNumber; // function printNumber from Publication becomes public for DailyNewsPaper
};

int main() {
    Publication p("Tabernakul", 1992);
    p.print();  // public - function

    Book *k = new Book("ProsvetnoDelo", 1900, 123);
    k->print(); //print is public in Book
    k->printyearBook(); // public - function
    cout << k->getName(); // error! protected - function

    NewsPaper *s = new NewsPaper("Tea", 2013, 30);
    s->print();  //error! protected - function
    cout << s->getYear(); //  error! protected - function
    s->printName();  // public - function

    DailyNewsPaper d("Vest", 2, 3, 2014, 25);
    d.print(); //public-function
    d.printName(); // error! private - function
    cout << d.getName(); // error! private – function

}