#pragma once
#include<string>
#include<sstream>
#include"list.h"
#include"data.h"
class UI {
private:
	DataStructure* ds;
	DataStructure* mds;
	Data* parseInputReturnData(string input) {
		string name; string phone;
		cout << "이름과 전화번호를 입력해주세요(홍길동:01012345678): ";
		cin >> input;

		stringstream ss(input);

		getline(ss, name, ':');
		getline(ss, phone, ':');
		Data* data = new Data(name, phone);

		return data;
	};
public:
	UI(DataStructure* pds, DataStructure* pmds);
	~UI();
	DataStructure* getDs() { return ds; }
	DataStructure* getMDs() { return mds; }

	int printList(DataStructure* pds);
	int add();
	int find();
	int printManual();
	int mark();
	int rm();
	int unmark();
};