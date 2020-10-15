#include <stdio.h>
#include <string.h>

int p5622(void) {
	char alpha[17];
	int size;
	int sum = 0;

	fgets(alpha, sizeof(alpha), stdin);
	
	size = strlen(alpha);

	for (int i = 0; i < size-1; i++) {
		int time;
		if (alpha[i] == 'S' || alpha[i] == 'V') {
			time = (alpha[i] - 65) / 3 + 2;
		}
		else {
			time = (alpha[i] - 65) / 3 + 3 < 11 ? (alpha[i] - 65) / 3 + 3 : 10;
		}
		sum += time;
	}

	printf("%d", sum);

	return 0;
}