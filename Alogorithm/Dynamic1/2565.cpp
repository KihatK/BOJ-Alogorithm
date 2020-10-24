#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p2565(void) {
	int n;
	int maxNum = 0;

	scanf_s("%d", &n);

	vector<vector<int>> arr(n);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		arr[i] = vector<int>(2);  //이걸 해줘야 scanf_s할 때 에러가 나지 않음
		scanf_s("%d %d", &arr[i][0], &arr[i][1]);
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i][1] > arr[j][1] && dp[i] <= dp[j]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		maxNum = max(maxNum, dp[i]);
	}

	printf("%d", n - maxNum);

	return 0;
}