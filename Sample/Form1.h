#pragma once
#include"Class\theFrozen.h"
namespace Sample {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			server = "localhost";
			userID = "root";
			password = "0410753";
			connectstr = "Network Address=" + server + ";" + "Persist Security Info=no;" + "User Name=" + userID + ";" + "Password=" + password + ";";
			connect = gcnew MySqlConnection(connectstr);
			try
			{
				/* 連結開啟 */
				connect->Open();

				/* 傳送指令到 MySQL */
				//
				strSQL = "use test1;";//MySQL command you want to use
									  //
				cmd = gcnew MySqlCommand(strSQL, connect);
				reader = cmd->ExecuteReader();
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
			comboBox1->Items->Add("顯示全部");
			comboBox1->Items->Add("品名");
			comboBox1->Items->Add("價格");
			comboBox1->Items->Add("數量");
			comboBox1->Items->Add("到店時間");
			comboBox1->Items->Add("到期日");
			comboBox1->Items->Add("烹飪時間");
			comboBox1->Items->Add("溫度");
			comboBox1->SelectedIndex = 0;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::ComboBox^  comboBox1;




	private:
		/// <summary>
		/// Required designer variable.
		String ^connectstr;
		String ^server;
		String ^userID;
		String ^password;
		String ^outputText;
		String ^table_name;
		/* MySQL連接器、指令傳送、資料讀取 */
		MySqlConnection ^connect;
		MySqlCommand ^cmd;
		MySqlDataReader ^reader;
		/* Used to input the MySQL message */
		String ^strSQL;
	private: System::Windows::Forms::DataGridView^  dataGridView1;








	private: System::Windows::Forms::DataGridViewTextBoxColumn^  流水號;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  品名;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  價格;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  數量;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  到店時間;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  到期日;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  烹飪時間;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  溫度;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::TextBox^  textBox2;
private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::Button^  button6;
private: System::Windows::Forms::TextBox^  textBox8;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::TextBox^  textBox6;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::TextBox^  textBox4;
private: System::Windows::Forms::TextBox^  textBox3;
		 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->流水號 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->品名 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->價格 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->數量 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->到店時間 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->到期日 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->烹飪時間 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->溫度 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(232, 13);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(975, 43);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1324, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(173, 64);
			this->button1->TabIndex = 1;
			this->button1->Text = L"查詢";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(16, 13);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(193, 38);
			this->comboBox1->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->流水號, this->品名,
					this->價格, this->數量, this->到店時間, this->到期日, this->烹飪時間, this->溫度
			});
			this->dataGridView1->Location = System::Drawing::Point(16, 97);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 45;
			this->dataGridView1->Size = System::Drawing::Size(1640, 710);
			this->dataGridView1->TabIndex = 4;
			// 
			// 流水號
			// 
			this->流水號->HeaderText = L"流水號";
			this->流水號->Name = L"流水號";
			// 
			// 品名
			// 
			this->品名->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			this->品名->DefaultCellStyle = dataGridViewCellStyle1;
			this->品名->HeaderText = L"品名";
			this->品名->Name = L"品名";
			this->品名->Width = 127;
			// 
			// 價格
			// 
			this->價格->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->價格->HeaderText = L"價格";
			this->價格->Name = L"價格";
			this->價格->Width = 127;
			// 
			// 數量
			// 
			this->數量->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->數量->HeaderText = L"數量";
			this->數量->Name = L"數量";
			this->數量->Width = 127;
			// 
			// 到店時間
			// 
			this->到店時間->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->到店時間->HeaderText = L"到店時間";
			this->到店時間->Name = L"到店時間";
			this->到店時間->Width = 187;
			// 
			// 到期日
			// 
			this->到期日->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->到期日->HeaderText = L"到期日";
			this->到期日->Name = L"到期日";
			this->到期日->Width = 157;
			// 
			// 烹飪時間
			// 
			this->烹飪時間->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->烹飪時間->HeaderText = L"烹飪時間";
			this->烹飪時間->Name = L"烹飪時間";
			this->烹飪時間->Width = 187;
			// 
			// 溫度
			// 
			this->溫度->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->溫度->HeaderText = L"溫度";
			this->溫度->Name = L"溫度";
			this->溫度->Width = 127;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(16, 57);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(171, 34);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"完全符合";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(1908, 170);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 75);
			this->button2->TabIndex = 7;
			this->button2->Text = L"查詢功能";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1908, 476);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(200, 75);
			this->button3->TabIndex = 8;
			this->button3->Text = L"進貨功能";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(1908, 328);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(200, 75);
			this->button4->TabIndex = 9;
			this->button4->Text = L"銷售功能";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(1908, 641);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(200, 75);
			this->button5->TabIndex = 10;
			this->button5->Text = L"人員管理";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(95, 94);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1659, 831);
			this->panel1->TabIndex = 11;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button6);
			this->panel2->Controls->Add(this->textBox8);
			this->panel2->Controls->Add(this->textBox7);
			this->panel2->Controls->Add(this->textBox6);
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1656, 825);
			this->panel2->TabIndex = 12;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
			this->button6->Location = System::Drawing::Point(754, 719);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(187, 65);
			this->button6->TabIndex = 14;
			this->button6->Text = L"確認";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(668, 220);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(435, 43);
			this->textBox8->TabIndex = 13;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(668, 304);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(435, 43);
			this->textBox7->TabIndex = 12;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(668, 388);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(435, 43);
			this->textBox6->TabIndex = 11;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(668, 478);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(435, 43);
			this->textBox5->TabIndex = 10;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(668, 553);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(435, 43);
			this->textBox4->TabIndex = 9;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(668, 628);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(435, 43);
			this->textBox3->TabIndex = 8;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(526, 628);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(73, 30);
			this->label7->TabIndex = 7;
			this->label7->Text = L"溫度";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(526, 220);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(73, 30);
			this->label6->TabIndex = 6;
			this->label6->Text = L"價格";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(526, 304);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 30);
			this->label5->TabIndex = 5;
			this->label5->Text = L"數量";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(526, 388);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(133, 30);
			this->label4->TabIndex = 4;
			this->label4->Text = L"到店日期";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(526, 478);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(103, 30);
			this->label3->TabIndex = 3;
			this->label3->Text = L"到期日";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(530, 553);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 30);
			this->label2->TabIndex = 2;
			this->label2->Text = L"烹飪時間";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(526, 135);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 30);
			this->label1->TabIndex = 1;
			this->label1->Text = L"品名";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(668, 135);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(435, 43);
			this->textBox2->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2216, 992);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
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
					strSQL ="SELECT * FROM 便利商店系統 WHERE "+ comboBox1->SelectedItem +" LIKE '\%"+textBox1->Text+"\%'";
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
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	bool same = false;
	try
	{
		/* 連結開啟 */
		connect->Open();

		/* 傳送指令到 MySQL */
		//
		strSQL = "SELECT * FROM 便利商店系統 WHERE 品名= '" + textBox2->Text + "'";//MySQL command you want to use
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
			if (same) {
				/* 連結開啟 */
				connect->Open();

				/* 傳送指令到 MySQL */
				//

				strSQL = "update 便利商店系統 set 數量 = 數量+"+ textBox7->Text +" where 品名='" + textBox2->Text + "';";//MySQL command you want to use															   //
				cmd = gcnew MySqlCommand(strSQL, connect);
				reader = cmd->ExecuteReader();
				connect->Close();
				System::Windows::Forms::DialogResult result;
				result = MessageBox::Show("新增成功");
				delete cmd;
			}
		}
		catch (Exception ^ex)
		{
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(ex->ToString());
			connect->Close();
			delete cmd;
		}


	
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	panel1->Visible = true;
	panel2->Visible = false;
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	panel1->Visible = false;
	panel2->Visible = true;
}
};
}

