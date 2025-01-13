#include "unmark.h"
#include "rm.h"

int unmark(List* mList) {
	string input; string name; string phone;

	cout << "이름과 전화번호를 입력해주세요(홍길동:01012345678): ";
	cin >> input;

	stringstream ss(input);

	getline(ss, name, ':');
	getline(ss, phone, ':');

	Data* unmarkData = new Data(name, phone);
	if (unmarkNode(mList, unmarkData) == 0) {
		cout << "즐찾 해제 완료했습니다." << endl;
		return 0;
	}

	return 1;
}