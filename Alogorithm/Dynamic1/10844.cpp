#include <iostream>

int p10844(void) {
	int n;
	long long count = 0;

	//ù��° �ε����� ���ڸ�����(n), �ι�° �ε����� ���� �ڸ��� ��
	long long stair_num[101][11] = { 0, };

	for (int i = 1; i < 10; i++) {
		stair_num[1][i] = 1;
	}

	scanf_s("%d", &n);

	for (int i = 2; i <= n; i++) {
		stair_num[i][0] = stair_num[i-1][1];
		for (int j = 1; j < 10; j++) {
			stair_num[i][j] = (stair_num[i - 1][j - 1] + stair_num[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i < 10; i++) {
		count += stair_num[n][i];
	}

	printf("%lld", count % 1000000000);

	return 0;
}