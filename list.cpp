#include "list.h"

int List::insertNode(Data* newData) {

	Node* head = getHead();
	Node* tail = getTail();

	// 리스트에 데이터가 없을때
	if (head->getNext() == tail) {
		Node* newNode = new Node(head, tail, newData);
		countSize();
		head->setNext(newNode); tail->setPrev(newNode);
		return 0;
	}
	
	// 리스트에 데이터가 있을때
	else {
		Node* prevNewNode = tail->getPrev();
		Node* newNode = new Node(prevNewNode, tail, newData);
		countSize();
		prevNewNode->setNext(newNode); tail->setPrev(newNode);
		return 0;
	}

	return 1;
}

int List::markNode(Data* markData) {
	Node* mHead = getHead(); 
	Node* mTail = getTail();

	// m리스트에 데이터가 없을때
	if (mHead->getNext() == mTail) {
		Node* markNode = new Node(mHead, mTail, markData);
		mHead->setNext(markNode); mTail->setPrev(markNode);
		countSize();
		return 0;
	}
	else {
		Node* prevMarkNode = mTail->getPrev();
		Node* markNode = new Node(prevMarkNode, mTail, markData);
		prevMarkNode->setNext(markNode); mTail->setPrev(markNode);
		countSize();
		return 0;
	}

	return 1;
}

int List::unmarkNode(Data* unmarkData) {
	string unmarkPhone = unmarkData->getPhone();
	Node* mfindNode = findNodeByPhone(unmarkPhone);

	if (mfindNode == NULL) return 1;

	Node* prevFindNode = mfindNode->getPrev();
	Node* nextFindNode = mfindNode->getNext();

	prevFindNode->setNext(nextFindNode);
	nextFindNode->setPrev(prevFindNode);

	return 0;
}

Node* List::findNodeByPhone(string pPhone) {
	Node* head = getHead();
	Node* tail = getTail();
	Node* curr = getHead()->getNext();

	while (curr != tail) {
		string currPhone = curr->getData()->getPhone();
		if (currPhone == pPhone) {
			return curr;
		}
		curr = curr->getNext();
	}
	return NULL;
}

int List::findNodeByName(string pName) {
	Node* head = getHead();
	Node* tail = getTail();
	Node* curr = head->getNext();
	while (curr != tail) {
		string currName = curr->getData()->getName();
		string currPhone = curr->getData()->getPhone();

		if (currName == pName) {
			cout << currName; cout << ":"; cout << currPhone << endl;
		}
		curr = curr->getNext();
	}

	return 0;
}

int List::print() {
	Node* head = getHead();
	Node* tail = getTail();

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

int List::rmNode(Data* rmData) {
	string rmPhone = rmData->getPhone();
	Node* findNode = findNodeByPhone(rmPhone);

	if (findNode == NULL) return 1;
	
	Node* prevFindNode = findNode->getPrev();
	Node* nextFindNode = findNode->getNext();

	prevFindNode->setNext(nextFindNode);
	nextFindNode->setPrev(prevFindNode);

	delete findNode;

	return 0;
}