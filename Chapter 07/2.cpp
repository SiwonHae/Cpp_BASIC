#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo {
private:
	char * name;
	int age;
public:
	MyFriendInfo(const char * _name, int _age)
		: age(_age)
		{
			name = new char[strlen(_name) + 1];
			strcpy(name, _name);
		}
	void ShowMyFriendInfo() {
		cout<<"이름: "<<name<<endl;
		cout<<"나이: "<<age<<endl;
	}
	~MyFriendInfo() {
		delete []name;
	}
};

class MyFriendDetailInfo : public MyFriendInfo {
private:
	char * address;
	char * phone;
public:
	MyFriendDetailInfo(const char * _name, int _age, const char * _address, const char * _phone)
		: MyFriendInfo(_name, _age)
		{
			address = new char[strlen(_address) + 1];
			strcpy(address, _address);
			phone = new char[strlen(_phone) + 1];
			strcpy(phone, _phone);
		}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout<<"주소: "<<address<<endl;
		cout<<"전화: "<<phone<<endl;
	}
	~MyFriendDetailInfo() {
		delete []address;
		delete []phone;
	}
};

int main(void) {
	
	MyFriendDetailInfo frn("Hong", 21, "서울특별시", "010-1111-2222");
	
	frn.ShowMyFriendDetailInfo();

	return 0;
}