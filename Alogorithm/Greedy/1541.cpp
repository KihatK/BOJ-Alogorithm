#include <iostream>
#include <string.h>

int p1541(void) {
	char str[51];
	int arr[25] = { 0, };
	int len;
	int temp = 0;
	int sum = 0;
	int j = 0;
	int answer = 0;

	scanf_s("%s", str, sizeof(str));

	len = strlen(str);

	for (int i = 0; i < len; i++) {
		if (str[i] == '-') {
			sum += temp;
			arr[j] = sum;
			j++;
			temp = 0;
			sum = 0;
		}
		else if (str[i] == '+') {
			sum += temp;
			temp = 0;
		}
		else {
			temp *= 10;
			temp += (str[i] - '0');
		}
	}

	sum += temp;
	arr[j] = sum;

	answer = arr[0];
	for (int i = 1; i < 25; i++) {
		answer -= arr[i];
	}

	printf("%d", answer);

	return 0;
}