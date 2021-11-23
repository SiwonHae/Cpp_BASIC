#include <iostream>

using namespace std;

class Calculator {
private:
	int addCount;
	int minCount;
	int mulCount;
	int divCount;
public:
	void init();
	double add(double num1, double num2);
	double min(double num1, double num2);
	double mul(double num1, double num2);
	double div(double num1, double num2);
	void showOpCount();
};

void Calculator::init() {
	addCount = 0;
	minCount = 0;
	mulCount = 0;
	divCount = 0;
}

double Calculator::add(double num1, double num2) {
	addCount++;
	return num1 + num2;
}

double Calculator::min(double num1, double num2) {
	minCount++;
	return num1 - num2;
}

double Calculator::mul(double num1, double num2) {
	mulCount++;
	return num1 * num2;
}

double Calculator::div(double num1, double num2) {
	divCount++;
	return num1 / num2;
}

void Calculator::showOpCount() {
	cout<<"덧셈 count: "<<addCount<<endl;
	cout<<"뺄셈 count: "<<minCount<<endl;
	cout<<"곱셈 count: "<<mulCount<<endl;
	cout<<"나눗셈 count: "<<divCount<<endl;
}

int main(void) {

	Calculator cal;
	cal.init();
	cout<<"3.2 + 2.4 = "<<cal.add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.min(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 = "<<cal.div(4.9, 1.2)<<endl;
	cal.showOpCount();
	
	return 0;
}