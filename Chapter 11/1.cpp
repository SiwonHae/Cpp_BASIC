#include <iostream>
#include <cstring>

using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum)
		: bullet(bnum) {}
	void Shot() {
		cout<<"BBANG!"<<endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs;
	Gun * pistol;
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
		{
			if (bnum > 0) {
				pistol = new Gun(bnum);
			} else {
				pistol = NULL;
			}
		}
	Police(const Police &ref)
		: handcuffs(ref.handcuffs)
		{
			if (ref.pistol != NULL) {
				pistol = new Gun(*(ref.pistol));
			} else {
				pistol = NULL;
			}
		}
	Police& operator=(const Police &ref) {
		if (pistol != NULL) {
			delete pistol;
		}
		
		if (ref.pistol != NULL) {
			pistol = new Gun(*(ref.pistol));
		} else {
			pistol = NULL;
		}
		
		handcuffs = ref.handcuffs;
		return *this;
	}
	void PutHandcuff() {
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL) {
			cout<<"Hut BBANG!"<<endl;
		} else {
			pistol->Shot();
		}
	}
	~Police() {
		delete pistol;
	}
};

using namespace std;

int main(void) {

	Police man1(5, 3);
	Police man2 = man1; // 복사 생성자
	man2.PutHandcuff();
	man2.Shot();
	
	Police man3(2, 4);
	man3 = man1; // 대입 연산자
	man3.PutHandcuff();
	man3.Shot();
	
	return 0;
}