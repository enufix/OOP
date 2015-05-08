#include <iostream>
#include <cstring>
using namespace std;
class WrongPriceException : public exception {

};
class ShortNameException : public exception {

};

class Discount {
public:
    static float euro;
    static float dollar;
    virtual float discount_price() = 0;
    virtual float price() = 0;
    virtual void print_rule() = 0;
    virtual ~Discount() {

    }
};
float Discount::euro = 61.7;
float Discount::dollar = 44.5;

class Product {
protected:
    char name[100];
    float price;
public:
    Product(const char *name = "", const float price = 0) {
        /*try {*/
            if (price < 0) throw WrongPriceException();
            if(strlen(name) <= 3) throw ShortNameException();
            strcpy(this->name, name);
            this->price = price;
        /*} catch (int) {
            cout << "Wrong price. Exception is thrown!" << endl;
            this->price = 0.0;
        }*/
    }
    float getPrice() {
        return price;
    }
    void print() {
        cout << "Product{ name=" << name << ", price=" << price << "}" << endl;
    }
    virtual ~Product() {

    }
};
class Cosmetics : public Product, public Discount {
private:
    int weight;
public:
    Cosmetics(const char *name = "", const float price = 0,
              const int weight = 0) : Product(name, price) {
        this->weight = weight;
    }
    float discount_price() {
        if (getPrice() / Discount::dollar > 20)
            return 0.86 * getPrice();
        if (getPrice() / Discount::euro > 5)
            return 0.88 * getPrice();
        return getPrice();
    }
    float price() {
        return getPrice();
    }
    void print_rule() {
        cout << "All cosmetic products with price over 5 euros have 12% discount." << endl;
        cout << "All cosmetic products with price over 10 dollars have discount 14%." << endl;
    }
};

class FoodProduct : public Product, public Discount {
private:
    float callories;
public:
    FoodProduct(const char *name = "", const float price = 0,
                const float callories = 0) : Product(name, price) {
        this->callories = callories;
    }
    float discount_price() {
        return getPrice();
    }
    float price() {
        return getPrice();
    }
    void print_rule() {
        cout << "No discount for food products" << endl;
    }
};

class Drinks : public Product, public Discount {
private:
    char brand[100];
    bool alcoholic;
public:
    Drinks(const char *name = "", const float price = 0,
           const char *brand = "", const bool alcoholic = false) : Product(name, price) {
        strcpy(this->brand, brand);
        this->alcoholic = alcoholic;
    }
    float discount_price() {
        if (this->alcoholic && (getPrice() / Discount::euro > 20))
            return 0.95 * getPrice();
        if (!this->alcoholic && (strcmp(this->brand, "Coca-Cola") == 0))
            return 0.90 * getPrice();
        return getPrice();
    }
    float price() {
        return getPrice();
    }
    void print_rule() {
        cout << "All alcholic beverages with price over 20 euros have 5% discount. " << endl;
        cout << "All no alcholic beverages of the brand Coca-Cola have discount of 10%" << endl;
    }
};

float total_discount(Discount **d, int n) {
    float discount = 0;
    for (int i = 0; i < n; ++i) {
        discount += d[i]->discount_price();
        cout << "Normal price: " << d[i]->price() << endl;
        cout << "Discounted price: " << d[i]->discount_price() << endl;
        d[i]->print_rule();
    }
    return discount;
}

int main() {
    int n = 7;
    Discount **d = new Discount*[n];
    try {
        d[0] = new FoodProduct("ab", -30);
    } catch(WrongPriceException e) {
        cout << "Negative price in constructor" << endl;
    } catch(ShortNameException e) {
        cout << "Short name" << endl;
    }
    d[1] = new Drinks("Whiskey", 1350, "Jack Daniel's", true);
    d[2] = new FoodProduct("Cheese", 390, 105);
    d[3] = new Drinks("Vodka", 850, "Finlandia", true);
    d[4] = new Cosmetics("Cream", 72, 100);
    d[5] = new Drinks("Soda", 50, "Coca-Cola", false);
    d[6] = new Cosmetics("Parfume", 3500, 50);
    cout << "Total price is: " << total_discount(d, n) << endl;
    for (int i = 1; i < n; ++i) {
        delete d[i];
    }
    delete [] d;
    return 0;
}
