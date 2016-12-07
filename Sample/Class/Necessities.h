#ifndef NECESSITIES
#define NECESSITIES
#include"Product.h"

class Necessities:public Product
{
public:
	Necessities();
	~Necessities();

private:
	uint32_t category; //1.stationary 2. hygiene item
};

Necessities::Necessities()
{
}

Necessities::~Necessities()
{
}
#endif
