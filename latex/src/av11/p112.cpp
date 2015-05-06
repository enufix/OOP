#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

template <typename T>
void merge_arrays(const T* a1, const int len1, const T* a2, const int len2, T** result) {
	*result = new T[len1 + len2];
	int i;
	for(i = 0; i < len1; ++i) {
		(*result)[i] = a1[i];
	}
	for(int j = 0; j < len2; ++j) {
		(*result)[i++] = a2[j];		
	}
}

template <typename T>
void print(const T* array, const int len) {
	for(int i = 0; i < len; ++i) {
		cout << array[i];
		if(i != len - 1) {
			cout << " ";
		} else {
			cout << endl;
		}
	}
}

int main() {
	int a1[] = {
		1, 4, 5 ,6, 7
	};
	
	int a2[] = {
		5, 6, 0
	};
	int* result;
	merge_arrays(a1, 5, a2, 3, &result);
	print(result, 8);
	delete [] result;
	return 0;
}