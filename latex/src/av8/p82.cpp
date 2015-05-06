#include <iostream>
#include <cstring>
using namespace std;

class Discount {
public:
    virtual float discount_price() = 0;
    virtual float price() = 0;
};

class Product {
protected:
    char name[100];
    float price;
public:
    Product(const char *name = "", const float price = 0) {
        strcpy(this->name, name);
        this->price = price;
    }

    float getPrice() {
        return price;
    }

};

class DigitalProduct : public Product, public Discount {
private:
    float size;
public:
    DigitalProduct(const char *name = "", const float price = 0, const float size = 0) : Product(name, price) {
        this->size = size;
    }

    float discount_price() {
        // 10% discount
        return 0.9 * getPrice();
    }

    float price() {
        return getPrice();
    }
};

class FoodProduct : public Product, public Discount {
private:
    float callories;
public:
    FoodProduct(const char *name = "", const float price = 0, const float callories = 0) : Product(name, price) {
        this->callories = callories;
    }

    float discount_price() {
        // 20% discount
        return .8 * getPrice();
    }

    float price() {
        return getPrice();
    }
};

class ClothesProduct : public Product {
private:
    char brand[100];
public:
    ClothesProduct(const char *name = "", const float price = 0, const char *brand = "") : Product(name, price) {
        strcpy(this->brand, brand);
    }
};
float total_discount(Discount **d, int n) {
    float price = 0;
    for (int i = 0; i < n; ++i) {
        price += d[i]->price();
    }
    float discount = 0;
    for (int i = 0; i < n; ++i) {
        discount += d[i]->discount_price();
    }
    return price - discount;
}
int main() {
    Discount **d = new Discount*[3];
    d[0] = new FoodProduct("Cheese", 450, 1200);
    d[1] = new FoodProduct("Wine", 780, 250);
    d[2] = new DigitalProduct("WOW", 380, 400);
    cout << "Difference: " << total_discount(d, 3) << endl;
    for (int i = 0; i < 3; ++i) {
        delete d[i];
    }
    delete [] d;
    return 0;
}

