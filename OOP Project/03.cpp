/*
Banking System Ver 0.3
내용 : Account 클래스에 깊은 복사를 진행하는 복사 생성자 정의
*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_COUNT = 100; // 최대 개설 가능한 계좌 수
const int NAME_LEN = 20; // 이름의 최대 길이

void showMenu(void);
void makeAccount(void);
void deposit(void);
void withdraw(void);
void printAllAcount(void);

class Account {
private:
	int accountId;
	char * customerName;
	int currentMoney;
public:
	Account (int id, char * name, int money) 
		: accountId(id), currentMoney(money)
	{
		customerName = new char[strlen(name) + 1];
		strcpy(customerName, name);
	}
	
	Account (const Account &copy)
		: accountId(copy.accountId), currentMoney(copy.currentMoney)
	{
		customerName = new char[strlen(copy.customerName) + 1];
		strcpy(customerName, copy.customerName);
	}
	
	int getCustomerID() {
		return accountId;
	}
	
	void depositAct(int money) {
		currentMoney += money;
	}
	
	int withdrawAct(int money) { // 출금 잔액 부족 시 0을 반환
		if (currentMoney < money) {
			return 0;
		}
		
		currentMoney -= money;
		return money;
	}
	
	void showActInfo() const {
		cout<<"계좌ID: "<<accountId<<endl;
		cout<<"이 름: "<<customerName<<endl;
		cout<<"잔 액: "<<currentMoney<<endl<<endl;
	}
	
	~Account() {
		delete []customerName;
	}
};

Account * customer[MAX_COUNT]; // 계좌 정보 저장 배열
int currentActCount = 0; // 개설된 계좌 수

int main(void) {
	int select;
	
	while (1) {
		showMenu();
		cout<<"선택: ";
		cin>>select;
		cout<<endl;
		
		if (select == 5) {
			cout<<"프로그램을 종료합니다."<<endl;
			break;
		}
		
		switch (select) {
			case 1:
				makeAccount();
				break;
			case 2:
				deposit();
				break;
			case 3:
				withdraw();
				break;
			case 4:
				printAllAcount();
				break;
			default:
				cout<<"잘못된 입력!"<<endl;
		}
		
	}
	
	return 0;
}

void showMenu(void) {
	cout<<"-----Menu-----"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void makeAccount(void) {
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

void deposit(void) {
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

void withdraw(void) {
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

void printAllAcount(void) {
	cout<<"[계좌정보 전체 출력]"<<endl;
	
	for (int i = 0; i < currentActCount; i++) {
		customer[i]->showActInfo();
	}
}