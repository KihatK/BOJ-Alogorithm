#include <iostream>

static int arr[101] = { 0, };
static int dp[10001] = { 0, };

int p2293(void) {
	int n, k;

	scanf_s("%d %d", &n, &k);

	for (int i = 1; i <= n; i++) {
		scanf_s("%d", &arr[i]);
	}

	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= arr[i]) {
				dp[j] += dp[j - arr[i]];
			}
		}
	}

	printf("%d", dp[k]);

	return 0;
}