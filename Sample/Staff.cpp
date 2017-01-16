#include"stdafx.h"
#include"Class\Staff.h"
Staff::Staff(String^name, String^id, String^shift, String^postion)
{
}
void Staff::staff_fired(MySqlConnection^ connect, TextBox ^ textBox1)
{
	try
	{
		/* �s���}�� */
		connect->Open();
		/* �ǰe���O�� MySQL */
		//
		strSQL = "delete from �H�� where �b��='"+textBox1->Text+"';";//MySQL command you want to use
																		 //textBox1->Text = strSQL;																 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		/* Ū����� */

		/* �s������ */
		connect->Close();
		delete cmd;
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show("���\�}���H��\t�b��="+textBox1->Text);
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
		/* �s���}�� */
		connect->Open();
		/* �ǰe���O�� MySQL */
		//
		strSQL = "select * from s201701;";//MySQL command you want to use
																	 //textBox1->Text = strSQL;																 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		int j = 0;
		/* Ū����� */
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
		/* �s������ */
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
		/* �s���}�� */
		connect->Open();
		/* �ǰe���O�� MySQL */
		//
		strSQL = "SELECT * FROM �H�� WHERE �b�� = '" + textBox1->Text + "';";//MySQL command you want to use
		//textBox1->Text = strSQL;																 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		if (reader->Read()) {
			same = true;
			num = Convert::ToInt32(reader->GetString(0));
		}
		/* Ū����� */

		/* �s������ */
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
		/* �s���}�� */
		connect->Open();

		/* �ǰe���O�� MySQL */
		//
		if (same)
		{
			strSQL = "update �H�� set ";
			if (textBox2->Text != "")
				strSQL += "�K�X='" + textBox2->Text + "'";
			if (textBox3->Text != "") {
				if (strSQL != "update �H�� set ")
					strSQL += ",";
				strSQL += "�m�W='" + textBox3->Text + "'";
			}
			if (textBox4->Text != "") {
				if (strSQL != "update �H�� set")
					strSQL += ",";
				strSQL += "�ƯZ='" + textBox4->Text + "'";
			}
			if (textBox5->Text != "") {
				if (strSQL != "update �H�� set")
					strSQL += ",";
				strSQL += "�~��='" + textBox5->Text + "'";
			}
			if (textBox6->Text != "") {
				if (strSQL != "update �H�� set")
					strSQL += ",";
				strSQL += "¾��='" + textBox6->Text + "'";
			}
			strSQL += " where �y���� = " + num + ";";//MySQL command you want to use															   //
		}
		else 
			strSQL = "insert into �H��(�b��,�K�X,�m�W,�ƯZ,�~��,¾��) values ('" + textBox1->Text + "','" + textBox2->Text + "','" + textBox3->Text + "','" + textBox4->Text + "','" + textBox5->Text + "','" + textBox6->Text + "');";
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		connect->Close();
		System::Windows::Forms::DialogResult result;
		if(same)
			result = MessageBox::Show("��令�\");
		else
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
void Staff::staff_getinfo(MySqlConnection^ connect, TextBox ^ textBox1, Label^ label1, Label^ label2, Label^ label3)
{
	try
	{
		/* �s���}�� */
		connect->Open();
		/* �ǰe���O�� MySQL */
		//
		strSQL = "SELECT * FROM �H�� WHERE �b�� = '" + textBox1->Text + "';";//MySQL command you want to use
									 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		reader->Read();
		/* Ū����� */
		label1->Text = "�m�W:"+reader->GetString(3);
		label2->Text = "�ƯZ:"+reader->GetString(4);
		label3->Text = "¾��:"+reader->GetString(6);
		/* �s������ */
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
		/* �s���}�� */
		connect->Open();
		dataGridView1->Rows->Clear();
		dataGridView1->Refresh();
		/* �ǰe���O�� MySQL */
		//
		if (comboBox1->SelectedItem == "��ܥ���")
			strSQL = "select * from �H��;";//MySQL command you want to use
		else if (comboBox1->SelectedItem == "�m�W")
		{
			if (checkBox1->Checked)
				strSQL = "SELECT * FROM �H�� WHERE " + comboBox1->SelectedItem + " = '" + textBox1->Text + "'";
			else
				strSQL = "SELECT * FROM �H�� WHERE " + comboBox1->SelectedItem + " LIKE '%%" + textBox1->Text + "%%'";
		}
		else
			strSQL = "SELECT * FROM �H�� WHERE " + comboBox1->SelectedItem + " = '" + textBox1->Text + "'";

		//
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();

		/* Ū����� */
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

		/* �s������ */
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
		/* �s���}�� */
		connect->Open();
		/* �ǰe���O�� MySQL */
		//
		strSQL = "select * from �H��;";//MySQL command you want to use
		//
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();

		/* Ū����� */
		int j = 0;
		while (reader->Read())
		{
			if (reader->GetString(1) == textBox1->Text&&reader->GetString(2) == textBox2->Text)
			{
				correct = true;
			}
		}

		/* �s������ */
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
		result = MessageBox::Show("�b���αK�X���~");
		return false;
	}
}

