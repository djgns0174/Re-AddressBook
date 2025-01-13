#include"mark.h"

int mark(List* list, List* mList) {
	string input; string name; string phone;

	cout << "이름과 전화번호를 입력해주세요(홍길동:01012345678): ";
	cin >> input;

	stringstream ss(input);

	getline(ss, name, ':');
	getline(ss, phone, ':');

	Data* newData = new Data(name, phone);
	if (markNode(list, mList, newData) == 0) {
		cout << "즐겨찾기를 완료했습니다." << endl;
	}

	return 1;
}