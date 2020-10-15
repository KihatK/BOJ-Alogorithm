#include <iostream>

int p2869(void) {
	int v, a, b;
	int time = 0;

	scanf_s("%d%d%d", &a, &b, &v);

	//마지막 날에는 내려갈 필요가 없으므로 v에 b를 빼준다.
	time = (v - b) / (a - b);

	//나누어 떨어지지 않는다는 것은 아직 다 올라가지 못했다는 뜻으로 하루가 더 필요하다
	if ((v - b) % (a - b) != 0) {
		time += 1;
	}

	printf("%d", time);
	
	return 0;
}