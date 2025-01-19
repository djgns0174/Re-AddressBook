#pragma once
#include"node.h"

class DataStructure {
public:
	DataStructure() {};
	~DataStructure() {};
	virtual int insertNode(Data* newData) { return 0; };
	virtual int markNode(Data* markData) { return 0; };
	virtual int unmarkNode(Data* unmarkData) { return 0; };
	virtual Node* findNodeByPhone(string pPhone) { return NULL; };
	virtual int findNodeByName(string pName) { return 0; };
	virtual int print() { return 0; };
	virtual int rmNode(Data* rmData) { return 0; };
};