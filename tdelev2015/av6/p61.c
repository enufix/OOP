#include <stdio.h>
#include <string.h>

struct tanc {
  char ime[15];
  char poteklo[15];
};

typedef struct tanc tanc;

struct tancher {
  char ime[20];
  char prezime[20];
  tanc tanci[3];
};

typedef struct tancher tancher;

void tancuvanje(tancher *t, int n, char *zemja) {
  int i;
  for (i = 0; i < n; ++i) {
    tancher x = t[i];
    int j;
    for (j = 0; j < 3; ++j) {
      if (strcmp(x.tanci[j].poteklo, zemja) == 0) {
        printf("%s %s, %s\n", x.ime, x.prezime, x.tanci[j].ime);
        break;
      }
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int i;
  tancher t[n];
  for (i = 0; i < n; ++i) {
    scanf("%s", t[i].ime);
    scanf("%s", t[i].prezime);
    int j;
    for (j = 0; j < 3; ++j) {
      scanf("%s", t[i].tanci[j].ime);
      scanf("%s", t[i].tanci[j].poteklo);
    }
  }
  char zemja[100];
  scanf("%s", zemja);
  tancuvanje(t, n, zemja);
  return 0;
}