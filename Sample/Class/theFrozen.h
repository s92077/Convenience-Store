#ifndef THEFROZEN
#define THEFROZEN
#include"Food.h"

class theFrozen:public Food
{
public:
	theFrozen();
	~theFrozen();

private:
	int temperature;
};

theFrozen::theFrozen()
{
}

theFrozen::~theFrozen()
{
}
#endif
