#include <iostream>

using namespace std;

void oneAdder(int &num) {
	num++;
}

void changeSign(int &num) {
	num *= -1;
}

int main(void) {
	
	int n = 10;
	
	oneAdder(n);
	cout<<n<<endl;
	
	changeSign(n);
	cout<<n<<endl;
	
	return 0;
}