#include <iostream>
#include <vector>

using namespace std;

int p12865(void) {
	int thing, mass;

	int arr_mass[101] = { 0, };
	int arr_value[101] = { 0, };

	scanf_s("%d %d", &thing, &mass);

	vector<vector<int>> dp(thing + 1, vector<int>(mass + 1, 0));

	for (int i = 1; i <= thing; i++) {
		scanf_s("%d %d", &arr_mass[i], &arr_value[i]);
	}

	for (int i = 1; i <= thing; i++) {
		for (int j = 1; j <= mass; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - arr_mass[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - arr_mass[i]] + arr_value[i]);
			}
		}
	}

	printf("%d", dp[thing][mass]);

	return 0;
}