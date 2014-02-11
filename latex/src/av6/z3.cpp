/*
 Да се дефинира класа Dogovor, во која се чуваат информации за:
 -	број на договор (int),
 -	категорија на договор (низа од 50 знаци)
 -	динамички алоцирано поле од имињата на потпишувачите на договорот (имињата на потпишувачите не се подолги од 20 знаци)
 -	датум на потпишување на договорот (да се развие посебна класа за датуми во која ќе биде имплементиран операторот < за споредување на два датуми)
 За потребите на оваа класа да се напишат
 -	преоптоварен конструктор со аргументите на класата
 -	set и get методи
 -	операторот << за проследување на ostream (печатење) на објект од класата Dogovor.

 Дополнително да се креира класа Klaster_za_dogovori во која ќе се чува динамички алоцирано поле од објекти од класата Dogovor и бројот на објекти кои се чуваат во полето. За оваа класа да се преоптоварат:
 -	унарниот оператор +=  коj се однесува на додавање на нов објект од класата Dogovor во рамките на полето
 -	метода (Potpisani_dogovori) на која се проследува објект од класата Datum како параметар
 а таа враќа листа од потпишаните договори на проследениот датум.
 -	операторот << за проследување на ostream (печатење) на Dogovor објектите меѓусебно одвоени со нов ред.
 */
#include<iostream>
#include<cstring>
#define DOLZINA 21
using namespace std;

class Datum {
	int den;
	int mesec;
	int godina;
public:
	Datum() {
	}
	Datum(int d, int m, int g) {
		den = d;
		mesec = m;
		godina = g;
	}
	bool operator<(const Datum& d) {
		if (godina < d.godina)
			return true;
		else if (godina == d.godina && mesec < d.mesec)
			return true;
		else if (godina == d.godina && mesec == d.mesec && den < d.den)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& out, const Datum& d) {
		out << d.den << "." << d.mesec << "." << d.godina;
		return out;
	}

};
class Dogovor {
	long brojDog;
	char kategorija[50];
	char** potpisuvaci;
	int brojPot;
	Datum date;
public:
	Dogovor(long _brojDog = 0, char* _kategorija = "", char** _potpisuvaci = 0,
			int _brojPot = 0, const Datum& _date = Datum()) {
		brojDog = _brojDog;
		strncpy(kategorija, _kategorija, 49);
		kategorija[49] = 0;
		potpisuvaci = new char*[_brojPot];
		brojPot = _brojPot;
		for (int i = 0; i < brojPot; i++) {
			potpisuvaci[i] = new char[DOLZINA];
			strcpy(potpisuvaci[i], _potpisuvaci[i]);
		}
		date = _date;
	}
	~Dogovor() {
		for (int i = 0; i < brojPot; i++) {
			delete[] potpisuvaci[i];
		}
		delete[] potpisuvaci;
	}

	Dogovor(const Dogovor& other) {
		brojDog = other.brojDog;
		strcpy(kategorija, other.kategorija);
		potpisuvaci = new char*[other.brojPot];
		brojPot = brojPot;
		for (int i = 0; i < brojPot; i++) {
			potpisuvaci[i] = new char[DOLZINA];
		}
		date = other.date;
	}
	Dogovor& operator=(const Dogovor& other) {
		if (this != &other) {
			brojDog = other.brojDog;
			strcpy(kategorija, other.kategorija);
			for (int i = 0; i < brojPot; i++) {
				delete[] potpisuvaci[i];
			}
			delete[] potpisuvaci;
			potpisuvaci = new char*[other.brojPot];
			brojPot = other.brojPot;
			for (int i = 0; i < brojPot; i++) {
				potpisuvaci[i] = new char[DOLZINA];
				strcpy(potpisuvaci[i], other.potpisuvaci[i]);
			}
			date = other.date;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Dogovor& d) {
		out << "broj dogovor: " << d.brojDog << endl;
		out << "kategorija: " << d.kategorija << endl;
		out << "potpisuvaci: " << endl;
		for (int i = 0; i < d.brojPot; i++) {
			out << d.potpisuvaci[i] << endl;
		}
		out << "datum: " << endl;
		out << d.date << endl;
		return out;
	}
	void set_dogovor(long _brojDog) {
		brojDog = _brojDog;
	}
	long get_dogovor() {
		return brojDog;
	}

	void set_kategorija(char* _kategorija) {
		strncpy(kategorija, _kategorija, 49);
		kategorija[49] = 0;
	}
	char const* get_kategorija() {
		return kategorija;
	}

	void set_potpisuvaci(char** _potpisuvaci, int _brojPot) {
		for (int i = 0; i < brojPot; i++) {
			delete[] potpisuvaci[i];
		}
		delete[] potpisuvaci;
		potpisuvaci = new char*[_brojPot];
		brojPot = _brojPot;
		for (int i = 0; i < brojPot; i++) {
			potpisuvaci[i] = new char[DOLZINA];
			strcpy(potpisuvaci[i], _potpisuvaci[i]);
		}
	}
	const char* const * get_potpisuvaci() {
		return potpisuvaci;
	}

	void set_datum(Datum _date) {
		date = _date;
	}
	Datum get_datum() {
		return date;
	}
};

class Klaster {
	Dogovor* dogovori;
	int brojDogovori;
public:
	Klaster() {
		dogovori = 0;
		brojDogovori = 0;
	}
	Klaster(Dogovor* _dogovori, int _brojDogovori) {
		brojDogovori = _brojDogovori;
		dogovori = new Dogovor[brojDogovori];
		for (int i = 0; i < brojDogovori; i++) {
			dogovori[i] = _dogovori[i];
		}
	}
	Klaster(const Klaster &other) {
		brojDogovori = other.brojDogovori;
		dogovori = new Dogovor[other.brojDogovori];
		for (int i = 0; i < brojDogovori; i++) {
			dogovori[i] = other.dogovori[i];
		}
	}
	Klaster& operator=(const Klaster &other) {
		if (this != &other) {
			delete[] dogovori;
			brojDogovori = other.brojDogovori;
			dogovori = new Dogovor[other.brojDogovori];
			for (int i = 0; i < brojDogovori; i++) {
				dogovori[i] = other.dogovori[i];
			}
		}
		return *this;
	}

	~Klaster() {
		delete[] dogovori;
	}

	Klaster& operator+=(Dogovor& d) {
		Dogovor* tmp = new Dogovor[brojDogovori + 1];
		for (int i = 0; i < brojDogovori; i++) {
			tmp[i] = dogovori[i];
		}
		delete[] dogovori;
		dogovori = tmp;
		dogovori[brojDogovori] = d;
		brojDogovori++;
		return *this;
	}

	Klaster potpisaniDogovori(Datum& date) {
		Klaster tmp;
		for (int i = 0; i < brojDogovori; i++) {
			if (!(dogovori[i].get_datum() < date) && !(date
					< dogovori[i].get_datum())) {
				tmp += dogovori[i];
			}
		}
		return tmp;
	}

	friend ostream& operator<<(ostream& out, const Klaster& other) {
		out << "Kalster na dogovori:" << endl;
		out << "Dogovori: " << endl;
		for (int i = 0; i < other.brojDogovori; i++) {
			out << other.dogovori[i] << endl;
		}
		return out;
	}

};

int main() {

	char* potpisuvaci[3] = { "aaa", "bbb", "ccc" };
	Dogovor d(10, "Kategorija1", potpisuvaci, 3, Datum(10, 10, 2010));
	Dogovor d2(11, "Kategorija2", potpisuvaci, 2, Datum(9, 9, 2010));
	cout << d;
	cout << d2;

	Dogovor* dog;
	dog = new Dogovor[2];
	dog[0] = d;
	dog[1] = d2;

	Klaster kls(dog, 2);
	Dogovor d3(15, "Kategorija3", 0, 0, Datum(9, 9, 2010));
	kls += d3;

	Datum date(9, 9, 2010);
	cout << endl;
	cout << kls.potpisaniDogovori(date) << endl;
	delete[] dog;
	return 0;
}

