#include <iostream>

int p11053(void) {
	int count;
	int max = 0;

	int arr[1010] = { 0, };
	int dp[1010] = { 0, };

	scanf_s("%d", &count);

	for (int i = 1; i <= count; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 1; i <= count; i++) {
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (min < dp[j]) {
					min = dp[j];
				}
			}
		}
		dp[i] = min + 1;
		if (max < dp[i]) {
			max = dp[i];
		}
	}

	printf("%d", max);

	return 0;
}