#include <iostream>
#include <cstring>
using namespace std;

class InvalidDiameterException : public exception {
char msg[100];
public:
    InvalidDiameterException(const char *msg) {
        strcpy(this->msg, msg);
    }
    char* getMessage() {
        return msg;
    }
};

class Bicycle {
protected:
    char *brand;
    float mass;
    int diameter;
    void copy(const Bicycle &b) {
        brand = new char[strlen(b.brand) + 1];
        strcpy(brand, b.brand);
        mass = b.mass;
        diameter = b.diameter;
    }
    static float MAX_MASS;
public:
    Bicycle(const char *b = "", float m = 0, int d = 0) {
        brand = new char[strlen(b) + 1];
        strcpy(brand, b);
        mass = m;
        if(d < 15 || d > 29) {
            throw 1;
            //throw InvalidDiameterException("Invalid diameter");
        }
        diameter = d;
    }

    Bicycle(const Bicycle &b) {
        copy(b);
    }

    Bicycle& operator=(const Bicycle &b) {
        if (this == &b) return *this;
        delete [] brand;
        copy(b);
        return *this;
    }

    friend ostream& operator<<(ostream &out, const Bicycle &b) {
        out << b.brand << " : " << b.mass << " : " << b.getRangCoefficient();
        return out;
    }

    virtual float getRangCoefficient() const = 0;
    virtual int getType() = 0;

    virtual ~Bicycle() {
        delete [] brand;
    }

    static bool isValid(Bicycle *b) {
        return b->mass < MAX_MASS;
    }

    static void changeMax(float max) {
        Bicycle::MAX_MASS = max;
    }

};
float Bicycle::MAX_MASS = 15;

class RoadBicycle : public virtual Bicycle {
private:
    float tireWidth;
public:
    RoadBicycle(const char *b = "", float m = 0, int d = 0, float tw = 0)
        : Bicycle(b, m, d) {
        tireWidth = tw;
    }

    float getRangCoefficient() const {
        return (2.5 - tireWidth) * 2 + diameter * 0.2;
    }

    int getType() {
        return 1;
    }

};

class MountainBicycle : public virtual Bicycle {
private:
    int suspension;
public:
    MountainBicycle(const char *b = "", float m = 0, int d = 0, int s = 0)
    : Bicycle(b, m, d) {
        suspension = s;
    }

    float getRangCoefficient() const {
        return suspension + (27 - diameter) * 0.8;
    }

    int getType() {
        return 2;
    }
};

class HybridBicycle: public RoadBicycle, public MountainBicycle {
public:
    HybridBicycle(const char *b = "", float m = 0, int d = 0, 
        float tw = 0, int sus = 0) :
    Bicycle(b, m, d),
    RoadBicycle(b, m, d, tw),
    MountainBicycle(b, m, d, sus) {

    }

    float getRangCoefficient() const {
        float rb = RoadBicycle::getRangCoefficient();
        float mb = MountainBicycle::getRangCoefficient();
        if(rb < mb) {
            return rb;
        } else {
            return mb;
        }
    }

    int getType() {
        return 3;
    }
};

class Competitor {
private:
    char name[100];
    Bicycle *bicycle;
public:
    Competitor(const char *n = "", Bicycle *b = NULL) {
        strcpy(name, n);
        bicycle = b;
    }

    Bicycle* getBicycle() {
        return bicycle;
    }

    friend ostream& operator<<(ostream &out, const Competitor &c) {
        out << c.name << "-> " << *(c.bicycle);
        return out;
    }

};
void print(Competitor c[], int n) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n - 1 - i; ++j) {
            if(c[j].getBicycle()->getRangCoefficient()
                > c[j + 1].getBicycle()->getRangCoefficient()) {
                Competitor temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    cout << "Road bicycles" << endl;
    int k = 0;
    for(int i = 0; i < n; ++i) {
        Bicycle* b = c[i].getBicycle();
        //RoadBicycle* rb = dynamic_cast<RoadBicycle*>(b);
        if(b->getType() == 1) {
            cout << ++k << ". " << c[i] << endl;
        }
    }
    k = 0;
    cout << "Mountain bicycles" << endl;
    for(int i = 0; i < n; ++i) {
        Bicycle* b = c[i].getBicycle();
        if(Bicycle::isValid(b)) {

        }
        //MountainBicycle* rb = dynamic_cast<MountainBicycle*>(b);
        if(b->getType() == 2) {
            cout << ++k << ". " << c[i] << endl;
        }
    }
    k = 0;
    cout << "Hybrid bicycles" << endl;
    for(int i = 0; i < n; ++i) {
        Bicycle* b = c[i].getBicycle();
        //HybridBicycle* rb = dynamic_cast<HybridBicycle*>(b);
        if(b->getType() == 3) {
            cout << ++k << ". " << c[i] << endl;
        }
    }
}

int main() {
    Competitor c[100];
    char name[100];
    int n;
    Bicycle::changeMax(30);
    cout << "Enter number of competitors: ";
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter bicycle type: 1/road 2/mountain 3/hybrid";
        int type;
        cin >> type;
        Bicycle *b;
        char brand[100];
        float mass;
        int diameter;
        cout << "Enter brand: ";
        cin >> brand;
        cout << "Enter mass: ";
        cin >> mass;
        cout << "Enter diameter: ";
        cin >> diameter;
        if(type == 1) {
            float tw;
            cout << "Enter tire width: ";
            cin >> tw;
            try {
                b = new RoadBicycle(brand, mass, diameter, tw);
            } catch(int i) {
                //cout << e.getMessage() << endl;
                b = new RoadBicycle(brand, mass, 21, tw);
            }
        } else if(type == 2) {
            int sus;
            cout << "Enter suspension number: ";
            cin >> sus;
            b = new MountainBicycle(brand, mass, diameter, sus);
        } else if(type == 3) {
            int sus;
            float tw;
            cout << "Enter tire width: ";
            cin >> tw;
            cout << "Enter suspension number: ";
            cin >> sus;
            b = new HybridBicycle(brand, mass, diameter, tw, sus);
        }

        c[i] = Competitor(name, b);
    }
    print(c, n);
    
    return 0;
}