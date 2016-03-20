#include <stdio.h>

typedef struct student {
    char ime[100];
    char prezime[100];
    char indeks[10];
    int poeni[4];
} student;

int vkupno(student s) {
    int i;
    int total = 0;
    for(i = 0; i < 4; ++i) {
        total += s.poeni[i];
    }
    return total;
}

void sort(student s[], int n) {
    int i, j;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n - 1 - i; ++j) {
            int s1 = vkupno(s[j]);
            int s2 = vkupno(s[j + 1]);
            if(s1 < s2) {
                student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    FILE *f = fopen("studenti.txt", "r");
    fscanf(f, "%d", &n);
    student s[n];
    int i;
    for(i = 0; i < n; ++i) {
        fscanf(f, "%s %s %s", s[i].ime, s[i].prezime, s[i].indeks);
        int j;
        for(j = 0; j < 4; ++j) {
            fscanf(f, "%d", &s[i].poeni[j]);
        }
    }
    fclose(f);
    sort(s, n);
    for(i = 0; i < n; ++i) {
        printf("%s %s %s %d\n", s[i].ime, s[i].prezime, 
            s[i].indeks, vkupno(s[i]));

    }
    return 0;


}