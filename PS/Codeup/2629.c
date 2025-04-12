#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct City {
	int x, y, p;
	double radius;
} City;

int compare(const City* a, const City* b) {
	return a->radius > b->radius;
}

int main(void) {
	int n, p;
	scanf("%d%d", &n, &p);
	City* cities = (City*)malloc(sizeof(City) * n);
	for (int _n = 0; _n < n; _n++)
	{
		City city;
		scanf("%d%d%d", &city.x, &city.y, &city.p);
		city.radius = sqrt(pow(city.x, 2) + pow(city.y, 2));
		cities[_n] = city;
	}

	qsort(cities, n, sizeof(City), compare);

	double radius = 0;
	int flag = 0;
	for (int _n = 0; _n < n; _n++)
	{
		p += cities[_n].p;
		radius = cities[_n].radius;

		if (p >= 1000000) {
			flag = 1;
			break;
		}
	}

	if (flag) {
		printf("%.3lf", radius);
	}
	else {
		printf("-1");
	}
}