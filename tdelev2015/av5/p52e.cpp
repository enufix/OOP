#include <iostream>
#include <cstdlib>
using namespace std;

class List {
private:
  int *a;
  int count;
  int size;
  void copy(const List &l) {
    a = new int[l.size];
    for (int i = 0; i < l.count; ++i) {
      a[i] = l.a[i];
    }
    count = l.count;
    size = l.size;
  }
public:
  List(int size = 5) {
    a = new int[size];
    this->size = size;
    count = 0;
  }

  List(const List &l) {
    copy(l);
  }

  List& operator=(const List &l) {
    if (this == &l) return *this;
    delete [] a;
    copy(l);
    return *this;
  }


  ~List() {
    delete [] a;
  }

  void add(int x) {
    if (size == count) {
      cout << "Allocate: " << size * 2 << endl;
      int *temp = a;
      a = new int[size * 2];
      for (int i = 0; i < count; ++i) {
        a[i] = temp[i];
      }
      delete [] temp;
      size *= 2;
    }
    a[count] = x;
    ++count;
  }

  List& operator<(int x) {
    add(x);
    return *this;
  }

  void set(int index, int value) {
    a[index] = value;
  }

  void print() {
    cout << "Size: " << size << endl;
    cout << "Count: " << count << endl;
    for (int i = 0; i < count; ++i) {
      cout << a[i] << '\t';
    }
    cout << endl;
  }

  int getCount() { return count; }

  int operator+(int x) {
    return count + x + 99;
  }
};

/*int operator+(List &l, int x) {
  return l.getCount() + x;
}*/

int main() {

  List l;
  l.print();
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x = rand() % 500;
    l.add(x);
    l < x;
  }
  l.print();
  List copy = l;
  copy.print();
  l.set(5, 99999);
  l.print();
  copy.print();
  l = copy;
  copy.set(0, 555555);
  l.print();
  copy.print();

  cout << copy + 5 << endl;
  return 0;
}