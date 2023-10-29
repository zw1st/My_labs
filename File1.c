#include <stdio.h>

void number11() {
	int a, b, d, e;
	scanf_s("%d %d", &a, &b);
	d = 0;
	e = 1;
	if (a % 3 == 0) {
		d++;
		e *= a;
	}
	if (b % 3 == 0) {
		d++;
		e *= b;
	}
	if (d == 0) {
		e = 0;
	}
	printf("%d %d", d, e);
}

void number12() {
	int a, b;
	scanf_s("%d", &a);
	b = a;
	do {
		printf("%d", b);
		b--;
	} while (b >= 1);

	do {
		b++;
		printf("%d", b);
	} while (b < a);
}

void number13() {
	int n, d;
	scanf_s("%d", &n);
	printf("%d = 1", n);
	d = 2;
	do {
		if (n % d == 0) {
			printf("*%d", d);
			n = n / d;
		}
		else {
			d++;
		}
	} while (n > 1);
}

void number23() {
	int a, b, k, s;
	scanf_s("%d %d", &a, &b);
	k = 1;
	s = a;
	while (k <= b) {
		s += k;
		k += 1;
		printf("%d ", s);
		if (s % 7 == 0) {
			break;
		}
	}
}

void number21() {
	int a, b, s;
	scanf_s("%d %d", &a, &b);
	s = 0;
	while (a <= b) {
		s += 4;
		a += 4;
		printf("%d ", s);
	}
}

void number22() {
	int a, b;
	scanf_s("%d", &a);
	b = 1;
	while (b <= a) {
		printf("\n %d", b);
		if (b % 3 == 0) {
			printf("*");
		}
		if (b % 4 == 0) {
			printf(":");
		}
		b++;
	}
}



void main() {
}