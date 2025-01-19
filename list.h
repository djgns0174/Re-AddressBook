#pragma once
#include<iostream>

#include "DataStructure.h"
#include "node.h"
#include "data.h"

class List :public DataStructure{
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

	int insertNode(Data* newData) override;
	int markNode(Data* markData)override;
	int unmarkNode(Data* unmarkData)override;
	Node* findNodeByPhone(string pPhone)override;
	int findNodeByName(string pName)override;
	int print()override;
	int rmNode(Data* rmData)override;
};