#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

class Bicycle {
protected:
    char name[100];
    float mass;
    int diameter;
    static const float MAX_MASS = 15;
    
public:
	enum CATEGORY {
    	ROAD,
    	MOUNTAIN,
    	HYBRID
    };
    Bicycle(const char *n = "", const float m = 0, const int d = 0) {
        strcpy(name, n);
        mass = m;
        if(d < 15 || d > 21) {
        	diameter = 21;
        } else {
        	diameter = d;	
        }
    }

    float getMass() const {
    	return mass;
    }

    static bool canCompete(Bicycle &b) {
    	return b.mass < MAX_MASS;
    }

    /*bool canCompete() {
    	return mass < MAX_MASS;
    }*/

    virtual float getRangCoefficient() const = 0;
    virtual CATEGORY getCategory() const = 0;
};

class RoadBicycle : public Bicycle {
private:
    float width;
public:
    RoadBicycle(const char *n = "", const float m = 0, const int d = 0, const float w = 0) :
        Bicycle(n, m, d) {
        width = w;
    }

    float getRangCoefficient() const {
    	return (2.5 * width) * 2 + diameter * 0.2;
    }

    CATEGORY getCategory() const {
    	return Bicycle::ROAD;
    }

};

class MountainBicycle : public Bicycle {
private:
    int number_of_ss;
public:
    MountainBicycle(const char *n = "", const float m = 0, const int d = 0, const int nss = 0) :
        Bicycle(n, m, d) {
        number_of_ss = nss;
    }

    float getRangCoefficient() const {
    	return number_of_ss + (27 - diameter) * 0.8;
    }

    CATEGORY getCategory() const {
    	return Bicycle::MOUNTAIN;
    }
};

class HybridBicycle : public RoadBicycle, public MountainBicycle {
public:
    HybridBicycle(const char *n = "", const float m = 0, const int d = 0,
                  const float w = 0, const int nss = 0) : RoadBicycle(n, m, d, w), MountainBicycle(n, m, d, nss) {

    }

    float getRangCoefficient() const {
    	return RoadBicycle::getRangCoefficient() < MountainBicycle::getRangCoefficient() ?
    	RoadBicycle::getRangCoefficient() : MountainBicycle::getRangCoefficient();
    }

    CATEGORY getCategory() const {
    	return Bicycle::HYBRID;
    }
};

class Competitor {
private:
	char name[100];
	Bicycle *bicycle;
public:
	Competitor(const char* n = "", Bicycle *b = NULL) {
		strcpy(name, n);
		bicycle = b;
	}

	Competitor& operator=(const Competitor &c) {
		strcpy(name, c.name);
		Bicycle *temp = bicycle;
		bicycle = c.bicycle;
		c.bicycle = temp;
	}

	bool operator<(const Competitor &c) {
		return this->bicycle->getRangCoefficient() < c.bicycle->getRangCoefficient();
	}

	friend ostream& operator<<(ostream &out, const Competitor &c) {
		out << c.name << "\t" << c.bicycle->getMass() << "\t" << c.bicycle->getRangCoefficient() << endl;
		return out;
	}

	RoadBicycle::CATEGORY getCategory() {
		return bicycle->getCategory();
	}
};

void printCompetitors(Competitor *c, int n) {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n - 1 - i; ++j) {
			if(c[j] < c[j + 1]) {
				Competitor temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}
	cout << "Road competitors" << endl;
	for(int i = 0; i < n; ++i) {
		if(c[i].getCategory() == Bicycle::ROAD) {
			cout << i + 1 << ". " << c[i];
		}
	}
	cout << "Mountain competitors" << endl;
	for(int i = 0; i < n; ++i) {
		if(c[i].getCategory() == Bicycle::MOUNTAIN) {
			cout << i + 1 << ". " << c[i];
		}
	}
	cout << "Hybrid competitors" << endl;
	for(int i = 0; i < n; ++i) {
		if(c[i].getCategory() == Bicycle::HYBRID) {
			cout << i + 1 << ". " << c[i];
		}
	}
}

int main() {
	int n;
	char name[100];
	char model[100];
	float mass;
	int diameter;

	cout << "Number of competitors: ";
	cin >> n;

	Competitor competitors[n];
	for(int i = 0; i < n; ++i) {
		cout << "Name: ";
		cin >> name;
		cout << "Type (0 - Road, 1 - Mountain, 2 - Hybrid): ";
		int type;
		cin >> type;
		cout << "Model: ";
			cin >> model;
			cout << "Mass: ";
			cin >> mass;
			cout << "Diameter: ";
			cin >> diameter;
		if(type == 0) {
			cout << "Width: ";
			float width;
			cin >> width;
			RoadBicycle rb(model, mass, diameter, width);
			competitors[i] = Competitor(name, &rb);
		} else if(type == 1) {
			cout << "Number of SS: ";
			int nss;
			cin >> nss;
			MountainBicycle mb(model, mass, diameter, nss);
			competitors[i] = Competitor(name, &mb);
		}
	}

	printCompetitors(competitors, n);
	return 0;
}


