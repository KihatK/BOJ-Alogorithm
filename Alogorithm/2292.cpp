#include <iostream>

int p2292(void) {
	int n;
	int time = 0;
	int sum = 1;

	scanf_s("%d", &n);

	while (n > sum) {
		if (n == 1) {
			printf("1");
		}
		else {
			time++;
			sum = sum + 6 * time;
		}
	}

	printf("%d", time+1);

	return 0;
}