#include <iostream>

int p2675(void) {
	int count, num;
	char string[21];

	char* p;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		p = string;
		scanf_s("%d %s", &num, string, 21);
		while (*p != '\0') {
			for (int j = 0; j < num; j++) {
				printf("%c", *p);
			}
			p++;
		}
		printf("\n");
	}

	return 0;
}