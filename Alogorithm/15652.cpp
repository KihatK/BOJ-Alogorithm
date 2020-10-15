#include <iostream>

static int arr[9];

void dfs4(int count, int n, int m) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[count - 1] <= i) {
			arr[count] = i;
			dfs4(count + 1, n, m);
		}
	}
}

int p15652(void) {
	int n, m;

	scanf_s("%d %d", &n, &m);

	dfs4(0, n, m);

	return 0;
}