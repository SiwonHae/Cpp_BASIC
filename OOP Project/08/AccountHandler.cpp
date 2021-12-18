/*
FileName: AccountHandler.cpp
Update: 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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