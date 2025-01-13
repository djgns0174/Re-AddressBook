#pragma once
#include<iostream>

#include "node.h"
#include "data.h"

class List {
private :
	Node* head;
	Node* tail;
	int size;

public:
	List() {
		this->head = new Node(nullptr, nullptr, nullptr);
		this->tail = new Node(head, nullptr, nullptr);
		this->head->setNext(tail);
		this->size = 0;
	}

	~List() {
		cout << "List 소멸자 호출" << endl;
		delete head;
		delete tail;
	};

	void setHead(Node* pHead) { this->head = pHead; }
	void setTail(Node* pTail) { this->tail = pTail; }
	void countSize() { this->size++; }
	Node* getHead() { return this->head; }
	Node* getTail() { return this->tail; }
	int getSize() { return this->size; }
};

int insertNode(List* list, Data* newData);
int markNode(List* list, List* mList, Data* markData);
int unmarkNode(List* mList, Data* unmarkData);
Node* findNodeByPhone(List* list, string pPhone);
int findNodeByName(List* list, string pName);
int printList(List* list);
int rmNode(List* list, List* mList, Data* rmData);