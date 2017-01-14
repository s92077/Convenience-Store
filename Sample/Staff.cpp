#include"stdafx.h"
#include"Class\Staff.h"
Staff::Staff(String^name, String^id, String^shift, String^postion)
{
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

