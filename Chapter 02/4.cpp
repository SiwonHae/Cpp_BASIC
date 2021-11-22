#include <iostream>

using namespace std;

typedef struct __point {
	int xpos;
	int ypos;
} Point;

Point& pntAdder(const Point &p1, const Point &p2) {
	Point * p = new Point;
	p->xpos = p1.xpos + p2.xpos;
	p->ypos = p1.ypos + p2.ypos;
	return *p;
}

int main(void) {

	Point * ptr1 = new Point;
	ptr1->xpos = 3;
	ptr1->ypos = 30;
	
	Point * ptr2 = new Point;
	ptr2->xpos = 70;
	ptr2->ypos = 7;
	
	Point &ref = pntAdder(*ptr1, *ptr2);
	cout<<ref.xpos<<"\t"<<ref.ypos<<endl;
	
	delete ptr1;
	delete ptr2;
	delete &ref;
	
	return 0;
}