#ifndef STAFF
#define STAFF
#include<iostream>
using namespace std;

class Staff
{
public:
	Staff() { salary = 10000; shift = 1; };
	Staff(int s1, int s2) { salary = s1; shift = s2; };

	int get_salary() { return salary; }
	int get_shift() { return shift; }
	string get_id() { return id; }
	string get_password() { return password; }

	void set_salary(int s) { salary = s; }
	void set_shift(int s) { shift = s; }
	void set_id(string s) { id = s; }
	void set_password(string s) { password = s; }
	~Staff();

private:
	int salary;
	int shift;//1. 6:00~12:00 2. 12.00~18:00 3. 18:00~24:00 4. 0:00~6:00 
	string id;
	string password;
};

Staff::~Staff()
{
}
#endif
