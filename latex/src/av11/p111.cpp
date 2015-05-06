#include <iostream>
#include <cstring>
using namespace std;

class ArtWork {
protected:
	int year;
	char* author;
	float price;
public:
	ArtWork(const int year = 0, const char *author = "", const float price = 0) {
		this->year = year;
		this->author = new char[strlen(author) + 1];
		strcpy(this->author, author);
		if(price < 0) {
			throw 1;
		}
		this->price = price;
	}

	ArtWork(const ArtWork &a) {
		year = a.year;
		author = new char[strlen(a.author) + 1];
		strcpy(author, a.author);
		price = a.price;
	}

	ArtWork& operator=(const ArtWork &a) {
		if(this == &a) return *this;
		year = a.year;
		delete [] author;
		author = new char[strlen(a.author) + 1];
		strcpy(author, a.author);
		price = a.price;
		return *this;	
	}

	virtual float calculate_price() const = 0;

	bool operator>(ArtWork &a) {
		return this->calculate_price() > a.calculate_price();
	}

	friend ostream& operator<<(ostream& out, const ArtWork &a) {
		out << "Author: " << a.author << endl;
		out << "Year: " << a.year << endl;
		out << "Price: " << a.calculate_price() << endl;
		return out;
	}

	~ArtWork() {
		delete [] author;
	}
};

class PaintWork : public ArtWork {
private:
	char technique[100];
	int damage;
public:
	PaintWork(const int year = 0, const char *author = "", const float price = 0, 
		const char* technique = "", const int damage = 0) : ArtWork(year, author, price) {
		strcpy(this->technique, technique);
		this->damage = damage;
	}

	float calculate_price() const {
		return price * (1 - damage / 100.0);
	}
};


class MusicWork : public ArtWork {
private:
	char genre[100];
	static int x;
public:
	MusicWork(const int year = 0, const char *author = "", const float price = 0, 
		const char* genre = "") : ArtWork(year, author, price) {
		strcpy(this->genre, genre);
	}

	float calculate_price() const {
		if(year < 1700) {
			return price * (1 + x / 100.0);
		}
		return price;
	}
};

int MusicWork::x = 10;

int main() {
	MusicWork *mw;
	PaintWork *pw;
	try{
		mw = new MusicWork(1990, "Metalica", -1500, "Heavy Metal");
		pw = new PaintWork(1650, "Leonardo DaVinci", 15000, "Oil", 8);
	} catch(int e) {
		mw = new MusicWork(1990, "Metalica", 600, "Heavy Metal");
		pw = new PaintWork(1650, "Leonardo DaVinci", 15000, "Oil", 8);
	}
	cout << *mw;
	cout << *pw;
	if(*mw > *pw) {
		cout << "Music work: " << mw->calculate_price();
	} else {
		cout << "Paint work: " << pw->calculate_price();
	}
	delete mw;
	delete pw;
	return 0;
}

