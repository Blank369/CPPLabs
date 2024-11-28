#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	cout.setf(ios::fixed);
	cout.precision(2);

	int i, choice;

	start:
	cout << "Выберите действие: " << endl;
	cout << "(1) Продемонстрировать работу с разными типами" << endl;
	cout << "(2) Построить график зависимости f(n)" << endl;
	cout << "Ваш выбор \t> ";
	for (i = 0; i < 1; ++i)
	{
		choice = check_number<int>();
		if (choice < 1 || choice > 2) {
			cout << "Выберете число из меню" << endl;
			i--;
		}
		else {}
	}
	cout << endl;

	if (choice == 1) { work(); }
	else {
		Application::SetCompatibleTextRenderingDefault(false);
		Application::EnableVisualStyles();
		Application::Run(gcnew MyForm);
	}
	
	cout << "Выберите действие: " << endl;
	cout << "(1) Вернуться к началу" << endl;
	cout << "(0) Завершить работу программы" << endl;
	cout << "Ваш выбор \t> ";
	for (i = 0; i < 1; ++i)
	{
		choice = check_number<int>();
		if (choice < 0 || choice > 1) {
			cout << "Выберете число из меню" << endl;
			i--;
		}
		else {}
	}

	if (choice == 1) { 
		cout << endl; 
		system("cls");
		goto start; 
	}
	else {
		return 0;
	}
}

