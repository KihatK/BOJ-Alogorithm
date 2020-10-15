#include <iostream>

int p1193(void) {
	int n;
	int count = 0;
	int start = 0;
	int remain;
	int parent, child;

	scanf_s("%d", &n);

	int sum = n;

	while (n > 0) {
		count++;
		n -= count;
		start += count;
	}

	if (count % 2 == 0) {
		remain = start - sum;
		parent = 1 + remain;
		child = count - remain;
	}
	else {
		remain = start - sum;
		child = 1 + remain;
		parent = count - remain;
	}

	printf("%d/%d", child, parent);

	return 0;
}