#ifndef THECOOKED
#define THECOOKED
#include"Food.h"

class theCooked:public Food
{
public:
	theCooked();
	~theCooked();

private:
	struct tm cooked_time;
};

theCooked::theCooked()
{
}

theCooked::~theCooked()
{
}
#endif
