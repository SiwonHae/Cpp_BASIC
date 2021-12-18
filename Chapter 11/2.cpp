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
	Book(const Book &ref)
		: price(ref.price)
		{
			title = new char[strlen(ref.title) + 1];
			strcpy(title, ref.title);
			isbn = new char[strlen(ref.isbn) + 1];
			strcpy(isbn, ref.isbn);
		}
	Book& operator=(const Book &ref) {
		delete []title;
		delete []isbn;
		
		title = new char[strlen(ref.title) + 1];
		strcpy(title, ref.title);
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(isbn, ref.isbn);
		
		price = ref.price;
		
		return *this;
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
	EBook(const EBook &ref)
		: Book(ref) 
		{
			DRMKey = new char[strlen(ref.DRMKey) + 1];
			strcpy(DRMKey, ref.DRMKey);
		}
	EBook& operator=(const EBook &ref) {
		Book::operator=(ref);
		
		delete []DRMKey;
		
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
		
		return *this;
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
	
	EBook ebook1("좋은 C++", "555-12345-890-0", 10000, "fdx9w0i8kiw");
	EBook ebook2 = ebook1; // 복사 생성자
	ebook2.ShowEBookInfo();
	cout<<endl;
	
	EBook ebook3("dummy", "dumy", 0, "dumy");
	ebook3 = ebook2; // 대입 연산자
	ebook3.ShowEBookInfo();
	
	return 0;
}