#include <iostream>
#include <cstring>
using namespace std;

class Product {
public:
    char name[100];
    float price;
public:
    Product(const char *n = "", float p = 0) {
        strcpy(name, n);
        price = p;
    }
    virtual char* description() const = 0;
    bool operator==(const Product &p) {
        return strcmp(description(), p.description()) == 0;
    }
    virtual ~Product() {
        cout << "PRoduct destructor" << endl;
    }
};

class Discount {
public:

    virtual float discount() const = 0;
    virtual float discountedPrice() const = 0;
    virtual float originalPrice() const = 0;
    virtual ~Discount() {
        cout << "Discount destructor" << endl;
    }
};

float totalDiscount(Discount **d, int n) {
    float total = 0;
    for(int i = 0; i < n; ++i) {
        total += d[i]->discount();
    }
    return total / n;
}
float savings(Discount **d, int n) {
    float total = 0;
    for(int i = 0; i < n; ++i) {
        total += d[i]->originalPrice() - d[i]->discountedPrice();
    }
    return total;
}

class Trip : public Discount {

};

class Deodorant : public Product, public Discount {
public:
    Deodorant(const char *name = "", float price = 0) :
        Product(name, price), Discount(){}
    char* description() const {
        cout << "This is deodorant" << endl;
        return "This is deodorant";
    }

    float discount() const {
        return 15;
    }

    float discountedPrice() const {
        return price * (1 - discount() / 100.0);
    }

    float originalPrice() const {
        return price;
    }

    bool equal(const Product *p) const {
        return price == p->price && 
        strcmp(name, p->name) == 0;
    }

    virtual ~Deodorant() {
        cout << "Deodorant destructor" << endl;
    }
};

class Juice : public Product, public Discount {
public:
    Juice(const char *name, float price) : Product(name, price) {

    }
    char* description() const {
        cout << "This is a Juice" << endl;
        return "this is juice";
    }

    float discount() const {
        return 8;
    }

    float discountedPrice() const {
        return price * (1 - discount() / 100.0);
    }

    float originalPrice() const {
        return price;
    }

    bool equal(const Product *p) const {
        return price == p->price && 
        strcmp(name, p->name) == 0;
    }
};

class Fruit : public Product {
public:
    Fruit(const char* name, float price) : Product(name, price) {

    }
    char* description() const {
        cout << "This is fruit" << endl;
        return "this is fruit";
    }

    bool equal(const Product *p) const {
        return price == p->price && 
        strcmp(name, p->name) == 0;
    }
};

int main() {
    Discount **d = new Discount*[3];
    d[0] = new Deodorant("Dove", 200);
    d[1] = new Deodorant("Nivea", 187);
    d[2] = new Juice("Some", 100);
    Juice y("Orange juice", 50);
    Product *x = new Fruit("Banana", 50);
    cout << "Total discount: " << totalDiscount(d, 3) << endl;
    cout << "Total savings: " << savings(d, 2) << endl;
    if(*x == y) {
        cout << "Banana and Coca Cola product are equal" << endl;
    } else {
        cout << "not equal" << endl;
    }
    delete d[0];
    delete d[1];
    delete d[2];
    delete [] d;
    delete x;
    return 0;
}


