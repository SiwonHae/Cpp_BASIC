#include <iostream>

using namespace std;

void swapPointer(int * (&p1), int * (&p2)) {
	int temp;
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

int main(void) {
	
	int num1 = 5;
	int * ptr1 = &num1;
	int num2 = 10;
	int * ptr2 = &num2;
	
	swapPointer(ptr1, ptr2);
	
	cout<<num1<<endl;
	cout<<num2<<endl;
	
	return 0;
}