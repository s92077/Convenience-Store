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
		/* MySQL�s�����B���O�ǰe�B���Ū�� */
		MySqlConnection ^connect;
		MySqlCommand ^cmd;
		MySqlDataReader ^reader;
		/* Used to input the MySQL message */
		String ^strSQL;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �~�W;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �ƶq;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �쩱�ɶ�;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �����;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �i���ɶ�;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �ū�;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->�~�W = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->���� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�ƶq = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�쩱�ɶ� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->����� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�i���ɶ� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->�ū� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(272, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(975, 43);
			this->textBox1->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(1273, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(173, 64);
			this->button1->TabIndex = 1;
			this->button1->Text = L"�d��";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(120, 80);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 38);
			this->comboBox1->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->�~�W, this->����,
					this->�ƶq, this->�쩱�ɶ�, this->�����, this->�i���ɶ�, this->�ū�
			});
			this->dataGridView1->Location = System::Drawing::Point(272, 192);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 45;
			this->dataGridView1->Size = System::Drawing::Size(1470, 710);
			this->dataGridView1->TabIndex = 4;
			// 
			// �~�W
			// 
			this->�~�W->HeaderText = L"�~�W";
			this->�~�W->Name = L"�~�W";
			this->�~�W->Width = 150;
			// 
			// ����
			// 
			this->����->HeaderText = L"����";
			this->����->Name = L"����";
			this->����->Width = 150;
			// 
			// �ƶq
			// 
			this->�ƶq->HeaderText = L"�ƶq";
			this->�ƶq->Name = L"�ƶq";
			this->�ƶq->Width = 150;
			// 
			// �쩱�ɶ�
			// 
			this->�쩱�ɶ�->HeaderText = L"�쩱�ɶ�";
			this->�쩱�ɶ�->Name = L"�쩱�ɶ�";
			this->�쩱�ɶ�->Width = 300;
			// 
			// �����
			// 
			this->�����->HeaderText = L"�����";
			this->�����->Name = L"�����";
			this->�����->Width = 225;
			// 
			// �i���ɶ�
			// 
			this->�i���ɶ�->HeaderText = L"�i���ɶ�";
			this->�i���ɶ�->Name = L"�i���ɶ�";
			this->�i���ɶ�->Width = 300;
			// 
			// �ū�
			// 
			this->�ū�->HeaderText = L"�ū�";
			this->�ū�->Name = L"�ū�";
			this->�ū�->Width = 150;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2031, 992);
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
			/* �s���}�� */
			connect->Open();

			/* �ǰe���O�� MySQL */
			//
			strSQL = "select * from �K�Q�ө��t��;";//MySQL command you want to use
								  //
			cmd = gcnew MySqlCommand(strSQL, connect);
			reader = cmd->ExecuteReader();

			/* Ū����� */
			//richTextBox1->Text = "";
			while (reader->Read())
			{
				for (int i = 0; i<reader->FieldCount; i++)
				{
					String ^read = reader->GetString(i);
					//richTextBox1->Text += read + "\t";
				}
				//richTextBox1->Text += Environment::NewLine;
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
};
}

