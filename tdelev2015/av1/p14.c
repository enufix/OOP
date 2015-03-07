#include <stdio.h>

typedef struct x {
	char name[100];
	char id[10];
	int points;
} student;

void swap(student *s1, student *s2) {
	student temp;
	strcpy(temp.name, s1->name);
	strcpy(temp.id, s1->id);
	temp.points = s1->points;
	strcpy(s1->name, s2->name);
	strcpy(s1->id, s2->id);
	s1->points = s2->points;
	strcpy(s2->name, temp.name);
	strcpy(s2->id, temp.id);
	s2->points = temp.points;
}

void sort(student *data, int n) {
	int i, j;
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n - 1; ++j) {
			if(strcmp(data[j].name, data[j + 1].name) > 0) {
			//if(data[j].points < data[j + 1].points) {
				swap(&data[j], &data[j + 1]);
			}
		}
	}
}

int main() {
	FILE *f;
	student data[500];
	int i = 0;
	f = fopen("students.txt", "r");
	while(!feof(f)) {
		int p1, p2, p3, p4;
		int res = fscanf(f, "%s\t%s\t%d\t%d\t%d\t%d\n", 
			&data[i].name, &data[i].id, &p1, &p2, &p3, &p4);
		if(res < 0) break;
		data[i].points = p1 + p2 + p3 + p4;
		++i;
	}
	fclose(f);
	int n = i;
	sort(data, n);
	for(i = 0; i < n; ++i) {
		printf("\t%s\t%s\t%d\n", data[i].name, data[i].id, data[i].points);
	}
	return 0;
}