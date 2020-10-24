#include <iostream>

int dp[1000001];

int get_min(int a, int b) {
	return a > b ? b: a;
}

int p1463(void) {
	int n;

	scanf_s("%d", &n);

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;  //i가 2나 3으로 나누어떨어지지 않으면 i-1까지의 최솟값에 +1하는 것이 최소다.
		if (i % 3 == 0) dp[i] = get_min(dp[i], dp[i / 3] + 1);
		if (i % 2 == 0) dp[i] = get_min(dp[i], dp[i / 2] + 1);
	}

	printf("%d", dp[n]);

	return 0;
}