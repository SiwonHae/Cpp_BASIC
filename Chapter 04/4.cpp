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
	NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.showNameCardInfo();
	manSenior.showNameCardInfo();
	manAssist.showNameCardInfo();
	
	return 0;
}