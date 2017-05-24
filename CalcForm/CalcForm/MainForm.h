#pragma once
#include "Formula.h"
#include <msclr/marshal.h>        // .NET string to C-style string
#include <msclr/marshal_cppstd.h> // .NET string to STL string
map<string, var> vars;
map<char, int> operators;
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
	private: System::Windows::Forms::GroupBox^  Nymber;
	protected:

	private: System::Windows::Forms::Button^  Imagine;
	protected:

	private: System::Windows::Forms::Button^  Dot;



	private: System::Windows::Forms::Button^  Zero;

	private: System::Windows::Forms::Button^  Nine;

	private: System::Windows::Forms::Button^  Eight;

	private: System::Windows::Forms::Button^  Seven;

	private: System::Windows::Forms::Button^  Six;

	private: System::Windows::Forms::Button^  Five;

	private: System::Windows::Forms::Button^  Four;

	private: System::Windows::Forms::Button^  Three;

	private: System::Windows::Forms::Button^  Two;

	private: System::Windows::Forms::Button^  One;
	private: System::Windows::Forms::TextBox^  Show;
	private: System::Windows::Forms::GroupBox^  Types;




	private: System::Windows::Forms::Button^  ComplexBTM;

	private: System::Windows::Forms::Button^  DecimalBTM;


	private: System::Windows::Forms::Button^  IntegerBTM;
	private: System::Windows::Forms::GroupBox^  Functions;






	private: System::Windows::Forms::Button^  Dev;

	private: System::Windows::Forms::Button^  Multiple;

	private: System::Windows::Forms::Button^  Sub;

	private: System::Windows::Forms::Button^  Plus;
	private: System::Windows::Forms::Button^  Equal;



	private: System::Windows::Forms::Button^  Clear;

	private: System::Windows::Forms::Button^  Back;
	private: System::Windows::Forms::Button^  Factor;
	private: System::Windows::Forms::Button^  POW;

	private: System::Windows::Forms::Button^  Right;
	private: System::Windows::Forms::Button^  Left;
	private: System::Windows::Forms::GroupBox^  Var;






	private: System::Windows::Forms::ListBox^  VarList;

	private: System::Windows::Forms::Button^  Set;
	private: System::Windows::Forms::TextBox^  VarName;




	private: System::Windows::Forms::Button^  Delete;

	private: System::Windows::Forms::Button^  Modify;



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
			this->Nymber = (gcnew System::Windows::Forms::GroupBox());
			this->Imagine = (gcnew System::Windows::Forms::Button());
			this->Dot = (gcnew System::Windows::Forms::Button());
			this->Zero = (gcnew System::Windows::Forms::Button());
			this->Nine = (gcnew System::Windows::Forms::Button());
			this->Eight = (gcnew System::Windows::Forms::Button());
			this->Seven = (gcnew System::Windows::Forms::Button());
			this->Six = (gcnew System::Windows::Forms::Button());
			this->Five = (gcnew System::Windows::Forms::Button());
			this->Four = (gcnew System::Windows::Forms::Button());
			this->Three = (gcnew System::Windows::Forms::Button());
			this->Two = (gcnew System::Windows::Forms::Button());
			this->One = (gcnew System::Windows::Forms::Button());
			this->Show = (gcnew System::Windows::Forms::TextBox());
			this->Types = (gcnew System::Windows::Forms::GroupBox());
			this->ComplexBTM = (gcnew System::Windows::Forms::Button());
			this->DecimalBTM = (gcnew System::Windows::Forms::Button());
			this->IntegerBTM = (gcnew System::Windows::Forms::Button());
			this->Functions = (gcnew System::Windows::Forms::GroupBox());
			this->Equal = (gcnew System::Windows::Forms::Button());
			this->Clear = (gcnew System::Windows::Forms::Button());
			this->Back = (gcnew System::Windows::Forms::Button());
			this->Factor = (gcnew System::Windows::Forms::Button());
			this->POW = (gcnew System::Windows::Forms::Button());
			this->Right = (gcnew System::Windows::Forms::Button());
			this->Left = (gcnew System::Windows::Forms::Button());
			this->Dev = (gcnew System::Windows::Forms::Button());
			this->Multiple = (gcnew System::Windows::Forms::Button());
			this->Sub = (gcnew System::Windows::Forms::Button());
			this->Plus = (gcnew System::Windows::Forms::Button());
			this->Var = (gcnew System::Windows::Forms::GroupBox());
			this->VarName = (gcnew System::Windows::Forms::TextBox());
			this->VarList = (gcnew System::Windows::Forms::ListBox());
			this->Modify = (gcnew System::Windows::Forms::Button());
			this->Delete = (gcnew System::Windows::Forms::Button());
			this->Set = (gcnew System::Windows::Forms::Button());
			this->Nymber->SuspendLayout();
			this->Types->SuspendLayout();
			this->Functions->SuspendLayout();
			this->Var->SuspendLayout();
			this->SuspendLayout();
			// 
			// Nymber
			// 
			this->Nymber->Controls->Add(this->Imagine);
			this->Nymber->Controls->Add(this->Dot);
			this->Nymber->Controls->Add(this->Zero);
			this->Nymber->Controls->Add(this->Nine);
			this->Nymber->Controls->Add(this->Eight);
			this->Nymber->Controls->Add(this->Seven);
			this->Nymber->Controls->Add(this->Six);
			this->Nymber->Controls->Add(this->Five);
			this->Nymber->Controls->Add(this->Four);
			this->Nymber->Controls->Add(this->Three);
			this->Nymber->Controls->Add(this->Two);
			this->Nymber->Controls->Add(this->One);
			this->Nymber->Location = System::Drawing::Point(12, 215);
			this->Nymber->Name = L"Nymber";
			this->Nymber->Size = System::Drawing::Size(256, 322);
			this->Nymber->TabIndex = 0;
			this->Nymber->TabStop = false;
			this->Nymber->Text = L"Numbers";
			// 
			// Imagine
			// 
			this->Imagine->Enabled = false;
			this->Imagine->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Imagine->Location = System::Drawing::Point(169, 241);
			this->Imagine->Name = L"Imagine";
			this->Imagine->Size = System::Drawing::Size(75, 67);
			this->Imagine->TabIndex = 0;
			this->Imagine->Text = L"i";
			this->Imagine->UseVisualStyleBackColor = true;
			this->Imagine->Click += gcnew System::EventHandler(this, &MainForm::Imagine_Click);
			// 
			// Dot
			// 
			this->Dot->Enabled = false;
			this->Dot->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Dot->Location = System::Drawing::Point(88, 241);
			this->Dot->Name = L"Dot";
			this->Dot->Size = System::Drawing::Size(75, 67);
			this->Dot->TabIndex = 0;
			this->Dot->Text = L".";
			this->Dot->UseVisualStyleBackColor = true;
			this->Dot->Click += gcnew System::EventHandler(this, &MainForm::Dot_Click);
			// 
			// Zero
			// 
			this->Zero->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Zero->Location = System::Drawing::Point(7, 241);
			this->Zero->Name = L"Zero";
			this->Zero->Size = System::Drawing::Size(75, 67);
			this->Zero->TabIndex = 0;
			this->Zero->Text = L"0";
			this->Zero->UseVisualStyleBackColor = true;
			this->Zero->Click += gcnew System::EventHandler(this, &MainForm::Zero_Click);
			// 
			// Nine
			// 
			this->Nine->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Nine->Location = System::Drawing::Point(169, 168);
			this->Nine->Name = L"Nine";
			this->Nine->Size = System::Drawing::Size(75, 67);
			this->Nine->TabIndex = 0;
			this->Nine->Text = L"9";
			this->Nine->UseVisualStyleBackColor = true;
			this->Nine->Click += gcnew System::EventHandler(this, &MainForm::Nine_Click);
			// 
			// Eight
			// 
			this->Eight->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Eight->Location = System::Drawing::Point(88, 168);
			this->Eight->Name = L"Eight";
			this->Eight->Size = System::Drawing::Size(75, 67);
			this->Eight->TabIndex = 0;
			this->Eight->Text = L"8";
			this->Eight->UseVisualStyleBackColor = true;
			this->Eight->Click += gcnew System::EventHandler(this, &MainForm::Eight_Click);
			// 
			// Seven
			// 
			this->Seven->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Seven->Location = System::Drawing::Point(7, 168);
			this->Seven->Name = L"Seven";
			this->Seven->Size = System::Drawing::Size(75, 67);
			this->Seven->TabIndex = 0;
			this->Seven->Text = L"7";
			this->Seven->UseVisualStyleBackColor = true;
			this->Seven->Click += gcnew System::EventHandler(this, &MainForm::Seven_Click);
			// 
			// Six
			// 
			this->Six->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Six->Location = System::Drawing::Point(169, 95);
			this->Six->Name = L"Six";
			this->Six->Size = System::Drawing::Size(75, 67);
			this->Six->TabIndex = 0;
			this->Six->Text = L"6";
			this->Six->UseVisualStyleBackColor = true;
			this->Six->Click += gcnew System::EventHandler(this, &MainForm::Six_Click);
			// 
			// Five
			// 
			this->Five->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Five->Location = System::Drawing::Point(88, 95);
			this->Five->Name = L"Five";
			this->Five->Size = System::Drawing::Size(75, 67);
			this->Five->TabIndex = 0;
			this->Five->Text = L"5";
			this->Five->UseVisualStyleBackColor = true;
			this->Five->Click += gcnew System::EventHandler(this, &MainForm::Five_Click);
			// 
			// Four
			// 
			this->Four->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Four->Location = System::Drawing::Point(7, 95);
			this->Four->Name = L"Four";
			this->Four->Size = System::Drawing::Size(75, 67);
			this->Four->TabIndex = 0;
			this->Four->Text = L"4";
			this->Four->UseVisualStyleBackColor = true;
			this->Four->Click += gcnew System::EventHandler(this, &MainForm::Four_Click);
			// 
			// Three
			// 
			this->Three->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Three->Location = System::Drawing::Point(169, 22);
			this->Three->Name = L"Three";
			this->Three->Size = System::Drawing::Size(75, 67);
			this->Three->TabIndex = 0;
			this->Three->Text = L"3";
			this->Three->UseVisualStyleBackColor = true;
			this->Three->Click += gcnew System::EventHandler(this, &MainForm::Three_Click);
			// 
			// Two
			// 
			this->Two->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Two->Location = System::Drawing::Point(88, 22);
			this->Two->Name = L"Two";
			this->Two->Size = System::Drawing::Size(75, 67);
			this->Two->TabIndex = 0;
			this->Two->Text = L"2";
			this->Two->UseVisualStyleBackColor = true;
			this->Two->Click += gcnew System::EventHandler(this, &MainForm::Two_Click);
			// 
			// One
			// 
			this->One->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->One->Location = System::Drawing::Point(7, 22);
			this->One->Name = L"One";
			this->One->Size = System::Drawing::Size(75, 67);
			this->One->TabIndex = 0;
			this->One->Text = L"1";
			this->One->UseVisualStyleBackColor = true;
			this->One->Click += gcnew System::EventHandler(this, &MainForm::One_Click);
			// 
			// Show
			// 
			this->Show->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Show->BackColor = System::Drawing::Color::White;
			this->Show->Font = (gcnew System::Drawing::Font(L"標楷體", 39.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Show->ForeColor = System::Drawing::Color::Black;
			this->Show->Location = System::Drawing::Point(12, 12);
			this->Show->Name = L"Show";
			this->Show->ReadOnly = true;
			this->Show->ScrollBars = System::Windows::Forms::ScrollBars::Horizontal;
			this->Show->Size = System::Drawing::Size(698, 71);
			this->Show->TabIndex = 1;
			this->Show->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// Types
			// 
			this->Types->Controls->Add(this->ComplexBTM);
			this->Types->Controls->Add(this->DecimalBTM);
			this->Types->Controls->Add(this->IntegerBTM);
			this->Types->Location = System::Drawing::Point(12, 100);
			this->Types->Name = L"Types";
			this->Types->Size = System::Drawing::Size(256, 89);
			this->Types->TabIndex = 2;
			this->Types->TabStop = false;
			this->Types->Text = L"Types";
			// 
			// ComplexBTM
			// 
			this->ComplexBTM->Font = (gcnew System::Drawing::Font(L"標楷體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->ComplexBTM->Location = System::Drawing::Point(169, 16);
			this->ComplexBTM->Name = L"ComplexBTM";
			this->ComplexBTM->Size = System::Drawing::Size(75, 67);
			this->ComplexBTM->TabIndex = 0;
			this->ComplexBTM->Text = L"Complex";
			this->ComplexBTM->UseVisualStyleBackColor = true;
			this->ComplexBTM->Click += gcnew System::EventHandler(this, &MainForm::ComplexBTM_Click);
			// 
			// DecimalBTM
			// 
			this->DecimalBTM->Font = (gcnew System::Drawing::Font(L"標楷體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->DecimalBTM->Location = System::Drawing::Point(88, 16);
			this->DecimalBTM->Name = L"DecimalBTM";
			this->DecimalBTM->Size = System::Drawing::Size(75, 67);
			this->DecimalBTM->TabIndex = 0;
			this->DecimalBTM->Text = L"Decimal";
			this->DecimalBTM->UseVisualStyleBackColor = true;
			this->DecimalBTM->Click += gcnew System::EventHandler(this, &MainForm::DecimalBTM_Click);
			// 
			// IntegerBTM
			// 
			this->IntegerBTM->Enabled = false;
			this->IntegerBTM->Font = (gcnew System::Drawing::Font(L"標楷體", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->IntegerBTM->Location = System::Drawing::Point(6, 16);
			this->IntegerBTM->Name = L"IntegerBTM";
			this->IntegerBTM->Size = System::Drawing::Size(75, 67);
			this->IntegerBTM->TabIndex = 0;
			this->IntegerBTM->Text = L"Integer";
			this->IntegerBTM->UseVisualStyleBackColor = true;
			this->IntegerBTM->Click += gcnew System::EventHandler(this, &MainForm::IntegerBTM_Click);
			// 
			// Functions
			// 
			this->Functions->Controls->Add(this->Equal);
			this->Functions->Controls->Add(this->Clear);
			this->Functions->Controls->Add(this->Back);
			this->Functions->Controls->Add(this->Factor);
			this->Functions->Controls->Add(this->POW);
			this->Functions->Controls->Add(this->Right);
			this->Functions->Controls->Add(this->Left);
			this->Functions->Controls->Add(this->Dev);
			this->Functions->Controls->Add(this->Multiple);
			this->Functions->Controls->Add(this->Sub);
			this->Functions->Controls->Add(this->Plus);
			this->Functions->Location = System::Drawing::Point(284, 100);
			this->Functions->Name = L"Functions";
			this->Functions->Size = System::Drawing::Size(173, 437);
			this->Functions->TabIndex = 3;
			this->Functions->TabStop = false;
			this->Functions->Text = L"Functions";
			// 
			// Equal
			// 
			this->Equal->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Equal->Location = System::Drawing::Point(6, 387);
			this->Equal->Name = L"Equal";
			this->Equal->Size = System::Drawing::Size(161, 36);
			this->Equal->TabIndex = 0;
			this->Equal->Text = L"=";
			this->Equal->UseVisualStyleBackColor = true;
			this->Equal->Click += gcnew System::EventHandler(this, &MainForm::Equal_Click);
			// 
			// Clear
			// 
			this->Clear->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Clear->Location = System::Drawing::Point(92, 314);
			this->Clear->Name = L"Clear";
			this->Clear->Size = System::Drawing::Size(75, 67);
			this->Clear->TabIndex = 0;
			this->Clear->Text = L"C";
			this->Clear->UseVisualStyleBackColor = true;
			this->Clear->Click += gcnew System::EventHandler(this, &MainForm::Clear_Click);
			// 
			// Back
			// 
			this->Back->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Back->Location = System::Drawing::Point(6, 314);
			this->Back->Name = L"Back";
			this->Back->Size = System::Drawing::Size(75, 67);
			this->Back->TabIndex = 0;
			this->Back->Text = L"<-";
			this->Back->UseVisualStyleBackColor = true;
			this->Back->Click += gcnew System::EventHandler(this, &MainForm::Back_Click);
			// 
			// Factor
			// 
			this->Factor->Enabled = false;
			this->Factor->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Factor->Location = System::Drawing::Point(92, 241);
			this->Factor->Name = L"Factor";
			this->Factor->Size = System::Drawing::Size(75, 67);
			this->Factor->TabIndex = 0;
			this->Factor->Text = L"!";
			this->Factor->UseVisualStyleBackColor = true;
			this->Factor->Click += gcnew System::EventHandler(this, &MainForm::Factor_Click);
			// 
			// POW
			// 
			this->POW->Enabled = false;
			this->POW->Font = (gcnew System::Drawing::Font(L"標楷體", 29.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->POW->Location = System::Drawing::Point(92, 168);
			this->POW->Name = L"POW";
			this->POW->Size = System::Drawing::Size(75, 67);
			this->POW->TabIndex = 0;
			this->POW->Text = L"^";
			this->POW->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->POW->UseVisualStyleBackColor = true;
			this->POW->Click += gcnew System::EventHandler(this, &MainForm::POW_Click);
			// 
			// Right
			// 
			this->Right->Enabled = false;
			this->Right->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Right->Location = System::Drawing::Point(92, 95);
			this->Right->Name = L"Right";
			this->Right->Size = System::Drawing::Size(75, 67);
			this->Right->TabIndex = 0;
			this->Right->Text = L")";
			this->Right->UseVisualStyleBackColor = true;
			this->Right->Click += gcnew System::EventHandler(this, &MainForm::Right_Click);
			// 
			// Left
			// 
			this->Left->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Left->Location = System::Drawing::Point(92, 22);
			this->Left->Name = L"Left";
			this->Left->Size = System::Drawing::Size(75, 67);
			this->Left->TabIndex = 0;
			this->Left->Text = L"(";
			this->Left->UseVisualStyleBackColor = true;
			this->Left->Click += gcnew System::EventHandler(this, &MainForm::Left_Click);
			// 
			// Dev
			// 
			this->Dev->Enabled = false;
			this->Dev->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Dev->Location = System::Drawing::Point(6, 241);
			this->Dev->Name = L"Dev";
			this->Dev->Size = System::Drawing::Size(75, 67);
			this->Dev->TabIndex = 0;
			this->Dev->Text = L"/";
			this->Dev->UseVisualStyleBackColor = true;
			this->Dev->Click += gcnew System::EventHandler(this, &MainForm::Dev_Click);
			// 
			// Multiple
			// 
			this->Multiple->Enabled = false;
			this->Multiple->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Multiple->Location = System::Drawing::Point(6, 168);
			this->Multiple->Name = L"Multiple";
			this->Multiple->Size = System::Drawing::Size(75, 67);
			this->Multiple->TabIndex = 0;
			this->Multiple->Text = L"*";
			this->Multiple->UseVisualStyleBackColor = true;
			this->Multiple->Click += gcnew System::EventHandler(this, &MainForm::Multiple_Click);
			// 
			// Sub
			// 
			this->Sub->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Sub->Location = System::Drawing::Point(6, 95);
			this->Sub->Name = L"Sub";
			this->Sub->Size = System::Drawing::Size(75, 67);
			this->Sub->TabIndex = 0;
			this->Sub->Text = L"-";
			this->Sub->UseVisualStyleBackColor = true;
			this->Sub->Click += gcnew System::EventHandler(this, &MainForm::Sub_Click);
			// 
			// Plus
			// 
			this->Plus->Enabled = false;
			this->Plus->Font = (gcnew System::Drawing::Font(L"標楷體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Plus->Location = System::Drawing::Point(6, 22);
			this->Plus->Name = L"Plus";
			this->Plus->Size = System::Drawing::Size(75, 67);
			this->Plus->TabIndex = 0;
			this->Plus->Text = L"+";
			this->Plus->UseVisualStyleBackColor = true;
			this->Plus->Click += gcnew System::EventHandler(this, &MainForm::Plus_Click);
			// 
			// Var
			// 
			this->Var->Controls->Add(this->VarName);
			this->Var->Controls->Add(this->VarList);
			this->Var->Controls->Add(this->Modify);
			this->Var->Controls->Add(this->Delete);
			this->Var->Controls->Add(this->Set);
			this->Var->Location = System::Drawing::Point(463, 100);
			this->Var->Name = L"Var";
			this->Var->Size = System::Drawing::Size(247, 437);
			this->Var->TabIndex = 1;
			this->Var->TabStop = false;
			this->Var->Text = L"Var";
			// 
			// VarName
			// 
			this->VarName->Location = System::Drawing::Point(20, 22);
			this->VarName->Name = L"VarName";
			this->VarName->Size = System::Drawing::Size(212, 22);
			this->VarName->TabIndex = 2;
			// 
			// VarList
			// 
			this->VarList->ColumnWidth = 100;
			this->VarList->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->VarList->FormattingEnabled = true;
			this->VarList->HorizontalScrollbar = true;
			this->VarList->IntegralHeight = false;
			this->VarList->ItemHeight = 24;
			this->VarList->Location = System::Drawing::Point(6, 91);
			this->VarList->Name = L"VarList";
			this->VarList->Size = System::Drawing::Size(235, 340);
			this->VarList->Sorted = true;
			this->VarList->TabIndex = 1;
			// 
			// Modify
			// 
			this->Modify->Location = System::Drawing::Point(103, 56);
			this->Modify->Name = L"Modify";
			this->Modify->Size = System::Drawing::Size(62, 24);
			this->Modify->TabIndex = 0;
			this->Modify->Text = L"Modify";
			this->Modify->UseVisualStyleBackColor = true;
			this->Modify->Click += gcnew System::EventHandler(this, &MainForm::Modify_Click);
			// 
			// Delete
			// 
			this->Delete->Location = System::Drawing::Point(171, 56);
			this->Delete->Name = L"Delete";
			this->Delete->Size = System::Drawing::Size(70, 24);
			this->Delete->TabIndex = 0;
			this->Delete->Text = L"DELETE";
			this->Delete->UseVisualStyleBackColor = true;
			this->Delete->Click += gcnew System::EventHandler(this, &MainForm::Delete_Click);
			// 
			// Set
			// 
			this->Set->Location = System::Drawing::Point(20, 56);
			this->Set->Name = L"Set";
			this->Set->Size = System::Drawing::Size(77, 24);
			this->Set->TabIndex = 0;
			this->Set->Text = L"SET";
			this->Set->UseVisualStyleBackColor = true;
			this->Set->Click += gcnew System::EventHandler(this, &MainForm::Set_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(725, 549);
			this->Controls->Add(this->Var);
			this->Controls->Add(this->Functions);
			this->Controls->Add(this->Types);
			this->Controls->Add(this->Show);
			this->Controls->Add(this->Nymber);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Nymber->ResumeLayout(false);
			this->Types->ResumeLayout(false);
			this->Functions->ResumeLayout(false);
			this->Var->ResumeLayout(false);
			this->Var->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		int subCount = 1;
		int bracketCount = 0;
		bool dotCheck = false;
		bool EQ = true;
		int type = 0;//0 integer  1 decimal  2 complex
		void typeLock()
		{
			IntegerBTM->Enabled = false;
			DecimalBTM->Enabled = false;
			ComplexBTM->Enabled = false;
		}
		void typeUnlock()
		{
			IntegerBTM->Enabled = true;
			DecimalBTM->Enabled = true;
			ComplexBTM->Enabled = true;
		}
		void numberLock()
		{
			One->Enabled = false;
			Two->Enabled = false;
			Three->Enabled = false;
			Four->Enabled = false;
			Five->Enabled = false;
			Six->Enabled = false;
			Seven->Enabled = false;
			Eight->Enabled = false;
			Nine->Enabled = false;
			Zero->Enabled = false;
			Dot->Enabled = false;
			Imagine->Enabled = false;
		}
		void numberUnlock()
		{
			One->Enabled = true;
			Two->Enabled = true;
			Three->Enabled = true;
			Four->Enabled = true;
			Five->Enabled = true;
			Six->Enabled = true;
			Seven->Enabled = true;
			Eight->Enabled = true;
			Nine->Enabled = true;
			Zero->Enabled = true;
			if (IntegerBTM->Enabled == false)
			{
				IntegerBTM->Enabled = false;
				DecimalBTM->Enabled = true;
				ComplexBTM->Enabled = true;
				Dot->Enabled = false;
				Imagine->Enabled = false;
			}
			else if (DecimalBTM->Enabled == false)
			{
				IntegerBTM->Enabled = true;
				DecimalBTM->Enabled = false;
				ComplexBTM->Enabled = true;
				Dot->Enabled = false;
				Imagine->Enabled = false;
			}
			else if (ComplexBTM->Enabled == false)
			{
				IntegerBTM->Enabled = true;
				DecimalBTM->Enabled = true;
				ComplexBTM->Enabled = false;
				Dot->Enabled = false;
				Imagine->Enabled = true;
			}
		}
		void operatorLock()
		{
			Plus->Enabled = false;
			Sub->Enabled = false;
			Multiple->Enabled = false;
			Dev->Enabled = false;
			Left->Enabled = false;
			POW->Enabled = false;
			Equal->Enabled = false;
			Factor->Enabled = false;
		}
		void operatorUnlock()
		{
			Plus->Enabled = true;
			Sub->Enabled = true;
			Multiple->Enabled = true;
			Dev->Enabled = true;
			Left->Enabled = true;
			POW->Enabled = true;
			Equal->Enabled = true;
			Factor->Enabled = true;
		}
		void EQCheck() {
			if (EQ)
				Show->Text = "";
			EQ = false;
			bracketCount = 0;
		}
		void bracketCheck() {
			if (bracketCount)
				Right->Enabled = true;
			else
				Right->Enabled = false;
		}
		void SubCheck() {
			// --檢查
			if (subCount == 2)
				Sub->Enabled = false;
			else
				Sub->Enabled = true;
		}
		void EnableFunctions()
		{
			EQCheck();
			Plus->Enabled = true;
			Sub->Enabled = true;
			Multiple->Enabled = true;
			Dev->Enabled = true;
			Left->Enabled = true;
			POW->Enabled = true;
			Equal->Enabled = true;
			Factor->Enabled = true;
			if (type == 1) {
				Factor->Enabled = false;
				if (dotCheck == false)
					Dot->Enabled = true;
				Imagine->Enabled = false;
			}
			else if (type == 2) {
				Factor->Enabled = false;
				if (dotCheck == false)
					Dot->Enabled = true;
				Imagine->Enabled = true;
			}
		}
		void SignFun() {
			if (!DecimalBTM->Enabled || !ComplexBTM->Enabled)
				Dot->Enabled = true;
			if (!ComplexBTM->Enabled)
				Imagine->Enabled = true;
			Plus->Enabled = false;
			Multiple->Enabled = false;
			Dev->Enabled = false;
			POW->Enabled = false;
			Factor->Enabled = false;
			One->Enabled = true;
			Two->Enabled = true;
			Three->Enabled = true;
			Four->Enabled = true;
			Five->Enabled = true;
			Six->Enabled = true;
			Seven->Enabled = true;
			Eight->Enabled = true;
			Nine->Enabled = true;
			Zero->Enabled = true;
			Dot->Enabled = false;
			dotCheck = false;
			SubCheck();
		}
private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e) {
	init();
}
private: System::Void IntegerBTM_Click(System::Object^  sender, System::EventArgs^  e) {
	IntegerBTM->Enabled = false;
	DecimalBTM->Enabled = true;
	ComplexBTM->Enabled = true;
	Dot->Enabled = false;
	Imagine->Enabled = false;
	numberUnlock();
	SubCheck();
	type = 0;
}
private: System::Void DecimalBTM_Click(System::Object^  sender, System::EventArgs^  e) {
	IntegerBTM->Enabled = true;
	DecimalBTM->Enabled = false;
	ComplexBTM->Enabled = true;
	Dot->Enabled = false;
	Imagine->Enabled = false;
	numberUnlock();
	SubCheck();
	type = 1;
}
private: System::Void ComplexBTM_Click(System::Object^  sender, System::EventArgs^  e) {
	IntegerBTM->Enabled = true;
	DecimalBTM->Enabled = true;
	ComplexBTM->Enabled = false;
	Dot->Enabled = false;
	Imagine->Enabled = true;
	numberUnlock();
	SubCheck();
	type = 2;
}
private: System::Void One_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "1";
}
private: System::Void Two_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "2";
}
private: System::Void Three_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "3";
}
private: System::Void Four_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "4";
}
private: System::Void Five_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "5";
}
private: System::Void Six_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "6";
}
private: System::Void Seven_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "7";
}
private: System::Void Eight_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "8";
}
private: System::Void Nine_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "9";
}
private: System::Void Zero_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	EnableFunctions();
	typeLock();
	Show->Text += "0";
}
private: System::Void Dot_Click(System::Object^  sender, System::EventArgs^  e) {
	Show->Text += ".";
	Dot->Enabled = false;
	dotCheck = true;
	Plus->Enabled = false;
	Sub->Enabled = false;
	Multiple->Enabled = false;
	Dev->Enabled = false;
	Left->Enabled = false;
	Right->Enabled = false;
	POW->Enabled = false;
	Factor->Enabled = false;
	Equal->Enabled = false;
	Imagine->Enabled = false;
}
private: System::Void Plus_Click(System::Object^  sender, System::EventArgs^  e) {
	EQ = false;
	subCount = 1;
	typeUnlock();
	Show->Text += "+";
	SignFun();
	numberLock();
	operatorLock();
	SubCheck();
}
private: System::Void Sub_Click(System::Object^  sender, System::EventArgs^  e) {
	EQ = false;
	subCount++;
	typeUnlock();
	Show->Text += "-";
	SignFun();
	if (subCount == 1)
	{
		numberLock();
		operatorLock();
	}
	else if (subCount == 2)
	{
		operatorLock();
		typeLock();
	}

}
private: System::Void Multiple_Click(System::Object^  sender, System::EventArgs^  e) {
	EQ = false;
	subCount = 1;
	typeUnlock();
	Show->Text += "*";
	SignFun();
	numberLock();
	operatorLock();
	SubCheck();
}
private: System::Void Dev_Click(System::Object^  sender, System::EventArgs^  e) {
	EQ = false;
	subCount = 1;
	typeUnlock();
	typeUnlock();
	Show->Text += "/";
	SignFun();
	numberLock();
	operatorLock();
	SubCheck();
}
private: System::Void Back_Click(System::Object^  sender, System::EventArgs^  e) {
	if (Show->Text->Length) {
		if (Show->Text[Show->Text->Length - 1] == '.')
		{
			Dot->Enabled = true;
			dotCheck = false;
		}
		else if (Show->Text[Show->Text->Length - 1] == '-') {
			subCount--;
		}
		if (Show->Text->Length - 1 == 0)
			subCount = 1;
		SubCheck();
		Show->Text = Show->Text->Substring(0, Show->Text->Length - 1);
	}
}
private: System::Void Left_Click(System::Object^  sender, System::EventArgs^  e) {
	EQCheck();
	subCount = 1;
	bracketCount++;
	bracketCheck();
	SubCheck();
	Show->Text += "(";
}
private: System::Void Right_Click(System::Object^  sender, System::EventArgs^  e) {
	subCount = 0;
	bracketCount--;
	SubCheck();
	bracketCheck();
	Show->Text += ")";
}
private: System::Void Factor_Click(System::Object^  sender, System::EventArgs^  e) {
	EQ = false;
	subCount = 0;
	SignFun();
	Factor->Enabled = false;
	Show->Text += "!";
}
private: System::Void Clear_Click(System::Object^  sender, System::EventArgs^  e) {
	EQ = false;
	bracketCount = 0;
	subCount = 1;
	SubCheck();
	Show->Text = "";
}
private: System::Void POW_Click(System::Object^  sender, System::EventArgs^  e) {
	EQ = false;
	Sub->Enabled = false;
	POW->Enabled = false;
	Show->Text += "^";
}
private: System::Void Equal_Click(System::Object^  sender, System::EventArgs^  e) {
	string result = msclr::interop::marshal_as<std::string>(Show->Text);
	result = dealNegativeSign(result);
	result = calc(result).data->ToString();
	Show->Text = gcnew String(result.c_str());
	Dot->Enabled = false;
	EQ = true;
	bracketCount = 0;
	bracketCheck();
}
private: System::Void Imagine_Click(System::Object^  sender, System::EventArgs^  e) {
	Show->Text += "i";
	Imagine->Enabled = false;
	Dot->Enabled = false;
	numberLock();
}
private: System::Void Set_Click(System::Object^  sender, System::EventArgs^  e) {
	var result;
	string value = msclr::interop::marshal_as<std::string>(VarName->Text);
	result = calc(dealNegativeSign(msclr::interop::marshal_as<std::string>(Show->Text)));
	map<string, var>::iterator iter;
	iter = vars.find(value);//find by name
	if (iter == vars.end()) {
		switch (result.type)
		{
		case 0:
			VarList->Items->Add("NumberObject\t" + VarName->Text + "\t" + Show->Text + " \b");
			vars[value] = result;
			break;
		case 1:
			VarList->Items->Add("Integer\t" + VarName->Text + "\t" + Show->Text + " \b");
			vars[value] = result;
			break;
		case 2:
			VarList->Items->Add("Decimal\t" + VarName->Text + "\t" + Show->Text + " \b");
			vars[value] = result;
			break;
		case 3:
			VarList->Items->Add("Complex\t" + VarName->Text + "\t" + Show->Text + " \b");
			vars[value] = result;
			break;
		}
		Show->Text = gcnew String(result.data->ToString().c_str());
	}
	else
		Show->Text = "Error!";
	Dot->Enabled = false;
	EQ = true;
	bracketCount = 0;
	bracketCheck();
}
private: System::Void Modify_Click(System::Object^  sender, System::EventArgs^  e) {
	var result;
	string value = msclr::interop::marshal_as<std::string>(VarName->Text);
	result = calc(dealNegativeSign(msclr::interop::marshal_as<std::string>(Show->Text)));
	map<string, var>::iterator iter;
	iter = vars.find(value);//find by name
	if (iter != vars.end()) {
		vars[value] = result;
		Show->Text = gcnew String(result.data->ToString().c_str());
		VarList->Items->Clear();
		for (map<string, var>::iterator iterator = vars.begin(); iterator != vars.end(); iterator++) {
			string combine;
			switch (iterator->second.type)
			{
			case 0:
				combine = "NumberObject\t" + iterator->first + "\t" + iterator->second.data->ToString() + " \b";
				VarList->Items->Add(gcnew String(combine.c_str()));
				break;
			case 1:
				combine = "Integer\t" + iterator->first + "\t" + iterator->second.data->ToString() + " \b";
				VarList->Items->Add(gcnew String(combine.c_str()));
				break;
			case 2:
				combine = "Decimal\t" + iterator->first + "\t" + iterator->second.data->ToString() + " \b";
				VarList->Items->Add(gcnew String(combine.c_str()));
				break;
			case 3:
				combine =  "Complex\t" + iterator->first + "\t" + iterator->second.data->ToString() + " \b";
				VarList->Items->Add(gcnew String(combine.c_str()));
				break;
			}
		}
		Show->Text = gcnew String(result.data->ToString().c_str());
	}
	else
		Show->Text = "Error!";
	Dot->Enabled = false;
	EQ = true;
	bracketCount = 0;
	bracketCheck();
}
private: System::Void Delete_Click(System::Object^  sender, System::EventArgs^  e) {

	map<string, var>::iterator iter;
	string value = msclr::interop::marshal_as<std::string>(VarName->Text);
	iter = vars.find(value);//find by name
	if (iter == vars.end()) 
		Show->Text = "Error!";
	else
	{
		VarList->Items->Clear();
		
		for (map<string, var>::iterator iterator = vars.begin(); iterator != vars.end(); iterator++) {
			if (iterator->first == value) {
				vars.erase(iterator);
				break;
			}
		}
		for (map<string, var>::iterator iterator = vars.begin(); iterator != vars.end(); iterator++) {
				string combine;
				switch (iterator->second.type)
				{
				case 0:
					combine = "NumberObject\t" + iterator->first + "\t" + iterator->second.data->ToString() + " \b";
					VarList->Items->Add(gcnew String(combine.c_str()));
					break;
				case 1:
					combine = "Integer\t" + iterator->first + "\t" + iterator->second.data->ToString() + " \b";
					VarList->Items->Add(gcnew String(combine.c_str()));
					break;
				case 2:
					combine = "Decimal\t" + iterator->first + "\t" + iterator->second.data->ToString() + " \b";
					VarList->Items->Add(gcnew String(combine.c_str()));
					break;
				case 3:
					combine = "Complex\t" + iterator->first + "\t" + iterator->second.data->ToString() + " \b";
					VarList->Items->Add(gcnew String(combine.c_str()));
					break;
				}
		}
		Show->Text = "";
	}
	Dot->Enabled = false;
	EQ = true;
	bracketCount = 0;
	bracketCheck();
}
};
}