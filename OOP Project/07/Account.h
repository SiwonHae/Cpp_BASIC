/*
FileName: Account.h
Update: 0.7
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

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
#endif