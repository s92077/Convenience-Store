#include"stdafx.h"
#include"Class\Product.h"

Product::Product()
{
	this->id = -1;
	this->productname = "";
	this->price = -1;
	arval_date = new SYSTEMTIME;
	GetLocalTime(this->arval_date);
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name, int price)
{
	this->id = id;
	this->productname = name;
	this->price = price;
	arval_date = new SYSTEMTIME;
	GetLocalTime(this->arval_date);
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name, SYSTEMTIME arval, int price) {
	this->id = id;
	this->productname = name;
	this->price = price;
	arval_date = new SYSTEMTIME;
	*(this->arval_date) = arval;
	onshelf_date = nullptr;
}
Product::Product(uint32_t id, System::String^ name, SYSTEMTIME arval, SYSTEMTIME onshelf, int price) {
	this->id = id;
	this->productname = name;
	this->price = price;
	arval_date = new SYSTEMTIME;
	*(this->arval_date) = arval;
	onshelf_date = new SYSTEMTIME;
	*(this->arval_date) = onshelf;
}
void Product::set_arvaltime(int year, int month, int day, int hour, int minute, int second) {
	(*(this->arval_date)).wYear = year;
	(*(this->arval_date)).wMonth = month;
	(*(this->arval_date)).wHour = hour;
	(*(this->arval_date)).wMinute = minute;
	(*(this->arval_date)).wSecond = second;

}
inline void Product::set_arvaltime_current() {
	GetLocalTime(this->arval_date);
}
void Product::set_onshelftime(int year, int month, int day, int hour, int minute, int second) {
	(*(this->onshelf_date)).wYear = year;
	(*(this->onshelf_date)).wMonth = month;
	(*(this->onshelf_date)).wHour = hour;
	(*(this->onshelf_date)).wMinute = minute;
	(*(this->onshelf_date)).wSecond = second;
}
inline void Product::set_onshelftime_current() {
	GetLocalTime(this->onshelf_date);
}
void Product::set_price(int price) {
	this->price = price;
}
void Product::set_number(int num)
{
	this->product_num = num;
}
void Product::search_product(MySqlConnection^ connect, ComboBox ^ comboBox1, CheckBox ^ checkBox1, TextBox ^ textBox1, DataGridView ^ dataGridView1)
{
	try
		{
			/* 連結開啟 */
			connect->Open();
			dataGridView1->Rows->Clear();
			dataGridView1->Refresh();
			/* 傳送指令到 MySQL */
			//
			if(comboBox1->SelectedItem=="顯示全部")
				strSQL = "select * from 便利商店系統;";//MySQL command you want to use
			else if(comboBox1->SelectedItem == "品名")
			{
				if(checkBox1->Checked)
					strSQL = "SELECT * FROM 便利商店系統 WHERE " + comboBox1->SelectedItem + " = '" + textBox1->Text + "'";
				else
					strSQL ="SELECT * FROM 便利商店系統 WHERE "+ comboBox1->SelectedItem +" LIKE '%%"+textBox1->Text+"%%'";
			}		
			else
				strSQL = "SELECT * FROM 便利商店系統 WHERE " + comboBox1->SelectedItem + " = '" + textBox1->Text + "'";

			//
			cmd = gcnew MySqlCommand(strSQL, connect);
			reader = cmd->ExecuteReader();

			/* 讀取資料 */
			int j = 0;
			while (reader->Read())
			{
				dataGridView1->Rows->Add();
				for (int i = 0; i<reader->FieldCount; i++)
				{
					String ^read = reader->GetString(i);
					
					dataGridView1->Rows[j]->Cells[i]->Value = read;
				}
				j++;
			}

			/* 連結關閉 */
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
}
void Product::search_sell_proudct(MySqlConnection^ connect, TextBox^ textBox1, TextBox^ textBox2, DataGridView^ dataGridView1)
{
	bool same = false;
	for(int i=0;i<dataGridView1->Rows->Count;i++)
		if (Convert::ToInt32(dataGridView1->Rows[i]->Cells[0]->Value) == Convert::ToInt32(textBox1->Text))
		{
			dataGridView1->Rows[i]->Cells[3]->Value = Convert::ToString(Convert::ToInt32(dataGridView1->Rows[i]->Cells[3]->Value) + Convert::ToInt32(textBox2->Text));
			dataGridView1->Rows[i]->Cells[4]->Value = Convert::ToString(Convert::ToInt32(dataGridView1->Rows[i]->Cells[2]->Value) * Convert::ToInt32(textBox2->Text)+ Convert::ToInt32(dataGridView1->Rows[i]->Cells[4]->Value));
			same = true;
		}
	int sum=1;
	if(!same)
	try
	{
		/* 連結開啟 */
		connect->Open();
		/* 傳送指令到 MySQL */
		//
		strSQL = "SELECT * FROM 便利商店系統 WHERE 流水號" + " = " + textBox1->Text + ";";
		//
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		reader->Read();
		
		sum = (Convert::ToInt32(textBox2->Text))*(Convert::ToInt32(reader->GetString(2)));
		/* 讀取資料 */
		dataGridView1->Rows->Add();
		int i = dataGridView1->Rows->Count-1;
		dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToInt32(textBox1->Text);
		dataGridView1->Rows[i]->Cells[1]->Value = reader->GetString(1);
		dataGridView1->Rows[i]->Cells[2]->Value = reader->GetString(2);
		dataGridView1->Rows[i]->Cells[3]->Value = textBox2->Text;
		dataGridView1->Rows[i]->Cells[4]->Value = Convert::ToString(sum);
		/* 連結關閉 */
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
}
void Product::stock(MySqlConnection ^ connect)
{
	bool same = false;
	try
	{
		/* 連結開啟 */
		connect->Open();

		/* 傳送指令到 MySQL */
		//
		strSQL = "SELECT * FROM 便利商店系統 WHERE 品名= '" + productname + "'";//MySQL command you want to use																   //
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
		System::String^ arvalstr=timetostring(*arval_date);
		
		/* 連結開啟 */
		connect->Open();

		/* 傳送指令到 MySQL */
		//
		if (same)
			strSQL = "update 便利商店系統 set 數量 = 數量+" + product_num + " where 品名='" + productname + "';";//MySQL command you want to use															   //
		else
			strSQL = "insert into 便利商店系統(品名,價格,數量,到店時間,到期日,烹飪時間,溫度,類別) values ('" + productname + "'," + price.ToString() + "," + product_num.ToString() + "," + arvalstr + ",'" + "1900/1/0" + "'," + "0" + "," + "0" + "," + "'日用品'"+");";

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
void Product::sell_product(MySqlConnection^ connect,String^sn, String^n) {
	try
	{
		/* 連結開啟 */
		connect->Open();
		/* 傳送指令到 MySQL */
		//
		strSQL = "update 便利商店系統 set 數量 = 數量-" + n + " where 流水號=" + sn + ";";//MySQL command you want to use
		//
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		reader->Read();
		/* 讀取資料 */
		/* 連結關閉 */
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

}
inline SYSTEMTIME& Product::get_arvaltime() {
	return *(this->arval_date);
}
inline SYSTEMTIME& Product::get_onshelftime() {
	return *(this->onshelf_date);
}
inline int Product::get_price(int price) {
	return this->price;
}
Product::~Product()
{
	if (this->arval_date != nullptr)
		delete[] arval_date;
	if (this->onshelf_date)
		delete[] onshelf_date;
}

System::String ^ Product::timetostring(SYSTEMTIME t)
{
	System::String^ str="";
	int year = t.wYear, month = t.wMonth, day = t.wDay;
	str = "'" + year + "/" + month + "/" + day + "'";
	return str;
	// TODO: 於此處插入傳回陳述式
}
