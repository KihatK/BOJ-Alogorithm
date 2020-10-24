#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int p1912(void) {
	int count;
	int maxNum = INT_MIN;

	scanf_s("%d", &count);

	vector<int> arr(count+1, 0);
	vector<int> dp(count + 1, 0);

	for (int i = 1; i <= count; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 1; i <= count; i++) {
		if (dp[i - 1] >= 0) {
			dp[i] = dp[i - 1] + arr[i];
		}
		else {
			dp[i] = arr[i];
		}
	}

	for (int i = 1; i <= count; i++) {
		maxNum = max(maxNum, dp[i]);
	}

	printf("%d", maxNum);

	return 0;
}