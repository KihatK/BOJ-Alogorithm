#include <iostream>

//zero[81][2]는 0인 숫자가 입력될 때마다 차례로 들어가므로 첫번째 인덱스는 숫자 0의 개수, 두번째 인덱스는 0인 숫자의 x,y 위치를 뜻한다.

static int arr[9][9];
static int zero[81][2];
static int count = 0;

static bool validate(int row, int col, int cur) {
	int i, j;
	//가로줄 체크
	for (i = 0; i < 9; i++) {
		if (arr[row][i] == cur) return false;
	}
	//세로줄 체크
	for (i = 0; i < 9; i++) {
		if (arr[i][col] == cur) return false;
	}
	//정사각형 체크
	int square_row = row / 3;
	int square_col = col / 3;
	for (i = square_row * 3; i < square_row * 3 + 3; i++) {
		for (j = square_col * 3; j < square_col * 3 + 3; j++) {
			if (arr[i][j] == cur) return false;
		}
	}
	return true;
}

static void dfs(int n) {
	if (n == count) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		exit(0);
		return;
	}
	for (int i = 1; i <= 9; i++) {
		int x = zero[n][0];
		int y = zero[n][1];
		if (validate(x, y, i)) {
			arr[x][y] = i;
			dfs(n + 1);
			arr[x][y] = 0;
		}
	}
}

int p2580(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] == 0) {
				zero[count][0] = i;
				zero[count][1] = j;
				count++;
			}
		}
	}

	dfs(0);

	return 0;
}