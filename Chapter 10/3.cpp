#include <iostream>

using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0)
		: xpos(x), ypos(y) {}
	void ShowPosition() {
		cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
	}
	friend Point operator-(const Point &pos1, const Point &pos2);
	
	Point& operator+=(const Point &pos) {
		xpos += pos.xpos;
		ypos += pos.ypos;
		return *this;
	}
	Point& operator-=(const Point &pos) {
		xpos -= pos.xpos;
		ypos -= pos.ypos;
		return *this;
	}
	
	friend bool operator==(const Point &pos1, const Point &pos2);
	friend bool operator!=(const Point &pos1, const Point &pos2);
};

Point operator-(const Point &pos1, const Point &pos2) {
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2. ypos);
	return pos;
}

bool operator==(const Point &pos1, const Point &pos2) {
	if (pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos) {
		return true;
	} else {
		return false;
	}
}

bool operator!=(const Point &pos1, const Point &pos2) {
	return !(pos1 == pos2);
}

int main(void) {
	Point pos1(3, 4);
	Point pos2(10, 20);
	Point pos3 = pos1 - pos2;
	Point pos4 = pos1 += pos2;
	
	Point p1(3, 4);
	Point p2(10, 20);
	Point pos5 = p1 -= p2;
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	
	cout<<endl<<endl;
	
	pos4.ShowPosition();
	pos5.ShowPosition();
	
	if (pos1 == pos3) {
		cout<<"equal"<<endl;
	} else {
		cout<<"not equal"<<endl;
	}
	
	if (pos1 != pos4) {
		cout<<"not equal"<<endl;
	} else {
		cout<<"equal"<<endl;
	}
	
	return 0;
}