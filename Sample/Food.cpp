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
			/* 連結開啟 */
			connect->Open();

			/* 傳送指令到 MySQL */
			//
			strSQL = "SELECT * FROM 便利商店系統 WHERE 品名= '" + productname + "'";//MySQL command you want to use
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
			/* 連結開啟 */
			connect->Open();

			/* 傳送指令到 MySQL */
			//
			strSQL = "insert into 便利商店系統(品名,價格,數量,到店時間,到期日,烹飪時間,溫度,類別) values ('" + productname + "'," + price.ToString() + "," + product_num.ToString() + "," + arvalstr + "," + expiredstr + "," + "0" + "," + "25" + "," + "'食品'" + ");";


			cmd = gcnew MySqlCommand(strSQL, connect);
			reader = cmd->ExecuteReader();
			connect->Close();
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show("新增成功");
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