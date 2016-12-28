#ifndef THECOOKED
#define THECOOKED
#include"Food.h"

ref class theCooked:public Food
{
public:
	theCooked();
	theCooked(uint32_t id, System::String^ name, SYSTEMTIME expired, int price);
	theCooked(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, SYSTEMTIME cooked, int price);
	theCooked(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, SYSTEMTIME cooked, int price);
	~theCooked();
	void set_cookedtime(int year, int month, int day, int hour, int minute, int second);
	SYSTEMTIME& get_cookedtime();
private:
	SYSTEMTIME* cooked_time;

};


#endif
