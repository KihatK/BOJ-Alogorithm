#include <iostream>

static bool visited[9];
static int arr[9];

void dfs2(int count, int start, int n, int m) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[count] = i;
			dfs2(count + 1, i + 1, n, m);
			visited[i] = false;
		}
	}
}

int p15650(void) {
	int n, m;

	scanf_s("%d %d", &n, &m);

	dfs2(0, 1, n, m);

	return 0;
}