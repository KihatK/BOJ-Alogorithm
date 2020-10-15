#include <stdio.h>
#include <string.h>

int p2908(void) {
	char a[4], b[4];

	scanf_s("%s %s", a, sizeof(a), b, sizeof(b));

	int size = strlen(a) - 1;

	for (int i = size; i >= 0; i--) {
		if (a[i] < b[i]) {
			for (int j = size; j >= 0; j--) {
				printf("%c", b[j]);
			}
			break;
		}
		else if (b[i] < a[i]) {
			for (int j = size; j >= 0; j--) {
				printf("%c", a[j]);
			}
			break;
		}
	}

	return 0;
}