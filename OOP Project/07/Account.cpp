/*
FileName: Account.cpp
Update: 0.7
*/

#include "BankingCommonDecl.h"
#include "Account.h"

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