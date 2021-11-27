#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };
	
	void showPostionInfo(int pos) {
		switch (pos) {
			case CLERK:
				cout<<"사원"<<endl;
				break;
			case SENIOR:
				cout<<"주임"<<endl;
				break;
			case ASSIST:
				cout<<"대리"<<endl;
				break;
			case MANAGER:
				cout<<"과장"<<endl;
				break;
		}
	}
}

class NameCard {
private:
	char * name;
	char * comName;
	char * phone;
	int position;
public:
	NameCard(const char * _name, const char * _comName, const char * _phone, int pos)
		: position(pos)
	{
		name = new char[strlen(_name) + 1];
		comName = new char[strlen(_comName) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);
		strcpy(comName, _comName);
		strcpy(phone, _phone);
	}
	NameCard(const NameCard &copy)
		: position(copy.position)
	{
		name = new char[strlen(copy.name) + 1];
		comName = new char[strlen(copy.comName) + 1];
		phone = new char[strlen(copy.phone) + 1];
		strcpy(name, copy.name);
		strcpy(comName, copy.comName);
		strcpy(phone, copy.phone);
	}
	void showNameCardInfo() const {
		cout<<"이름: "<<name<<endl;
		cout<<"회사: "<<comName<<endl;
		cout<<"전화번호: "<<phone<<endl;
		cout<<"직급: ";
		COMP_POS::showPostionInfo(position);
		cout<<endl;
	}
	~NameCard() {
		delete []name;
		delete []comName;
		delete []phone;
	}
};

int main(void) {

	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSenior;
	
	copy1.showNameCardInfo();
	copy2.showNameCardInfo();
	
	return 0;
}