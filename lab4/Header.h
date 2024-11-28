#pragma once

#ifndef HEADER_H
#define HEADER_H

#include "MyForm.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <typeinfo>
#include <fstream>
#include <chrono>
#include <type_traits>

#define type int

using namespace std;
using namespace std::chrono;

using namespace System;
using namespace System::Windows::Forms;
using namespace lab44;

template <typename I> I check_number(istream&);
template <typename I> I CheckInput();

class people
{
private:
	int id;
	string name;
public:
	people() :id(), name() {};
	people(int ID, string NAME)
	{
		id = ID;
		name = NAME;
	}
	people(const people& p1)
	{
		id = p1.id;
		name = p1.name;
	}
	~people()
	{
		id = 0;
		name = "";
	}

	int get_id() { return id; }
	string get_name() { return name; }

	void set_id(int NewID) { id = NewID; }
	void set_name(string NewName) { name = NewName; }

	people& operator=(const people& p2)
	{
		id = p2.id;
		name = p2.name;
		return *this;
	}

	friend istream& operator>>(istream& inStream, people& p)
	{
		cout << "¬ведите id: \t > ";
		p.id = check_number<int>(inStream);
		cout << "¬ведите им€: \t > ";
		inStream >> p.name;
		return inStream;
	}

	friend ostream& operator<<(ostream& outStream, people& p)
	{
		outStream << p.id << "\t" << p.name << endl;
		return outStream;
	}

	template <typename T> bool operator ==(const T& key)
	{
		//cout << typeid(key).name() << endl;
		string check_int = "int";
		if (typeid(key).name() == check_int) {
			//cout << typeid(key).name() << endl;
			if constexpr (std::is_convertible<T, int>::value) {

				if (get_id() == key) { return true; }
				else { return false; }
			}
			else {
				cout << "error" << endl;
				return false;
			}
		}
		else {
			if constexpr (std::is_convertible<T, string>::value) {
				//cout << "here-----------------" << endl;
					//cout << get_name() << " - " << key << endl;
				if (get_name() == key) { return true; }
				else { return false; }
			}
			else {
				cout << "error" << endl;
				return false;
			}
		}
	}

	template <typename T> bool operator <(const T& key)
	{
		//cout << typeid(key).name() << endl;
		string check_int = "int";
		if (typeid(key).name() == check_int) {
			//cout << typeid(key).name() << endl;
			if constexpr (std::is_convertible<T, int>::value) {

				if (get_id() < key) { return true; }
				else { return false; }
			}
			else {
				cout << "error" << endl;
				return false;
			}
		}
		else {
			if constexpr (std::is_convertible<T, string>::value) {
				//cout << "here-----------------" << endl;
					//cout << get_name() << " - " << key << endl;
				if (get_name() < key) { return true; }
				else { return false; }
			}
			else {
				cout << "error" << endl;
				return false;
			}
		}
	}

	template <typename T> bool operator >(const T& key)
	{
		//cout << typeid(key).name() << endl;
		string check_int = "int";
		if (typeid(key).name() == check_int) {
			//cout << typeid(key).name() << endl;
			if constexpr (std::is_convertible<T, int>::value) {

				if (get_id() > key) { return true; }
				else { return false; }
			}
			else {
				cout << "error" << endl;
				return false;
			}
		}
		else {
			if constexpr (std::is_convertible<T, string>::value) {
				//cout << "here-----------------" << endl;
					//cout << get_name() << " - " << key << endl;
				if (get_name() > key) { return true; }
				else { return false; }
			}
			else {
				cout << "error" << endl;
				return false;
			}
		}
	}

	void random()
	{
		id = rand();
		name = rand();
	}
};

void in_people(people* P, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << endl << "¬ведите данные человека " << i + 1 << endl;
		cin >> P[i];
	}
}

void out_people(people* P, int n)
{
	cout << "id\tname" << endl
		<< "----------------" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << P[i];
	}
}

void fout_people(ofstream& out, people* P, int n)
{
	for (int i = 0; i < n; ++i)
	{
		out << P[i];
	}
}

void fin_people(ifstream& in, people* P, int n)
{
	cout.setstate(std::ios_base::failbit);
	for (int i = 0; i < n; ++i)
	{
		in >> P[i];
	}
	cout.clear();
}

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
			cout << "¬ведите число:\t > ";
		}
		else {}
	}
	return num;
}

template<typename I>
I check_number(istream& in)
{
	I num;
	for (int j = 0; j < 1; j++)
	{
		in >> num;
		if (in.fail()) {
			in.clear();
			in.ignore();
			j--;
			//cout << "¬ведите число:\t > ";
		}
		else {}
	}
	return num;
}

template<typename T>
int linear_search(people* p, int N, T key)
{
	int keyNumber = -1;
	for (int i = 0; i < N; ++i)
	{
		if (p[i] == key) {
			keyNumber = i;
			break;
		}
	}
	return keyNumber;
}

template<typename T>
int linear_search(T* p, int N, T key)
{
	int keyNumber = -1;
	for (int i = 0; i < N; ++i)
	{
		if (p[i] == key) {
			keyNumber = i;
			break;
		}
	}
	return keyNumber;
}

void insert_sort(people* mas, int n, int choice_field)
{
	//cout << "here-------------------------" << endl;
	int i, j;
	if (choice_field == 1) {
		people key;

		for (i = 1; i < n; ++i)
		{
			key = mas[i];
			j = i - 1;

			while (j >= 0 && mas[j].get_id() > key.get_id()) {
				mas[j + 1] = mas[j];
				j = j - 1;
			}
			mas[j + 1] = key;
		}
	}
	else {
		people key;
		for (i = 1; i < n; ++i)
		{
			key = mas[i];
			j = i - 1;

			while (j >= 0 && mas[j].get_name() > key.get_name()) {
				mas[j + 1] = mas[j];
				j = j - 1;
			}
			mas[j + 1] = key;
		}
	}
	//out_people(mas, n);
}

template<typename T>
void insert_sort(T* mas, int n)
{
	T key;
	int i, j;

	for (i = 1; i < n; ++i)
	{
		key = mas[i];
		j = i - 1;

		while (j >= 0 && mas[j] > key) {
			mas[j + 1] = mas[j];
			j = j - 1;
		}
		mas[j + 1] = key;
	}
}

template<typename T>
int binary_search(people* p, int N, T key)
{
	int keyNumber = -1, A = 0, B = N - 1;
	//cout << "hello" << endl;
	while ((B - A) > 1)
	{
		if (p[A] == key) { return 0; }
		else if (p[B] == key) { return N - 1; }
		//cout << "A = " << A << endl;
		//cout << "B = " << B << endl;
		if ((A - B) % 2 == 0) {
			//cout << "here----------------------------" << endl;
			N = (A + B) / 2;
		}
		else {
			//cout << "here---------------" << endl;
			N = (A + B) / 2 + 1;
		}

		if (p[N] < key) { A = N; }
		else if (p[N] == key) { return N; }
		else { B = N; }
	}
	return keyNumber;
}

template<typename T>
int binary_search(T * p, int N, T key)
{
	int keyNumber = -1, A = 0, B = N - 1;
	//cout << "hello" << endl;
	while ((B - A) > 1)
	{
		if (p[A] == key) { return 0; }
		else if (p[B] == key) { return N - 1; }
		//cout << "A = " << A << endl;
		//cout << "B = " << B << endl;
		if ((A - B) % 2 == 0) {
			//cout << "here----------------------------" << endl;
			N = (A + B) / 2;
		}
		else {
			//cout << "here---------------" << endl;
			N = (A + B) / 2 + 1;
		}

		if (p[N] < key) { A = N; }
		else if (p[N] == key) { return N; }
		else { B = N; }
	}
	return keyNumber;
}

template<typename T>
int Fibonacci_search(people* p, int N, T key)
{
	int fib2 = 0;
	int fib1 = 1;
	int fib = fib1 + fib2;

	while (fib < N) {
		fib2 = fib1;
		fib1 = fib;
		fib = fib1 + fib2;
	}

	int offset = -1;

	while (fib > 1) {
		int i = min(offset + fib2, N - 1);

		if (p[i] < key) {
			fib = fib1;
			fib1 = fib2;
			fib2 = fib - fib1;
			offset = i;
		}
		else if (p[i] > key) {
			fib = fib2;
			fib1 = fib1 - fib2;
			fib2 = fib - fib1;
		}
		else {
			return i;
		}
	}

	if (fib1 && p[offset + 1] == key) {
		return offset + 1;
	}

	return -1;
}

template<typename T>
int Fibonacci_search(T* p, int N, T key)
{
	int fib2 = 0;
	int fib1 = 1;
	int fib = fib1 + fib2;

	while (fib < N) {
		fib2 = fib1;
		fib1 = fib;
		fib = fib1 + fib2;
	}

	int offset = -1;

	while (fib > 1) {
		int i = min(offset + fib2, N - 1);

		if (p[i] < key) {
			fib = fib1;
			fib1 = fib2;
			fib2 = fib - fib1;
			offset = i;
		}
		else if (p[i] > key) {
			fib = fib2;
			fib1 = fib1 - fib2;
			fib2 = fib - fib1;
		}
		else {
			return i;
		}
	}

	if (fib1 && p[offset + 1] == key) {
		return offset + 1;
	}

	return -1;
}

System::Void lab44::MyForm::button_start_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[2]->Points->Clear();

	int N;
	if (this->textBox_N->Text == "" || Convert::ToInt32(this->textBox_N->Text) <= 0) {
		System::Windows::Forms::MessageBox::Show(this, "¬ведите количество элементов", "упс", MessageBoxButtons::OK);
	}
	else {
		N = Convert::ToInt32(this->textBox_N->Text);

		for (int i = 2; i < N; ++i)
		{
			int keyNumber = -1, p = 100;
			//int el_best = 0, el_mid = i / 2, el_worst = i - 1;
			int el = i - 1;

			type* array;
			array = new type[i];

			//type p_best, p_mid, p_worst;
			type p_search;

			for (int j = 0; j < i; ++j)
			{
				array[j] = rand();
			}

			double* timer = new double[3];
			timer[0] = 0; timer[1] = 0; timer[2] = 0;

			insert_sort(array, i);

			p_search = array[el];
			/*p_best = array[el_best];
			p_mid = array[el_mid];
			p_worst = array[el_worst];*/

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				keyNumber = linear_search(array, i, p_search);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer[0] += elapsed_time.count();
			}
			timer[0] /= p;
			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				keyNumber = binary_search(array, i, p_search);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer[1] += elapsed_time.count();
			}
			timer[1] /= p;
			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				keyNumber = Fibonacci_search(array, i, p_search);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer[2] += elapsed_time.count();
			}
			timer[2] /= p;


			if (this->checkBox_linear->Checked) {
				this->chart1->Series[0]->Points->AddXY(i, timer[0]);
			}
			if (this->checkBox_binary->Checked) {
				this->chart1->Series[1]->Points->AddXY(i, timer[1]);
			}
			if (this->checkBox_Fibonacci->Checked) {
				this->chart1->Series[2]->Points->AddXY(i, timer[2]);
			}
			delete[] timer;
			delete[] array;
		}
	}
	return System::Void();
}

System::Void lab44::MyForm::button_end_Click(System::Object^ sender, System::EventArgs^ e)
{
	exit(1);
	return System::Void();
}

#endif
