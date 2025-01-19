#include "eventHandler.h"
#include "UI.h"
#include "DataStructure.h"
#include "list.h"

int main() {
	DataStructure* list = new List();
	DataStructure* mlist = new List();


	UI* ui = new UI(list, mlist);
	EventHandler* eh = new EventHandler(ui);
	eh->run();
}

/*
Parent* list = new List();
Parent* tree = new Tree();

UI* ui1 = new UI(list, mlist); -> 자료구조 list 사용
UI* ui2 = new UI(tree, mtree); -> 자료구조 tree 사용

EventHandler* eh = new EventHandler(ui1 or ui2);
*/