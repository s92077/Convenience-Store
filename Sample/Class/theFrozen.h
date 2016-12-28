#ifndef THEFROZEN
#define THEFROZEN
#include"Food.h"

ref class theFrozen:public Food
{
public:
	theFrozen();
	theFrozen(uint32_t id, System::String^ name, SYSTEMTIME expired, int price, int temp);
	theFrozen(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, int price, int temp);
	theFrozen(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, int price, int temp);
	void set_temperature(int temp);
	int get_temperature();
private:
	int temperature;
};

#endif
