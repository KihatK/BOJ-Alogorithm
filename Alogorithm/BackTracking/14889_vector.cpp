#include <iostream>
#include <vector>
#include <climits>

using namespace std;

static vector<int> start, link;

static int synergy[21][21];
static int result = INT_MAX;
static int start_sum = 0;
static int link_sum = 0;

static int my_abs(int &&a) {
	return a >= 0 ? a : -a;
}
static int min(int a, int b) {
	return a > b ? b : a;
}

static void dfs(int person, int number) {
	if (person == number + 1) {
		if (start.size() == number / 2 && link.size() == number / 2) {
			start_sum = 0;
			link_sum = 0;
			for (int i = 0; i < number / 2; i++) {
				for (int j = i + 1; j < number / 2; j++) {
					int start_first = start[i];
					int start_second = start[j];

					start_sum += synergy[start_first][start_second] + synergy[start_second][start_first];

					int link_first = link[i];
					int link_second = link[j];

					link_sum += synergy[link_first][link_second] + synergy[link_second][link_first];
				}
			}
			result = min(result, my_abs(start_sum - link_sum));
		}
		return;
	}

	start.push_back(person);
	dfs(person + 1, number);
	start.pop_back();

	link.push_back(person);
	dfs(person + 1, number);
	link.pop_back();
}

int p14889_vector(void) {
	int number;

	scanf_s("%d", &number);

	for (int i = 1; i <= number; i++) {
		for (int j = 1; j <= number; j++) {
			scanf_s("%d", &synergy[i][j]);
		}
	}

	dfs(1, number);

	printf("%d", result);

	return 0;
}