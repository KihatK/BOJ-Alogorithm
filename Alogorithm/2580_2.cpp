#include <iostream>

//0�� �ִ� �ε����� ������, ������, ���簢���� �����ϴ� ���ڵ��� true�� �ؼ� 1~9 �ݺ����� ���� false�� ���� �ش� ���ڸ� ä��
//�� ���� ��츸 ����ؾ� �ϹǷ� exit(0)�� ����� ��
//check_row[9][10]���� ù��° �ε����� ���° ������, �ι�° �ε����� 1~9������ ������ ���������� ���� true, false�� ��Ÿ�� ���̴�.

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