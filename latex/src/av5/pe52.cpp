#include <iostream>
using namespace std;

class Array {
private:
	int *x;
	int size;
	int capacity;
public:
	Array(const int capacity = 5) {
		x = new int[capacity];
		size = 0;
		this->capacity = capacity;
	}

	// copy constructor
	Array(const Array &a) {
		size = a.size;
		capacity = a.capacity;
		x = new int[capacity];
		for(int i = 0; i < size; ++i) {
			x[i] = a.x[i];
		}
	}

	// asignment operator =
	Array& operator=(const Array &a) {
		if(this == &a) return *this;
		size = a.size;
		capacity = a.capacity;
		delete [] x;
		x = new int[capacity];
		for(int i = 0; i < size; ++i) {
			x[i] = a.x[i];
		}
		return *this;
	}

	// destructor
	~Array() {
		delete [] x;
	}

	friend ostream& operator<<(ostream &o, const Array &a) {
		o << "Capacity: " << a.capacity << endl;
		o << "Size: " << a.size << endl;
		for(int i = 0; i < a.size; ++i) {
			o << a.x[i] << endl;
		}
		return o;
	}

	Array& operator+=(const int n) {
		if(capacity == size) {
			int *y = new int[2 * capacity];
			for(int i = 0; i < size; ++i) {
				y[i] = x[i];
			}
			delete [] x;
			x = y;
			capacity = capacity * 2;
		}
		x[size] = n;
		size++;
		return *this;
	}

	int& operator[](int i) {
		return x[i];
	}

	int getAt(int index) {
		return x[index];
	}

	void setAt(int index, int value) {
		x[index] = value;
	}
};

int main() {
	Array a;
	a += 5;
	a += 1;
	a += 9;
	a += 8;
	a += 3;
	a += 10;
	Array b(a);
	a.setAt(0, 20);
	a = b;
	b.setAt(5, 50);
	cout << a;
	cout << b;
	return 0;
}