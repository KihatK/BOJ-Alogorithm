#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

static int arr[501];
static int dp[501][501];
static int sum[501];

//dp[1][7] = dp[1][1] + dp[2][7],
//dp[1][7] = dp[1][2] + dp[3][7],
//dp[1][7] = dp[1][3] + dp[4][7],
//dp[1][7] = dp[1][4] + dp[5][7],
//dp[1][7] = dp[1][5] + dp[6][7],
//dp[1][7] = dp[1][6] + dp[7][7]

int p11066(void) {
	int num = 0;
	int count;

	scanf_s("%d", &num);

	while (num--) {
		scanf_s("%d", &count);
		for (int i = 1; i <= count; i++) {
			scanf_s("%d", &arr[i]);
			sum[i] = sum[i - 1] + arr[i];
		}

		for (int i = 1; i < count; i++) {
			for (int tx = 1; tx + i <= count; tx++) {
				int ty = tx + i;
				dp[tx][ty] = INT_MAX;

				for (int mid = tx; mid < ty; mid++) {
					dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
				}
			}
		}

		printf("%d\n", dp[1][count]);
	}

	return 0;
}