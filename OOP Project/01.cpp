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

typedef struct account {
	int accountId;
	char customerName[NAME_LEN];
	int currentMoney;
} Account;

Account customer[MAX_COUNT]; // 계좌 정보 저장 배열
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
	
	customer[currentActCount].accountId = id;
	customer[currentActCount].currentMoney = initialMoney;
	strcpy(customer[currentActCount].customerName, name);
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
		if (customer[i].accountId == id) {
			customer[i].currentMoney += depositMoney;
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
		if (customer[i].accountId == id) {
			if (customer[i].currentMoney < withdrawMoney) {
				cout<<"잔액이 부족합니다."<<endl<<endl;
				return;
			}
			customer[i].currentMoney -= withdrawMoney;
			cout<<"출금완료"<<endl<<endl;
			return;
		}
	}
	
	cout<<"유효하지 않은 계좌ID 입니다."<<endl<<endl;
}

void printAllAcount(void) {
	cout<<"[계좌정보 전체 출력]"<<endl;
	
	for (int i = 0; i < currentActCount; i++) {
		cout<<"계좌ID: "<<customer[i].accountId<<endl;
		cout<<"이 름: "<<customer[i].customerName<<endl;
		cout<<"잔 액: "<<customer[i].currentMoney<<endl<<endl;
	}
}