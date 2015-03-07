#include <stdio.h>

struct capital {
	char name[100];
	int population;
};

struct president {
	char name[100];
	int age;
};

typedef struct country {
	char name[100];
	int population;
	struct capital capital;
	struct president president;
} country;

int main() {
	country c;
	strcpy(c.name, "Macedonia");
	c.population = 2000000;
	struct capital cc = { "Skopje", 600000};
	c.capital = cc;
	c.president = {"Thename", 50};

	c.capital.population
}