#include <iostream>

int p2869(void) {
	int v, a, b;
	int time = 0;

	scanf_s("%d%d%d", &a, &b, &v);

	//������ ������ ������ �ʿ䰡 �����Ƿ� v�� b�� ���ش�.
	time = (v - b) / (a - b);

	//������ �������� �ʴ´ٴ� ���� ���� �� �ö��� ���ߴٴ� ������ �Ϸ簡 �� �ʿ��ϴ�
	if ((v - b) % (a - b) != 0) {
		time += 1;
	}

	printf("%d", time);
	
	return 0;
}