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

void theFrozen::stock(MySqlConnection ^ connect)
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
		strSQL = "insert into 便利商店系統(品名,價格,數量,到店時間,到期日,烹飪時間,溫度,類別) values ('" + productname + "'," + price.ToString() + "," + product_num.ToString() + "," + arvalstr + "," + expiredstr + "," + "0" + "," + temperature.ToString() + "," + "'生鮮食品'" + ");";


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
