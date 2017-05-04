#pragma once

namespace CalcForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm 的摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  groupBox1;
	protected:
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button24;
	private: System::Windows::Forms::Button^  button23;
	private: System::Windows::Forms::Button^  button22;
	private: System::Windows::Forms::Button^  button21;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button28;
	private: System::Windows::Forms::Button^  button29;

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->button21 = (gcnew System::Windows::Forms::Button());
			this->button22 = (gcnew System::Windows::Forms::Button());
			this->button23 = (gcnew System::Windows::Forms::Button());
			this->button24 = (gcnew System::Windows::Forms::Button());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button28 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button29 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button12);
			this->groupBox1->Controls->Add(this->button11);
			this->groupBox1->Controls->Add(this->button10);
			this->groupBox1->Controls->Add(this->button9);
			this->groupBox1->Controls->Add(this->button8);
			this->groupBox1->Controls->Add(this->button7);
			this->groupBox1->Controls->Add(this->button6);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(12, 215);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(256, 322);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Numbers";
			// 
			// button12
			// 
			this->button12->Enabled = false;
			this->button12->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button12->Location = System::Drawing::Point(169, 241);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 67);
			this->button12->TabIndex = 0;
			this->button12->Text = L"i";
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Enabled = false;
			this->button11->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button11->Location = System::Drawing::Point(88, 241);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(75, 67);
			this->button11->TabIndex = 0;
			this->button11->Text = L".";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button10->Location = System::Drawing::Point(7, 241);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 67);
			this->button10->TabIndex = 0;
			this->button10->Text = L"0";
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button9->Location = System::Drawing::Point(169, 168);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(75, 67);
			this->button9->TabIndex = 0;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button8->Location = System::Drawing::Point(88, 168);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 67);
			this->button8->TabIndex = 0;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button7->Location = System::Drawing::Point(7, 168);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 67);
			this->button7->TabIndex = 0;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button6->Location = System::Drawing::Point(169, 95);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 67);
			this->button6->TabIndex = 0;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button5->Location = System::Drawing::Point(88, 95);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 67);
			this->button5->TabIndex = 0;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button4->Location = System::Drawing::Point(7, 95);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 67);
			this->button4->TabIndex = 0;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button3->Location = System::Drawing::Point(169, 22);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 67);
			this->button3->TabIndex = 0;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button2->Location = System::Drawing::Point(88, 22);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 67);
			this->button2->TabIndex = 0;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button1->Location = System::Drawing::Point(7, 22);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 67);
			this->button1->TabIndex = 0;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"標楷體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->textBox1->Location = System::Drawing::Point(12, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(698, 65);
			this->textBox1->TabIndex = 1;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button15);
			this->groupBox2->Controls->Add(this->button14);
			this->groupBox2->Controls->Add(this->button13);
			this->groupBox2->Location = System::Drawing::Point(12, 100);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(256, 89);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Types";
			// 
			// button15
			// 
			this->button15->Font = (gcnew System::Drawing::Font(L"標楷體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button15->Location = System::Drawing::Point(169, 16);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(75, 67);
			this->button15->TabIndex = 0;
			this->button15->Text = L"Complex";
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->Font = (gcnew System::Drawing::Font(L"標楷體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button14->Location = System::Drawing::Point(88, 16);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(75, 67);
			this->button14->TabIndex = 0;
			this->button14->Text = L"Decimal";
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->Enabled = false;
			this->button13->Font = (gcnew System::Drawing::Font(L"標楷體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button13->Location = System::Drawing::Point(7, 16);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(75, 67);
			this->button13->TabIndex = 0;
			this->button13->Text = L"Integer";
			this->button13->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button26);
			this->groupBox3->Controls->Add(this->button25);
			this->groupBox3->Controls->Add(this->button24);
			this->groupBox3->Controls->Add(this->button23);
			this->groupBox3->Controls->Add(this->button22);
			this->groupBox3->Controls->Add(this->button21);
			this->groupBox3->Controls->Add(this->button20);
			this->groupBox3->Controls->Add(this->button19);
			this->groupBox3->Controls->Add(this->button18);
			this->groupBox3->Controls->Add(this->button17);
			this->groupBox3->Controls->Add(this->button16);
			this->groupBox3->Location = System::Drawing::Point(284, 100);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(173, 437);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Functions";
			// 
			// button19
			// 
			this->button19->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button19->Location = System::Drawing::Point(6, 241);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(75, 67);
			this->button19->TabIndex = 0;
			this->button19->Text = L"/";
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button18->Location = System::Drawing::Point(6, 168);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(75, 67);
			this->button18->TabIndex = 0;
			this->button18->Text = L"*";
			this->button18->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button17->Location = System::Drawing::Point(6, 95);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(75, 67);
			this->button17->TabIndex = 0;
			this->button17->Text = L"-";
			this->button17->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button16->Location = System::Drawing::Point(6, 22);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(75, 67);
			this->button16->TabIndex = 0;
			this->button16->Text = L"+";
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button20
			// 
			this->button20->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button20->Location = System::Drawing::Point(92, 22);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(75, 67);
			this->button20->TabIndex = 0;
			this->button20->Text = L"(";
			this->button20->UseVisualStyleBackColor = true;
			// 
			// button21
			// 
			this->button21->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button21->Location = System::Drawing::Point(92, 95);
			this->button21->Name = L"button21";
			this->button21->Size = System::Drawing::Size(75, 67);
			this->button21->TabIndex = 0;
			this->button21->Text = L")";
			this->button21->UseVisualStyleBackColor = true;
			// 
			// button22
			// 
			this->button22->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button22->Location = System::Drawing::Point(92, 168);
			this->button22->Name = L"button22";
			this->button22->Size = System::Drawing::Size(75, 67);
			this->button22->TabIndex = 0;
			this->button22->Text = L"POW";
			this->button22->UseVisualStyleBackColor = true;
			// 
			// button23
			// 
			this->button23->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button23->Location = System::Drawing::Point(92, 241);
			this->button23->Name = L"button23";
			this->button23->Size = System::Drawing::Size(75, 67);
			this->button23->TabIndex = 0;
			this->button23->Text = L"!";
			this->button23->UseVisualStyleBackColor = true;
			// 
			// button24
			// 
			this->button24->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button24->Location = System::Drawing::Point(6, 314);
			this->button24->Name = L"button24";
			this->button24->Size = System::Drawing::Size(75, 67);
			this->button24->TabIndex = 0;
			this->button24->Text = L"<-";
			this->button24->UseVisualStyleBackColor = true;
			// 
			// button25
			// 
			this->button25->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button25->Location = System::Drawing::Point(92, 314);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(75, 67);
			this->button25->TabIndex = 0;
			this->button25->Text = L"C";
			this->button25->UseVisualStyleBackColor = true;
			// 
			// button26
			// 
			this->button26->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->button26->Location = System::Drawing::Point(6, 387);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(161, 36);
			this->button26->TabIndex = 0;
			this->button26->Text = L"=";
			this->button26->UseVisualStyleBackColor = true;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->textBox2);
			this->groupBox4->Controls->Add(this->listBox1);
			this->groupBox4->Controls->Add(this->button29);
			this->groupBox4->Controls->Add(this->button28);
			this->groupBox4->Controls->Add(this->button27);
			this->groupBox4->Location = System::Drawing::Point(463, 100);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(247, 437);
			this->groupBox4->TabIndex = 1;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"groupBox4";
			// 
			// button27
			// 
			this->button27->Location = System::Drawing::Point(20, 56);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(77, 24);
			this->button27->TabIndex = 0;
			this->button27->Text = L"SET";
			this->button27->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Location = System::Drawing::Point(6, 91);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(235, 340);
			this->listBox1->TabIndex = 1;
			// 
			// button28
			// 
			this->button28->Location = System::Drawing::Point(171, 56);
			this->button28->Name = L"button28";
			this->button28->Size = System::Drawing::Size(70, 24);
			this->button28->TabIndex = 0;
			this->button28->Text = L"DELETE";
			this->button28->UseVisualStyleBackColor = true;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(20, 22);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(212, 22);
			this->textBox2->TabIndex = 2;
			// 
			// button29
			// 
			this->button29->Location = System::Drawing::Point(103, 56);
			this->button29->Name = L"button29";
			this->button29->Size = System::Drawing::Size(62, 24);
			this->button29->TabIndex = 0;
			this->button29->Text = L"Modify";
			this->button29->UseVisualStyleBackColor = true;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(725, 549);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->groupBox1);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

	}
};
}
