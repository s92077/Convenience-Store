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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(339, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(975, 43);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1414, 77);
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
			this->comboBox1->Location = System::Drawing::Point(120, 80);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(168, 38);
			this->comboBox1->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->流水號, this->品名,
					this->價格, this->數量, this->到店時間, this->到期日, this->烹飪時間, this->溫度
			});
			this->dataGridView1->Location = System::Drawing::Point(120, 170);
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
			this->checkBox1->Location = System::Drawing::Point(120, 130);
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
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(1908, 476);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(200, 75);
			this->button3->TabIndex = 8;
			this->button3->Text = L"進貨功能";
			this->button3->UseVisualStyleBackColor = true;
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2216, 992);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->MinimizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

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
};
}

