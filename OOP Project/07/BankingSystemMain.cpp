/*
FileName: BankingSystemMain.cpp
SW Version: 0.7
Update: 0.7
*/

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

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