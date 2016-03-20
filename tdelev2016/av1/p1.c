#include <stdio.h>

struct datum {
    int den;
    int mesec;
    int godina;
};

typedef struct datum date;

typedef struct x {
    float y;
} x;

void printDate(date d) {
    printf("%02d.%02d.%d\n", d.den, d.mesec, d.godina);    
}
int meseci[] = {
    31,28,31,30,31,30,31,31,30,31,30,31
};

int razlika(date od, date doo) {
    int y = doo.godina - od.godina;
    int m = doo.mesec - od.mesec;
}

int main() {
    date denes = {9, 2, 2016};
    x a = {5};
    date utre;
    utre.den = 10;
    utre.mesec = 2;
    utre.godina = 2016;
    printDate(utre);
    printDate(denes);

    return 0;
}











