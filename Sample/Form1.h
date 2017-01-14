#pragma once
#include"Class\theFrozen.h"
#include"Class\theCooked.h"
#include"Class\Staff.h"
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
			String ^connectstr;
			String ^server;
			String ^userID;
			String ^password;
			MySqlCommand ^cmd;
			MySqlDataReader ^reader;
			/* Used to input the MySQL message */
			String ^strSQL;
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
			comboBox1->Items->Add("類別");
			comboBox1->SelectedIndex = 0;
			//
			//TODO: Add the constructor code here
			//
			comboBox2->Items->Add("微波食品");
			comboBox2->Items->Add("生鮮食品");
			comboBox2->Items->Add("食品");
			comboBox2->Items->Add("日用品");
			comboBox2->SelectedIndex = 0;

			comboBox3->Items->Add("顯示全部");
			comboBox3->Items->Add("姓名");
			comboBox3->Items->Add("排班");
			comboBox3->Items->Add("薪資");
			comboBox3->Items->Add("職位");
			comboBox3->SelectedIndex = 0;
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
		/* MySQL連接器、指令傳送、資料讀取 */
		MySqlConnection ^connect;

	private: System::Windows::Forms::DataGridView^  dataGridView1;
















	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Panel^  search;

	private: System::Windows::Forms::Panel^  purchase;

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

	private: System::Windows::Forms::Panel^  login;
	private: System::Windows::Forms::TextBox^  account;
	private: System::Windows::Forms::TextBox^  passwordbox;




	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  sell;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::DataGridView^  dataGridView2;





	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::TextBox^  textBox11;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  流水號;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  品名;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  價格;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  數量;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  到店時間;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  到期日;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  烹飪時間;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  溫度;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  類別;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::ComboBox^  comboBox2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  s品名;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  s價格;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  s數量;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  s小記;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Button^  button8;
private: System::Windows::Forms::Button^  button9;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::TextBox^  textBox9;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Panel^  member;

private: System::Windows::Forms::DataGridView^  dataGridView3;









private: System::Windows::Forms::ComboBox^  comboBox3;
private: System::Windows::Forms::CheckBox^  checkBox2;
private: System::Windows::Forms::TextBox^  textBox12;
private: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label19;







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
				 System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
				 this->類別 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->search = (gcnew System::Windows::Forms::Panel());
				 this->member = (gcnew System::Windows::Forms::Panel());
				 this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
				 this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
				 this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
				 this->textBox12 = (gcnew System::Windows::Forms::TextBox());
				 this->button10 = (gcnew System::Windows::Forms::Button());
				 this->purchase = (gcnew System::Windows::Forms::Panel());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
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
				 this->login = (gcnew System::Windows::Forms::Panel());
				 this->button11 = (gcnew System::Windows::Forms::Button());
				 this->passwordbox = (gcnew System::Windows::Forms::TextBox());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->account = (gcnew System::Windows::Forms::TextBox());
				 this->sell = (gcnew System::Windows::Forms::Panel());
				 this->button9 = (gcnew System::Windows::Forms::Button());
				 this->label16 = (gcnew System::Windows::Forms::Label());
				 this->textBox9 = (gcnew System::Windows::Forms::TextBox());
				 this->label15 = (gcnew System::Windows::Forms::Label());
				 this->label14 = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->button8 = (gcnew System::Windows::Forms::Button());
				 this->button7 = (gcnew System::Windows::Forms::Button());
				 this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
				 this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->s品名 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->s價格 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->s數量 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->s小記 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->textBox10 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox11 = (gcnew System::Windows::Forms::TextBox());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->button12 = (gcnew System::Windows::Forms::Button());
				 this->label17 = (gcnew System::Windows::Forms::Label());
				 this->label18 = (gcnew System::Windows::Forms::Label());
				 this->label19 = (gcnew System::Windows::Forms::Label());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
				 this->search->SuspendLayout();
				 this->member->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
				 this->purchase->SuspendLayout();
				 this->login->SuspendLayout();
				 this->sell->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // textBox1
				 // 
				 this->textBox1->Location = System::Drawing::Point(232, 12);
				 this->textBox1->Margin = System::Windows::Forms::Padding(4);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(976, 43);
				 this->textBox1->TabIndex = 0;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(1324, 12);
				 this->button1->Margin = System::Windows::Forms::Padding(4);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(172, 64);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"查詢";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->Location = System::Drawing::Point(16, 12);
				 this->comboBox1->Margin = System::Windows::Forms::Padding(4);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(192, 38);
				 this->comboBox1->TabIndex = 3;
				 // 
				 // dataGridView1
				 // 
				 this->dataGridView1->AllowUserToAddRows = false;
				 this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
					 this->流水號, this->品名,
						 this->價格, this->數量, this->到店時間, this->到期日, this->烹飪時間, this->溫度, this->類別
				 });
				 this->dataGridView1->Location = System::Drawing::Point(16, 122);
				 this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
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
				 // 類別
				 // 
				 this->類別->HeaderText = L"類別";
				 this->類別->Name = L"類別";
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Location = System::Drawing::Point(16, 62);
				 this->checkBox1->Margin = System::Windows::Forms::Padding(4);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(171, 34);
				 this->checkBox1->TabIndex = 6;
				 this->checkBox1->Text = L"完全符合";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 // 
				 // button2
				 // 
				 this->button2->Enabled = false;
				 this->button2->Location = System::Drawing::Point(1780, 51);
				 this->button2->Margin = System::Windows::Forms::Padding(4);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(200, 76);
				 this->button2->TabIndex = 7;
				 this->button2->Text = L"查詢功能";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
				 // 
				 // button3
				 // 
				 this->button3->Enabled = false;
				 this->button3->Location = System::Drawing::Point(1780, 307);
				 this->button3->Margin = System::Windows::Forms::Padding(4);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(200, 76);
				 this->button3->TabIndex = 8;
				 this->button3->Text = L"進貨功能";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
				 // 
				 // button4
				 // 
				 this->button4->Enabled = false;
				 this->button4->Location = System::Drawing::Point(1780, 190);
				 this->button4->Margin = System::Windows::Forms::Padding(4);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(200, 76);
				 this->button4->TabIndex = 9;
				 this->button4->Text = L"銷售功能";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
				 // 
				 // button5
				 // 
				 this->button5->Enabled = false;
				 this->button5->Location = System::Drawing::Point(1780, 463);
				 this->button5->Margin = System::Windows::Forms::Padding(4);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(200, 76);
				 this->button5->TabIndex = 10;
				 this->button5->Text = L"人員管理";
				 this->button5->UseVisualStyleBackColor = true;
				 this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
				 // 
				 // search
				 // 
				 this->search->Controls->Add(this->dataGridView1);
				 this->search->Controls->Add(this->comboBox1);
				 this->search->Controls->Add(this->checkBox1);
				 this->search->Controls->Add(this->textBox1);
				 this->search->Controls->Add(this->button1);
				 this->search->Location = System::Drawing::Point(61, 39);
				 this->search->Margin = System::Windows::Forms::Padding(4);
				 this->search->Name = L"search";
				 this->search->Size = System::Drawing::Size(1703, 894);
				 this->search->TabIndex = 11;
				 this->search->Visible = false;
				 // 
				 // member
				 // 
				 this->member->Controls->Add(this->dataGridView3);
				 this->member->Controls->Add(this->comboBox3);
				 this->member->Controls->Add(this->checkBox2);
				 this->member->Controls->Add(this->textBox12);
				 this->member->Controls->Add(this->button10);
				 this->member->Location = System::Drawing::Point(13, 11);
				 this->member->Margin = System::Windows::Forms::Padding(4);
				 this->member->Name = L"member";
				 this->member->Size = System::Drawing::Size(1725, 894);
				 this->member->TabIndex = 12;
				 this->member->Visible = false;
				 // 
				 // dataGridView3
				 // 
				 this->dataGridView3->AllowUserToAddRows = false;
				 this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
					 this->dataGridViewTextBoxColumn6,
						 this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
				 });
				 this->dataGridView3->Location = System::Drawing::Point(339, 124);
				 this->dataGridView3->Margin = System::Windows::Forms::Padding(4);
				 this->dataGridView3->Name = L"dataGridView3";
				 this->dataGridView3->RowHeadersVisible = false;
				 this->dataGridView3->RowTemplate->Height = 45;
				 this->dataGridView3->Size = System::Drawing::Size(811, 698);
				 this->dataGridView3->TabIndex = 4;
				 // 
				 // dataGridViewTextBoxColumn6
				 // 
				 this->dataGridViewTextBoxColumn6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->dataGridViewTextBoxColumn6->HeaderText = L"帳號";
				 this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
				 this->dataGridViewTextBoxColumn6->Width = 127;
				 // 
				 // dataGridViewTextBoxColumn2
				 // 
				 this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
				 this->dataGridViewTextBoxColumn2->DefaultCellStyle = dataGridViewCellStyle2;
				 this->dataGridViewTextBoxColumn2->HeaderText = L"姓名";
				 this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
				 this->dataGridViewTextBoxColumn2->Width = 127;
				 // 
				 // dataGridViewTextBoxColumn3
				 // 
				 this->dataGridViewTextBoxColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->dataGridViewTextBoxColumn3->HeaderText = L"排班";
				 this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
				 this->dataGridViewTextBoxColumn3->Width = 127;
				 // 
				 // dataGridViewTextBoxColumn4
				 // 
				 this->dataGridViewTextBoxColumn4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->dataGridViewTextBoxColumn4->HeaderText = L"薪資";
				 this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
				 this->dataGridViewTextBoxColumn4->Width = 127;
				 // 
				 // dataGridViewTextBoxColumn5
				 // 
				 this->dataGridViewTextBoxColumn5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->dataGridViewTextBoxColumn5->HeaderText = L"職位";
				 this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
				 this->dataGridViewTextBoxColumn5->Width = 127;
				 // 
				 // comboBox3
				 // 
				 this->comboBox3->FormattingEnabled = true;
				 this->comboBox3->Location = System::Drawing::Point(16, 12);
				 this->comboBox3->Margin = System::Windows::Forms::Padding(4);
				 this->comboBox3->Name = L"comboBox3";
				 this->comboBox3->Size = System::Drawing::Size(192, 38);
				 this->comboBox3->TabIndex = 3;
				 // 
				 // checkBox2
				 // 
				 this->checkBox2->AutoSize = true;
				 this->checkBox2->Location = System::Drawing::Point(18, 68);
				 this->checkBox2->Margin = System::Windows::Forms::Padding(4);
				 this->checkBox2->Name = L"checkBox2";
				 this->checkBox2->Size = System::Drawing::Size(171, 34);
				 this->checkBox2->TabIndex = 6;
				 this->checkBox2->Text = L"完全符合";
				 this->checkBox2->UseVisualStyleBackColor = true;
				 // 
				 // textBox12
				 // 
				 this->textBox12->Location = System::Drawing::Point(232, 12);
				 this->textBox12->Margin = System::Windows::Forms::Padding(4);
				 this->textBox12->Name = L"textBox12";
				 this->textBox12->Size = System::Drawing::Size(976, 43);
				 this->textBox12->TabIndex = 0;
				 // 
				 // button10
				 // 
				 this->button10->Location = System::Drawing::Point(1238, 8);
				 this->button10->Margin = System::Windows::Forms::Padding(4);
				 this->button10->Name = L"button10";
				 this->button10->Size = System::Drawing::Size(172, 64);
				 this->button10->TabIndex = 1;
				 this->button10->Text = L"查詢";
				 this->button10->UseVisualStyleBackColor = true;
				 this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
				 // 
				 // purchase
				 // 
				 this->purchase->Controls->Add(this->label13);
				 this->purchase->Controls->Add(this->comboBox2);
				 this->purchase->Controls->Add(this->button6);
				 this->purchase->Controls->Add(this->textBox8);
				 this->purchase->Controls->Add(this->textBox7);
				 this->purchase->Controls->Add(this->textBox6);
				 this->purchase->Controls->Add(this->textBox5);
				 this->purchase->Controls->Add(this->textBox4);
				 this->purchase->Controls->Add(this->textBox3);
				 this->purchase->Controls->Add(this->label7);
				 this->purchase->Controls->Add(this->label6);
				 this->purchase->Controls->Add(this->label5);
				 this->purchase->Controls->Add(this->label4);
				 this->purchase->Controls->Add(this->label3);
				 this->purchase->Controls->Add(this->label2);
				 this->purchase->Controls->Add(this->label1);
				 this->purchase->Controls->Add(this->textBox2);
				 this->purchase->Location = System::Drawing::Point(47, 39);
				 this->purchase->Margin = System::Windows::Forms::Padding(4);
				 this->purchase->Name = L"purchase";
				 this->purchase->Size = System::Drawing::Size(1698, 898);
				 this->purchase->TabIndex = 12;
				 this->purchase->Visible = false;
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Location = System::Drawing::Point(528, 628);
				 this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(73, 30);
				 this->label13->TabIndex = 17;
				 this->label13->Text = L"類別";
				 // 
				 // comboBox2
				 // 
				 this->comboBox2->FormattingEnabled = true;
				 this->comboBox2->Location = System::Drawing::Point(670, 628);
				 this->comboBox2->Margin = System::Windows::Forms::Padding(6);
				 this->comboBox2->Name = L"comboBox2";
				 this->comboBox2->Size = System::Drawing::Size(436, 38);
				 this->comboBox2->TabIndex = 16;
				 this->comboBox2->SelectedValueChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedValueChanged);
				 // 
				 // button6
				 // 
				 this->button6->Font = (gcnew System::Drawing::Font(L"新細明體", 12));
				 this->button6->Location = System::Drawing::Point(754, 720);
				 this->button6->Margin = System::Windows::Forms::Padding(4);
				 this->button6->Name = L"button6";
				 this->button6->Size = System::Drawing::Size(188, 64);
				 this->button6->TabIndex = 14;
				 this->button6->Text = L"確認";
				 this->button6->UseVisualStyleBackColor = true;
				 this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
				 // 
				 // textBox8
				 // 
				 this->textBox8->AcceptsTab = true;
				 this->textBox8->Location = System::Drawing::Point(670, 136);
				 this->textBox8->Margin = System::Windows::Forms::Padding(4);
				 this->textBox8->Name = L"textBox8";
				 this->textBox8->Size = System::Drawing::Size(436, 43);
				 this->textBox8->TabIndex = 13;
				 // 
				 // textBox7
				 // 
				 this->textBox7->AcceptsTab = true;
				 this->textBox7->Location = System::Drawing::Point(670, 220);
				 this->textBox7->Margin = System::Windows::Forms::Padding(4);
				 this->textBox7->Name = L"textBox7";
				 this->textBox7->Size = System::Drawing::Size(436, 43);
				 this->textBox7->TabIndex = 12;
				 // 
				 // textBox6
				 // 
				 this->textBox6->AcceptsTab = true;
				 this->textBox6->Location = System::Drawing::Point(670, 304);
				 this->textBox6->Margin = System::Windows::Forms::Padding(4);
				 this->textBox6->Name = L"textBox6";
				 this->textBox6->Size = System::Drawing::Size(436, 43);
				 this->textBox6->TabIndex = 11;
				 // 
				 // textBox5
				 // 
				 this->textBox5->AcceptsTab = true;
				 this->textBox5->Location = System::Drawing::Point(670, 394);
				 this->textBox5->Margin = System::Windows::Forms::Padding(4);
				 this->textBox5->Name = L"textBox5";
				 this->textBox5->Size = System::Drawing::Size(436, 43);
				 this->textBox5->TabIndex = 10;
				 // 
				 // textBox4
				 // 
				 this->textBox4->AcceptsTab = true;
				 this->textBox4->Location = System::Drawing::Point(670, 468);
				 this->textBox4->Margin = System::Windows::Forms::Padding(4);
				 this->textBox4->Name = L"textBox4";
				 this->textBox4->Size = System::Drawing::Size(436, 43);
				 this->textBox4->TabIndex = 9;
				 // 
				 // textBox3
				 // 
				 this->textBox3->AcceptsTab = true;
				 this->textBox3->Location = System::Drawing::Point(670, 544);
				 this->textBox3->Margin = System::Windows::Forms::Padding(4);
				 this->textBox3->Name = L"textBox3";
				 this->textBox3->Size = System::Drawing::Size(436, 43);
				 this->textBox3->TabIndex = 8;
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(528, 550);
				 this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(73, 30);
				 this->label7->TabIndex = 7;
				 this->label7->Text = L"溫度";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(528, 142);
				 this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(73, 30);
				 this->label6->TabIndex = 6;
				 this->label6->Text = L"價格";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(528, 232);
				 this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(73, 30);
				 this->label5->TabIndex = 5;
				 this->label5->Text = L"數量";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(528, 310);
				 this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(133, 30);
				 this->label4->TabIndex = 4;
				 this->label4->Text = L"到店日期";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(528, 400);
				 this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(103, 30);
				 this->label3->TabIndex = 3;
				 this->label3->Text = L"到期日";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(528, 474);
				 this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(133, 30);
				 this->label2->TabIndex = 2;
				 this->label2->Text = L"烹飪時間";
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(528, 58);
				 this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(73, 30);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"品名";
				 // 
				 // textBox2
				 // 
				 this->textBox2->AcceptsTab = true;
				 this->textBox2->Location = System::Drawing::Point(670, 52);
				 this->textBox2->Margin = System::Windows::Forms::Padding(4);
				 this->textBox2->Name = L"textBox2";
				 this->textBox2->Size = System::Drawing::Size(436, 43);
				 this->textBox2->TabIndex = 0;
				 // 
				 // login
				 // 
				 this->login->Controls->Add(this->button11);
				 this->login->Controls->Add(this->passwordbox);
				 this->login->Controls->Add(this->label9);
				 this->login->Controls->Add(this->label8);
				 this->login->Controls->Add(this->account);
				 this->login->Location = System::Drawing::Point(13, 9);
				 this->login->Margin = System::Windows::Forms::Padding(4);
				 this->login->Name = L"login";
				 this->login->Size = System::Drawing::Size(1768, 924);
				 this->login->TabIndex = 13;
				 // 
				 // button11
				 // 
				 this->button11->Location = System::Drawing::Point(716, 545);
				 this->button11->Name = L"button11";
				 this->button11->Size = System::Drawing::Size(161, 61);
				 this->button11->TabIndex = 17;
				 this->button11->Text = L"登入";
				 this->button11->UseVisualStyleBackColor = true;
				 this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
				 // 
				 // passwordbox
				 // 
				 this->passwordbox->Location = System::Drawing::Point(716, 408);
				 this->passwordbox->Margin = System::Windows::Forms::Padding(4);
				 this->passwordbox->Name = L"passwordbox";
				 this->passwordbox->Size = System::Drawing::Size(336, 43);
				 this->passwordbox->TabIndex = 16;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(512, 408);
				 this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(73, 30);
				 this->label9->TabIndex = 15;
				 this->label9->Text = L"密碼";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(512, 228);
				 this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(73, 30);
				 this->label8->TabIndex = 14;
				 this->label8->Text = L"帳號";
				 // 
				 // account
				 // 
				 this->account->Location = System::Drawing::Point(716, 216);
				 this->account->Margin = System::Windows::Forms::Padding(4);
				 this->account->Name = L"account";
				 this->account->Size = System::Drawing::Size(336, 43);
				 this->account->TabIndex = 13;
				 // 
				 // sell
				 // 
				 this->sell->Controls->Add(this->button9);
				 this->sell->Controls->Add(this->label16);
				 this->sell->Controls->Add(this->textBox9);
				 this->sell->Controls->Add(this->label15);
				 this->sell->Controls->Add(this->label14);
				 this->sell->Controls->Add(this->label10);
				 this->sell->Controls->Add(this->button8);
				 this->sell->Controls->Add(this->button7);
				 this->sell->Controls->Add(this->dataGridView2);
				 this->sell->Controls->Add(this->textBox10);
				 this->sell->Controls->Add(this->textBox11);
				 this->sell->Controls->Add(this->label11);
				 this->sell->Controls->Add(this->label12);
				 this->sell->Location = System::Drawing::Point(51, 39);
				 this->sell->Margin = System::Windows::Forms::Padding(4);
				 this->sell->Name = L"sell";
				 this->sell->Size = System::Drawing::Size(1709, 890);
				 this->sell->TabIndex = 14;
				 this->sell->Visible = false;
				 // 
				 // button9
				 // 
				 this->button9->Location = System::Drawing::Point(221, 535);
				 this->button9->Margin = System::Windows::Forms::Padding(4);
				 this->button9->Name = L"button9";
				 this->button9->Size = System::Drawing::Size(168, 59);
				 this->button9->TabIndex = 25;
				 this->button9->Text = L"確認";
				 this->button9->UseVisualStyleBackColor = true;
				 this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Location = System::Drawing::Point(57, 424);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(81, 30);
				 this->label16->TabIndex = 24;
				 this->label16->Text = L"實收:";
				 // 
				 // textBox9
				 // 
				 this->textBox9->Location = System::Drawing::Point(221, 424);
				 this->textBox9->Name = L"textBox9";
				 this->textBox9->Size = System::Drawing::Size(436, 43);
				 this->textBox9->TabIndex = 23;
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Location = System::Drawing::Point(704, 836);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(81, 30);
				 this->label15->TabIndex = 22;
				 this->label15->Text = L"找零:";
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Location = System::Drawing::Point(704, 778);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(81, 30);
				 this->label14->TabIndex = 21;
				 this->label14->Text = L"實收:";
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(704, 714);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(81, 30);
				 this->label10->TabIndex = 20;
				 this->label10->Text = L"總價:";
				 // 
				 // button8
				 // 
				 this->button8->Location = System::Drawing::Point(1238, 696);
				 this->button8->Name = L"button8";
				 this->button8->Size = System::Drawing::Size(168, 66);
				 this->button8->TabIndex = 19;
				 this->button8->Text = L"結帳";
				 this->button8->UseVisualStyleBackColor = true;
				 this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
				 // 
				 // button7
				 // 
				 this->button7->Location = System::Drawing::Point(221, 285);
				 this->button7->Margin = System::Windows::Forms::Padding(4);
				 this->button7->Name = L"button7";
				 this->button7->Size = System::Drawing::Size(168, 59);
				 this->button7->TabIndex = 18;
				 this->button7->Text = L"新增";
				 this->button7->UseVisualStyleBackColor = true;
				 this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
				 // 
				 // dataGridView2
				 // 
				 this->dataGridView2->AllowUserToAddRows = false;
				 this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
				 this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
					 this->Column1,
						 this->s品名, this->s價格, this->s數量, this->s小記
				 });
				 this->dataGridView2->Location = System::Drawing::Point(704, 28);
				 this->dataGridView2->Margin = System::Windows::Forms::Padding(4);
				 this->dataGridView2->Name = L"dataGridView2";
				 this->dataGridView2->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
				 this->dataGridView2->RowHeadersVisible = false;
				 this->dataGridView2->RowTemplate->Height = 45;
				 this->dataGridView2->Size = System::Drawing::Size(959, 624);
				 this->dataGridView2->TabIndex = 17;
				 this->dataGridView2->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView2_CellValueChanged);
				 // 
				 // Column1
				 // 
				 this->Column1->HeaderText = L"流水號";
				 this->Column1->Name = L"Column1";
				 this->Column1->Visible = false;
				 // 
				 // s品名
				 // 
				 this->s品名->HeaderText = L"品名";
				 this->s品名->Name = L"s品名";
				 // 
				 // s價格
				 // 
				 this->s價格->HeaderText = L"價格";
				 this->s價格->Name = L"s價格";
				 // 
				 // s數量
				 // 
				 this->s數量->HeaderText = L"數量";
				 this->s數量->Name = L"s數量";
				 // 
				 // s小記
				 // 
				 this->s小記->HeaderText = L"小記";
				 this->s小記->Name = L"s小記";
				 // 
				 // textBox10
				 // 
				 this->textBox10->AcceptsTab = true;
				 this->textBox10->Location = System::Drawing::Point(221, 184);
				 this->textBox10->Margin = System::Windows::Forms::Padding(4);
				 this->textBox10->Name = L"textBox10";
				 this->textBox10->Size = System::Drawing::Size(436, 43);
				 this->textBox10->TabIndex = 15;
				 // 
				 // textBox11
				 // 
				 this->textBox11->AcceptsTab = true;
				 this->textBox11->Location = System::Drawing::Point(221, 77);
				 this->textBox11->Margin = System::Windows::Forms::Padding(4);
				 this->textBox11->Name = L"textBox11";
				 this->textBox11->Size = System::Drawing::Size(436, 43);
				 this->textBox11->TabIndex = 14;
				 this->textBox11->TextChanged += gcnew System::EventHandler(this, &Form1::textBox11_TextChanged);
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Location = System::Drawing::Point(57, 187);
				 this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(73, 30);
				 this->label11->TabIndex = 8;
				 this->label11->Text = L"數量";
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(57, 80);
				 this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(103, 30);
				 this->label12->TabIndex = 7;
				 this->label12->Text = L"流水號";
				 // 
				 // button12
				 // 
				 this->button12->Enabled = false;
				 this->button12->Location = System::Drawing::Point(1780, 609);
				 this->button12->Name = L"button12";
				 this->button12->Size = System::Drawing::Size(200, 64);
				 this->button12->TabIndex = 15;
				 this->button12->Text = L"登出";
				 this->button12->UseVisualStyleBackColor = true;
				 this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
				 // 
				 // label17
				 // 
				 this->label17->AutoSize = true;
				 this->label17->Location = System::Drawing::Point(225, 974);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(0, 30);
				 this->label17->TabIndex = 16;
				 // 
				 // label18
				 // 
				 this->label18->AutoSize = true;
				 this->label18->Location = System::Drawing::Point(724, 974);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(0, 30);
				 this->label18->TabIndex = 17;
				 // 
				 // label19
				 // 
				 this->label19->AutoSize = true;
				 this->label19->Location = System::Drawing::Point(1196, 974);
				 this->label19->Name = L"label19";
				 this->label19->Size = System::Drawing::Size(0, 30);
				 this->label19->TabIndex = 18;
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(16, 30);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(3178, 1046);
				 this->Controls->Add(this->label19);
				 this->Controls->Add(this->label18);
				 this->Controls->Add(this->label17);
				 this->Controls->Add(this->button12);
				 this->Controls->Add(this->login);
				 this->Controls->Add(this->button5);
				 this->Controls->Add(this->button4);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->search);
				 this->Controls->Add(this->purchase);
				 this->Controls->Add(this->sell);
				 this->Controls->Add(this->member);
				 this->Margin = System::Windows::Forms::Padding(4);
				 this->MinimizeBox = false;
				 this->Name = L"Form1";
				 this->Text = L"Form1";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
				 this->search->ResumeLayout(false);
				 this->search->PerformLayout();
				 this->member->ResumeLayout(false);
				 this->member->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
				 this->purchase->ResumeLayout(false);
				 this->purchase->PerformLayout();
				 this->login->ResumeLayout(false);
				 this->login->PerformLayout();
				 this->sell->ResumeLayout(false);
				 this->sell->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Product A;
		A.search_product(connect, comboBox1, checkBox1, textBox1, dataGridView1);
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox2->SelectedItem == "微波食品")
		{
			SYSTEMTIME arval = stringtotime(textBox6->Text);//{ 2017,12,0,7,0,0,0,0 };
			SYSTEMTIME expired = stringtotime(textBox5->Text);// { 2017, 12, 0, 8, 0, 0, 0, 0 };
			SYSTEMTIME cooked{ 0,0,0,0,0,0,Convert::ToInt32(textBox4->Text),0 };
			int price = Convert::ToInt32(textBox8->Text);
			int temp = Convert::ToInt32(textBox3->Text);
			theCooked tc(0, textBox2->Text, arval, expired, cooked, price, temp);
			tc.set_number(Convert::ToInt32(textBox7->Text));
			tc.stock(connect);
		}
		else if (comboBox2->SelectedItem == "生鮮食品")
		{
			SYSTEMTIME arval = stringtotime(textBox6->Text);//{ 2017,12,0,7,0,0,0,0 };
			SYSTEMTIME expired = stringtotime(textBox5->Text);// { 2017, 12, 0, 8, 0, 0, 0, 0 };
			int price = Convert::ToInt32(textBox8->Text);
			int temp = Convert::ToInt32(textBox3->Text);
			theFrozen tf(0, textBox2->Text, arval, expired, price, temp);
			tf.set_number(Convert::ToInt32(textBox7->Text));
			tf.stock(connect);
		}
		else if (comboBox2->SelectedItem == "食品")
		{
			SYSTEMTIME arval = stringtotime(textBox6->Text);//{ 2017,12,0,7,0,0,0,0 };
			SYSTEMTIME expired = stringtotime(textBox5->Text);// { 2017, 12, 0, 8, 0, 0, 0, 0 };
			int price = Convert::ToInt32(textBox8->Text);
			Food f(0, textBox2->Text, arval, expired, price);
			f.set_number(Convert::ToInt32(textBox7->Text));
			f.stock(connect);
			/*WORD wYear;
			WORD wMonth;
			WORD wDayOfWeek;
			WORD wDay;
			WORD wHour;
			WORD wMinute;
			WORD wSecond;
			WORD wMilliseconds;*/
		}
		else if (comboBox2->SelectedItem == "日用品")
		{
			SYSTEMTIME arval = stringtotime(textBox6->Text);//{ 2017,12,0,7,0,0,0,0 };
			int price = Convert::ToInt32(textBox8->Text);

			Product p(0, textBox2->Text, arval, arval, price);
			p.set_number(Convert::ToInt32(textBox7->Text));
			p.stock(connect);
		}

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		search->Visible = true;

		sell->Visible = false;
		purchase->Visible = false;
		member->Visible = false;
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		purchase->Visible = true;

		sell->Visible = false;
		search->Visible = false;
		member->Visible = false;
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		sell->Visible = true;

		purchase->Visible = false;
		search->Visible = false;
		member->Visible = false;
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		member->Visible = true;

		purchase->Visible = false;
		search->Visible = false;
		sell->Visible = false;
	}
	private: System::Void comboBox2_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox2->SelectedItem == "微波食品") {
			textBox3->Enabled = true;
			textBox4->Enabled = true;
			textBox5->Enabled = true;
		}
		if (comboBox2->SelectedItem == "生鮮食品") {
			textBox4->Enabled = false;
			textBox5->Enabled = true;
			textBox3->Enabled = true;
		}
		if (comboBox2->SelectedItem == "食品") {
			textBox5->Enabled = true;
			textBox4->Enabled = false;
			textBox3->Enabled = false;
		}
		if (comboBox2->SelectedItem == "日用品") {
			textBox4->Enabled = false;
			textBox3->Enabled = false;
			textBox5->Enabled = false;
		}

	}
			 SYSTEMTIME stringtotime(String^ s)
			 {
				 SYSTEMTIME t;
				 array<String^>^ words;
				 words = s->Split('/');
				 t.wYear = Convert::ToInt32(words[0]);
				 t.wMonth = Convert::ToInt32(words[1]);
				 t.wDay = Convert::ToInt32(words[2]);
				 return t;
			 }
	private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
		Product A;
		A.search_sell_proudct(connect,textBox11,textBox10,dataGridView2);
		int sum = 0;
		for (int i = 0; i < dataGridView2->Rows->Count; i++)
			sum += Convert::ToInt32(dataGridView2->Rows[i]->Cells[4]->Value);
		label10->Text = "總價:" + Convert::ToString(sum);
		textBox11->Text = "";
		textBox10->Text = "";
	}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	Product A;
	for (int i = 0; i <dataGridView2->Rows->Count; i++)
		A.sell_product(connect, Convert::ToString(dataGridView2->Rows[i]->Cells[0]->Value), Convert::ToString(dataGridView2->Rows[i]->Cells[3]->Value));
	dataGridView2->Rows->Clear();
	dataGridView2->Refresh();
	label10->Text = "總價:";
	label14->Text = "實收:";
	label15->Text = "找零:";
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show("銷售成功");
}

private: System::Void dataGridView2_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	String^ value;
	int sum;
	for (int i = 0; i < dataGridView2->Rows->Count; i++) {
		value = Convert::ToString(Convert::ToInt32(dataGridView2->Rows[i]->Cells[2]->Value)*Convert::ToInt32(dataGridView2->Rows[i]->Cells[3]->Value));
		if (dataGridView2->Rows[i]->Cells[4]->Value != value)
			dataGridView2->Rows[i]->Cells[4]->Value = value;
	}
	for (int i = 0; i < dataGridView2->Rows->Count; i++)
		sum += Convert::ToInt32(dataGridView2->Rows[i]->Cells[4]->Value);
	label10->Text = "總價:" + Convert::ToString(sum);
}
private: System::Void textBox11_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	label14->Text = "實收:" + textBox9->Text;
	array<String^>^ words1;
	words1 = label10->Text->Split(':');
	array<String^>^ words2;
	words2 = label14->Text->Split(':');
	label15->Text = "找零:" + Convert::ToString(Convert::ToInt32(words1[1]) - Convert::ToInt32(words2[1]));
	textBox9->Text = "";
}
private: System::Void dataGridView3_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}

private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	Staff A;
	A.staff_search(connect, comboBox3, checkBox2, textBox12, dataGridView3);
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	Staff A;
	if (A.login(connect, account, passwordbox))
	{
		A.staff_getinfo(connect, account, label17, label18, label19);
		if (label19->Text == "職位:店長")
		{
			button3->Enabled = true;
			button5->Enabled = true;
		}
		purchase->Visible = false;
		sell->Visible = false;
		search->Visible = false;
		member->Visible = false;
		login->Visible = false;
		button2->Enabled = true;
		button4->Enabled = true;
		button12->Enabled = true;
	}
	account->Text = "";
	passwordbox->Text = "";
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	purchase->Visible = false;
	sell->Visible = false;
	search->Visible = false;
	member->Visible = false;
	login->Visible = true;
	button2->Enabled = false;
	button3->Enabled = false;
	button4->Enabled = false;
	button5->Enabled = false;
	button12->Enabled = false;
	label17->Text = "";
	label18->Text = "";
	label19->Text = "";
}
};
}

