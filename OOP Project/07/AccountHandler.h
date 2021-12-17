/*
FileName: AccountHandler.h
Update: 0.7
*/

#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

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
#endif