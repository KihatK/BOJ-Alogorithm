#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int p11399(void) {
	int num;
	int waiting = 0;

	scanf_s("%d", &num);

	vector<int> arr(num, 0);
	vector<int> sum(num, 0);

	for (int i = 0; i < num; i++) {
		scanf_s("%d", &arr[i]);
	}

	sort(arr.begin(), arr.end());

	sum[0] = arr[0];
	waiting += arr[0];

	for (int i = 1; i < num; i++) {
		sum[i] = sum[i - 1] + arr[i];
		waiting += sum[i];
	}

	printf("%d", waiting);

	return 0;
}