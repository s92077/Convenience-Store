#include"stdafx.h"
#include"Class\theFrozen.h"

theFrozen::theFrozen()
{
}
theFrozen::theFrozen(uint32_t id, System::String^ name, SYSTEMTIME expired, int price, int temp) {
	temperature = temp;

}
theFrozen::theFrozen(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, int price, int temp) :Food(id, name, arval, expired, price)
{
	temperature = temp;
}
theFrozen::theFrozen(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, int price, int temp) : Food(id, name, arval, onshelf, expired, price)
{
	temperature = temp;
}

void theFrozen::set_temperature(int temp)
{
	throw gcnew System::NotImplementedException();
	temperature = temp;
}

int theFrozen::get_temperature()
{
	return temperature;
}
