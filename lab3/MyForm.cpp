#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	cout.setf(ios::fixed);
	cout.precision(2);

	int i, choice;

	start:
	cout << "�������� ��������: " << endl;
	cout << "(1) ������������������ ������ � ������� ������" << endl;
	cout << "(2) ��������� ������ ����������� f(n)" << endl;
	cout << "��� ����� \t> ";
	for (i = 0; i < 1; ++i)
	{
		choice = check_number<int>();
		if (choice < 1 || choice > 2) {
			cout << "�������� ����� �� ����" << endl;
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
	
	cout << "�������� ��������: " << endl;
	cout << "(1) ��������� � ������" << endl;
	cout << "(0) ��������� ������ ���������" << endl;
	cout << "��� ����� \t> ";
	for (i = 0; i < 1; ++i)
	{
		choice = check_number<int>();
		if (choice < 0 || choice > 1) {
			cout << "�������� ����� �� ����" << endl;
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

