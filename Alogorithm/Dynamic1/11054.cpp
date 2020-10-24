#include <iostream>

int p11054(void) {
	int count;
	int max = 0;

	int arr[1001] = { 0, };
	int dp_inc[1001] = { 0, };
	int dp_dec[1001] = { 0, };

	scanf_s("%d", &count);

	for (int i = 1; i <= count; i++) {
		scanf_s("%d", &arr[i]);
	}

	//오름차순
	for (int i = 1; i <= count; i++) {
		int maxA = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (maxA < dp_inc[j]) {
					maxA = dp_inc[j];
				}
			}
		}
		dp_inc[i] = maxA + 1;
	}

	//내림차순
	for (int i = count; i >= 1; i--) {
		int maxA = 0;
		for (int j = count; j > i; j--) {
			if (arr[i] > arr[j]) {
				if (maxA < dp_dec[j]) {
					maxA = dp_dec[j];
				}
			}
		}
		dp_dec[i] = maxA + 1;
	}

	for (int i = 1; i <= count; i++) {
		if (max < dp_inc[i] + dp_dec[i]) {
			max = dp_inc[i] + dp_dec[i];
		}
	}

	printf("%d", max - 1);

	return 0;
}