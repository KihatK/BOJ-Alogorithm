#include <iostream>
#include <climits>

static int arr[1000][3];
static int dp[1000][3];

static int minimum = INT_MAX;

static int min(int a, int b) {
	return a > b ? b : a;
}

int p1149(void) {
	int count;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < 3; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}

	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];

	for (int i = 1; i < count; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
	}

	for (int i = 0; i < 3; i++) {
		if (minimum > dp[count - 1][i]) {
			minimum = dp[count - 1][i];
		}
	}

	printf("%d", minimum);

	return 0;
}