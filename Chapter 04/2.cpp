#include <iostream>

using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	void init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void showPointInfo() const {
		cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
	}
};

class Circle {
private:
	Point center; // 원의 중심좌표
	int radius; // 반지름의 길이
public:
	void init(int x, int y, int rad) {
		radius = rad;
		center.init(x, y);
	}
	void showCircleInfo() const {
		cout<<"원 반지름: "<<radius<<endl;
		center.showPointInfo();
	}
};

class Ring {
private:
	Circle c1; // 안쪽 원
	Circle c2; // 바깥쪽 원
public:
	void init(int inX, int inY, int inR, int outX, int outY, int outR) {
		c1.init(inX, inY, inR);
		c2.init(outX, outY, outR);
	}
	void showRingInfo() const {
		cout<<"Inner Circle Info..."<<endl;
		c1.showCircleInfo();
		cout<<"Outter Circle Info..."<<endl;
		c2.showCircleInfo();
	}
};

int main(void) {
	
	Ring ring;
	ring.init(1, 1, 4, 2, 2, 9);
	ring.showRingInfo();
	
	return 0;
}