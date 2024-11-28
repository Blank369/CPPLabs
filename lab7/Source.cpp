#include "Header.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1215);
	SetConsoleOutputCP(1215);
	system("chcp 1251");

	Graph g("graph_2.txt");

	while (true)
	{
		cout << g;
		cout << "--------------------------------------------------" << endl
			<< "Выберите действие:" << endl
			<< "--------------------------------------------------" << endl
			<< "(1) - Добавить вершину в граф" << endl
			<< "(-1) - Удалить вершину из графа" << endl
			<< "(2) - Изменить вес ребра" << endl
			<< "--------------------------------------------------" << endl
			<< "(3) - Поиск кратчайшего пути алгоритмом Дейкстры" << endl
			<< "(4) - Неинформированный поиск в ширину" << endl
			<< "(5) - Неинформированный поиск в глубину" << endl
			<< "--------------------------------------------------" << endl
			<< "(0) - Завершить работу" << endl
			<< "--------------------------------------------------" << endl
			<< "Ваш выбор:\t > ";

		int choice = CheckInput<int>(-1, 5, menu);
		if (choice == 1) {
			++g;
		}
		else if (choice == -1) {
			--g;
		}
		else if (choice == 2) {
			g.ChangeWeigth();
		}
		else if (choice == 3) {
			g.AlgorithmDijkstra();
		}
		else if (choice == 4) {
			cout << "Введите искомую вершину:\t > ";
			int find = CheckInput<int>();
			int found = g.BreadthFirstSearch(find);
			if (found != -1) {
				cout << "Вершина найдена: " << found << endl;
			}
			else {
				cout << "Вершины с данным значением нет в графе" << endl;
			}
		}
		else if (choice == 5) {
			cout << "Введите искомую вершину:\t > ";
			int find = CheckInput<int>();
			int found = g.DepthFirstSearch(find);
			if (found != -1) {
				cout << "Вершина найдена: " << found << endl;
			}
			else {
				cout << "Вершины с данным значением нет в графе" << endl;
			}
		}
		else if (choice == 0) {
			cout << "Завершение работы" << endl;
			return 0;
		}
	}
}