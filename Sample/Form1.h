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
				/* �s���}�� */
				connect->Open();

				/* �ǰe���O�� MySQL */
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
			comboBox1->Items->Add("��ܥ���");
			comboBox1->Items->Add("�~�W");
			comboBox1->Items->Add("����");
			comboBox1->Items->Add("�ƶq");
			comboBox1->Items->Add("�쩱�ɶ�");
			comboBox1->Items->Add("�����");
			comboBox1->Items->Add("�i���ɶ�");
			comboBox1->Items->Add("�ū�");
			comboBox1->Items->Add("���O");
			comboBox1->SelectedIndex = 0;
			//
			//TODO: Add the constructor code here
			//
			comboBox2->Items->Add("�L�i���~");
			comboBox2->Items->Add("���A���~");
			comboBox2->Items->Add("���~");
			comboBox2->Items->Add("��Ϋ~");
			comboBox2->SelectedIndex = 0;

			comboBox3->Items->Add("��ܥ���");
			comboBox3->Items->Add("�m�W");
			comboBox3->Items->Add("�ƯZ");
			comboBox3->Items->Add("�~��");
			comboBox3->Items->Add("¾��");
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
		/* MySQL�s�����B���O�ǰe�B���Ū�� */
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �y����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �~�W;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �ƶq;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �쩱�ɶ�;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �i���ɶ�;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �ū�;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ���O;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::ComboBox^  comboBox2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  s�~�W;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  s����;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  s�ƶq;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  s�p�O;
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
private: System::Windows::Forms::Button^  button13;
private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::Label^  label25;
private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::TextBox^  textBox17;
private: System::Windows::Forms::TextBox^  textBox18;
private: System::Windows::Forms::TextBox^  textBox15;
private: System::Windows::Forms::TextBox^  textBox16;
private: System::Windows::Forms::TextBox^  textBox14;
private: System::Windows::Forms::TextBox^  textBox13;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::Button^  button17;
private: System::Windows::Forms::Button^  button16;
private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::DataGridView^  dataGridView4;









private: System::Windows::Forms::Button^  button18;
private: System::Windows::Forms::Button^  button20;
private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;


private: System::Windows::Forms::DataGridViewTextBoxColumn^  �H��;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  �P����;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  �P���@;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  �P���G;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  �P���T;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  �P���|;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  �P����;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  �P����;
private: System::Windows::Forms::Button^  button21;









































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
				 this->�y���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�~�W = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�ƶq = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�쩱�ɶ� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->����� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�i���ɶ� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�ū� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->���O = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button3 = (gcnew System::Windows::Forms::Button());
				 this->button4 = (gcnew System::Windows::Forms::Button());
				 this->button5 = (gcnew System::Windows::Forms::Button());
				 this->search = (gcnew System::Windows::Forms::Panel());
				 this->member = (gcnew System::Windows::Forms::Panel());
				 this->button17 = (gcnew System::Windows::Forms::Button());
				 this->button16 = (gcnew System::Windows::Forms::Button());
				 this->button15 = (gcnew System::Windows::Forms::Button());
				 this->textBox17 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox18 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox15 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox16 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox14 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox13 = (gcnew System::Windows::Forms::TextBox());
				 this->button14 = (gcnew System::Windows::Forms::Button());
				 this->label25 = (gcnew System::Windows::Forms::Label());
				 this->label24 = (gcnew System::Windows::Forms::Label());
				 this->label23 = (gcnew System::Windows::Forms::Label());
				 this->label22 = (gcnew System::Windows::Forms::Label());
				 this->label21 = (gcnew System::Windows::Forms::Label());
				 this->label20 = (gcnew System::Windows::Forms::Label());
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
				 this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
				 this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
				 this->label13 = (gcnew System::Windows::Forms::Label());
				 this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
				 this->button6 = (gcnew System::Windows::Forms::Button());
				 this->textBox8 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox7 = (gcnew System::Windows::Forms::TextBox());
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
				 this->button13 = (gcnew System::Windows::Forms::Button());
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
				 this->s�~�W = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->s���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->s�ƶq = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->s�p�O = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->textBox10 = (gcnew System::Windows::Forms::TextBox());
				 this->textBox11 = (gcnew System::Windows::Forms::TextBox());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->button12 = (gcnew System::Windows::Forms::Button());
				 this->label17 = (gcnew System::Windows::Forms::Label());
				 this->label18 = (gcnew System::Windows::Forms::Label());
				 this->label19 = (gcnew System::Windows::Forms::Label());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->button21 = (gcnew System::Windows::Forms::Button());
				 this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
				 this->button20 = (gcnew System::Windows::Forms::Button());
				 this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
				 this->�H�� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�P���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�P���@ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�P���G = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�P���T = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�P���| = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�P���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->�P���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
				 this->button18 = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
				 this->search->SuspendLayout();
				 this->member->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
				 this->purchase->SuspendLayout();
				 this->login->SuspendLayout();
				 this->sell->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
				 this->panel1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // textBox1
				 // 
				 this->textBox1->Location = System::Drawing::Point(232, 12);
				 this->textBox1->Margin = System::Windows::Forms::Padding(5);
				 this->textBox1->Name = L"textBox1";
				 this->textBox1->Size = System::Drawing::Size(975, 43);
				 this->textBox1->TabIndex = 0;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(1323, 12);
				 this->button1->Margin = System::Windows::Forms::Padding(5);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(171, 65);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"�d��";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->Location = System::Drawing::Point(16, 12);
				 this->comboBox1->Margin = System::Windows::Forms::Padding(5);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(191, 38);
				 this->comboBox1->TabIndex = 3;
				 // 
				 // dataGridView1
				 // 
				 this->dataGridView1->AllowUserToAddRows = false;
				 this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
					 this->�y����, this->�~�W,
						 this->����, this->�ƶq, this->�쩱�ɶ�, this->�����, this->�i���ɶ�, this->�ū�, this->���O
				 });
				 this->dataGridView1->Location = System::Drawing::Point(16, 122);
				 this->dataGridView1->Margin = System::Windows::Forms::Padding(5);
				 this->dataGridView1->Name = L"dataGridView1";
				 this->dataGridView1->RowHeadersVisible = false;
				 this->dataGridView1->RowTemplate->Height = 45;
				 this->dataGridView1->Size = System::Drawing::Size(1640, 710);
				 this->dataGridView1->TabIndex = 4;
				 // 
				 // �y����
				 // 
				 this->�y����->HeaderText = L"�y����";
				 this->�y����->Name = L"�y����";
				 // 
				 // �~�W
				 // 
				 this->�~�W->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
				 this->�~�W->DefaultCellStyle = dataGridViewCellStyle1;
				 this->�~�W->HeaderText = L"�~�W";
				 this->�~�W->Name = L"�~�W";
				 this->�~�W->Width = 127;
				 // 
				 // ����
				 // 
				 this->����->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->����->HeaderText = L"����";
				 this->����->Name = L"����";
				 this->����->Width = 127;
				 // 
				 // �ƶq
				 // 
				 this->�ƶq->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->�ƶq->HeaderText = L"�ƶq";
				 this->�ƶq->Name = L"�ƶq";
				 this->�ƶq->Width = 127;
				 // 
				 // �쩱�ɶ�
				 // 
				 this->�쩱�ɶ�->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->�쩱�ɶ�->HeaderText = L"�쩱�ɶ�";
				 this->�쩱�ɶ�->Name = L"�쩱�ɶ�";
				 this->�쩱�ɶ�->Width = 187;
				 // 
				 // �����
				 // 
				 this->�����->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->�����->HeaderText = L"�����";
				 this->�����->Name = L"�����";
				 this->�����->Width = 157;
				 // 
				 // �i���ɶ�
				 // 
				 this->�i���ɶ�->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->�i���ɶ�->HeaderText = L"�i���ɶ�";
				 this->�i���ɶ�->Name = L"�i���ɶ�";
				 this->�i���ɶ�->Width = 187;
				 // 
				 // �ū�
				 // 
				 this->�ū�->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->�ū�->HeaderText = L"�ū�";
				 this->�ū�->Name = L"�ū�";
				 this->�ū�->Width = 127;
				 // 
				 // ���O
				 // 
				 this->���O->HeaderText = L"���O";
				 this->���O->Name = L"���O";
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Location = System::Drawing::Point(16, 62);
				 this->checkBox1->Margin = System::Windows::Forms::Padding(5);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(171, 34);
				 this->checkBox1->TabIndex = 6;
				 this->checkBox1->Text = L"�����ŦX";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 // 
				 // button2
				 // 
				 this->button2->Enabled = false;
				 this->button2->Location = System::Drawing::Point(1781, 50);
				 this->button2->Margin = System::Windows::Forms::Padding(5);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(200, 75);
				 this->button2->TabIndex = 7;
				 this->button2->Text = L"�d�ߥ\��";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
				 // 
				 // button3
				 // 
				 this->button3->Enabled = false;
				 this->button3->Location = System::Drawing::Point(1781, 308);
				 this->button3->Margin = System::Windows::Forms::Padding(5);
				 this->button3->Name = L"button3";
				 this->button3->Size = System::Drawing::Size(200, 75);
				 this->button3->TabIndex = 8;
				 this->button3->Text = L"�i�f�\��";
				 this->button3->UseVisualStyleBackColor = true;
				 this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
				 // 
				 // button4
				 // 
				 this->button4->Enabled = false;
				 this->button4->Location = System::Drawing::Point(1781, 190);
				 this->button4->Margin = System::Windows::Forms::Padding(5);
				 this->button4->Name = L"button4";
				 this->button4->Size = System::Drawing::Size(200, 75);
				 this->button4->TabIndex = 9;
				 this->button4->Text = L"�P��\��";
				 this->button4->UseVisualStyleBackColor = true;
				 this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
				 // 
				 // button5
				 // 
				 this->button5->Enabled = false;
				 this->button5->Location = System::Drawing::Point(1781, 462);
				 this->button5->Margin = System::Windows::Forms::Padding(5);
				 this->button5->Name = L"button5";
				 this->button5->Size = System::Drawing::Size(200, 75);
				 this->button5->TabIndex = 10;
				 this->button5->Text = L"�H���޲z";
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
				 this->search->Location = System::Drawing::Point(61, 40);
				 this->search->Margin = System::Windows::Forms::Padding(5);
				 this->search->Name = L"search";
				 this->search->Size = System::Drawing::Size(1704, 895);
				 this->search->TabIndex = 11;
				 this->search->Visible = false;
				 // 
				 // member
				 // 
				 this->member->Controls->Add(this->button17);
				 this->member->Controls->Add(this->button16);
				 this->member->Controls->Add(this->button15);
				 this->member->Controls->Add(this->textBox17);
				 this->member->Controls->Add(this->textBox18);
				 this->member->Controls->Add(this->textBox15);
				 this->member->Controls->Add(this->textBox16);
				 this->member->Controls->Add(this->textBox14);
				 this->member->Controls->Add(this->textBox13);
				 this->member->Controls->Add(this->button14);
				 this->member->Controls->Add(this->label25);
				 this->member->Controls->Add(this->label24);
				 this->member->Controls->Add(this->label23);
				 this->member->Controls->Add(this->label22);
				 this->member->Controls->Add(this->label21);
				 this->member->Controls->Add(this->label20);
				 this->member->Controls->Add(this->dataGridView3);
				 this->member->Controls->Add(this->comboBox3);
				 this->member->Controls->Add(this->checkBox2);
				 this->member->Controls->Add(this->textBox12);
				 this->member->Controls->Add(this->button10);
				 this->member->Location = System::Drawing::Point(13, 10);
				 this->member->Margin = System::Windows::Forms::Padding(5);
				 this->member->Name = L"member";
				 this->member->Size = System::Drawing::Size(1725, 895);
				 this->member->TabIndex = 12;
				 this->member->Visible = false;
				 // 
				 // button17
				 // 
				 this->button17->Location = System::Drawing::Point(1275, 755);
				 this->button17->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button17->Name = L"button17";
				 this->button17->Size = System::Drawing::Size(117, 65);
				 this->button17->TabIndex = 28;
				 this->button17->Text = L"�T�w";
				 this->button17->UseVisualStyleBackColor = true;
				 this->button17->Visible = false;
				 this->button17->Click += gcnew System::EventHandler(this, &Form1::button17_Click);
				 // 
				 // button16
				 // 
				 this->button16->Location = System::Drawing::Point(1400, 755);
				 this->button16->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button16->Name = L"button16";
				 this->button16->Size = System::Drawing::Size(133, 65);
				 this->button16->TabIndex = 27;
				 this->button16->Text = L"����";
				 this->button16->UseVisualStyleBackColor = true;
				 this->button16->Visible = false;
				 this->button16->Click += gcnew System::EventHandler(this, &Form1::button16_Click);
				 // 
				 // button15
				 // 
				 this->button15->Location = System::Drawing::Point(1333, 755);
				 this->button15->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button15->Name = L"button15";
				 this->button15->Size = System::Drawing::Size(200, 65);
				 this->button15->TabIndex = 26;
				 this->button15->Text = L"�}��";
				 this->button15->UseVisualStyleBackColor = true;
				 this->button15->Click += gcnew System::EventHandler(this, &Form1::button15_Click);
				 // 
				 // textBox17
				 // 
				 this->textBox17->Location = System::Drawing::Point(1061, 565);
				 this->textBox17->Margin = System::Windows::Forms::Padding(5);
				 this->textBox17->Name = L"textBox17";
				 this->textBox17->Size = System::Drawing::Size(423, 43);
				 this->textBox17->TabIndex = 25;
				 // 
				 // textBox18
				 // 
				 this->textBox18->Location = System::Drawing::Point(1061, 655);
				 this->textBox18->Margin = System::Windows::Forms::Padding(5);
				 this->textBox18->Name = L"textBox18";
				 this->textBox18->Size = System::Drawing::Size(423, 43);
				 this->textBox18->TabIndex = 24;
				 // 
				 // textBox15
				 // 
				 this->textBox15->Location = System::Drawing::Point(1061, 352);
				 this->textBox15->Margin = System::Windows::Forms::Padding(5);
				 this->textBox15->Name = L"textBox15";
				 this->textBox15->Size = System::Drawing::Size(423, 43);
				 this->textBox15->TabIndex = 23;
				 // 
				 // textBox16
				 // 
				 this->textBox16->Location = System::Drawing::Point(1061, 460);
				 this->textBox16->Margin = System::Windows::Forms::Padding(5);
				 this->textBox16->Name = L"textBox16";
				 this->textBox16->Size = System::Drawing::Size(423, 43);
				 this->textBox16->TabIndex = 22;
				 // 
				 // textBox14
				 // 
				 this->textBox14->Location = System::Drawing::Point(1061, 260);
				 this->textBox14->Margin = System::Windows::Forms::Padding(5);
				 this->textBox14->Name = L"textBox14";
				 this->textBox14->Size = System::Drawing::Size(423, 43);
				 this->textBox14->TabIndex = 21;
				 // 
				 // textBox13
				 // 
				 this->textBox13->Location = System::Drawing::Point(1061, 170);
				 this->textBox13->Margin = System::Windows::Forms::Padding(5);
				 this->textBox13->Name = L"textBox13";
				 this->textBox13->Size = System::Drawing::Size(423, 43);
				 this->textBox13->TabIndex = 20;
				 // 
				 // button14
				 // 
				 this->button14->Location = System::Drawing::Point(1061, 755);
				 this->button14->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button14->Name = L"button14";
				 this->button14->Size = System::Drawing::Size(200, 65);
				 this->button14->TabIndex = 19;
				 this->button14->Text = L"�s�W/�ק�";
				 this->button14->UseVisualStyleBackColor = true;
				 this->button14->Click += gcnew System::EventHandler(this, &Form1::button14_Click);
				 // 
				 // label25
				 // 
				 this->label25->AutoSize = true;
				 this->label25->Location = System::Drawing::Point(973, 665);
				 this->label25->Name = L"label25";
				 this->label25->Size = System::Drawing::Size(81, 30);
				 this->label25->TabIndex = 12;
				 this->label25->Text = L"¾��:";
				 // 
				 // label24
				 // 
				 this->label24->AutoSize = true;
				 this->label24->Location = System::Drawing::Point(973, 562);
				 this->label24->Name = L"label24";
				 this->label24->Size = System::Drawing::Size(81, 30);
				 this->label24->TabIndex = 11;
				 this->label24->Text = L"�~��:";
				 // 
				 // label23
				 // 
				 this->label23->AutoSize = true;
				 this->label23->Location = System::Drawing::Point(973, 260);
				 this->label23->Name = L"label23";
				 this->label23->Size = System::Drawing::Size(81, 30);
				 this->label23->TabIndex = 10;
				 this->label23->Text = L"�K�X:";
				 // 
				 // label22
				 // 
				 this->label22->AutoSize = true;
				 this->label22->Location = System::Drawing::Point(973, 355);
				 this->label22->Name = L"label22";
				 this->label22->Size = System::Drawing::Size(81, 30);
				 this->label22->TabIndex = 9;
				 this->label22->Text = L"�m�W:";
				 // 
				 // label21
				 // 
				 this->label21->AutoSize = true;
				 this->label21->Location = System::Drawing::Point(973, 462);
				 this->label21->Name = L"label21";
				 this->label21->Size = System::Drawing::Size(81, 30);
				 this->label21->TabIndex = 8;
				 this->label21->Text = L"�ƯZ:";
				 // 
				 // label20
				 // 
				 this->label20->AutoSize = true;
				 this->label20->Location = System::Drawing::Point(973, 170);
				 this->label20->Name = L"label20";
				 this->label20->Size = System::Drawing::Size(81, 30);
				 this->label20->TabIndex = 7;
				 this->label20->Text = L"�b��:";
				 // 
				 // dataGridView3
				 // 
				 this->dataGridView3->AllowUserToAddRows = false;
				 this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
					 this->dataGridViewTextBoxColumn6,
						 this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, this->dataGridViewTextBoxColumn5
				 });
				 this->dataGridView3->Location = System::Drawing::Point(16, 120);
				 this->dataGridView3->Margin = System::Windows::Forms::Padding(5);
				 this->dataGridView3->Name = L"dataGridView3";
				 this->dataGridView3->RowHeadersVisible = false;
				 this->dataGridView3->RowTemplate->Height = 45;
				 this->dataGridView3->Size = System::Drawing::Size(811, 698);
				 this->dataGridView3->TabIndex = 4;
				 // 
				 // dataGridViewTextBoxColumn6
				 // 
				 this->dataGridViewTextBoxColumn6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->dataGridViewTextBoxColumn6->HeaderText = L"�b��";
				 this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
				 this->dataGridViewTextBoxColumn6->Width = 127;
				 // 
				 // dataGridViewTextBoxColumn2
				 // 
				 this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
				 this->dataGridViewTextBoxColumn2->DefaultCellStyle = dataGridViewCellStyle2;
				 this->dataGridViewTextBoxColumn2->HeaderText = L"�m�W";
				 this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
				 this->dataGridViewTextBoxColumn2->Width = 127;
				 // 
				 // dataGridViewTextBoxColumn3
				 // 
				 this->dataGridViewTextBoxColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->dataGridViewTextBoxColumn3->HeaderText = L"�ƯZ";
				 this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
				 this->dataGridViewTextBoxColumn3->Width = 127;
				 // 
				 // dataGridViewTextBoxColumn4
				 // 
				 this->dataGridViewTextBoxColumn4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->dataGridViewTextBoxColumn4->HeaderText = L"�~��";
				 this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
				 this->dataGridViewTextBoxColumn4->Width = 127;
				 // 
				 // dataGridViewTextBoxColumn5
				 // 
				 this->dataGridViewTextBoxColumn5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
				 this->dataGridViewTextBoxColumn5->HeaderText = L"¾��";
				 this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
				 this->dataGridViewTextBoxColumn5->Width = 127;
				 // 
				 // comboBox3
				 // 
				 this->comboBox3->FormattingEnabled = true;
				 this->comboBox3->Location = System::Drawing::Point(16, 12);
				 this->comboBox3->Margin = System::Windows::Forms::Padding(5);
				 this->comboBox3->Name = L"comboBox3";
				 this->comboBox3->Size = System::Drawing::Size(191, 38);
				 this->comboBox3->TabIndex = 3;
				 // 
				 // checkBox2
				 // 
				 this->checkBox2->AutoSize = true;
				 this->checkBox2->Location = System::Drawing::Point(19, 68);
				 this->checkBox2->Margin = System::Windows::Forms::Padding(5);
				 this->checkBox2->Name = L"checkBox2";
				 this->checkBox2->Size = System::Drawing::Size(171, 34);
				 this->checkBox2->TabIndex = 6;
				 this->checkBox2->Text = L"�����ŦX";
				 this->checkBox2->UseVisualStyleBackColor = true;
				 // 
				 // textBox12
				 // 
				 this->textBox12->Location = System::Drawing::Point(232, 12);
				 this->textBox12->Margin = System::Windows::Forms::Padding(5);
				 this->textBox12->Name = L"textBox12";
				 this->textBox12->Size = System::Drawing::Size(975, 43);
				 this->textBox12->TabIndex = 0;
				 // 
				 // button10
				 // 
				 this->button10->Location = System::Drawing::Point(1237, 8);
				 this->button10->Margin = System::Windows::Forms::Padding(5);
				 this->button10->Name = L"button10";
				 this->button10->Size = System::Drawing::Size(171, 65);
				 this->button10->TabIndex = 1;
				 this->button10->Text = L"�d��";
				 this->button10->UseVisualStyleBackColor = true;
				 this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
				 // 
				 // purchase
				 // 
				 this->purchase->Controls->Add(this->dateTimePicker2);
				 this->purchase->Controls->Add(this->dateTimePicker1);
				 this->purchase->Controls->Add(this->label13);
				 this->purchase->Controls->Add(this->comboBox2);
				 this->purchase->Controls->Add(this->button6);
				 this->purchase->Controls->Add(this->textBox8);
				 this->purchase->Controls->Add(this->textBox7);
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
				 this->purchase->Location = System::Drawing::Point(48, 40);
				 this->purchase->Margin = System::Windows::Forms::Padding(5);
				 this->purchase->Name = L"purchase";
				 this->purchase->Size = System::Drawing::Size(1699, 898);
				 this->purchase->TabIndex = 12;
				 this->purchase->Visible = false;
				 // 
				 // dateTimePicker2
				 // 
				 this->dateTimePicker2->Location = System::Drawing::Point(669, 390);
				 this->dateTimePicker2->Margin = System::Windows::Forms::Padding(8);
				 this->dateTimePicker2->Name = L"dateTimePicker2";
				 this->dateTimePicker2->Size = System::Drawing::Size(436, 43);
				 this->dateTimePicker2->TabIndex = 19;
				 // 
				 // dateTimePicker1
				 // 
				 this->dateTimePicker1->Location = System::Drawing::Point(669, 308);
				 this->dateTimePicker1->Margin = System::Windows::Forms::Padding(8);
				 this->dateTimePicker1->Name = L"dateTimePicker1";
				 this->dateTimePicker1->Size = System::Drawing::Size(436, 43);
				 this->dateTimePicker1->TabIndex = 18;
				 // 
				 // label13
				 // 
				 this->label13->AutoSize = true;
				 this->label13->Location = System::Drawing::Point(528, 628);
				 this->label13->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label13->Name = L"label13";
				 this->label13->Size = System::Drawing::Size(73, 30);
				 this->label13->TabIndex = 17;
				 this->label13->Text = L"���O";
				 // 
				 // comboBox2
				 // 
				 this->comboBox2->FormattingEnabled = true;
				 this->comboBox2->Location = System::Drawing::Point(669, 628);
				 this->comboBox2->Margin = System::Windows::Forms::Padding(5);
				 this->comboBox2->Name = L"comboBox2";
				 this->comboBox2->Size = System::Drawing::Size(436, 38);
				 this->comboBox2->TabIndex = 16;
				 this->comboBox2->SelectedValueChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedValueChanged);
				 // 
				 // button6
				 // 
				 this->button6->Font = (gcnew System::Drawing::Font(L"�s�ө���", 12));
				 this->button6->Location = System::Drawing::Point(755, 720);
				 this->button6->Margin = System::Windows::Forms::Padding(5);
				 this->button6->Name = L"button6";
				 this->button6->Size = System::Drawing::Size(187, 65);
				 this->button6->TabIndex = 14;
				 this->button6->Text = L"�T�{";
				 this->button6->UseVisualStyleBackColor = true;
				 this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
				 // 
				 // textBox8
				 // 
				 this->textBox8->AcceptsTab = true;
				 this->textBox8->Location = System::Drawing::Point(669, 135);
				 this->textBox8->Margin = System::Windows::Forms::Padding(5);
				 this->textBox8->Name = L"textBox8";
				 this->textBox8->Size = System::Drawing::Size(436, 43);
				 this->textBox8->TabIndex = 13;
				 // 
				 // textBox7
				 // 
				 this->textBox7->AcceptsTab = true;
				 this->textBox7->Location = System::Drawing::Point(669, 220);
				 this->textBox7->Margin = System::Windows::Forms::Padding(5);
				 this->textBox7->Name = L"textBox7";
				 this->textBox7->Size = System::Drawing::Size(436, 43);
				 this->textBox7->TabIndex = 12;
				 // 
				 // textBox4
				 // 
				 this->textBox4->AcceptsTab = true;
				 this->textBox4->Location = System::Drawing::Point(669, 468);
				 this->textBox4->Margin = System::Windows::Forms::Padding(5);
				 this->textBox4->Name = L"textBox4";
				 this->textBox4->Size = System::Drawing::Size(436, 43);
				 this->textBox4->TabIndex = 9;
				 // 
				 // textBox3
				 // 
				 this->textBox3->AcceptsTab = true;
				 this->textBox3->Location = System::Drawing::Point(669, 545);
				 this->textBox3->Margin = System::Windows::Forms::Padding(5);
				 this->textBox3->Name = L"textBox3";
				 this->textBox3->Size = System::Drawing::Size(436, 43);
				 this->textBox3->TabIndex = 8;
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(528, 550);
				 this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(73, 30);
				 this->label7->TabIndex = 7;
				 this->label7->Text = L"�ū�";
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(528, 142);
				 this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(73, 30);
				 this->label6->TabIndex = 6;
				 this->label6->Text = L"����";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(528, 232);
				 this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(73, 30);
				 this->label5->TabIndex = 5;
				 this->label5->Text = L"�ƶq";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(528, 310);
				 this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(133, 30);
				 this->label4->TabIndex = 4;
				 this->label4->Text = L"�쩱���";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(528, 400);
				 this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(103, 30);
				 this->label3->TabIndex = 3;
				 this->label3->Text = L"�����";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(528, 475);
				 this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(133, 30);
				 this->label2->TabIndex = 2;
				 this->label2->Text = L"�i���ɶ�";
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(528, 58);
				 this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(73, 30);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"�~�W";
				 // 
				 // textBox2
				 // 
				 this->textBox2->AcceptsTab = true;
				 this->textBox2->Location = System::Drawing::Point(669, 52);
				 this->textBox2->Margin = System::Windows::Forms::Padding(5);
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
				 this->login->Location = System::Drawing::Point(13, 10);
				 this->login->Margin = System::Windows::Forms::Padding(5);
				 this->login->Name = L"login";
				 this->login->Size = System::Drawing::Size(1768, 925);
				 this->login->TabIndex = 13;
				 // 
				 // button11
				 // 
				 this->button11->Location = System::Drawing::Point(715, 545);
				 this->button11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button11->Name = L"button11";
				 this->button11->Size = System::Drawing::Size(160, 60);
				 this->button11->TabIndex = 17;
				 this->button11->Text = L"�n�J";
				 this->button11->UseVisualStyleBackColor = true;
				 this->button11->Click += gcnew System::EventHandler(this, &Form1::button11_Click);
				 // 
				 // passwordbox
				 // 
				 this->passwordbox->Location = System::Drawing::Point(715, 408);
				 this->passwordbox->Margin = System::Windows::Forms::Padding(5);
				 this->passwordbox->Name = L"passwordbox";
				 this->passwordbox->PasswordChar = '*';
				 this->passwordbox->Size = System::Drawing::Size(335, 43);
				 this->passwordbox->TabIndex = 16;
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Location = System::Drawing::Point(512, 408);
				 this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(73, 30);
				 this->label9->TabIndex = 15;
				 this->label9->Text = L"�K�X";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(512, 228);
				 this->label8->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(73, 30);
				 this->label8->TabIndex = 14;
				 this->label8->Text = L"�b��";
				 // 
				 // account
				 // 
				 this->account->Location = System::Drawing::Point(715, 215);
				 this->account->Margin = System::Windows::Forms::Padding(5);
				 this->account->Name = L"account";
				 this->account->Size = System::Drawing::Size(335, 43);
				 this->account->TabIndex = 13;
				 // 
				 // sell
				 // 
				 this->sell->Controls->Add(this->button13);
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
				 this->sell->Location = System::Drawing::Point(51, 40);
				 this->sell->Margin = System::Windows::Forms::Padding(5);
				 this->sell->Name = L"sell";
				 this->sell->Size = System::Drawing::Size(1709, 890);
				 this->sell->TabIndex = 14;
				 this->sell->Visible = false;
				 // 
				 // button13
				 // 
				 this->button13->Location = System::Drawing::Point(1429, 695);
				 this->button13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button13->Name = L"button13";
				 this->button13->Size = System::Drawing::Size(168, 65);
				 this->button13->TabIndex = 26;
				 this->button13->Text = L"���m";
				 this->button13->UseVisualStyleBackColor = true;
				 this->button13->Click += gcnew System::EventHandler(this, &Form1::button13_Click);
				 // 
				 // button9
				 // 
				 this->button9->Location = System::Drawing::Point(221, 535);
				 this->button9->Margin = System::Windows::Forms::Padding(5);
				 this->button9->Name = L"button9";
				 this->button9->Size = System::Drawing::Size(168, 60);
				 this->button9->TabIndex = 25;
				 this->button9->Text = L"�T�{";
				 this->button9->UseVisualStyleBackColor = true;
				 this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
				 // 
				 // label16
				 // 
				 this->label16->AutoSize = true;
				 this->label16->Location = System::Drawing::Point(56, 425);
				 this->label16->Name = L"label16";
				 this->label16->Size = System::Drawing::Size(81, 30);
				 this->label16->TabIndex = 24;
				 this->label16->Text = L"�ꦬ:";
				 // 
				 // textBox9
				 // 
				 this->textBox9->Location = System::Drawing::Point(221, 425);
				 this->textBox9->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->textBox9->Name = L"textBox9";
				 this->textBox9->Size = System::Drawing::Size(436, 43);
				 this->textBox9->TabIndex = 23;
				 // 
				 // label15
				 // 
				 this->label15->AutoSize = true;
				 this->label15->Location = System::Drawing::Point(704, 835);
				 this->label15->Name = L"label15";
				 this->label15->Size = System::Drawing::Size(81, 30);
				 this->label15->TabIndex = 22;
				 this->label15->Text = L"��s:";
				 // 
				 // label14
				 // 
				 this->label14->AutoSize = true;
				 this->label14->Location = System::Drawing::Point(704, 778);
				 this->label14->Name = L"label14";
				 this->label14->Size = System::Drawing::Size(81, 30);
				 this->label14->TabIndex = 21;
				 this->label14->Text = L"�ꦬ:";
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Location = System::Drawing::Point(704, 715);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(81, 30);
				 this->label10->TabIndex = 20;
				 this->label10->Text = L"�`��:";
				 // 
				 // button8
				 // 
				 this->button8->Location = System::Drawing::Point(1237, 695);
				 this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button8->Name = L"button8";
				 this->button8->Size = System::Drawing::Size(168, 65);
				 this->button8->TabIndex = 19;
				 this->button8->Text = L"���b";
				 this->button8->UseVisualStyleBackColor = true;
				 this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
				 // 
				 // button7
				 // 
				 this->button7->Location = System::Drawing::Point(221, 285);
				 this->button7->Margin = System::Windows::Forms::Padding(5);
				 this->button7->Name = L"button7";
				 this->button7->Size = System::Drawing::Size(168, 60);
				 this->button7->TabIndex = 18;
				 this->button7->Text = L"�s�W";
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
						 this->s�~�W, this->s����, this->s�ƶq, this->s�p�O
				 });
				 this->dataGridView2->Location = System::Drawing::Point(704, 28);
				 this->dataGridView2->Margin = System::Windows::Forms::Padding(5);
				 this->dataGridView2->Name = L"dataGridView2";
				 this->dataGridView2->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
				 this->dataGridView2->RowHeadersVisible = false;
				 this->dataGridView2->RowTemplate->Height = 45;
				 this->dataGridView2->Size = System::Drawing::Size(960, 625);
				 this->dataGridView2->TabIndex = 17;
				 this->dataGridView2->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView2_CellValueChanged);
				 // 
				 // Column1
				 // 
				 this->Column1->HeaderText = L"�y����";
				 this->Column1->Name = L"Column1";
				 this->Column1->Visible = false;
				 // 
				 // s�~�W
				 // 
				 this->s�~�W->HeaderText = L"�~�W";
				 this->s�~�W->Name = L"s�~�W";
				 // 
				 // s����
				 // 
				 this->s����->HeaderText = L"����";
				 this->s����->Name = L"s����";
				 // 
				 // s�ƶq
				 // 
				 this->s�ƶq->HeaderText = L"�ƶq";
				 this->s�ƶq->Name = L"s�ƶq";
				 // 
				 // s�p�O
				 // 
				 this->s�p�O->HeaderText = L"�p�O";
				 this->s�p�O->Name = L"s�p�O";
				 // 
				 // textBox10
				 // 
				 this->textBox10->AcceptsTab = true;
				 this->textBox10->Location = System::Drawing::Point(221, 185);
				 this->textBox10->Margin = System::Windows::Forms::Padding(5);
				 this->textBox10->Name = L"textBox10";
				 this->textBox10->Size = System::Drawing::Size(436, 43);
				 this->textBox10->TabIndex = 15;
				 // 
				 // textBox11
				 // 
				 this->textBox11->AcceptsTab = true;
				 this->textBox11->Location = System::Drawing::Point(221, 78);
				 this->textBox11->Margin = System::Windows::Forms::Padding(5);
				 this->textBox11->Name = L"textBox11";
				 this->textBox11->Size = System::Drawing::Size(436, 43);
				 this->textBox11->TabIndex = 14;
				 this->textBox11->TextChanged += gcnew System::EventHandler(this, &Form1::textBox11_TextChanged);
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Location = System::Drawing::Point(56, 188);
				 this->label11->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(73, 30);
				 this->label11->TabIndex = 8;
				 this->label11->Text = L"�ƶq";
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(56, 80);
				 this->label12->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(103, 30);
				 this->label12->TabIndex = 7;
				 this->label12->Text = L"�y����";
				 // 
				 // button12
				 // 
				 this->button12->Enabled = false;
				 this->button12->Location = System::Drawing::Point(1781, 698);
				 this->button12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
				 this->button12->Name = L"button12";
				 this->button12->Size = System::Drawing::Size(200, 65);
				 this->button12->TabIndex = 15;
				 this->button12->Text = L"�n�X";
				 this->button12->UseVisualStyleBackColor = true;
				 this->button12->Click += gcnew System::EventHandler(this, &Form1::button12_Click);
				 // 
				 // label17
				 // 
				 this->label17->AutoSize = true;
				 this->label17->Location = System::Drawing::Point(224, 975);
				 this->label17->Name = L"label17";
				 this->label17->Size = System::Drawing::Size(73, 30);
				 this->label17->TabIndex = 16;
				 this->label17->Text = L"�m�W";
				 this->label17->Visible = false;
				 // 
				 // label18
				 // 
				 this->label18->AutoSize = true;
				 this->label18->Location = System::Drawing::Point(725, 975);
				 this->label18->Name = L"label18";
				 this->label18->Size = System::Drawing::Size(73, 30);
				 this->label18->TabIndex = 17;
				 this->label18->Text = L"�ƯZ";
				 this->label18->Visible = false;
				 // 
				 // label19
				 // 
				 this->label19->AutoSize = true;
				 this->label19->Location = System::Drawing::Point(1195, 975);
				 this->label19->Name = L"label19";
				 this->label19->Size = System::Drawing::Size(73, 30);
				 this->label19->TabIndex = 18;
				 this->label19->Text = L"¾��";
				 this->label19->Visible = false;
				 // 
				 // panel1
				 // 
				 this->panel1->Controls->Add(this->button21);
				 this->panel1->Controls->Add(this->checkedListBox1);
				 this->panel1->Controls->Add(this->button20);
				 this->panel1->Controls->Add(this->dataGridView4);
				 this->panel1->Location = System::Drawing::Point(13, 10);
				 this->panel1->Margin = System::Windows::Forms::Padding(8);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(1768, 1028);
				 this->panel1->TabIndex = 19;
				 this->panel1->Visible = false;
				 // 
				 // button21
				 // 
				 this->button21->Location = System::Drawing::Point(210, 580);
				 this->button21->Margin = System::Windows::Forms::Padding(5);
				 this->button21->Name = L"button21";
				 this->button21->Size = System::Drawing::Size(171, 65);
				 this->button21->TabIndex = 32;
				 this->button21->Text = L"���s���J";
				 this->button21->UseVisualStyleBackColor = true;
				 this->button21->Click += gcnew System::EventHandler(this, &Form1::button21_Click);
				 // 
				 // checkedListBox1
				 // 
				 this->checkedListBox1->FormattingEnabled = true;
				 this->checkedListBox1->Location = System::Drawing::Point(421, 575);
				 this->checkedListBox1->Margin = System::Windows::Forms::Padding(8);
				 this->checkedListBox1->Name = L"checkedListBox1";
				 this->checkedListBox1->Size = System::Drawing::Size(313, 194);
				 this->checkedListBox1->TabIndex = 31;
				 // 
				 // button20
				 // 
				 this->button20->Enabled = false;
				 this->button20->Location = System::Drawing::Point(29, 580);
				 this->button20->Margin = System::Windows::Forms::Padding(5);
				 this->button20->Name = L"button20";
				 this->button20->Size = System::Drawing::Size(171, 65);
				 this->button20->TabIndex = 30;
				 this->button20->Text = L"�T�{�ק�";
				 this->button20->UseVisualStyleBackColor = true;
				 this->button20->Click += gcnew System::EventHandler(this, &Form1::button20_Click_1);
				 // 
				 // dataGridView4
				 // 
				 this->dataGridView4->AllowUserToAddRows = false;
				 this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
					 this->�H��, this->�P����,
						 this->�P���@, this->�P���G, this->�P���T, this->�P���|, this->�P����, this->�P����
				 });
				 this->dataGridView4->Location = System::Drawing::Point(29, 108);
				 this->dataGridView4->Margin = System::Windows::Forms::Padding(8);
				 this->dataGridView4->Name = L"dataGridView4";
				 this->dataGridView4->RowHeadersVisible = false;
				 this->dataGridView4->RowTemplate->Height = 24;
				 this->dataGridView4->Size = System::Drawing::Size(1491, 445);
				 this->dataGridView4->TabIndex = 0;
				 this->dataGridView4->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Form1::dataGridView4_CellValueChanged);
				 // 
				 // �H��
				 // 
				 this->�H��->HeaderText = L"�H��";
				 this->�H��->Name = L"�H��";
				 this->�H��->ReadOnly = true;
				 // 
				 // �P����
				 // 
				 this->�P����->HeaderText = L"�P����";
				 this->�P����->Name = L"�P����";
				 // 
				 // �P���@
				 // 
				 this->�P���@->HeaderText = L"�P���@";
				 this->�P���@->Name = L"�P���@";
				 // 
				 // �P���G
				 // 
				 this->�P���G->HeaderText = L"�P���G";
				 this->�P���G->Name = L"�P���G";
				 // 
				 // �P���T
				 // 
				 this->�P���T->HeaderText = L"�P���T";
				 this->�P���T->Name = L"�P���T";
				 // 
				 // �P���|
				 // 
				 this->�P���|->HeaderText = L"�P���|";
				 this->�P���|->Name = L"�P���|";
				 // 
				 // �P����
				 // 
				 this->�P����->HeaderText = L"�P����";
				 this->�P����->Name = L"�P����";
				 // 
				 // �P����
				 // 
				 this->�P����->HeaderText = L"�P����";
				 this->�P����->Name = L"�P����";
				 // 
				 // button18
				 // 
				 this->button18->Enabled = false;
				 this->button18->Location = System::Drawing::Point(1781, 575);
				 this->button18->Margin = System::Windows::Forms::Padding(8);
				 this->button18->Name = L"button18";
				 this->button18->Size = System::Drawing::Size(200, 75);
				 this->button18->TabIndex = 20;
				 this->button18->Text = L"�Z��";
				 this->button18->UseVisualStyleBackColor = true;
				 this->button18->Click += gcnew System::EventHandler(this, &Form1::button18_Click);
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(16, 30);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(3824, 1045);
				 this->Controls->Add(this->button18);
				 this->Controls->Add(this->label19);
				 this->Controls->Add(this->label18);
				 this->Controls->Add(this->label17);
				 this->Controls->Add(this->button12);
				 this->Controls->Add(this->button5);
				 this->Controls->Add(this->button4);
				 this->Controls->Add(this->button3);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->member);
				 this->Controls->Add(this->panel1);
				 this->Controls->Add(this->login);
				 this->Controls->Add(this->search);
				 this->Controls->Add(this->purchase);
				 this->Controls->Add(this->sell);
				 this->Margin = System::Windows::Forms::Padding(5);
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
				 this->panel1->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Product A;
		A.search_product(connect, comboBox1, checkBox1, textBox1, dataGridView1);
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		String ^arv, ^exp;
		String^s = Convert::ToString(dateTimePicker1->Value);
		array<String^>^ words1 = s->Split(' ');
		arv = words1[0];
		s = Convert::ToString(dateTimePicker2->Value);
		words1 = s->Split(' ');
		exp = words1[0];
		if (comboBox2->SelectedItem == "�L�i���~")
		{
			SYSTEMTIME arval = stringtotime(arv);//{ 2017,12,0,7,0,0,0,0 };
			SYSTEMTIME expired = stringtotime(exp);// { 2017, 12, 0, 8, 0, 0, 0, 0 };
			SYSTEMTIME cooked{ 0,0,0,0,0,0,Convert::ToInt32(textBox4->Text),0 };
			int price = Convert::ToInt32(textBox8->Text);
			int temp = Convert::ToInt32(textBox3->Text);
			theCooked tc(0, textBox2->Text, arval, expired, cooked, price, temp);
			tc.set_number(Convert::ToInt32(textBox7->Text));
			tc.stock(connect);
		}
		else if (comboBox2->SelectedItem == "���A���~")
		{
			SYSTEMTIME arval = stringtotime(arv);//{ 2017,12,0,7,0,0,0,0 };
			SYSTEMTIME expired = stringtotime(exp);// { 2017, 12, 0, 8, 0, 0, 0, 0 };
			int price = Convert::ToInt32(textBox8->Text);
			int temp = Convert::ToInt32(textBox3->Text);
			theFrozen tf(0, textBox2->Text, arval, expired, price, temp);
			tf.set_number(Convert::ToInt32(textBox7->Text));
			tf.stock(connect);
		}
		else if (comboBox2->SelectedItem == "���~")
		{
			SYSTEMTIME arval = stringtotime(arv);//{ 2017,12,0,7,0,0,0,0 };
			SYSTEMTIME expired = stringtotime(exp);// { 2017, 12, 0, 8, 0, 0, 0, 0 };
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
		else if (comboBox2->SelectedItem == "��Ϋ~")
		{
			SYSTEMTIME arval = stringtotime(arv);//{ 2017,12,0,7,0,0,0,0 };
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
		panel1->Visible = false;
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		purchase->Visible = true;

		sell->Visible = false;
		search->Visible = false;
		member->Visible = false;
		panel1->Visible = false;
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		sell->Visible = true;

		purchase->Visible = false;
		search->Visible = false;
		member->Visible = false;
		panel1->Visible = false;
	}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
		member->Visible = true;

		purchase->Visible = false;
		search->Visible = false;
		sell->Visible = false;
		panel1->Visible = false;
	}
	private: System::Void comboBox2_SelectedValueChanged(System::Object^  sender, System::EventArgs^  e) {
		if (comboBox2->SelectedItem == "�L�i���~") {
			textBox3->Enabled = true;
			textBox4->Enabled = true;
			dateTimePicker2->Enabled = true;
		}
		if (comboBox2->SelectedItem == "���A���~") {
			textBox4->Enabled = false;
			dateTimePicker2->Enabled = true;
			textBox3->Enabled = true;
		}
		if (comboBox2->SelectedItem == "���~") {
			dateTimePicker2->Enabled = true;
			textBox4->Enabled = false;
			textBox3->Enabled = false;
		}
		if (comboBox2->SelectedItem == "��Ϋ~") {
			textBox4->Enabled = false;
			textBox3->Enabled = false;
			dateTimePicker2->Enabled = false;
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
		label10->Text = "�`��:" + Convert::ToString(sum);
		textBox11->Text = "";
		textBox10->Text = "";
	}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	Product A;
	for (int i = 0; i <dataGridView2->Rows->Count; i++)
		A.sell_product(connect, Convert::ToString(dataGridView2->Rows[i]->Cells[0]->Value), Convert::ToString(dataGridView2->Rows[i]->Cells[3]->Value));
	dataGridView2->Rows->Clear();
	dataGridView2->Refresh();
	label10->Text = "�`��:";
	label14->Text = "�ꦬ:";
	label15->Text = "��s:";
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show("�P�⦨�\");
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
	label10->Text = "�`��:" + Convert::ToString(sum);
}
private: System::Void textBox11_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	label14->Text = "�ꦬ:" + textBox9->Text;
	array<String^>^ words1;
	words1 = label10->Text->Split(':');
	array<String^>^ words2;
	words2 = label14->Text->Split(':');
	label15->Text = "��s:" + Convert::ToString(Convert::ToInt32(words2[1]) - Convert::ToInt32(words1[1]));
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
		if (label19->Text == "¾��:����")
		{
			button3->Enabled = true;
			button5->Enabled = true;
			button18->Enabled = true;
		}
		purchase->Visible = false;
		sell->Visible = false;
		search->Visible = false;
		member->Visible = false;
		login->Visible = false;
		button2->Enabled = true;
		button4->Enabled = true;
		button12->Enabled = true;
		label17->Visible = true;
		label18->Visible = true;
		label19->Visible = true;
	}
	account->Text = "";
	passwordbox->Text = "";
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
	purchase->Visible = false;
	sell->Visible = false;
	search->Visible = false;
	member->Visible = false;
	panel1->Visible = false;
	login->Visible = true;
	button2->Enabled = false;
	button3->Enabled = false;
	button4->Enabled = false;
	button5->Enabled = false;
	button18->Enabled = false;
	button12->Enabled = false;
	label17->Visible = false;
	label18->Visible = false;
	label19->Visible = false;
}
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	dataGridView2->Rows->Clear();
	dataGridView2->Refresh();
	label10->Text = "�`��:";
	label14->Text = "�ꦬ:";
	label15->Text = "��s:";
}
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	Staff A;
	A.staff_change(connect, textBox13, textBox14, textBox15, textBox16, textBox17, textBox18);
	textBox13->Text = "";
	textBox14->Text = "";
	textBox15->Text = "";
	textBox16->Text = "";
	textBox17->Text = "";
	textBox18->Text = "";
}
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	button16->Visible = true;
	button17->Visible = true;
	button15->Visible = false;
}
private: System::Void button16_Click(System::Object^  sender, System::EventArgs^  e) {
	button16->Visible = false;
	button17->Visible = false;
	button15->Visible = true;
}
private: System::Void button17_Click(System::Object^  sender, System::EventArgs^  e) {
	Staff A;
	A.staff_fired(connect, textBox13);
}
private: System::Void button20_Click(System::Object^  sender, System::EventArgs^  e) {
	MySqlCommand ^cmd;
	MySqlDataReader ^reader;
	/* Used to input the MySQL message */
	String^ strSQL;


	System::String^ usr;
	strSQL = "select * from s201701";
	bool first = false;
	for (int i = 0; i < checkedListBox1->Items->Count; i++) {
		if (checkedListBox1->GetItemChecked(i)) {
			if (first == false) {
				usr = checkedListBox1->Items[i]->ToString();
				usr = usr->Split(L' ')[0];
				strSQL += " where �b��=" + "'" + usr + "'";
				first = true;
			}
			else {
				usr = checkedListBox1->Items[i]->ToString();
				usr = usr->Split(L' ')[0];
				strSQL += " or �b��=" + "'" + usr + "'";
			}
		}
	}
	strSQL += ";";
	
	dataGridView4->Rows->Clear();
	for (int i = 0; i < checkedListBox1->Items->Count; i++) {
		String^ s = checkedListBox1->Items[i]->ToString();
		array<String^>^ words;
		words = s->Split(' ');
		strSQL = "SELECT * FROM S201701 WHERE �b�� =" + words[0];
		
		try
		{
			/* �s���}�� */
			connect->Open();
			/* �ǰe���O�� MySQL */
			//
			cmd = gcnew MySqlCommand(strSQL, connect);
			reader = cmd->ExecuteReader();
			int j = 0;
			/* Ū����� */
			dataGridView4->Rows->Add();
			if (reader->Read()) {
				
				for (int j = 0; j < reader->FieldCount; j++)
					dataGridView4->Rows[i]->Cells[j]->Value = reader->GetString(j);
			}
			else
			{
				dataGridView4->Rows[i]->Cells[0]->Value = words[0];
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

	

	
}
private: System::Void button18_Click(System::Object^  sender, System::EventArgs^  e) {
	member->Visible = false;

	purchase->Visible = false;
	search->Visible = false;
	sell->Visible = false;
	panel1->Visible = true;
	dataGridView4->Rows->Clear();
	checkedListBox1->Items->Clear();
	

	MySqlCommand ^cmd;
	MySqlDataReader ^reader;
	/* Used to input the MySQL message */
	String^ strSQL;
	try
	{
		/* �s���}�� */
		connect->Open();
		/* �ǰe���O�� MySQL */
		//
		strSQL = "select �b��,�m�W from �H��;";//MySQL command you want to use
										 //textBox1->Text = strSQL;																 //
		cmd = gcnew MySqlCommand(strSQL, connect);
		reader = cmd->ExecuteReader();
		int j = 0;
		/* Ū����� */
		while (reader->Read())
		{
			String ^read;
			for (int i = 0; i<reader->FieldCount; i++)
			{
				if (i != 0)
					read += " ";
				read += reader->GetString(i);
			}
			checkedListBox1->Items->Add(read);
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

	for (int i = 0; i < checkedListBox1->Items->Count; i++) {
		String^ s = checkedListBox1->Items[i]->ToString();
		array<String^>^ words;
		words = s->Split(' ');
		strSQL = "SELECT * FROM S201701 WHERE �b�� =" + words[0];

		try
		{
			/* �s���}�� */
			connect->Open();
			/* �ǰe���O�� MySQL */
			//
			cmd = gcnew MySqlCommand(strSQL, connect);
			reader = cmd->ExecuteReader();
			int j = 0;
			/* Ū����� */
			dataGridView4->Rows->Add();
			if (reader->Read()) {

				for (int j = 0; j < reader->FieldCount; j++)
					dataGridView4->Rows[i]->Cells[j]->Value = reader->GetString(j);
			}
			else
			{
				dataGridView4->Rows[i]->Cells[0]->Value = words[0];
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
	button20->Enabled = false;
}
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
	dataGridView4->Rows->Clear();
//	checkedListBox1->Items->Clear();


	MySqlCommand ^cmd;
	MySqlDataReader ^reader;
	/* Used to input the MySQL message */
	String^ strSQL;
	for (int i = 0; i < checkedListBox1->Items->Count; i++) {
		String^ s = checkedListBox1->Items[i]->ToString();
		array<String^>^ words;
		words = s->Split(' ');
		strSQL = "SELECT * FROM S201701 WHERE �b�� =" + words[0];

		try
		{
			/* �s���}�� */
			connect->Open();
			/* �ǰe���O�� MySQL */
			//
			cmd = gcnew MySqlCommand(strSQL, connect);
			reader = cmd->ExecuteReader();
			int j = 0;
			/* Ū����� */
			if (reader->Read()) {
				if (checkedListBox1->GetItemChecked(i)|| checkedListBox1->CheckedItems->Count==0) {
					dataGridView4->Rows->Add();
					for (int j = 0; j < reader->FieldCount; j++)
						dataGridView4->Rows[i]->Cells[j]->Value = reader->GetString(j);
				}
			}
			else
			{
				if (checkedListBox1->GetItemChecked(i)|| checkedListBox1->CheckedItems->Count == 0) {
					dataGridView4->Rows->Add();
					dataGridView4->Rows[i]->Cells[0]->Value = words[0];
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

	}
	button20->Enabled = false;
}
private: System::Void dataGridView4_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	button20->Enabled = true;
}
private: System::Void button20_Click_1(System::Object^  sender, System::EventArgs^  e) {
	MySqlCommand ^cmd;
	MySqlDataReader ^reader;
	/* Used to input the MySQL message */
	String^ strSQL;
	bool same = false;
	int num;

	for (int i = 0; i < dataGridView4->Rows->Count; i++) {
		String^ s = dataGridView4->Rows[i]->Cells[0]->Value->ToString();
		strSQL = "SELECT * FROM S201701 WHERE �b�� ='" + s + "';";
		try
		{
			/* �s���}�� */
			connect->Open();
			/* �ǰe���O�� MySQL */
			//
			cmd = gcnew MySqlCommand(strSQL, connect);
			reader = cmd->ExecuteReader();
			int j = 0;
			/* Ū����� */
			if (reader->Read()) {
				same = true;
			}
			else
			{
				same = false;
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
		try
		{
			/* �s���}�� */
			connect->Open();

			/* �ǰe���O�� MySQL */
			//
			if (same) {
				strSQL = "update s201701 set ";
				strSQL += "d1='" + dataGridView4->Rows[i]->Cells[1]->Value + "',";
				strSQL += "d2='" + dataGridView4->Rows[i]->Cells[2]->Value + "',";
				strSQL += "d3='" + dataGridView4->Rows[i]->Cells[3]->Value + "',";
				strSQL += "d4='" + dataGridView4->Rows[i]->Cells[4]->Value + "',";
				strSQL += "d5='" + dataGridView4->Rows[i]->Cells[5]->Value + "',";
				strSQL += "d6='" + dataGridView4->Rows[i]->Cells[6]->Value + "',";
				strSQL += "d7='" + dataGridView4->Rows[i]->Cells[7]->Value + "'";
				strSQL += " where �b�� = '" + s + "';";//MySQL command you want to use		
			}//
			else
			{

				strSQL = "insert into s201701(�b��, d1, d2, d3, d4, d5,d6,d7) values (";
				strSQL += "'" + dataGridView4->Rows[i]->Cells[0]->Value + "',";
				strSQL += "'" + dataGridView4->Rows[i]->Cells[1]->Value + "',";
				strSQL += "'" + dataGridView4->Rows[i]->Cells[2]->Value + "',";
				strSQL += "'" + dataGridView4->Rows[i]->Cells[3]->Value + "',";
				strSQL += "'" + dataGridView4->Rows[i]->Cells[4]->Value + "',";
				strSQL += "'" + dataGridView4->Rows[i]->Cells[5]->Value + "',";
				strSQL += "'" + dataGridView4->Rows[i]->Cells[6]->Value + "',";
				strSQL += "'" + dataGridView4->Rows[i]->Cells[7]->Value + "'";
				strSQL += ");";
			}
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
	}
	System::Windows::Forms::DialogResult result;
	result = MessageBox::Show("��令�\");
}
};
}

