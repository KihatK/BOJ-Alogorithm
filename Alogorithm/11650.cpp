#include <iostream>
#include <algorithm>

using namespace std;

struct loc {
	int x;
	int y;
};

loc arr[100000];

bool compareX(loc a, loc b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}

int p11650(void) {
	int count;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%d %d", &arr[i].x, &arr[i].y);
	}

	sort(arr, arr + count, compareX);

	for (int i = 0; i < count; i++) {
		printf("%d %d\n", arr[i].x, arr[i].y);
	}

	return 0;
}