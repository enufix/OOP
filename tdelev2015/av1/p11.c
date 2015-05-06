#include <stdio.h>

typedef struct date {
	int day, month, year;
} date;

//typedef struct date date;

void print(date *d) {
	printf("%02d.%02d.%d\n", d->day, d->month, d->year);
}

int compare(date d1, date d2) {
	if(d1.year < d2.year) return -1;
	else if(d1.year > d2.year) return 1;
	else if(d1.month < d2.month) return -1;
	else if(d1.month > d2.month) return 1;
	else if(d1.day < d2.day) return -1;
	else if(d1.day > d2.day) return 1;
	else return 0;
}

int main() {
	date d1 = { 10, 5, 2000};
	date d2 = { 10, 5, 2000};
	printf("%d\n", compare(d1, d2));
	print(&d1);
	return 0;

}