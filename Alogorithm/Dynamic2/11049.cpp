#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

static int arr[501][2];
static int dp[501][501];

int p11049(void) {
	int num;

	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf_s("%d %d", &arr[i][0], &arr[i][1]);
	}

	for (int i = 1; i < num; i++) {
		dp[i][i + 1] = arr[i][0] * arr[i][1] * arr[i + 1][1];
	}

	for (int m = 2; m <= num; m++) {
		for (int i = 1; i+m <= num; i++) {
			int j = i + m;
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + arr[i][0] * arr[k][1] * arr[j][1]);
			}
		}
	}

	printf("%d", dp[1][num]);

	return 0;
}