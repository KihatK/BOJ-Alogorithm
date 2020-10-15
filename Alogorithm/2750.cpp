#include <iostream>
#include <algorithm>

using namespace std;

int p2750(void) {
	int arr[1000000];
	int count;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%d", &arr[i]);
	}

	sort(arr, arr + count);

	for (int i = 0; i < count; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}