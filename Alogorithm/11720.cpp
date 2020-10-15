#include <iostream>

int p11720(void) {
	int count;
	int i, sum = 0;
	char num[101];

	scanf_s("%d", &count);
	scanf_s("%s", num, 101);
	for (i = 0; i < count; i++) {
		sum += num[i] - 48;
	}

	printf("%d", sum);

	return 0;
}