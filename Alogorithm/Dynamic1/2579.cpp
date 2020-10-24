#include <iostream>

static int get_max(int a, int b) {
	return a > b ? a : b;
}

int p2579(void) {
	int num;
	int stair[300] = { 0, };
	int acc[300] = { 0, };

	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &stair[i]);
	}

	acc[0] = stair[0];
	acc[1] = get_max(stair[0] + stair[1], stair[1]);
	acc[2] = get_max(stair[1] + stair[2], stair[0] + stair[2]);

	for (int i = 3; i < num; i++) {
		acc[i] = get_max(acc[i - 3] + stair[i - 1] + stair[i], acc[i - 2] + stair[i]);
	}

	printf("%d", acc[num - 1]);
	
	return 0;
}