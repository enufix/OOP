#include <stdio.h>

typedef struct vector {
	float x, y, z;
} vec;

float scalar(vec* v1, vec* v2) {
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z; 
}

vec product(vec* v1, vec* v2) {
	vec res;
	res.x = v1->y * v2->z - v1->z * v2->y;
	res.y = v1->z * v2->x - v1->x * v2->z;
	res.z = v1->x * v2->y - v1->y * v2->x;
	return res;
}

void read_vec(vec v) {
	scanf("%f", &v.x);
	scanf("%f", &v.y);
	scanf("%f", &v.z);
}

int main() {
	vec v1, v2;
	read_vec(v1);
	read_vec(v2);
	printf("Scalar product: %f\n", scalar(&v1, &v2));
	vec result = product(&v1, &v2);
	printf("Vector product: %f, %f, %f\n", result.x, result.y, result.z);
	return 0;
}
