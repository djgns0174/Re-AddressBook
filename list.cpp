#include "list.h"

int insertNode(List* list, Data* newData) {

	Node* head = list->getHead();
	Node* tail = list->getTail();

	// 리스트에 데이터가 없을때
	if (head->getNext() == tail) {
		Node* newNode = new Node(head, tail, newData);
		list->countSize();
		head->setNext(newNode); tail->setPrev(newNode);
		return 0;
	}
	
	// 리스트에 데이터가 있을때
	else {
		Node* prevNewNode = tail->getPrev();
		Node* newNode = new Node(prevNewNode, tail, newData);
		list->countSize();
		prevNewNode->setNext(newNode); tail->setPrev(newNode);
		return 0;
	}

	return 1;
}

int markNode(List* list, List* mList, Data* markData) {
	Node* findNode = findNodeByPhone(list, markData->getPhone());
	if (findNode == NULL) return 1;

	Node* mHead = mList->getHead(); 
	Node* mTail = mList->getTail();

	// m리스트에 데이터가 없을때
	if (mHead->getNext() == mTail) {
		Node* markNode = new Node(mHead, mTail, markData);
		mHead->setNext(markNode); mTail->setPrev(markNode);
		mList->countSize();
		return 0;
	}
	else {
		Node* prevMarkNode = mTail->getPrev();
		Node* markNode = new Node(prevMarkNode, mTail, markData);
		prevMarkNode->setNext(markNode); mTail->setPrev(markNode);
		mList->countSize();
		return 0;
	}

	return 1;
}

int unmarkNode(List* mList, Data* unmarkData) {
	string unmarkPhone = unmarkData->getPhone();
	Node* mfindNode = findNodeByPhone(mList, unmarkPhone);

	if (mfindNode == NULL) return 1;

	Node* prevFindNode = mfindNode->getPrev();
	Node* nextFindNode = mfindNode->getNext();

	prevFindNode->setNext(nextFindNode);
	nextFindNode->setPrev(prevFindNode);

	return 0;
}

Node* findNodeByPhone(List* list, string pPhone) {
	Node* head = list->getHead();
	Node* tail = list->getTail();
	Node* curr = list->getHead()->getNext();

	while (curr != tail) {
		string currPhone = curr->getData()->getPhone();
		if (currPhone == pPhone) {
			return curr;
		}
		curr = curr->getNext();
	}
	return NULL;
}

int findNodeByName(List* list, string pName) {
	Node* head = list->getHead();
	Node* tail = list->getTail();
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

int printList(List* list) {
	Node* head = list->getHead();
	Node* tail = list->getTail();

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

int rmNode(List* list, List* mList, Data* rmData) {
	string rmPhone = rmData->getPhone();
	Node* findNode = findNodeByPhone(list, rmPhone);

	if (findNode == NULL) return 1;
	
	Node* prevFindNode = findNode->getPrev();
	Node* nextFindNode = findNode->getNext();

	prevFindNode->setNext(nextFindNode);
	nextFindNode->setPrev(prevFindNode);

	unmarkNode(mList, rmData);

	delete findNode;

	return 0;
}