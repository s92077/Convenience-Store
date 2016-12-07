#ifndef STAFF
#define STAFF
#include<iostream>
using namespace std;

class Staff
{
public:
	Staff();
	~Staff();

private:
	int salary;
	int shift;//1. 6:00~12:00 2. 12.00~18:00 3. 18:00~24:00 4. 0:00~6:00 
};

Staff::Staff()
{
}

Staff::~Staff()
{
}
#endif
