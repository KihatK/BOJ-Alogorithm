#include <iostream>
#include <algorithm>

using namespace std;

struct member {
	char name[101];
	int age;
	int createdAt;
};

static member arr[100000];

bool compare(member a, member b) {
	if (a.age == b.age) {
		return a.createdAt < b.createdAt;
	}
	return a.age < b.age;
}

int p10814(void) {
	int count;

	scanf_s("%d", &count);
	
	for (int i = 0; i < count; i++) {
		scanf_s("%d %s", &arr[i].age, arr[i].name, sizeof(arr[0].name));
		arr[i].createdAt = i;
	}

	sort(arr, arr + count, compare);

	for (int i = 0; i < count; i++) {
		printf("%d %s\n", arr[i].age, arr[i].name);
	}

	return 0;
}