#ifndef THECOOKED
#define THECOOKED
#include"Food.h"

class theCooked:public Food
{
public:
	theCooked();
	theCooked();
	~theCooked();

private:
	SYSTEMTIME* cooked_time;

};

theCooked::theCooked()
{
}

theCooked::~theCooked()
{
}
#endif
