#include"stdafx.h"
#include"Class\theCooked.h"

theCooked::theCooked() :Food()
{
	this->cooked_time = nullptr;
}
theCooked::theCooked(uint32_t id, System::String^ name, SYSTEMTIME expired, int price, int temp) : Food(id, name, expired, price)
{
	temperature = temp;
	this->cooked_time = new SYSTEMTIME;
}
theCooked::theCooked(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, SYSTEMTIME cooked, int price, int temp) : Food(id, name, arval, expired, price)
{
	temperature = temp;
	this->cooked_time = new SYSTEMTIME;
	*(this->cooked_time) = cooked;
}
theCooked::theCooked(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, SYSTEMTIME cooked, int price, int temp) : Food(id, name, arval, onshelf, expired, price)
{
	temperature = temp;
	this->cooked_time = new SYSTEMTIME;
	*(this->cooked_time) = cooked;
}
theCooked::~theCooked()
{
	if (this->cooked_time != nullptr) {
		delete[] cooked_time;
	}
}
void theCooked::set_cookedtime(int year, int month, int day, int hour, int minute, int second)
{
	(*(this->cooked_time)).wYear = year;
	(*(this->cooked_time)).wMonth = month;
	(*(this->cooked_time)).wHour = hour;
	(*(this->cooked_time)).wMinute = minute;
	(*(this->cooked_time)).wSecond = second;
}
SYSTEMTIME& theCooked::get_cookedtime()
{
	return *(this->cooked_time);
}

void theCooked::stock(MySqlConnection ^ connect)
{
	bool same = false;
	try
	{
		/* �s���}�� */
		connect->Open();

		/* �ǰe���O�� MySQL */
		//
		strSQL = "SELECT * FROM �K�Q�ө��t�� WHERE �~�W= '" + productname + "'";//MySQL command you want to use
																		//
		cmd = gcnew MySqlCommand(strSQL, connect);

		reader = cmd->ExecuteReader();
		if (reader->Read())
			same = true;
		connect->Close();
		delete cmd;
	}
	catch (Exception ^ex)
	{
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show(ex->ToString());
		connect->Close();
		delete cmd;
	}


	try
	{
		System::String^ arvalstr = timetostring(*arval_date);
		System::String^ expiredstr = timetostring(*expired_date);
		int cooktime = cooked_time->wSecond;
		/* �s���}�� */
		connect->Open();

		/* �ǰe���O�� MySQL */
		//
		strSQL = "insert into �K�Q�ө��t��(�~�W,����,�ƶq,�쩱�ɶ�,�����,�i���ɶ�,�ū�,���O) values ('" + productname + "'," + price.ToString() + "," + product_num.ToString() + "," + arvalstr + "," + expiredstr + "," + cooktime + "," + temperature.ToString() + "," + "'�L�i���~'" + ");";


		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		connect->Close();
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show("�s�W���\");
		delete cmd;

	}
	catch (Exception ^ex)
	{
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show(ex->ToString());
		connect->Close();
		delete cmd;
	}
}
