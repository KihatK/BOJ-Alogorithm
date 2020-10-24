#include <iostream>

static int arr[10001];
static int acc[10001];

static int get_max(int a, int b, int c) {
	if (b > c) {
		return a > b ? a : b;
	}
	else {
		return a > c ? a : c;
	}
}

int p2156(void) {
	int count;

	scanf_s("%d", &count);

	for (int i = 1; i <= count; i++) {
		scanf_s("%d", &arr[i]);
	}

	acc[1] = arr[1];
	acc[2] = arr[1] + arr[2];

	//i-3까지의 최댓값 + i-1번째 포도주 + i번째 포도주,
	//i-2까지의 최댓값 + i번째 포도주,
	//i-1까지의 최대값 중에서 가장 큰 값을 고르기
	for (int i = 3; i <= count; i++) {
		acc[i] = get_max(acc[i - 3] + arr[i - 1] + arr[i], acc[i - 2] + arr[i], acc[i - 1]);
	}

	printf("%d", acc[count]);

	return 0;
}