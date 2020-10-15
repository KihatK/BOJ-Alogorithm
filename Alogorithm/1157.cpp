#include <iostream>
#include <string.h>

int p1157(void) {
	char word[1000001];
	int alpha[26] = {0};
	int sum = 0;

	fgets(word, sizeof(word), stdin);

	int size = strlen(word);

	for (int i = 0; i < size; i++) {
		if (word[i] > 90) {
			word[i] = toupper(word[i]);
		}
	}

	//알파벳이 나올 때마다 그에 해당하는 인덱스 숫자 1개씩 올라감
	for (int i = 0; i < size; i++) {
		alpha[word[i] - 65]++;
	}

	char ch = sum + 65;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > alpha[sum]) {
			sum = i;
			ch = sum + 65;
		}
		else if (alpha[i] == alpha[sum] && i != 0) {
			ch = '?';
		}
	}

	putchar(ch);

	return 0;
}