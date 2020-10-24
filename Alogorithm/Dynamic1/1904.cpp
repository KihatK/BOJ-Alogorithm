#include <iostream>

static long long history[1000000];

int p1904(void) {
	int n;

	scanf_s("%d", &n);

	history[0] = 0;
	history[1] = 1;
	history[2] = 2;

	for (int i = 3; i <= n; i++) {
		history[i] = (history[i - 1] + history[i - 2]) % 15746;
	}

	printf("%d", history[n]);

	return 0;
}