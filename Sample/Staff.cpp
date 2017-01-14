#include"stdafx.h"
#include"Class\Staff.h"
Staff::Staff(String^name, String^id, String^shift, String^postion)
{
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

