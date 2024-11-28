#pragma once

namespace lab44 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ button_end;
	private: System::Windows::Forms::Button^ button_start;
	private: System::Windows::Forms::TextBox^ textBox_N;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::CheckBox^ checkBox_Fibonacci;

	private: System::Windows::Forms::CheckBox^ checkBox_binary;
	private: System::Windows::Forms::CheckBox^ checkBox_linear;







	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button_end = (gcnew System::Windows::Forms::Button());
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->textBox_N = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox_Fibonacci = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_binary = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox_linear = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::SemiTransparent;
			series1->BorderWidth = 3;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series1->Legend = L"Legend1";
			series1->Name = L"Линейный";
			series2->BorderWidth = 3;
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series2->Legend = L"Legend1";
			series2->Name = L"Бинарный";
			series3->BorderWidth = 3;
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Spline;
			series3->Legend = L"Legend1";
			series3->Name = L"Фибоначчи";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Size = System::Drawing::Size(738, 583);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Azure;
			this->groupBox1->Controls->Add(this->button_end);
			this->groupBox1->Controls->Add(this->button_start);
			this->groupBox1->Controls->Add(this->textBox_N);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->checkBox_Fibonacci);
			this->groupBox1->Controls->Add(this->checkBox_binary);
			this->groupBox1->Controls->Add(this->checkBox_linear);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(756, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(278, 583);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Выбор алгоритма поиска";
			// 
			// button_end
			// 
			this->button_end->BackColor = System::Drawing::Color::LightSlateGray;
			this->button_end->Location = System::Drawing::Point(6, 519);
			this->button_end->Name = L"button_end";
			this->button_end->Size = System::Drawing::Size(267, 58);
			this->button_end->TabIndex = 9;
			this->button_end->Text = L"Завершить работу";
			this->button_end->UseVisualStyleBackColor = false;
			this->button_end->Click += gcnew System::EventHandler(this, &MyForm::button_end_Click);
			// 
			// button_start
			// 
			this->button_start->BackColor = System::Drawing::Color::SteelBlue;
			this->button_start->Location = System::Drawing::Point(6, 447);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(267, 70);
			this->button_start->TabIndex = 8;
			this->button_start->Text = L"Начертить график";
			this->button_start->UseVisualStyleBackColor = false;
			this->button_start->Click += gcnew System::EventHandler(this, &MyForm::button_start_Click);
			// 
			// textBox_N
			// 
			this->textBox_N->Location = System::Drawing::Point(164, 282);
			this->textBox_N->Name = L"textBox_N";
			this->textBox_N->Size = System::Drawing::Size(97, 27);
			this->textBox_N->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 285);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(127, 21);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Кол-во эл-тов";
			// 
			// checkBox_Fibonacci
			// 
			this->checkBox_Fibonacci->AutoSize = true;
			this->checkBox_Fibonacci->Location = System::Drawing::Point(6, 161);
			this->checkBox_Fibonacci->Name = L"checkBox_Fibonacci";
			this->checkBox_Fibonacci->Size = System::Drawing::Size(206, 25);
			this->checkBox_Fibonacci->TabIndex = 5;
			this->checkBox_Fibonacci->Text = L"Фибоначчиев поиск";
			this->checkBox_Fibonacci->UseVisualStyleBackColor = true;
			// 
			// checkBox_binary
			// 
			this->checkBox_binary->AutoSize = true;
			this->checkBox_binary->Location = System::Drawing::Point(6, 110);
			this->checkBox_binary->Name = L"checkBox_binary";
			this->checkBox_binary->Size = System::Drawing::Size(181, 25);
			this->checkBox_binary->TabIndex = 4;
			this->checkBox_binary->Text = L"Бинарный поиск";
			this->checkBox_binary->UseVisualStyleBackColor = true;
			// 
			// checkBox_linear
			// 
			this->checkBox_linear->AutoSize = true;
			this->checkBox_linear->Location = System::Drawing::Point(6, 56);
			this->checkBox_linear->Name = L"checkBox_linear";
			this->checkBox_linear->Size = System::Drawing::Size(253, 25);
			this->checkBox_linear->TabIndex = 3;
			this->checkBox_linear->Text = L"Последовательный поиск";
			this->checkBox_linear->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::PowderBlue;
			this->ClientSize = System::Drawing::Size(1041, 599);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart1);
			this->Name = L"MyForm";
			this->Text = L"Время алгоритмов поиска";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button_start_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void button_end_Click(System::Object^ sender, System::EventArgs^ e);
};
}
