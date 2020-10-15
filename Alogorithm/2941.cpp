#include <iostream>
#include <string.h>

int p2941(void) {
	char word[102];
	int num = 0;
	int size;

	fgets(word, sizeof(word), stdin);
	word[strlen(word) - 1] = '\0';

	size = strlen(word);

	for (int i = 0; i < size; i++) {
		if (word[i] == '=' || word[i] == '-') {
			if (word[i - 1] && word[i - 1] == 'z') {
				if (word[i - 2] && word[i - 2] == 'd') {
					num--;
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}
		}
		else if (word[i] == 'j') {
			if (word[i - 1] && (word[i - 1] == 'l' || word[i - 1] == 'n')) {
				continue;
			}
			else {
				num++;
			}
		}
		else {
			num++;
		}
	}

	printf("%d", num);

	return 0;
}