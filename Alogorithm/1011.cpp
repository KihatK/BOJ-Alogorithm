#include <iostream>
#include <cmath>

int p1011(void) {
	int count;
	double start, end;
	long long a;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%lf %lf", &start, &end);
		int diff = end - start;
		a = (int)sqrt(diff);

		if (diff == a * a) {
			printf("%lld\n", a * 2 - 1);
		}
		else if (a * a < diff && diff <= a * a + a) {
			printf("%lld\n", a * 2);
		}
		else if (a * a + a < diff && diff < (a + 1) * (a + 1)) {
			printf("%lld\n", a * 2 + 1);
		}
	}

	return 0;
}