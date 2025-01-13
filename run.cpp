#include "run.h"
#include "manual.h"
#include "add.h"
#include "list.h"
#include "c.h"
#include "mark.h"
#include "find.h"
#include "rm.h"
#include "unmark.h"

int run(List* list, List* mList) {
	char input[64];

	printManual();
	
	while (1) {
		cout << "명령어를 입력해주세요:";
		cin >> input;

		if (strcmp(input, "add") == 0) {
			add(list);
			continue;
		}
		else if (strcmp(input, "mark") == 0) {
			mark(list, mList);
			continue;
		}
		else if (strcmp(input, "cmark") == 0) {
			c(mList);
			continue;
		}
		else if (strcmp(input, "unmark") == 0) {
			unmark(mList);
			continue;
		}
		else if (strcmp(input, "c") == 0) {
			c(list);
			continue;
		}
		else if (strcmp(input, "find") == 0) {
			find(list);
			continue;
		}
		else if (strcmp(input, "rm") == 0) {
			rm(list, mList);
			continue;
		}
		else if (strcmp(input, "exit") == 0) {
			break;
		}
		else {
			cout << "명령어를 잘못 입력했습니다." << endl;
			continue;
		}
	}

	return 0;
}