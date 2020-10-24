#include <iostream>
#include <climits>

static int synergy[21][21];
static int start[10];
static int link[10];
static int minimum = INT_MAX;
static int start_sum = 0;
static int link_sum = 0;

static int num_len(int* arr) {
	int count = 0;
	int i = 0;
	while (*(arr + i) != 0) {
		count++;
		i++;
	}
	return count;
}

static int my_min(int a, int b) {
	return a < b ? a : b;
}

// 절대값 반환
static int my_abs(int a) {
	if (a < 0) a = a * -1;
	return a;
}

static void dfs(int n, int start_member, int link_member, int count) {
	if (n == count + 1) {
		if (num_len(start) == count / 2 && num_len(link) == count / 2) {
			//팀이 정해진 후 시너지 합 구하기
			start_sum = 0;
			link_sum = 0;
			for (int i = 0; i < n / 2; i++) {
				for (int j = i + 1; j < n / 2; j++) {
					int start_first = start[i];
					int start_second = start[j];

					start_sum += synergy[start_first][start_second] + synergy[start_second][start_first];

					int link_first = link[i];
					int link_second = link[j];

					link_sum += synergy[link_first][link_second] + synergy[link_second][link_first];
				}
			}
			minimum = my_min(minimum, my_abs(start_sum - link_sum));
		}
		return;
	}

	start[start_member] = n;
	dfs(n + 1, start_member + 1, link_member, count);
	start[start_member] = 0;

	link[link_member] = n;
	dfs(n + 1, start_member, link_member + 1, count);
	link[link_member] = 0;
}

int p14889(void) {
	int count;

	scanf_s("%d", &count);

	for (int i = 1; i <= count; i++) {
		for (int j = 1; j <= count; j++) {
			scanf_s("%d", &synergy[i][j]);
		}
	}

	dfs(1, 0, 0, count);

	printf("%d", minimum);

	return 0;
}