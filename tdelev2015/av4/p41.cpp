#include <iostream>
#include <cstring>
using namespace std;

class Momche {
private:
	char ime[100];
	char prezime[100];
	int godini;
public:
	Momche(char *ime = "", char *prezime = "", int godini = 0) {
		strcpy(this->ime, ime);
		strcpy(this->prezime, prezime);
		this->godini = godini;
	}

	void print() {
		cout << "Momche: " << ime << " " << prezime << ", " << godini << endl;
	}

	int ascii() {
		int s = 0;
		char *x = ime;
		while(*x) {
			s += (int)*x;
			++x;
		}
		x = prezime;
		while(*x) {
			s += (int)*x;
			++x;
		}
		return s;
	}

	void setIme(char *ime) {
		strcpy(this->ime, ime);
	}

};

class Devojche {
private:
	char ime[100];
	char prezime[100];
	int godini;
public:
	Devojche(char *ime = "", char *prezime = "", int godini = 0) {
		strcpy(this->ime, ime);
		strcpy(this->prezime, prezime);
		this->godini = godini;
	}

	void print() {
		cout << "Devojche: " << ime << " " << prezime << ", " << godini << endl;
	}

	int ascii() {
		int s = 0;
		char *x = ime;
		while(*x) {
			s += (int)*x;
			++x;
		}
		x = prezime;
		while(*x) {
			s += (int)*x;
			++x;
		}
		return s;
	}

	void setIme(char *ime) {
		strcpy(this->ime, ime);
	}

};
class Sredba {
private:
	Momche m;
	Devojche d;
public:
	Sredba(Momche m, Devojche d) {
		this->m = m;
		this->d = d;
	}

	void print() {
		cout << "Sredba" << endl;
		m.print();
		d.print();
	}

	bool match() {
		int s1 = m.ascii();
		int s2 = d.ascii();
		return ((s1 + s2) % 10) < 5;
	}
};

int main() {
	Momche m("Jovan", "Jovanovski", 20);
	Devojche d("Ana", "Mihajlovska", 21);
	Sredba s(m, d);
	s.print();
	if(s.match()) {
		cout << "Si odgovaraat :)" << endl;
	} else {
		cout << "Ne si odgovaraat :(" << endl;
 	}
	return 0;
}