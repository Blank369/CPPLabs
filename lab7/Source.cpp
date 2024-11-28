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
			<< "�������� ��������:" << endl
			<< "--------------------------------------------------" << endl
			<< "(1) - �������� ������� � ����" << endl
			<< "(-1) - ������� ������� �� �����" << endl
			<< "(2) - �������� ��� �����" << endl
			<< "--------------------------------------------------" << endl
			<< "(3) - ����� ����������� ���� ���������� ��������" << endl
			<< "(4) - ����������������� ����� � ������" << endl
			<< "(5) - ����������������� ����� � �������" << endl
			<< "--------------------------------------------------" << endl
			<< "(0) - ��������� ������" << endl
			<< "--------------------------------------------------" << endl
			<< "��� �����:\t > ";

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
			cout << "������� ������� �������:\t > ";
			int find = CheckInput<int>();
			int found = g.BreadthFirstSearch(find);
			if (found != -1) {
				cout << "������� �������: " << found << endl;
			}
			else {
				cout << "������� � ������ ��������� ��� � �����" << endl;
			}
		}
		else if (choice == 5) {
			cout << "������� ������� �������:\t > ";
			int find = CheckInput<int>();
			int found = g.DepthFirstSearch(find);
			if (found != -1) {
				cout << "������� �������: " << found << endl;
			}
			else {
				cout << "������� � ������ ��������� ��� � �����" << endl;
			}
		}
		else if (choice == 0) {
			cout << "���������� ������" << endl;
			return 0;
		}
	}
}