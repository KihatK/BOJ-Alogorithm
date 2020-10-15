#include <iostream>
#include <climits>

static int arr_num[11];
static int arr_calc[4];

static int max = INT_MIN;
static int min = INT_MAX;

static void dfs(int plus, int minus, int multiple, int division, int n, int sum, int count) {
	if (n == count) {
		//최대값, 최소값 비교
		if (max < sum) {
			max = sum;
		}
		if (min > sum) {
			min = sum;
		}
	}
	
	if (plus) {  //더하기가 있으면
		dfs(plus - 1, minus, multiple, division, n + 1, sum + arr_num[n], count);
	}
	if (minus) {  //빼기가 있으면
		dfs(plus, minus - 1, multiple, division, n + 1, sum - arr_num[n], count);
	}
	if (multiple) {  //곱하기가 있으면
		dfs(plus, minus, multiple - 1, division, n + 1, sum * arr_num[n], count);
	}
	if (division) {  //나누기가 있으면
		dfs(plus, minus, multiple, division - 1, n + 1, sum / arr_num[n], count);
	}
}

int p14888(void) {
	int count;

	scanf_s("%d", &count);

	for (int i = 0; i < count; i++) {
		scanf_s("%d", &arr_num[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf_s("%d", &arr_calc[i]);
	}

	dfs(arr_calc[0], arr_calc[1], arr_calc[2], arr_calc[3], 1, arr_num[0], count);

	printf("%d\n", max);
	printf("%d\n", min);

	return 0;
}