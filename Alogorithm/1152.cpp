#include <stdio.h>
#include <string.h>

int p1152(void) {
	char word[1000000];
	int num = 1;
	int size;

	fgets(word, sizeof(word), stdin);

	word[strlen(word) - 1] = '\0';

	size = strlen(word);

	if (word[0] == '\0') {
		printf("%d", 0);
		return 0;
	}

	for (int i = 0; i < size; i++) {
		if (word[i] == ' ') {
			num++;
		}
	}
	if (word[0] == ' ') {
		num--;
	}
	if (word[size - 1] == ' ') {
		num--;
	}

	printf("%d", num);

	return 0;
}