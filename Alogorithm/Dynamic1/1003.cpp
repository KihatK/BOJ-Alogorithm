#include <iostream>

int p1003(void) {
	int count;
	int n;

	int list[41] = { 0, 1, 1 };

	for (int i = 3; i < 41; i++) {
		list[i] = list[i - 1] + list[i - 2];
	}

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%d", &n);
		if (n == 0) printf("1 0\n");
		else if (n == 1) printf("0 1\n");
		else printf("%d %d\n", list[n - 1], list[n]);
	}

	return 0;
}