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
	using namespace System::Windows::Forms::DataVisualization::Charting;
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
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^  title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
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
			this->textBox1->Location = System::Drawing::Point(96, 260);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(308, 38);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"ft06.txt";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(125, 210);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Fichier à utiliser :";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 50);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(440, 131);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Lancer l\'algorithme génétique";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(90, 333);
			this->label2->Name = L"label2";
			this->label2->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label2->Size = System::Drawing::Size(154, 32);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Nombre de";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(240, 333);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(180, 32);
			this->label3->TabIndex = 4;
			this->label3->Text = L"générations :";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(96, 390);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(308, 38);
			this->textBox2->TabIndex = 5;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(501, 76);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1100, 1068);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// chart1
			// 
			this->chart1->AccessibleName = L"";
			chartArea1->AxisX->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisX2->IntervalAutoMode = System::Windows::Forms::DataVisualization::Charting::IntervalAutoMode::VariableCount;
			chartArea1->AxisY->IsStartedFromZero = false;
			chartArea1->AxisY2->IsStartedFromZero = false;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(1677, 76);
			this->chart1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->Name = L"Population après génétique";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::StepLine;
			series2->Legend = L"Legend1";
			series2->Name = L"Population de base";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(1339, 1073);
			this->chart1->TabIndex = 7;
			title1->Name = L"Title1";
			title1->Text = L"Coût pour chaque élément de la population";
			this->chart1->Titles->Add(title1);
			this->chart1->Click += gcnew System::EventHandler(this, &MyForm::chart1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(3093, 1233);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"Algorithme Genetique";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma 
		
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	System::String^ fichier = textBox1->Text;
	msclr::interop::marshal_context context;
	std::string fichier_a_lire = context.marshal_as<std::string>(fichier);

	Tpopulation population(fichier_a_lire);

	population.genererPopulation();

	int nbEval = Convert::ToInt32(textBox2->Text);

	this->richTextBox1->Text = "POPULATION AVANT L'ALGORITHME GENETIQUE\n\n";

	this->richTextBox1->Text += context.marshal_as<String^>(population.toString());

	chart1->Series["Population de base"]->Points->Clear();
	chart1->Show();

	for (int k = 0; k < TAILLEPOP; k++) {
		chart1->Series["Population de base"]->Points->AddXY(k, population.getListeCout()[k]);
		chart1->Refresh();
	}

	for (int i = 0; i < nbEval; i++) {
		population.generationSuivante();
	}
	this->richTextBox1->Text += "\n\nPOPULATION APRES L'ALGORITHME GENETIQUE\n\n";
	this->richTextBox1->Text += context.marshal_as<String^>(population.toString());

	chart1->Series["Population après génétique"]->Points->Clear();

	for (int k = 0; k < TAILLEPOP; k++) {
		chart1->Series["Population après génétique"]->Points->AddXY(k, population.getListeCout()[k]);
		chart1->Refresh();
	}
	
}

private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void chart1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
