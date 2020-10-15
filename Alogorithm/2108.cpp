#include <iostream>
#include <algorithm>

using namespace std;

static int arr[500000];
static int mode[8001];

int p2108(void) {
	int count;
	int total = 0;
	int max = 0;
	int flag = 0;

	scanf_s("%d", &count);

	//숫자 입력받고 총합 더하기 + 최빈값 구하기 위해 계수 정렬처럼 나온 값 1씩 더하기
	for (int i = 0; i < count; i++) {
		scanf_s("%d", &arr[i]);
		total += arr[i];
		mode[arr[i] + 4000]++;
	}

	sort(arr, arr + count);

	//최빈값 몇번째 자리에 있는지 구하기
	for (int i = 0; i < 8001; i++) {
		if (mode[max] < mode[i]) {
			max = i;
		}
	}

	//최빈값이 2개 이상이 있다면 첫번째 최빈값 때 flag = 1을 하고 그 다음에 나오는 2번째 최빈값의 자리를 입력하기
	//최빈값이 1개면 그냥 통과
	for (int i = 0; i < 8001; i++) {
		if (flag == 1) {
			if (mode[max] == mode[i]) {
				max = i;
				break;
			}
		}
		else {
			if (mode[max] == mode[i]) {
				flag = 1;
			}
		}
	}

	//범위 구하기
	int diff = arr[count - 1] - arr[0] < 0 ? -(arr[count - 1] - arr[0]) : arr[count - 1] - arr[0];

	printf("%.lf\n", (double)total / (double)count);
	printf("%d\n", arr[count / 2]);
	printf("%d\n", max - 4000);
	printf("%d\n", diff);

	return 0;
}