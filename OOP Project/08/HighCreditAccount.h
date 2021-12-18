/*
FileName: HighCreditAccount.h
Update: 0.7
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

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
#endif