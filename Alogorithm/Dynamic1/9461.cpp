#include <iostream>

int p9461(void) {
	int count;
	int n;

	long long triangle[101] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };

	for (int i = 11; i <= 100; i++) {
		triangle[i] = triangle[i - 1] + triangle[i - 5];
	}

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%d", &n);
		printf("%lld\n", triangle[n]);
	}

	return 0;
}