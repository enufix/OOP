#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
	char name[100];
	int age;
public:
	Person(char *n = "", int a = 0) {
		strcpy(name, n);
		age = a;
	}

	void print() {
		cout << "Person: " << name << " : " << age << endl;
	}

	int magic() {
		int sum = 0;
		char *p = name;
		while (*p) {
			sum += (int) * p;
			++p;
		}
		return sum;
	}

};

class Date {
private:
	Person a;
	Person b;
public:
	Date(Person a, Person b) {
		this->a = a;
		this->b = b;
	}
	void print() {
		cout << "Date: " << endl;
		a.print();
		b.print();
	}

	bool areMatch() {
		int total = a.magic() + b.magic();
		return total % 10 < 5;
	}
};

int main() {
	Date d(Person("Jane", 24), Person("Jake", 21));
	d.print();
	if (d.areMatch()) {
		cout << "They are a match :)" << endl;
	} else {
		cout << "No luck this time :(" << endl;
	}
	return 0;
}


