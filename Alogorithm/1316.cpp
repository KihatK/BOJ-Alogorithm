#include <iostream>
#include <string.h>

int p1316(void) {
	int count, size, sum = 0;
	char word[102];
	int alpha[26];

	scanf_s("%d", &count);
	fgetc(stdin);

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < 26; j++) {
			alpha[j] = 0;
		}
		fgets(word, sizeof(word), stdin);
		word[strlen(word) - 1] = '\0';
		size = strlen(word);

		for (int j = 0; j < size; j++) {
			if (word[j - 1] && word[j] != word[j - 1]) {
				if (alpha[word[j] - 'a'] > 0) {
					sum--;
					break;
				}
				else {
					alpha[word[j] - 'a'] += 1;
				}
			}
			else {
				alpha[word[j] - 'a'] += 1;
			}
		}
		sum++;
	}

	printf("%d", sum);

	return 0;
}