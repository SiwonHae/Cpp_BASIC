#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	
	const char * str1 = "My name is good";
	int str1Len = strlen(str1);
	
	cout<<str1<<"\t"<<"문자열 길이: "<<str1Len<<endl<<endl;
	
	const char * str2 = " is right????";
	char str3[100];
	
	strcpy(str3, str1);
	strcat(str3, str2);
	cout<<"str1, str2 합치기 : "<<str3<<endl<<endl;
	
	if (strcmp(str1, str2) == 0) {
		cout<<"문자열이 같아요."<<endl;
	} else {
		cout<<"문자열이 달라요."<<endl;
	}
	
	return 0;
}