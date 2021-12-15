#include <iostream>

using namespace std;

class Rectangle {
private:
	int x, y;
public:
	Rectangle(int xpos, int ypos)
		: x(xpos), y(ypos) {}
	void ShowAreaInfo() {
		cout<<"면적: "<<x * y<<endl;
	}
};

class Square : public Rectangle {
public:
	Square(int line)
		: Rectangle(line, line) {}
};

int main(void) {
	
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();
	
	return 0;
}