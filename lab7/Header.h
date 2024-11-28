#pragma once

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <Windows.h>
#include <typeinfo>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>

#define menu "Введите число в пределах меню\t > "

using namespace std;

template<typename I> I CheckInput();
template<typename I> I CheckInput(I);
template<typename I> I CheckInput(I, I, const char*);

class Graph
{
private:
	int** matrixA;
	//int** matrixQ;

	int V = 0, E = 0;

public:
	Graph() : V(0), E(0), matrixA(nullptr) {}

	Graph(int n, int e)
	{
		V = n;
		E = e;
		matrixA = new int* [V];
		//matrixQ = new int* [V];
		for (int i = 0; i < V; i++)
		{
			matrixA[i] = new int[V];
			for (int j = 0; j < V; j++)
			{
				matrixA[i][j] = 0;
			}

			/*matrixQ[i] = new int[E];
			for (int j = 0; j < E; j++)
			{
				matrixQ[i][j] = 0;
			}*/
		}
	}

	Graph(string file)
	{
		ifstream ifile;
		ifile.open(file);

		ifile >> V;
		matrixA = new int* [V];
		for (int i = 0; i < V; i++)
		{
			matrixA[i] = new int[V];
			for (int j = 0; j < V; j++)
			{
				ifile >> matrixA[i][j];
				/*if (matrixA[i][j] != 0) {
					E++;
					if (i == j) {
						E++;
					}
				}*/
			}
		}
		E = CountEdge();
		//CreateMaxrixQ();
		ifile.close();
	}

	~Graph()
	{
		for (int i = 0; i < V; i++) {
			delete[] matrixA[i];
			//	delete[] matrixQ[i];
		}
		delete[] matrixA;
		//delete[] matrixQ;
		matrixA = nullptr;
		//matrixQ = nullptr;
		cout << "Память очищена" << endl;
	}

	Graph(const Graph* originalGraph)
	{
		V = originalGraph->V;
		E = originalGraph->E;
		matrixA = new int* [V];
		//matrixQ = new int* [V];
		for (int i = 0; i < V; i++)
		{
			matrixA[i] = new int[V];
			//matrixQ[i] = new int[E];
			for (int j = 0; j < V; j++)
			{
				matrixA[i][j] = originalGraph->matrixA[i][j];
			}
			/*for (int j = 0; j < E; j++)
			{
				matrixQ[i][j] = originalGraph->matrixQ[i][j];
			}*/

		}
	}

	Graph operator=(const Graph* originalGraph)
	{
		V = originalGraph->V;
		E = originalGraph->E;
		matrixA = new int* [V];
		for (int i = 0; i < V; i++)
		{
			matrixA[i] = new int[V];
			for (int j = 0; j < V; j++)
			{
				matrixA[i][j] = originalGraph->matrixA[i][j];
			}
		}
		return this;
	}

	bool Adjacency(int v1, int v2)
	{
		if (matrixA[v1][v2] != 0) { return true; }
		else { return false; }
	}

	int Weight(int v1, int v2)
	{
		return matrixA[v1][v2];
	}

	int CountEdge()
	{
		int count = 0;
		for (int i = 0; i < V; i++)
		{
			for (int j = i; j < V; j++)
			{
				if (matrixA[i][j] != 0) {
					count++;
				}
			}
		}
		return count;
	}

	void ChangeWeigth()
	{
		cout << "Введите ребро, вес которого хотите изменить (v1 -- v2):";
		cout << "v1\t > ";
		int v1 = CheckInput<int>(1, V, "Введите существующее ребро\t > ");
		cout << "v2\t > ";
		int v2 = CheckInput<int>(1, V, "Введите существующее ребро\t > ");
		cout << "Введите новый вес ребра " << v1 << " -- " << v2 << " (0, если хотите удалить ребро):\t > ";
		int olgEdge = matrixA[v1][v2];
		matrixA[v1][v2] = CheckInput<int>(0);
		matrixA[v2][v1] = matrixA[v1][v2];
		if (olgEdge == 0 || matrixA[v1][v2] != 0) { E++; }
		else if (olgEdge != 0 || matrixA[v1][v2] == 0) { E--; }
	}

	void operator++()
	{
		int** newMatrixA = new int* [V + 1];
		for (int i = 0; i < V + 1; i++)
		{
			newMatrixA[i] = new int[V + 1];
			for (int j = 0; j < V + 1; j++)
			{
				newMatrixA[i][j] = 0;
			}
		}
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				newMatrixA[i][j] = matrixA[i][j];
			}
		}

		int countNewEdge = 0;
		cout << "Вводим новую вершину. Введите веса ребер (0, если вершины не смежные)" << endl;
		for (int i = 0; i < V + 1; ++i)
		{
			cout << "v" << V << " -- " << "v" << i << "\t > ";
			newMatrixA[V][i] = CheckInput<int>(0);
			newMatrixA[i][V] = newMatrixA[V][i];
		}

		int** copyMatrixA = matrixA;
		matrixA = newMatrixA;

		for (int i = 0; i < V; i++) {
			delete[] copyMatrixA[i];
		}
		delete[] copyMatrixA;

		V++;
		E = CountEdge();
	}

	void operator--()
	{
		cout << "Удаляем вершину. Введите номер вершины, которую хотите удалить:\t > ";
		int delV = CheckInput<int>(0, V, "Введите существующее ребро\t > ");

		int** newMatrixA = new int* [V - 1];
		for (int i = 0; i < V - 1; i++)
		{
			newMatrixA[i] = new int[V - 1];
			for (int j = 0; j < V - 1; j++)
			{
				newMatrixA[i][j] = 0;
			}
		}
		for (int i1 = 0, i2 = 0; i1 < V-1; i1++, i2++)
		{
			if (i1 == delV) {
				i1++;
				//continue;
			}
			for (int j1 = 0, j2 = 0; j1 < V-1; j1++, j2++)
			{
				if (j1 == delV) {

					j1++;
					//continue;
				}
				newMatrixA[i2][j2] = matrixA[i1][j1];
				cout << newMatrixA[i2][j2] << " ";
			}
		}

		int** copyMatrixA = matrixA;
		matrixA = newMatrixA;

		for (int i = 0; i < V; i++) {
			delete[] copyMatrixA[i];
		}
		delete[] copyMatrixA;
		
		V--;
		E = CountEdge();
	}

	void OutMatrix(int** matrix, int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "| " << i << " ";
		}
		cout << "|" << endl;
		for (int i = 0; i < n - 2; i++)
		{
			cout << "---------";
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "| " << i << "\t|";
			for (int j = 0; j < n; j++)
			{
				cout << " " << matrix[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}

	friend ostream& operator<<(ostream& stream, const Graph& g)
	{
		cout << endl << "Граф:\tКол-во вершин = " << g.V << "\tКол-во ребер = " << g.E << endl;
		cout << "Матрица смежности:" << endl << "\t";

		for (int i = 0; i < g.V; i++)
		{
			cout << "| " << i << " ";
		}
		cout << "|" << endl;
		for (int i = 0; i < g.V - 2; i++)
		{
			cout << "---------";
		}
		cout << endl;
		for (int i = 0; i < g.V; i++)
		{
			cout << "| " << i << "\t|";
			for (int j = 0; j < g.V; j++)
			{
				cout << " " << g.matrixA[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;

		return stream;
	}

	void AlgorithmDijkstra()
	{
		bool* visited = new bool[V];
		int* distance = new int[V];
		for (int i = 0; i < V; i++)
		{
			distance[i] = INT_MAX;
			visited[i] = false;
		}
		distance[0] = 0;

		/*vector<vector<int>> ways;
		for (int i = 0; i < V; i++)
		{
			vector<int> way {0};
			ways.push_back(way);
		}*/

		int minIndex = INT_MAX, min = INT_MAX;
		do
		{
			minIndex = INT_MAX;
			min = INT_MAX;

			for (int j = 0; j < V; j++)
			{
				if (!visited[j] && distance[j] < min) {
					min = distance[j];
					minIndex = j;
					//ways[minIndex].push_back(j);
					//cout << *ways[minIndex].begin() << " - ";
					//cout << *(ways[minIndex].begin() + 1) << " - ";
				}
			}
			if (minIndex != INT_MAX)
			{
				for (int i = 0; i < V; i++)
				{
					if (Adjacency(minIndex, i))
					{
						int temp = min + matrixA[minIndex][i];
						if (temp < distance[i])
						{
							distance[i] = temp;
							//cout << i << " - ";
							//ways[minIndex].push_back(i);
						}
					}
				}
				visited[minIndex] = true;
			}

		} while (minIndex < INT_MAX);

		vector<stack<int>> ways;
		for (int i = 0; i < V; i++)
		{
			stack<int> way;
			ways.push_back(way);
		}

		for (int i = 0; i < V; ++i)
		{
			if (distance[i] != INT_MAX)
			{
				//cout << "Кратчайший путь " << 0 << " -> " << i << " = " << distance[i] << "\t" << "Путь: ";
				int end = i;
				int weight = distance[end];
				ways[i].push(i);
				//cout << ways[i].top() << " -> ";
				while (end != 0)
				{
					for (int j = 0; j < V; ++j)
					{
						if (matrixA[j][end])
						{
							int temp = weight - matrixA[j][end];

							if (temp == distance[j])
							{
								end = j;
								weight = temp;
								if (j != 0) {
									//cout << " -> " << j;
									ways[i].push(end);
									//cout << ways[i].top() << " -> ";
								}
							}
						}
					}
				}
					ways[i].push(end);
					//cout << ways[i].top() << " -> ";
					//cout << endl;
				
			}
		}
		for (int i = 0; i < V; i++)
		{
			cout << "Кратчайший путь " << 0 << " -> " << i << " = " << distance[i] << "\t" << "Путь: ";
		//	//for_each(ways[i].top(), ways[i].pop(), [](int x) {cout << "| " << x << " |\t"; })
		//	//for (auto iter = ways[i].top(); iter != ways[i].pop(); iter++)
			for (; !ways[i].empty(); )
			{
				cout << ways[i].top() << " -> ";
				ways[i].pop();
			}
			cout << "|" << endl;
		}
		delete[] visited;
		delete[] distance;
 	}

	//int MinDistance(int* distance, bool* visited) {
	//	int min = INF, minIndex = 0;
	//	for (int i = 0; i < V; i++) {
	//		if (!visited[i] && distance[i] < min) {
	//			min = distance[i];
	//			minIndex = i;
	//		}
	//	}
	//	return minIndex;
	//}

	int BreadthFirstSearch(int searchElement)
	{
		vector<int> visited { 0 };
		int count = 0;
		for (auto iter = visited.begin(); iter != visited.end(); iter = visited.begin()+count)
		{
			count++;
			int i = *iter;
			cout << "Исследование вершины " << i << "\t->  " <<
				"Посещены новые вершины: ";
			for (int j = 0; j < V; j++)
			{
				if (Adjacency(i, j) && find(visited.begin(), visited.end(), j) == visited.end()) {
					cout << j << " ";
					visited.push_back(j);
					if (j == searchElement) {
						cout << endl;
						return j;
					}
				}
			}
			cout << endl;
		}
		return -1;
	}

	int DepthFirstSearch(int searchElement)
	{
		/*int found = -1, count = 0;
		vector<int> visited{ firstElement };
		for (auto iter = visited.begin(); iter != visited.end(); iter = visited.begin() + count)
		{
			count++;
			int i = *iter;
			for (int j = 0; j < V; j++)
			{
				if (Adjacency(i, j) && find(visited.begin(), visited.end(), j) == visited.end()) {
					cout << j << " - ";
					if (j == searchElement) {
						cout << "|" << endl;
						return j;
					}
					else {
						found = DepthFirstSearch(searchElement, j);
					}
					if (found != -1) { return found; }
				}
			}
		}
		return found;*/
		vector<bool> visited(V, false);
		for (int i = 0; i < V; ++i) {
			if (!visited[i]) {
				if (i == searchElement) {
					//cout << i << " ";
					return i;
				}
				int found = DFS(matrixA, visited, i, searchElement);
				if (found != -1) {
					cout << endl;
					return found;
				}
			}
		}
		return -1;
		/*stack<int> s;
		s.push(firstElement);
		while (!s.empty()) {
			int current = s.top();
			s.pop();
			if (!visited[current]) {
				visited[current] = true;
				cout << current << " ";
				for (int neighbor = matrixA[][];) {
					if (!visited[neighbor]) {
						s.push(neighbor);
					}
				}
			}
		}*/
	}
	int DFS(int** graph, vector<bool>& visited, int firstElement, int searchElement)
	{
		visited[firstElement] = true;
		cout << firstElement << " ";

		cout << endl  << "Исследование вершины " << firstElement << "\t->  " <<
			"Посещены новые вершины: ";

		for (int i = 0; i < V; ++i) {
			if (graph[firstElement][i] && !visited[i]) {
				if (i == searchElement) {
					cout << i << " ";
					return i;
				}
				int found = DFS(graph, visited, i, searchElement);
				if (found != -1) {
					return found;
				}
			}
		}
		return -1;
	}
	/*void CreateMaxrixQ()
	{
		matrixQ = new int* [V];
		for (int i = 0; i < V; i++)
		{
			matrixQ[i] = new int[E];
			for (int j = 0; j < E; j++)
			{
				matrixQ[i][j] = 0;
			}
		}

		for (int i = 0, count = 0; i < V; i++)
		{
			for (int j = count, k = i; j < E ; j++)
			{
				for (int m = k; m < V; m++, k++)
				{
					if (matrixA[i][m] != 0) {
						matrixQ[i][j] = matrixA[i][m];
						matrixQ[m][j] = matrixA[i][m];
						k++; count++;
						break;
					}
				}
				if (k == V) { break; }
			}
		}
	}

	void outQ()
	{
		cout << "Матрица инцидентности:" << endl << "\t";

		char e = 'a';
		for (int i = 0; i < E; i++, e++)
		{
			cout << " | " << e;
		}
		cout << " |" << endl;
		for (int i = 0; i < E - 2; i++)
		{
			cout << "--------";
		}
		cout << endl;
		for (int i = 0; i < V; i++)
		{
			cout << i + 1 << "\t |";
			for (int j = 0; j < E; j++)
			{
				cout << " " << matrixQ[i][j] << "  ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
};

template<typename I>
I CheckInput()
{
	I num;
	for (int j = 0; j < 1; j++)
	{
		cin >> num;
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
			j--;
			cout << "Введите число:\t > ";
		}
		else {}
	}
	return num;
}

template<typename I>
I CheckInput(I left)
{
	I num;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				j--;
				cout << "Введите число:\t > ";
			}
			else {}
		}
		if (num < left) {
			cout << "Введите корректное число:\t > ";
			i--;
		}
	}
	return num;
}

template<typename I>
I CheckInput(I left, I right, const char* message)
{
	I num;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			cin >> num;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				j--;
				cout << "Введите число:\t > ";
			}
			else {}
		}
		if (num < left || num > right) {
			cout << message;
			i--;
		}
	}
	return num;
}


#endif