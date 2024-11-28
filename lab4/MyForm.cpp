#include "Header.h"

int main()
{
	setlocale(0, "");
	SetConsoleCP(1215);
	SetConsoleOutputCP(1215);
	system("chcp 1251");

	//UINT codepage = GetConsoleOutputCP();
	//std::cout << codepage << std::endl;

	while (true)
	{
		int i, choice;
		cout << "Выберите дейстивие: " << endl;
		cout << "(1) Поиск элемента" << endl;
		cout << "(2) Построить график сложности f(n)" << endl;
		cout << "(0) Завершить работу" << endl;
		cout << "Ваш выбор \t> ";
		for (i = 0; i < 1; ++i)
		{
			choice = check_number<int>(cin);
			if (choice < 0 || choice > 2) {
				cout << "Введитее число в пределах меню\t > ";
				i--;
			}
			else {}
		}
		system("cls");

		if (choice == 1) {
			int choice_in;
			cout << "Выберите способ ввода данных: " << endl;
			cout << "(1) С клавиатуры" << endl;
			cout << "(2) Из файла" << endl;
			cout << "Ваш выбор \t> ";
			for (i = 0; i < 1; ++i)
			{
				choice_in = check_number<int>(cin);
				if (choice < 1 || choice > 2) {
					cout << "Введитее число в пределах меню\t > ";
					i--;
				}
				else {}
			}
			cout << endl;

			people* PeopleList;
			int n;

			if (choice_in == 1) {
				cout << "Введите количество элементов:\t> ";
				for (i = 0; i < 1; ++i)
				{
					n = check_number<int>(cin);
					if (n <= 1) {
						cout << "Введитее число больше единицы\t > ";
						i--;
					}
					else {}
				}
				
				PeopleList = new people[n];
				in_people(PeopleList, n);
				cout << endl;
				out_people(PeopleList, n);
				ofstream people_list; people_list.open("people_list1.txt");
				fout_people(people_list, PeopleList, n);
				people_list.close();
			}
			else {
				n = 20;
				PeopleList = new people[n];
				ifstream people_list; people_list.open("people_list.txt");
				if (!people_list.is_open()){
					cout << "Не удалось открыть файл" << endl;
				}
				else {
					fin_people(people_list, PeopleList, n);
					out_people(PeopleList, n);
					people_list.close();
				}
			}

			while (true)
			{
				int choice_field;

				cout << endl << "Выберите поле, по которому будет производиться поиск:" << endl;
				cout << "--------------------------------------------------------" << endl;
				cout << "(1) - id" << endl;
				cout << "(2) - name" << endl;
				cout << "(0) Вернуться назад" << endl;
				cout << "Ваш выбор:\t > ";
				for (i = 0; i < 1; ++i)
				{
					choice_field = check_number<int>(cin);
					if (choice_field < 0 || choice_field > 2) {
						cout << "Введитее число в пределах меню\t > ";
						i--;
					}
					else {}
				}

				int id_key;
				string name_key;

				if (choice_field == 1) {
					cout << endl << "Введите ключ для поиска (id)\t> ";
					id_key = check_number<int>(cin);
				}
				else if (choice_field == 2){
					cout << endl << "Введите ключ для поиска (name)\t> ";
					getline(cin, name_key);
					getline(cin, name_key);
					//cout << "Ваш ключ " << name_key << endl;
				}
				else { break; }

				int choice_search;
				cout << endl << endl << "Выберите алгоритм поиска:" << endl;
				cout << "-------------------------------------------------" << endl;
				cout << "(1) - Последовательный поиск" << endl;
				cout << "(2) - Бинарный поиск" << endl;
				cout << "(3) - Фибаначчиев поиск" << endl;
				cout << "Ваш выбор:\t > ";
				for (i = 0; i < 1; ++i)
				{
					choice_search = check_number<int>(cin);
					if (choice_search < 1 || choice_search > 3) {
						cout << "Введитее число в пределах меню\t > ";
						i--;
					}
					else if (choice_field == 2 && choice_search == 3) {
						cout << "Фибоначчиевым поиском можно производить поиск только по id. Воспользуйтесь другим алгоритмом." << endl
							<< "Ваш выбор:\t > ";
						i--;
					}
					else {}
				}
				cout << endl;

				int keyNumber = -1;

				if (choice_search == 1)
				{
					if (choice_field == 1) {
						keyNumber = linear_search(PeopleList, n, id_key);
					}
					else {
						keyNumber = linear_search<string>(PeopleList, n, name_key);
					}
				}

				else if (choice_search == 2)
				{
					insert_sort(PeopleList, n, choice_field);
					if (choice_field == 1) {
						keyNumber = binary_search(PeopleList, n, id_key);
					}
					else {
						keyNumber = binary_search(PeopleList, n, name_key);
					}
				}

				else if (choice_search == 3)
				{
					insert_sort(PeopleList, n, choice_field);
					keyNumber = Fibonacci_search(PeopleList, n, id_key);
				}

				if (keyNumber == -1) {
					cout << "Элемент с данным id/именем не найдет" << endl;
				}
				else {
					cout << "Искомый элемент: " << PeopleList[keyNumber] << endl;
				}
			}
			delete[] PeopleList;
		}
		else if(choice == 2) {
			Application::SetCompatibleTextRenderingDefault(false);
			Application::EnableVisualStyles();
			Application::Run(gcnew MyForm);
		}
		else { return 0; }

		cout << endl;

	}
}

