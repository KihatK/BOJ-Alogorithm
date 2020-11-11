#include <iostream>

using namespace std;

static int arr[10];
static int count_cur = 0;

static void greedy(int n, int k) {
	for (int i = n - 1; i >= 0; i--) {
		count_cur += k / arr[i];
		k = k % arr[i];
	}
}

int p11047(void) {
	int n, k;

	scanf_s("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf_s("%d", &arr[i]);
	}

	greedy(n, k);

	printf("%d", count_cur);

	return 0;
}