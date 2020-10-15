#include <iostream>

int p2839(void) {
	int n;
	int num = 0;

	scanf_s("%d", &n);

	while (n > 0) {
		if (n % 5 == 0) {
			num++;
			n -= 5;
		}
		else if (n % 3 == 0) {
			num++;
			n -= 3;
		}
		else if (n > 5) {
			num++;
			n -= 5;
		}
		else {
			num = -1;
			break;
		}
	}

	printf("%d", num);

	return 0;
}