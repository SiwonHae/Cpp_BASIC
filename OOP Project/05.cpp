/*
Banking System Ver 0.5
내용 : 컨트롤 클래스 적용
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_COUNT = 100; // 최대 개설 가능한 계좌 수
const int NAME_LEN = 20; // 이름의 최대 길이

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
	int id;
	char name[NAME_LEN];
	int initialMoney;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌ID: ";
	cin>>id;
	cout<<"이 름: ";
	cin>>name;
	cout<<"입금액: ";
	cin>>initialMoney;
	cout<<endl;
	
	customer[currentActCount] = new Account(id, name, initialMoney);
	currentActCount++;
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