#include"list.h"
#include "find.h"

int find(List* list) {
	string name;
	cout << "이름을 입력해주세요:";
	cin >> name;
	findNodeByName(list, name);
	return 0;
}