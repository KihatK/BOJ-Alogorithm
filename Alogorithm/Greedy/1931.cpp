#include <iostream>
#include <algorithm>

using namespace std;

static struct Meeting {
	int start;
	int end;
};

static Meeting arr[100000];

static bool compare(Meeting a, Meeting b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

int p1931(void) {
	int num;
	int count = 0;

	scanf_s("%d", &num);

	for (int i = 0; i < num; i++) {
		scanf_s("%d %d", &arr[i].start, &arr[i].end);
	}

	sort(arr, arr + num, compare);

	int minNum = 0;

	for (int i = 0; i < num; i++) {
		if (arr[i].start >= minNum) {
			count++;
			minNum = arr[i].end;
		}
	}

	printf("%d", count);

	return 0;
}