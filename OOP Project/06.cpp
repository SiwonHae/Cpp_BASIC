/*
Banking System Ver 0.6
내용 : 이자관련 계좌 클래스의 추가
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_COUNT = 100; // 최대 개설 가능한 계좌 수
const int NAME_LEN = 20; // 이름의 최대 길이

enum {
	LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2
};

/*
클래스 이름: Account
클래스 유형: Entity 클래스
*/
class Account {
private:
	int accountId;
	char * customerName;
	int currentMoney;
public:
	Account(int id, const char * name, int money);
	Account(const Account &copy);
	
	int getCustomerID() const;
	void depositAct(int money);
	int withdrawAct(int money);
	void showActInfo() const;
	~Account();
};

Account::Account(int id, const char * name, int money) 
	: accountId(id), currentMoney(money)
	{
		customerName = new char[strlen(name) + 1];
		strcpy(customerName, name);
	}
	
Account::Account(const Account &copy)
	: accountId(copy.accountId), currentMoney(copy.currentMoney)
	{
		customerName = new char[strlen(copy.customerName) + 1];
		strcpy(customerName, copy.customerName);
	}

int Account::getCustomerID() const {
	return accountId;
}
	
void Account::depositAct(int money) {
	currentMoney += money;
}
	
int Account::withdrawAct(int money) { // 출금 잔액 부족 시 0을 반환
	if (currentMoney < money) {
		return 0;
	}
		
	currentMoney -= money;
	return money;
}
	
void Account::showActInfo() const {
	cout<<"계좌ID: "<<accountId<<endl;
	cout<<"이 름: "<<customerName<<endl;
	cout<<"잔 액: "<<currentMoney<<endl<<endl;
}
	
Account::~Account() {
	delete []customerName;
}

/*
클래스 이름: NormalAccount
클래스 유형: Entity 클래스
*/

class NormalAccount : public Account {
private:
	int interRate; // 이자율
public:
	NormalAccount(int id, const char * name, int initialMoney, int rate)
		: Account(id, name, initialMoney), interRate(rate) {}
	virtual void depositAct(int money) {
		Account::depositAct(money); // 원금 추가
		Account::depositAct(money * (interRate / 100.0)); // 이자 추가
	}
};

/*
클래스 이름: HighCreditAccount
클래스 유형: Entity 클래스
*/

class HighCreditAccount : public NormalAccount {
private:
	int specialRate; // 이자율
public:
	HighCreditAccount(int id, const char * name, int initialMoney, int rate, int special)
		: NormalAccount(id, name, initialMoney, rate), specialRate(special) {}
	virtual void depositAct(int money) {
		NormalAccount::depositAct(money); // 원금과 이자 추가
		Account::depositAct(money * (specialRate / 100.0)); // 특별이자 추가
	}
};

/*
클래스 이름: AccountHandler
클래스 유형: 컨트롤(Control) 클래스
*/

class AccountHandler {
private:
	Account * customer[MAX_COUNT]; // 계좌 정보 저장 배열
	int currentActCount = 0; // 개설된 계좌 수
public:
	AccountHandler();
	void showMenu() const;
	void makeAccount();
	void deposit();
	void withdraw();
	void printAllAcount() const;
	
	void MakeNormalAccount();
	void MakeCreditAccount();
	
	~AccountHandler();
};

AccountHandler::AccountHandler()
	: currentActCount(0) {}

void AccountHandler::showMenu() const {
	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void AccountHandler::makeAccount() {
	int select;
	cout<<"[계좌종류선택]"<<endl;
	cout<<"1. 보통예금계좌 2.신용신뢰계좌"<<endl;
	cout<<"선택: ";
	cin>>select;
	
	if (select == 1) {
		MakeNormalAccount();
	} else if (select == 2) {
		MakeCreditAccount();
	} else {
		cout<<"잘못 선택하셨습니다."<<endl;
	}
}

void AccountHandler::MakeNormalAccount() {
	int id;
	char name[NAME_LEN];
	int initialMoney;
	int interRate; // 이자율
	
	cout<<"[보통예금계좌 개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"이 름: ";
	cin>>name;
	cout<<"입금액: ";
	cin>>initialMoney;
	cout<<"이자율: ";
	cin>>interRate;
	cout<<endl;
	
	customer[currentActCount++] = new NormalAccount(id, name, initialMoney, interRate);
}

void AccountHandler::MakeCreditAccount() {
	int id;
	char name[NAME_LEN];
	int initialMoney;
	int interRate; // 이자율
	int creditLevel; // 신용등급
	
	cout<<"[신용신뢰계좌 개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"이 름: ";
	cin>>name;
	cout<<"입금액: ";
	cin>>initialMoney;
	cout<<"이자율: ";
	cin>>interRate;
	cout<<"신용등급(1 to A, 2 to B, 3 to C): ";
	cin>>creditLevel;
	cout<<endl;
	
	switch(creditLevel) {
		case 1:
			customer[currentActCount++] = new HighCreditAccount(id, name, initialMoney, interRate, LEVEL_A);
		case 2:
			customer[currentActCount++] = new HighCreditAccount(id, name, initialMoney, interRate, LEVEL_B);
		case 3:
			customer[currentActCount++] = new HighCreditAccount(id, name, initialMoney, interRate, LEVEL_C);
	}
}

void AccountHandler::deposit() {
	int id;
	int depositMoney;
	
	cout<<"[입 금]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"입금액: ";
	cin>>depositMoney;
	
	for (int i = 0; i < currentActCount; i++) {
		if (customer[i]->getCustomerID() == id) {
			customer[i]->depositAct(depositMoney);
			cout<<"입금완료"<<endl<<endl;
			return;
		}
	}
	
	cout<<"유효하지 않은 계좌ID 입니다."<<endl<<endl;
}

void AccountHandler::withdraw() {
	int id;
	int withdrawMoney;
	
	cout<<"[출 금]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"출금액: ";
	cin>>withdrawMoney;
	
	for (int i = 0; i < currentActCount; i++) {
		if (customer[i]->getCustomerID() == id) {
			if (customer[i]->withdrawAct(withdrawMoney) == 0) {
				cout<<"잔액이 부족합니다."<<endl<<endl;
				return;
			}
			cout<<"출금완료"<<endl<<endl;
			return;
		}
	}
	
	cout<<"유효하지 않은 계좌ID 입니다."<<endl<<endl;
}

void AccountHandler::printAllAcount() const {
	cout<<"[계좌정보 전체 출력]"<<endl;
	
	for (int i = 0; i < currentActCount; i++) {
		customer[i]->showActInfo();
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < currentActCount; i++) {
		delete []customer[i];
	}
}

/*
컨트롤 클래스 AccountHandler를 중심으로 변경된 main 함수
*/
int main(void) {
	AccountHandler manager;
	int select;
	
	while (1) {
		manager.showMenu();
		cout<<"선택: ";
		cin>>select;
		cout<<endl;
		
		if (select == 5) {
			cout<<"프로그램을 종료합니다."<<endl;
			break;
		}
		
		switch (select) {
			case 1:
				manager.makeAccount();
				break;
			case 2:
				manager.deposit();
				break;
			case 3:
				manager.withdraw();
				break;
			case 4:
				manager.printAllAcount();
				break;
			default:
				cout<<"잘못된 입력!"<<endl;
		}
		
	}
	
	return 0;
}