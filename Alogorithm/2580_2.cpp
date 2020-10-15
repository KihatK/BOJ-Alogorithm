#include <iostream>

//0이 있는 인덱스의 가로줄, 세로줄, 정사각형에 존재하는 숫자들을 true로 해서 1~9 반복문을 돌려 false일 때만 해당 숫자를 채움
//한 가지 경우만 출력해야 하므로 exit(0)을 해줘야 함
//check_row[9][10]에서 첫번째 인덱스는 몇번째 줄인지, 두번째 인덱스는 1~9까지의 숫자의 존재유무에 따른 true, false로 나타낸 것이다.

int arr[9][9];
bool check_row[9][10];
bool check_col[9][10];
bool check_square[9][10];

static void dfs(int row, int col) {
	if (row == 9) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}
	
	if (arr[row][col] != 0) {
		col == 8 ? dfs(row + 1, 0) : dfs(row, col + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			if (check_row[row][i] || check_col[col][i] || check_square[((row / 3) * 3) + (col / 3)][i]) {
				continue;
			}
			arr[row][col] = i;
			check_row[row][i] = true;
			check_col[col][i] = true;
			check_square[((row / 3) * 3) + (col / 3)][i] = true;
			col == 8 ? dfs(row + 1, 0) : dfs(row, col + 1);
			arr[row][col] = 0;
			check_row[row][i] = false;
			check_col[col][i] = false;
			check_square[((row / 3) * 3) + (col / 3)][i] = false;
		}
	}
}

int p2580_2(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] != 0) {
				check_row[i][arr[i][j]] = true;
				check_col[j][arr[i][j]] = true;
				check_square[((i / 3) * 3) + (j / 3)][arr[i][j]] = true;
			}
		}
	}

	dfs(0, 0);

	return 0;
}