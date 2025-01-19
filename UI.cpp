#include<string>
#include<sstream>
#include "UI.h"

UI::UI(DataStructure* pds, DataStructure* pmds) {
	ds = pds;
	mds = pmds;
}

UI::~UI() {
	cout << "UI 소멸자 호출" << endl;
}

int UI::printList(DataStructure* pds) {
	Node* head = ((List*)pds)->getHead();
	Node* tail = ((List*)pds)->getTail();

	Node* curr = head->getNext();
	if (curr == NULL) return 1;

	while (curr != tail) {
		string currName = curr->getData()->getName();
		string currPhone = curr->getData()->getPhone();

		cout << currName; cout << ":"; cout << currPhone << endl;

		curr = curr->getNext();
	}

	return 0;
}

int UI::add() {
	string input;
	Data* data = parseInputReturnData(input);
	if (ds->insertNode(data) == 0) {
		cout << "성공적으로 저장되었습니다." << endl;
	}

	return 1;
}

int UI::find() {
	string name;
	cout << "이름을 입력해주세요:";
	cin >> name;
	ds->findNodeByName(name);
	return 0;
}

int UI::printManual() {
	cout << "==============================================================================================================\n\n" << endl;
	cout << "명령어 매뉴얼\n저장:add  즐겨찾기:mark  즐겨찾기 목록:cmark  즐겨찾기 해제:unmark  모든목록:c  검색:find  삭제:rm  종료:exit\n\n" << endl;
	cout << "==============================================================================================================\n\n" << endl;

	return 0;
}

int UI::mark() {
	string input;
	Data* data = parseInputReturnData(input);
	string dataPhone = data->getPhone();
	if (ds->findNodeByPhone(dataPhone) != NULL) {
		if (mds->markNode(data) == 0) {
			cout << "즐겨찾기를 완료했습니다." << endl;
		}
	}

	return 1;
}

int UI::rm() {
	string input;
	Data* data = parseInputReturnData(input);
	if (ds->rmNode(data) == 0 && mds->unmarkNode(data) == 0) {
		cout << "성공적으로 삭제되었습니다." << endl;
		return 0;
	}
	return 1;
}

int UI::unmark() {
	string input; 
	Data* data = parseInputReturnData(input);
	if (mds->unmarkNode(data) == 0) {
		cout << "즐찾 해제 완료했습니다." << endl;
		return 0;
	}

	return 1;
}