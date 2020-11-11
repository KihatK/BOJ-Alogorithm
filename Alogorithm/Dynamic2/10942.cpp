#include <iostream>

static int arr[2001];
static int dp[2001][2001];

int p10942(void) {
	int num;
	int quest_num;
	int start, end;

	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf_s("%d", &arr[i]);
	}

	for (int i = 1; i <= num; i++) {
		dp[i][i] = true;
		if (arr[i] == arr[i - 1]) {
			dp[i - 1][i] = true;
		}
	}

	for (int i = 2; i <= num - 1; i++) {
		for (int j = 1; j <= num - i; j++) {
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1]) {
				dp[j][j + i] = true;
			}
		}
	}

	scanf_s("%d", &quest_num);

	while (quest_num--) {
		scanf_s("%d %d", &start, &end);
		if (dp[start][end]) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	return 0;
}