#ifndef THEWARM
#define THEWARM
#include"Food.h"

ref class theWarm:public Food
{
public:
	theWarm() :Food() { ; }
	theWarm(uint32_t id, System::String^ name, SYSTEMTIME expired, int price) :Food(id, name, expired, price) { ; }
	theWarm(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, int price) :Food(id, name, arval, expired, price) { ; }
	theWarm(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, int price) :Food(id, name, arval, onshelf, expired, price) { ; }

private:
	
};
#endif
