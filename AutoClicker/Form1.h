#pragma once
#include <cstdlib>
#include <iostream>
#include <list>
#include <process.h>
#include "Click.h"
#include <cstdio>
#include <ctime>
#include <Windows.h>
#include "listenToClicks.h"
#define BOOST_ALL_DYN_LINK
#include <boost/thread.hpp>

namespace boost {
	struct thread::dummy {};
}

namespace AutoClicker {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Button^  Start;
	protected: 

	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  record_button;


	private: System::Windows::Forms::Button^  clos;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->Start = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->record_button = (gcnew System::Windows::Forms::Button());
			this->clos = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// Start
			// 
			this->Start->Location = System::Drawing::Point(125, 6);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(111, 23);
			this->Start->TabIndex = 0;
			this->Start->Text = L"Start auto clicking";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Form1::start_auto_clicker);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(198, 10);
			this->textBox1->Name = L"textBox1";
			this->textBox1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->textBox1->Size = System::Drawing::Size(81, 20);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"1.0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(153, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Time between clicks (seconds)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 24.25F));
			this->label2->Location = System::Drawing::Point(12, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(194, 38);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Auto Clicker";
			// 
			// record_button
			// 
			this->record_button->Location = System::Drawing::Point(16, 6);
			this->record_button->Name = L"record_button";
			this->record_button->Size = System::Drawing::Size(100, 23);
			this->record_button->TabIndex = 6;
			this->record_button->Text = L"Record clicks";
			this->record_button->UseCompatibleTextRendering = true;
			this->record_button->UseVisualStyleBackColor = true;
			this->record_button->Click += gcnew System::EventHandler(this, &Form1::record);
			// 
			// clos
			// 
			this->clos->Location = System::Drawing::Point(11, 10);
			this->clos->Name = L"clos";
			this->clos->Size = System::Drawing::Size(107, 23);
			this->clos->TabIndex = 5;
			this->clos->Text = L"Remove all clicks";
			this->clos->TextImageRelation = System::Windows::Forms::TextImageRelation::TextBeforeImage;
			this->clos->UseVisualStyleBackColor = true;
			this->clos->Click += gcnew System::EventHandler(this, &Form1::Close);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(237, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Print current";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::current);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 45);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Offset of clicks (pixel)";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(198, 42);
			this->textBox2->Name = L"textBox2";
			this->textBox2->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->textBox2->Size = System::Drawing::Size(81, 20);
			this->textBox2->TabIndex = 9;
			this->textBox2->Text = L"2";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(124, 10);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(107, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Remove last click";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::removeLast);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(12, 64);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(292, 13);
			this->label4->TabIndex = 11;
			this->label4->Text = L"While auto clicker is running. Use F11 to pause, F12 to stop.";
			// 
			// panel1
			// 
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(12, 90);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(340, 80);
			this->panel1->TabIndex = 12;
			this->panel1->MouseLeave += gcnew System::EventHandler(this, &Form1::check_values);
			// 
			// panel2
			// 
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Controls->Add(this->clos);
			this->panel2->Location = System::Drawing::Point(12, 176);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(340, 45);
			this->panel2->TabIndex = 13;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->record_button);
			this->panel3->Controls->Add(this->Start);
			this->panel3->Location = System::Drawing::Point(12, 231);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(340, 36);
			this->panel3->TabIndex = 14;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(367, 279);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Auto Clicker";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		/*
		* Start of my methods for recording clicks. etc.
		*
		*/
		// Removes all clicks from the list of clicks.


		//private: ListenToClicks * listenToClicks;
	private: System::Void Close(System::Object^  sender, System::EventArgs^  e) {
				 cout << "Any and all clicks are being removed." << endl;
				 ListenToClicks::instance().click_list_clear();
				 ListenToClicks::instance().PrintList();
				 cout << endl;
			 }

			 // Changes the time between clicks.
	private: System::Void ChangeTime(System::Object^  sender, System::EventArgs^  e) {
				 double val;
				 if(Double::TryParse(this->textBox1->Text, val)){
					 ListenToClicks::instance().set_time(val);
				 }else{
					 ListenToClicks::instance().set_time(1.000);
				 }
				 this->textBox1->Text = L""+ListenToClicks::instance().time();
			 }

			 // Records the clicks until you push stop.
	private: System::Void record(System::Object^  sender, System::EventArgs^  e) {
				 //unsigned threadid;
				 if(!ListenToClicks::instance().clicked_record()){
					 this->record_button->Text  = L"Stop Recording";
					 cout<< "Recording clicks." << endl;
					 ListenToClicks::instance().set_clicked_record(true);

					 //must create a thread to listen to make sure that you can stop the recording.
					 boost::thread* pThread = new boost::thread(&ListenToClicks::ListenClicks, &ListenToClicks::instance());
					 //threadid = _beginthread(&ListenToClicks::ListenClicks,0,NULL);
					 //PrintList();
				 }else{
					 ListenToClicks::instance().set_clicked_record(false);
					 this->record_button->Text  = L"Record clicks";
					 Sleep(1000);
					 if(ListenToClicks::instance().click_list_size() > 1){
						 ListenToClicks::instance().click_list_pop_back();
					 }else if(ListenToClicks::instance().click_list_size() == 1){
						 ListenToClicks::instance().click_list_clear();
					 }
					 ListenToClicks::instance().PrintList();
				 }
			 }

			 // Starts clicking automatically, as long as there is clicks recorded.
			 // Waits for a pause signal, or a stop signal. Otherwise keeps looping.
	private: System::Void start_auto_clicker(System::Object^  sender, System::EventArgs^  e) {
				 double val;
				 int val2;
				 if(Double::TryParse(this->textBox1->Text, val)){
					 ListenToClicks::instance().set_time(val);
				 }else{
					 ListenToClicks::instance().set_time(1.000);
				 }
				 this->textBox1->Text = L""+ListenToClicks::instance().time();

				 cout<< "Time between clicks: " << ListenToClicks::instance().time();
				 if(ListenToClicks::instance().time() == 1)
					 cout << " second." << endl;
				 else
					 cout << " seconds." << endl;

				 if(int::TryParse(this->textBox2->Text, val2)){
					 ListenToClicks::instance().set_offset(val2);
				 }else{
					 ListenToClicks::instance().set_offset(2);
				 }
				 cout<< "Offset: " << ListenToClicks::instance().offset();
				 if(ListenToClicks::instance().offset()==1)
					 cout << " pixel." << endl;
				 else
					 cout << " pixels." << endl;

				 this->textBox2->Text = L""+ListenToClicks::instance().offset();

				 if(!ListenToClicks::instance().clicked_start()){
					 ListenToClicks::instance().set_clicked_start(true);

					 // Makes sure that you can pause while the clicker is running.
					 boost::thread* pThread1 = new boost::thread(&ListenToClicks::CheckForPause, &ListenToClicks::instance());
					 //start autoclicker
					 boost::thread* pThread2 = new boost::thread(&ListenToClicks::AutoClick, &ListenToClicks::instance());
					 //_beginthread(&ListenToClicks::instance().CheckForPause, 0, NULL);
					 //_beginthread(&ListenToClicks::instance().AutoClick,0,NULL);
				 }
				 cout << endl;
			 }

			 // When you push "print current" this happens.
			 // Prints the current clicks that are recorded.
			 // And then draws how the clicks match up.
	private: System::Void current(System::Object^  sender, System::EventArgs^  e) {
				 ListenToClicks::instance().PrintList();
				 ListenToClicks::instance().DrawLines();
				 cout << endl;
			 }

			 // Removes the last click added to the list.
	private: System::Void removeLast(System::Object^  sender, System::EventArgs^  e) {
				 cout << "Removing the last click." << endl;
				 cout << "Current clicks are:" << endl;
				 if(ListenToClicks::instance().click_list_size() == 1)
					 ListenToClicks::instance().click_list_clear();
				 else
					 ListenToClicks::instance().click_list_pop_back();
				 ListenToClicks::instance().PrintList();
				 cout << endl;
			 }

	private: System::Void check_values(System::Object^  sender, System::EventArgs^  e) {
				 double val;
				 int val2;
				 try
				 {
					 if(Double::TryParse(this->textBox1->Text, val)){
						 ListenToClicks::instance().set_time(val);
					 }else{
						 ListenToClicks::instance().set_time(1.000);
					 }
					 this->textBox1->Text = L""+ListenToClicks::instance().time();
					 if(int::TryParse(this->textBox2->Text, val2)){
						 ListenToClicks::instance().set_offset(val2);
					 }else{
						 ListenToClicks::instance().set_offset(2);
					 }
					 this->textBox2->Text = L""+ListenToClicks::instance().offset();
				 }
				 catch (NullReferenceException^ e)
				 {

				 }
			 }
	};


}

