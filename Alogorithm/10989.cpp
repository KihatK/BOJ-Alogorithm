#include <iostream>

int p10989(void) {
	int count;
	int arr[10001] = { 0, };
	int num;
	int max = 0;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%d", &num);
		arr[num]++;
		if (max < num) {
			max = num;
		}
	}

	for (int i = 0; i <= max; i++) {
		for (int j = 0; j < arr[i]; j++) {
			printf("%d\n", i);
		}
	}

	return 0;
}