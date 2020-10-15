#include <iostream>
#include <string.h>

int p10809(void) {
	char word[101];
	int alpha[26], size;

	for (int i = 0; i < 26; i++) {
		alpha[i] = -1;
	}

	scanf_s("%s", word, 101);

	size = strlen(word);

	for (int i = 0; i < size; i++) {
		char ch = word[i] - 97;
		if (alpha[ch] == -1) {
			alpha[ch] = i;
		}
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", alpha[i]);
	}

	return 0;
}