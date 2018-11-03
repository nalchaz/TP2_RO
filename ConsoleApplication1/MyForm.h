#pragma once
#include "Tpopulation.h"
#include "msclr\marshal_cppstd.h""
#include <stdlib.h>
#include <string.h>

namespace ConsoleApplication1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;



	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(95, 259);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(309, 38);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(126, 209);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Fichier à utiliser :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(28, 51);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(439, 130);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Lancer l\'algorithme génétique";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(98, 334);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label2->Size = System::Drawing::Size(289, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Nombre d\'evaluations";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(126, 366);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(246, 32);
			this->label3->TabIndex = 4;
			this->label3->Text = L"de chromosomes :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(95, 427);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(309, 38);
			this->textBox2->TabIndex = 5;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(502, 77);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1000, 1068);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			this->chart1->Location = System::Drawing::Point(1529, 77);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(848, 743);
			this->chart1->TabIndex = 7;
			this->chart1->UseWaitCursor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(2443, 1174);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"Algorithme Genetique";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma 
		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {}
	/*
	if (!this->textBox1 || !this->textBox2) {
		this->richTextBox1->Text = "Veuillez remplir les champs correctement.";
		return;
	}

	char * fichier = marshal_as<char *>(this->textBox1->Text);
	int nbEval = Convert::ToInt32(this->textBox2->Text);
	String^ text;
	Tpopulation population(fichier);

	population.genererPopulation();

	this->textBox1->Text += "POPULATION AVANT L'ALGORITHME GENETIQUE\n\n";
	text = marshal_as<String^>(population.toString());
	this->textBox1->Text += text;

	for (int i = 0; i < nbEval; i++) {
		population.genererFils();
	}
	this->textBox1->Text += "\n\nPOPULATION APRES L'ALGORITHME GENETIQUE\n\n";
	text = marshal_as<String^>(population.toString());
	this->textBox1->Text += text;

}
*/
};
}
