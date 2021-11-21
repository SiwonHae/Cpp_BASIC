#include <iostream>

int main(void) {
	
	char name[20];
	char phone[20];
	
	std::cout<<"이름: ";
	std::cin>>name;
	std::cout<<"전화번호: ";
	std::cin>>phone;
	
	std::cout<<"입력한 이름: "<<name<<std::endl;
	std::cout<<"입력한 전화번호: "<<phone<<std::endl;
	
	return 0;
}