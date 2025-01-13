#include "add.h"
#include "data.h"
#include "list.h"

int add(List* list) {
	string input; string name; string phone; 

	cout << "이름과 전화번호를 입력해주세요(홍길동:01012345678): ";
	cin >> input;

	stringstream ss(input);
	
	getline(ss, name, ':');
	getline(ss, phone, ':');

	Data* newData = new Data(name, phone);
	if (insertNode(list, newData) == 0) {
		cout << "성공적으로 저장되었습니다." << endl;
	}

	return 1;
}