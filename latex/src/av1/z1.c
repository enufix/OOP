#include <stdio.h>

struct date {
	int day;
	int month;
	int year;
};

typedef struct date date;

short compare(date d1, date d2) {
	if (d1.day == d2.day && d1.month == d2.month && d1.year == d2.year)
		return 0;
	if (d1.year > d2.year)
		return 1;
	else if (d1.year < d2.year)
		return -1;
	else {
		if (d1.month > d2.month)
			return 1;
		else if (d1.month < d2.month)
			return -1;
		else {
			if (d1.day > d2.day)
				return 1;
			else
				return -1;
		}
	}
}

long difference(date d1, date d2) {
	long days;
	days = d1.day - d2.day;
	days += (d1.month - d2.month) * 30;
	days += (d1.year - d2.year) * 360;
	return days;
}

int main() {
	date d1 = { 14, 12, 1989 };
	date d2;
	d2.day = 16;
	d2.month = 12;
	d2.year = 1989;
	if (compare(d1, d2) == 0)
		printf("Dates are equal.\n");
	else if (compare(d1, d2) == 1)
		printf("Difference between dates is %d days.\n", difference(d1, d2));
	else
		printf("Difference between dates is %d days.\n", difference(d2, d1));
	return 0;
}
