#include <stdio.h>

struct student {
	char name[100];
	int number;
	int p1, p2, p3, p4;
	int total;
};

typedef struct student student;

void sort(student *data, int n) {
	int i, j;
	for(i = 0; i < n; ++i) {
		for(j = 0; j < n - 1 - i; ++j) {
			//if(data[j].total < data[j + 1].total) {
			if(strcmp(data[j].name, data[j + 1].name) > 0) {
				student temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
}

int main() {
	student data[200];
	int n;
	//scanf("%d", &n);
	FILE *f = fopen("students.txt", "r");
	int i = 0;
	for(;;) {
		int r = fscanf(f, "%s\t%d\t%d\t%d\t%d\t%d\n", 
			data[i].name, &data[i].number, &data[i].p1, 
			&data[i].p2, &data[i].p3, &data[i].p4);
		data[i].total = data[i].p1 + data[i].p2 + data[i].p3 + data[i].p4; 
		if(r <= 0) break;
		if(feof(f)) break;
		++i;

	}
	fclose(f);
	n = i;
	sort(data, n);
	for(i = 0; i < n; ++i) {
		printf("%s\t%d\t%d\n", data[i].name, data[i].number, 
			data[i].total);
	}
	return 0;

}