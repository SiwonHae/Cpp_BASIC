#include <iostream>
#include <cstring>

using namespace std;

class Book {
private:
	char * title;
	char * isbn; // 국제표준도서번호
	int price;
public:
	Book(const char * _title, const char * _isbn, int _price)
		: price(_price)
		{
			title = new char[strlen(_title) + 1];
			strcpy(title, _title);
			isbn = new char[strlen(_isbn) + 1];
			strcpy(isbn, _isbn);
		}
	void ShowBookInfo() const {
		cout<<"제목: "<<title<<endl;
		cout<<"ISBN: "<<isbn<<endl;
		cout<<"가격: "<<price<<endl;
	}
	~Book() {
		delete []title;
		delete []isbn;
	}
};

class EBook : public Book {
private:
	char * DRMKey; // 보안관련 키
public:
	EBook(const char * _title, const char * _isbn, int _price, const char * _DRMKey)
		: Book(_title, _isbn, _price)
		{
			DRMKey = new char[strlen(_DRMKey) + 1];
			strcpy(DRMKey, _DRMKey);
		}
	void ShowEBookInfo() const {
		ShowBookInfo();
		cout<<"인증키: "<<DRMKey<<endl;
	}
	~EBook() {
		delete []DRMKey;
	}
};

int main(void) {
	
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;
	
	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	
	return 0;
}