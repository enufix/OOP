#include <stdio.h>


typedef struct vector {
    float x, y, z;
} vec;

void readVector(vec *v) {
    scanf("%f %f %f", &v->x, &v->y, &v->z);
}

void printVector(vec *v) {
    printf("%.2f %.2f %.2f", v->x, v->y, v->z);
}

float scalar(vec *v1, vec *v2) {
    return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

vec vectorProduct(vec *v1, vec *v2) {
    vec v;
    v.x = v1->y * v2->z - v1->z * v2->y ;
    v.y = v1->z * v2->x - v1->x * v2->z ;
    v.z = v1->x * v2->y - v1->y * v2->x ;
    return v;
}

int main() {
    vec v1, v2;
    readVector(&v1);
    readVector(&v2);

    printVector(&v1);
    printf("\n");
    printVector(&v2);
    printf("\n");

    printf("Skalaren proizvod: %.2f\n", scalar(&v1, &v2));
    printf("Vektorski proizvod\n");
    vec v = vectorProduct(&v1, &v2);
    printVector(&v);
    printf("\n");
    return 0;
}