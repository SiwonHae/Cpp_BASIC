#include <iostream>
#include <cstring>

using namespace std;

class Employee {
private:
	char name[100];
public:
	Employee(const char * _name) {
		strcpy(name, _name);
	}
	void ShowYourName() const {
		cout<<"name: "<<name<<endl;
	}
	virtual int GetPay() const = 0; // 순수 가상함수
	virtual void ShowSalaryInfo() const = 0; // 순수 가상함수
};

class PermanentWorker : public Employee {
private:
	int salary; // 월 급여
public:
	PermanentWorker(const char * name, int money)
		: Employee(name), salary(money) {}
	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime; // 이 달에 일한 시간의 합
	int payPerHour; // 시급
public:
	TemporaryWorker(const char * name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) {}
	void AddWorkTime(int time) {
		workTime += time;
	}
	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult; // 월 판매실적
	double bonusRatio; // 상여금 비율
public:
	SalesWorker(const char * name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
	void AddSalesResult(int value) {
		salesResult += value;
	}
	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class EmployeeHandler {
private:
	Employee * empList[50];
	int empNum;
public:
	EmployeeHandler()
		: empNum(0) {}
	void AddEmployee(Employee * emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main(void) {

	// 직원 관리를 목적으로 설계된 컨트롤 클래스의 객체 생성
	EmployeeHandler handler;
	
	// 정규직(PermanentWorker) 등록
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));
	
	// 임시직(TemporaryWorker) 등록
	TemporaryWorker * alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5); // 5시간 일함
	handler.AddEmployee(alba);
	
	// 영업직(SalesWorker) 등록
	SalesWorker * seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(seller);
	
	// 이번 달 지불해야 할 급여 정보
	handler.ShowAllSalaryInfo();
	
	// 이번 달 지불해야할 급여의 총 합
	handler.ShowTotalSalary();
	
	return 0;
}