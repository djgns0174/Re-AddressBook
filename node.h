#pragma once
#include<iostream>

#include"data.h"

class Node {
private:
	Node* prev;
	Node* next;
	Data* data;
public:
	Node() { 
		this->prev = nullptr; 
		this->next = nullptr;
		this->data = nullptr;
	};
	Node(Node* pPrev, Node* pNext, Data* pData) : prev(pPrev), next(pNext), data(pData) {};
	~Node() {
		cout << "Node 소멸자 호출" << endl;
	}
	void setNext(Node* pNext) {this->next = pNext;}
	void setPrev(Node* pPrev) { this->prev = pPrev; }
	void setData(Data* pData) { this->data = pData; }
	Node* getNext() { return this->next;}
	Node* getPrev() { return this->prev; }
	Data* getData() { return this->data; }
};