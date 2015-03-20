#include <iostream>
#include <cstdlib>
using namespace std;

class Array {
private:
	int *a;
	int size;
	int count;
public:
	// constructor
	Array(int size = 10) {
		count = 0;
		this->size = size;
		a = new int[size];
	}

	// copy constructor
	Array(const Array &x) {
		a = new int[x.size];
		size = x.size;
		count = x.count;
		for (int i = 0; i < size; ++i) {
			a[i] = x.a[i];
		}
	}

	// destructor
	~Array() {
		delete [] a;
	}

	// asignment operator =
	Array& operator=(const Array &x) {
		if (this == &x) return *this;
		delete [] a;
		a = new int[x.size];
		size = x.size;
		count = x.count;
		for (int i = 0; i < size; ++i) {
			a[i] = x.a[i];
		}
		return *this;
	}

	void add(int x) {
		if (count == size) {
			cout << "Allocation : " << size << endl;
			int *t = a;
			// Solution number 1
			//a = new int[size + 1];
			//size++;
			// Solution number 2
			a = new int[2 * size];
			size *= 2;
			for (int i = 0; i < count; ++i) {
				a[i] = t[i];
			}
			delete [] t;
		}
		a[count] = x;
		count++;
	}
	Array& operator>(int x) {
		if (count == size) {
			cout << "Allocation : " << size << endl;
			int *t = a;
			// Solution number 1
			//a = new int[size + 1];
			//size++;
			// Solution number 2
			a = new int[2 * size];
			size *= 2;
			for (int i = 0; i < count; ++i) {
				a[i] = t[i];
			}
			delete [] t;
		}
		a[count] = x;
		count++;
		return *this;
	}

	int get(int index) {
		return a[index];
	}

	void set(int index, int value) {
		a[index] = value;
	}

	int& operator[](int index) {
		return a[index];
	}

	int getCount() {
		return count;
	}

	void show() {
		cout << "Count: " << count << endl;
		cout << "Size: " << size << endl;
		for (int i = 0; i < count; ++i) {
			cout << (*this)[i] << "\t";
		}
		cout << endl;
	}
};

int main() {
	Array x(5);
	Array y;
	int a;
	/*while (true) {
		cin >> a;
		if (a < 0) break;
		x.add(a);
	}*/
	for (int i = 0; i < 10; ++i) {
		x > (rand() % 100);
	}
	x[5] = 100000;
	x.show();
	y = x;
	x.set(4, 99);
	x.show();
	y.show();
	return 0;
}