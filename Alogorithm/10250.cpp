#include <iostream>

int p10250(void) {
	int h, w, n;
	int count;
	int x, y;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%d %d %d", &h, &w, &n);
		y = n % h == 0 ? h : n % h;
		x = n % h == 0 ? n / h : n / h + 1;
		printf("%d%02d\n", y, x);
	}

	return 0;
}