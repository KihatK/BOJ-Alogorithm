#include <iostream>

static bool arr[14][14];
static int answer = 0;

static bool validate(int row, int col, int n) {
	int i, j;
	for (i = 0; i < col; i++) {
		if (arr[row][i]) return false;
	}
	for (i = col - 1, j = row - 1; j >= 0; i--, j--) {
		if (arr[j][i]) return false;
	}
	for (i = col - 1, j = row + 1; j < n; i--, j++) {
		if (arr[j][i]) return false;
	}
	return true;
}

static void dfs(int count, int n) {
	if (count == n) {
		answer++;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!arr[i][count] && validate(i, count, n)) {
			arr[i][count] = true;
			dfs(count + 1, n);
			arr[i][count] = false;
		}
	}
}

int p9663(void) {
	int n;

	scanf_s("%d", &n);

	dfs(0, n);

	printf("%d", answer);

	return 0;
}