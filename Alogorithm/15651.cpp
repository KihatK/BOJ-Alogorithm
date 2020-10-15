#include <iostream>

static int arr[8];

void dfs3(int count, int n, int m) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[count] = i;
		dfs3(count + 1, n, m);
	}
}

int p15651(void) {
	int n, m;

	scanf_s("%d %d", &n, &m);

	dfs3(0, n, m);

	return 0;
}