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

	//���� �Է¹ް� ���� ���ϱ� + �ֺ� ���ϱ� ���� ��� ����ó�� ���� �� 1�� ���ϱ�
	for (int i = 0; i < count; i++) {
		scanf_s("%d", &arr[i]);
		total += arr[i];
		mode[arr[i] + 4000]++;
	}

	sort(arr, arr + count);

	//�ֺ� ���° �ڸ��� �ִ��� ���ϱ�
	for (int i = 0; i < 8001; i++) {
		if (mode[max] < mode[i]) {
			max = i;
		}
	}

	//�ֺ��� 2�� �̻��� �ִٸ� ù��° �ֺ� �� flag = 1�� �ϰ� �� ������ ������ 2��° �ֺ��� �ڸ��� �Է��ϱ�
	//�ֺ��� 1���� �׳� ���
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

	//���� ���ϱ�
	int diff = arr[count - 1] - arr[0] < 0 ? -(arr[count - 1] - arr[0]) : arr[count - 1] - arr[0];

	printf("%.lf\n", (double)total / (double)count);
	printf("%d\n", arr[count / 2]);
	printf("%d\n", max - 4000);
	printf("%d\n", diff);

	return 0;
}