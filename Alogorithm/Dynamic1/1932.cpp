#include <iostream>

static int triangle[500][500];

static int get_max(int a, int b) {
	return a > b ? a : b;
}

int p1932(void) {
	int count;
	int max = 0;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j <= i; j++) {
			scanf_s("%d", &triangle[i][j]);
		}
	}

	for (int i = 1; i < count; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				triangle[i][j] = triangle[i - 1][j] + triangle[i][j];
			}
			else if (i == j) {
				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i][j];
			}
			else {
				triangle[i][j] = get_max(triangle[i - 1][j - 1], triangle[i - 1][j]) + triangle[i][j];
			}

			max = get_max(max, triangle[i][j]);
		}
	}

	printf("%d", max);

	return 0;
}