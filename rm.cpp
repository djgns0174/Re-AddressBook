#include"rm.h"
#include"list.h"

int rm(List* list, List* mList) {
	string input; string name; string phone;

	cout << "이름과 전화번호를 입력해주세요(홍길동:01012345678): ";
	cin >> input;

	stringstream ss(input);

	getline(ss, name, ':');
	getline(ss, phone, ':');

	Data* newData = new Data(name, phone);
	if (rmNode(list, mList, newData) == 0) {
		cout << "성공적으로 삭제되었습니다." << endl;
		return 0;
	}
	return 1;
}