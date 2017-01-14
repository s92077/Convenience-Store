#include"stdafx.h"
#include"Class\Food.h"
//using namespace Food;
Food::Food()
{
	this->expired_date = nullptr;
}
Food::Food(uint32_t id, System::String^ name, SYSTEMTIME expired, int price) : Product(id, name, price)
{
	this->expired_date = new SYSTEMTIME;
	*(this->expired_date) = expired;

}
Food::Food(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME expired, int price) :Product(id, name, arval, price)
{
	this->expired_date = new SYSTEMTIME;
	*(this->expired_date) = expired;
}
Food::Food(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, SYSTEMTIME expired, int price) : Product(id, name, arval, onshelf, price)
{
	this->expired_date = new SYSTEMTIME;
	*(this->expired_date) = expired;
}
void Food::set_expiredtime(int year, int month, int day, int hour, int minute, int second) {
	(*(this->expired_date)).wYear = year;
	(*(this->expired_date)).wMonth = month;
	(*(this->expired_date)).wHour = hour;
	(*(this->expired_date)).wMinute = minute;
	(*(this->expired_date)).wSecond = second;
}
inline SYSTEMTIME& Food::get_expiredtime() {
	return *(this->expired_date);
}
void Food::stock(MySqlConnection ^ connect)
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
			/* �s���}�� */
			connect->Open();

			/* �ǰe���O�� MySQL */
			//
			strSQL = "insert into �K�Q�ө��t��(�~�W,����,�ƶq,�쩱�ɶ�,�����,�i���ɶ�,�ū�,���O) values ('" + productname + "'," + price.ToString() + "," + product_num.ToString() + "," + arvalstr + "," + expiredstr + "," + "0" + "," + "25" + "," + "'���~'" + ");";


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
Food::~Food()
{
	if (this->expired_date != nullptr) {
		delete[] expired_date;
	}
}