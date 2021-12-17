/*
FileName: NormalAccount.h
Update: 0.7
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

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
#endif