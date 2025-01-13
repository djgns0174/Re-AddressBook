#pragma once
#include <string>
#include <iostream>

using namespace std;
class Data {

	private :
		string name;
		string phone;

	public:
		Data(const string pName, const string pPhone) : name(pName), phone(pPhone){};
		~Data() {
			cout << "Data 소멸자 호출" << endl;
		};

		void setName(const string& pName) { this->name = pName; }
		void setPhone(const string& pPhone) { this->phone = pPhone; }
		string getName() { return this->name; }
		string getPhone() { return this->phone; }

};