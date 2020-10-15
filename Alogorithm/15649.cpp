#include <iostream>

static bool visited[9];
static int arr[9];

void dfs(int count, int n, int m) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[count] = i;
			dfs(count + 1, n, m);
			visited[i] = false;
		}
	}
}

int p15649(void) {
	int n, m;

	scanf_s("%d %d", &n, &m);

	dfs(0, n, m);

	return 0;
}