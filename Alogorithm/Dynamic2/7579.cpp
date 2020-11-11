#include <iostream>
#include <algorithm>

using namespace std;

struct App {
	int memory;
	int cost;
};

static App arr[101];
static int dp[10001];

int p7579(void) {
	int n, m;
	int sum = 0;

	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i].memory);
	}

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i].cost);
		sum += arr[i].cost;
	}

	for (int i = 0; i < n; i++) {
		for (int j = sum; j >= arr[i].cost; j--) {
			dp[j] = max(dp[j], dp[j - arr[i].cost] + arr[i].memory);
		}
	}

	int i = 0;
	for (i = 0; i <= sum, dp[i] < m; i++);
	printf("%d", i);

	return 0;
}