#include<string>
#include"eventHandler.h"


EventHandler::~EventHandler() {
	cout << "이벤트핸들러 소멸" << endl;
}

int EventHandler::run() {
	string input;

	ui->printManual();

	while (1) {
		cout << "명령어를 입력해주세요:";
		cin >> input;

		if (input == "add") {
			ui->add();
			continue;
		}
		else if (input == "mark") {
			ui->mark();
			continue;
		}
		else if (input == "cmark") {
			ui->printList(ui->getMDs());
			continue;
		}
		else if (input == "unmark") {
			ui->unmark();
			continue;
		}
		else if (input == "c") {
			ui->printList(ui->getDs());
			continue;
		}
		else if (input == "find") {
			ui->find();
			continue;
		}
		else if (input == "rm") {
			ui->rm();
			continue;
		}
		else if (input == "exit") {
			break;
		}
		else {
			cout << "명령어를 잘못 입력했습니다." << endl;
			continue;
		}
	}

	return 0;

}