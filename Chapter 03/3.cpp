#include <iostream>
#include <cstring>

using namespace std;

class Printer {
private:
	char str[100];
public:
	void setString(const char * s);
	void showString();
};

void Printer::setString(const char * s) {
	strcpy(str, s);
}

void Printer::showString() {
	cout<<str<<endl;
}

int main(void) {

	Printer pnt;
	
	pnt.setString("Hello world!");
	pnt.showString();
	
	pnt.setString("I love C++");
	pnt.showString();
	
	return 0;
}