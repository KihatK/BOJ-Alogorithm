#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

struct word {
	char ch[51];
	int len;
};

static word arr[20000];

bool compare(word a, word b) {
	if (a.len == b.len) {
		for (int i = 0; i < a.len; i++) {
			if (a.ch[i] == b.ch[i]) continue;
			else if (a.ch[i] < b.ch[i]) return true;
			else return false;
		}
	}
	return a.len < b.len;
}

int p1181(void) {
	int count;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%s", arr[i].ch, sizeof(arr[0].ch));
		arr[i].len = strlen(arr[i].ch);
	}

	sort(arr, arr + count, compare);

	for (int i = 0; i < count; i++) {
		if (i != 0) {
			if (!strcmp(arr[i].ch, arr[i - 1].ch)) {
				continue;
			}
		}
		printf("%s\n", arr[i].ch);
	}

	return 0;
}