#include <iostream>

int get_num(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (b == 1) {
		return 1;
	}
	return get_num(a - 1, b) + get_num(a, b - 1);
}

int p2775(void) {
	int count;
	int k, n;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%d", &k);
		scanf_s("%d", &n);
		printf("%d\n", get_num(k, n));
	}

	return 0;
}