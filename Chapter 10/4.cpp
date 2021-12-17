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
	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}
};

int main(void) {
	Point pos1(1, 2);
	Point pos2 = -pos1;
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	
	return 0;
}