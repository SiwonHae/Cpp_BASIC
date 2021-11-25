#include <iostream>

using namespace std;

class FruitSeller {
private:
	int APPLE_PRICE;
	int appleCount;
	int myMoney;
public:
	void initMembers(int price, int count, int money) {
		APPLE_PRICE = price;
		appleCount = count;
		myMoney = money;
	}
	
	int saleApples(int money) {
		if (money < 0) {
			cout<<"money 값이 정상적이지 않습니다."<<endl;
			return 0;
		}
		int count = money / APPLE_PRICE;
		appleCount -= count;
		myMoney += money;
		return count;
	}
	void showSalesResult() const {
		cout<<"남은 사과: "<<appleCount<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
};

class FruitBuyer {
private:
	int myMoney;
	int appleCount;
public:
	void initMembers(int money) {
		myMoney = money;
		appleCount = 0;
	}
	void buyApples(FruitSeller &seller, int money) {
		if (money < 0) {
			cout<<"money 값이 정상적이지 않습니다."<<endl;
			return;
		}
		appleCount += seller.saleApples(money);
		myMoney -= money;
	}
	void showBuyResult() const {
		cout<<"구매 사과: "<<appleCount<<endl;
		cout<<"잔액 : "<<myMoney<<endl<<endl;
	}
};

int main(void) {

	FruitSeller seller;
	seller.initMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.initMembers(5000);
	buyer.buyApples(seller, 2000);
	
	cout<<"seller 결과"<<endl;
	seller.showSalesResult();
	cout<<"buyer 결과"<<endl;
	buyer.showBuyResult();
	
	return 0;
}