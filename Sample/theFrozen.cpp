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
		strSQL = "insert into �K�Q�ө��t��(�~�W,����,�ƶq,�쩱�ɶ�,�����,�i���ɶ�,�ū�,���O) values ('" + productname + "'," + price.ToString() + "," + product_num.ToString() + "," + arvalstr + "," + expiredstr + "," + "0" + "," + temperature.ToString() + "," + "'���A���~'" + ");";


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
