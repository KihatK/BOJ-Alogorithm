#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

char word[11];

bool compare(int a, int b) {
	return a > b;
}

int p1427(void) {
	scanf_s("%s", word, sizeof(word));

	int size = strlen(word);

	sort(word, word + size, compare);

	printf("%s", word);

	return 0;
}