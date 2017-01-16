#include"stdafx.h"
#include"Class\Staff.h"
Staff::Staff(String^name, String^id, String^shift, String^postion)
{
}
void Staff::staff_fired(MySqlConnection^ connect, TextBox ^ textBox1)
{
	try
	{
		/* 連結開啟 */
		connect->Open();
		/* 傳送指令到 MySQL */
		//
		strSQL = "delete from 人員 where 帳號='"+textBox1->Text+"';";//MySQL command you want to use
																		 //textBox1->Text = strSQL;																 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		/* 讀取資料 */

		/* 連結關閉 */
		connect->Close();
		delete cmd;
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show("成功開除人員\t帳號="+textBox1->Text);
	}
	catch (Exception ^ex)
	{
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show(ex->ToString());
		connect->Close();
		delete cmd;
	}
}
void Staff::get_schedule(MySqlConnection ^ connect, DataGridView ^dataGridView4, int year, int month)
{
	try
	{
		/* 連結開啟 */
		connect->Open();
		/* 傳送指令到 MySQL */
		//
		strSQL = "select * from s201701;";//MySQL command you want to use
																	 //textBox1->Text = strSQL;																 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		int j = 0;
		/* 讀取資料 */
		while (reader->Read())
		{
			dataGridView4->Rows->Add();
			for (int i = 0; i<reader->FieldCount; i++)
			{
				String ^read = reader->GetString(i);

				dataGridView4->Rows[j]->Cells[i]->Value = read;
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
void Staff::staff_change(MySqlConnection^ connect,TextBox ^ textBox1, TextBox ^ textBox2, TextBox ^ textBox3, TextBox ^ textBox4, TextBox ^ textBox5, TextBox ^ textBox6)
{
	bool same = false;
	int num;
	try
	{
		/* 連結開啟 */
		connect->Open();
		/* 傳送指令到 MySQL */
		//
		strSQL = "SELECT * FROM 人員 WHERE 帳號 = '" + textBox1->Text + "';";//MySQL command you want to use
		//textBox1->Text = strSQL;																 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		if (reader->Read()) {
			same = true;
			num = Convert::ToInt32(reader->GetString(0));
		}
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
	try
	{
		/* 連結開啟 */
		connect->Open();

		/* 傳送指令到 MySQL */
		//
		if (same)
		{
			strSQL = "update 人員 set ";
			if (textBox2->Text != "")
				strSQL += "密碼='" + textBox2->Text + "'";
			if (textBox3->Text != "") {
				if (strSQL != "update 人員 set ")
					strSQL += ",";
				strSQL += "姓名='" + textBox3->Text + "'";
			}
			if (textBox4->Text != "") {
				if (strSQL != "update 人員 set")
					strSQL += ",";
				strSQL += "排班='" + textBox4->Text + "'";
			}
			if (textBox5->Text != "") {
				if (strSQL != "update 人員 set")
					strSQL += ",";
				strSQL += "薪資='" + textBox5->Text + "'";
			}
			if (textBox6->Text != "") {
				if (strSQL != "update 人員 set")
					strSQL += ",";
				strSQL += "職位='" + textBox6->Text + "'";
			}
			strSQL += " where 流水號 = " + num + ";";//MySQL command you want to use															   //
		}
		else 
			strSQL = "insert into 人員(帳號,密碼,姓名,排班,薪資,職位) values ('" + textBox1->Text + "','" + textBox2->Text + "','" + textBox3->Text + "','" + textBox4->Text + "','" + textBox5->Text + "','" + textBox6->Text + "');";
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		connect->Close();
		System::Windows::Forms::DialogResult result;
		if(same)
			result = MessageBox::Show("更改成功");
		else
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
void Staff::staff_getinfo(MySqlConnection^ connect, TextBox ^ textBox1, Label^ label1, Label^ label2, Label^ label3)
{
	try
	{
		/* 連結開啟 */
		connect->Open();
		/* 傳送指令到 MySQL */
		//
		strSQL = "SELECT * FROM 人員 WHERE 帳號 = '" + textBox1->Text + "';";//MySQL command you want to use
									 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		reader->Read();
		/* 讀取資料 */
		label1->Text = "姓名:"+reader->GetString(3);
		label2->Text = "排班:"+reader->GetString(4);
		label3->Text = "職位:"+reader->GetString(6);
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
void Staff::staff_search(MySqlConnection^ connect, ComboBox ^ comboBox1, CheckBox ^ checkBox1, TextBox ^ textBox1, DataGridView ^ dataGridView1)
{
	try
	{
		/* 連結開啟 */
		connect->Open();
		dataGridView1->Rows->Clear();
		dataGridView1->Refresh();
		/* 傳送指令到 MySQL */
		//
		if (comboBox1->SelectedItem == "顯示全部")
			strSQL = "select * from 人員;";//MySQL command you want to use
		else if (comboBox1->SelectedItem == "姓名")
		{
			if (checkBox1->Checked)
				strSQL = "SELECT * FROM 人員 WHERE " + comboBox1->SelectedItem + " = '" + textBox1->Text + "'";
			else
				strSQL = "SELECT * FROM 人員 WHERE " + comboBox1->SelectedItem + " LIKE '%%" + textBox1->Text + "%%'";
		}
		else
			strSQL = "SELECT * FROM 人員 WHERE " + comboBox1->SelectedItem + " = '" + textBox1->Text + "'";

		//
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();

		/* 讀取資料 */
		int j = 0;
		while (reader->Read())
		{
			dataGridView1->Rows->Add();
			for (int i = 3; i<reader->FieldCount; i++)
			{
				String ^read = reader->GetString(i);

				dataGridView1->Rows[j]->Cells[i-2]->Value = read;
			}
			String ^read = reader->GetString(1);
			dataGridView1->Rows[j]->Cells[0]->Value = read;
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
bool Staff::login(MySqlConnection^ connect, TextBox ^ textBox1, TextBox ^ textBox2)
{
	bool correct=false;
	try
	{
		/* 連結開啟 */
		connect->Open();
		/* 傳送指令到 MySQL */
		//
		strSQL = "select * from 人員;";//MySQL command you want to use
		//
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();

		/* 讀取資料 */
		int j = 0;
		while (reader->Read())
		{
			if (reader->GetString(1) == textBox1->Text&&reader->GetString(2) == textBox2->Text)
			{
				correct = true;
			}
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
	if (correct)	
		return true;
	else 
	{
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show("帳號或密碼錯誤");
		return false;
	}
}

