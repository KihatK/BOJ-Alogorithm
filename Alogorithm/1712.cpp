#include <iostream>

int p1712(void) {
	int a, b, c;
	int benefit;

	scanf_s("%d%d%d", &a, &b, &c);

	if (b >= c) {
		printf("-1");
	}
	else {
		benefit = a / (c - b) + 1;
		printf("%d", benefit);
	}

	return 0;
}