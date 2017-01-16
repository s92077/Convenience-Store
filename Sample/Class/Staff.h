#ifndef STAFF
#define STAFF
#include<iostream>
#include<iostream>
#include<String>
#include<windows.h>
using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace System::Windows::Forms;
ref class Staff
{
public:
	Staff() {};
	Staff(String^, String^, String^, String^);
	void staff_search(MySqlConnection^ connect, ComboBox ^ comboBox1, CheckBox ^ checkBox1, TextBox ^ textBox1, DataGridView ^ dataGridView1);
	void staff_getinfo(MySqlConnection^ connect, TextBox ^ textBox1,Label^ label1, Label^ label2, Label^ label3);
	void staff_change(MySqlConnection^ connect,TextBox ^ textBox1, TextBox ^ textBox2, TextBox ^ textBox3, TextBox ^ textBox4, TextBox ^ textBox5, TextBox ^ textBox6);
	void staff_fired(MySqlConnection^ connect, TextBox ^ textBox1);
	void get_schedule(MySqlConnection^ connect, DataGridView ^dataGridView4, int year, int month);
	/*void staff_add(MySqlConnection^ connect);
	void staff_fired();
	void staff_change();*/
	bool login(MySqlConnection^ connect, TextBox ^ textBox1, TextBox ^ textBox2);
	~Staff() {};

protected:
	MySqlCommand ^cmd;
	MySqlDataReader ^reader;
	/* Used to input the MySQL message */
	String^ strSQL;
	String^ id;
	String^ password;
	String^ name;
	String^ shift;//1. 6:00~12:00 2. 12.00~18:00 3. 18:00~24:00 4. 0:00~6:00*/ 
	String^ pos;
private:

};
#endif
