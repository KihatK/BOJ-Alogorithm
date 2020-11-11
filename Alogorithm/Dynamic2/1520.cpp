#include <iostream>

static int map[501][501];
static int dp[501][501];
static int check_x[4] = { 1,0,-1,0 };
static int check_y[4] = { 0,1,0,-1 };
static int m, n;

static int dfs(int y, int x) {
	if (y == m && x == n) {
		return 1;
	}
	else if (dp[y][x] == -1) {
		dp[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int newX = x + check_x[i];
			int newY = y + check_y[i];
			if (map[y][x] > map[newY][newX] && newY > 0 && newY <= m && newX > 0 && newX <= n) {
				dp[y][x] += dfs(newY, newX);
			}
		}
	}
	return dp[y][x];
}

int p1520(void) {
	scanf_s("%d %d", &m, &n);

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf_s("%d", &map[i][j]);
			dp[i][j] = -1;
		}
	}

	printf("%d", dfs(1, 1));

	return 0;
}