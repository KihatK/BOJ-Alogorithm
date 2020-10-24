#include <iostream>

static unsigned long long memo[91];

static unsigned long long fibo(int n) {
	if (n == 0) {
		return memo[0] = 0;
	}
	if (n == 1) {
		return memo[1] = 1;
	}
	if (memo[n]) {
		return memo[n];
	}
	else {
		return memo[n] = fibo(n - 1) + fibo(n - 2);
	}
}

int p2748(void) {
	int n;

	scanf_s("%d", &n);

	printf("%lld", fibo(n));

	return 0;
}