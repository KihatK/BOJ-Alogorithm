#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int p9251(void) {
	char first[1001];
	char second[1001];
	int str1, str2;

	scanf_s("%s", first, sizeof(first));
	scanf_s("%s", second, sizeof(second));

	str1 = strlen(first);
	str2 = strlen(second);

	vector<vector<int>> dp(str1+1, vector<int>(str2+1));

	for (int i = 1; i <= str1; i++) {
		for (int j = 1; j <= str2; j++) {
			if (first[i-1] == second[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	printf("%d", dp[str1][str2]);

	return 0;
}