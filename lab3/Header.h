#pragma once

#ifndef HEADER_H
#define HEADER_H

#include "MyForm.h"
#include <iostream>
#include <Windows.h>
#include <typeinfo>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

using namespace System;
using namespace System::Windows::Forms;
using namespace lab3;



class Element
{
public:

    int* Int_el;
    short* Short_el;
    long* Long_el;
    float* Float_el;
    double* Double_el;
    long double* LongDouble_el;

    int n;

    Element() : Int_el(), Short_el(), Long_el(), Float_el(), Double_el(), LongDouble_el() {};
    Element(int N) {
        Int_el = new int[N];
        Short_el = new short[N];
        Long_el = new long[N];
        Float_el = new float[N];
        Double_el = new double[N];
        LongDouble_el = new long double[N];

        n = N;
    }

    ~Element() {
        delete[] Int_el;
        delete[] Short_el;
        delete[] Long_el;
        delete[] Float_el;
        delete[] Double_el;
        delete[] LongDouble_el;
    }

    void output();

};


template<typename I>
I check_number()
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

void Element::output()
{
    for (int i = 0; i < n; ++i)
    {
        cout << Int_el[i] << " | " << Short_el[i] << " | " << Long_el[i] << " | " << Float_el[i] << " | " << Double_el[i] << " | " << LongDouble_el[i] << endl;
    }
}

template<typename T>
void out(T* mas, int n)
{
    for (int k = 0; k < n; ++k)
    {
        cout << mas[k] << " | ";
    }
    cout << endl;
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
        out(mas, n);
    }
}

template<typename T>
void stooge_sort(T* mas, int n0, int n)
{
    out(mas, n);
    T place;
    if (mas[n0] > mas[n]) {
        place = mas[n0];
        mas[n0] = mas[n];
        mas[n] = place;
    }
    if (n - n0 + 1 > 2) {
        int t = (n - n0 + 1) / 3;;
        stooge_sort(mas, n0, n - t);
        stooge_sort(mas, n0 + t, n);
        stooge_sort(mas, n0, n - t);
    }
}

template<typename T>
void gnome_sort(T* mas, int n)
{
    int i = 1, j = 2;
    while (i < n)
    {
        if (mas[i] >= mas[i - 1]) {
            i = j;
            j++;
        }
        else
        {
            int t = mas[i];
            mas[i] = mas[i - 1];
            mas[i - 1] = t;
            i--;
            if (i == 0) {
                i = j;
                j++;
            }
        }
		out(mas, n);
    }
}

void work() 
{
	cout << "Задайте количество элементов: \t > ";
	int i, n;
	for (i = 0; i < 1; ++i)
	{
		n = check_number<int>();
		if (n < 0) {
			cout << "Введите положительное число" << endl;
			i--;
		}
		else {}
	}
	cout << endl;

	Element best_case(n), worst_case(n), random_case(n);

	int ni, n0; short ns; long nl; float nf; double nd; long double nld;
	for (n0 = 0, ni = 0, ns = 0, nl = 0, nf = 0, nd = 0, nld = 0; n0 < n; ++n0, ++ni, ++ns, ++nl, ++nf, ++nd, ++nld)
	{
		best_case.Int_el[n0] = ni;
		best_case.Short_el[n0] = ns;
		best_case.Long_el[n0] = nl;
		best_case.Float_el[n0] = nf;
		best_case.Double_el[n0] = nd;
		best_case.LongDouble_el[n0] = nld;
	}

	for (n0 = 0, ni = n, ns = (short)n, nl = (long)n, nf = (float)n, nd = (double)n, nld = (long double)n; n0 < n; ++n0, --ni, --ns, --nl, --nf, --nd, --nld)
	{
		worst_case.Int_el[n0] = ni;
		worst_case.Short_el[n0] = ns;
		worst_case.Long_el[n0] = nl;
		worst_case.Float_el[n0] = nf;
		worst_case.Double_el[n0] = nd;
		worst_case.LongDouble_el[n0] = nld;
	}

	for (n0 = 0; n0 < n; ++n0)
	{
		random_case.Int_el[n0] = rand();
		random_case.Short_el[n0] = rand();
		random_case.Long_el[n0] = rand();
		random_case.Float_el[n0] = (float)rand();
		random_case.Double_el[n0] = (double)rand();
		random_case.LongDouble_el[n0] = (long double)rand();
	}

	cout << "Лучший случай" << endl;
	best_case.output();
	cout << endl;
	cout << "Рандомный случай" << endl;
	random_case.output();
	cout << endl;
	cout << "Худший случай" << endl;
	worst_case.output();
	cout << endl;

	int choice_sort;
	cout << endl << "Выберите сортировку:" << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "(1) - сортировка вставкой" << endl;
	cout << "(2) - Придурковатая сортировка" << endl;
	cout << "(3) - Гномья сортировка" << endl;
	cout << "Ваш выбор:\t > ";
	for (i = 0; i < 1; ++i)
	{
		choice_sort = check_number<int>();
		if (choice_sort < 1 || choice_sort > 3) {
			cout << "Выберете число из меню" << endl;
			i--;
		}
		else {}
	}
	cout << endl;
	
	if (choice_sort == 1)
	{
		cout << "(1) - сортировка вставкой" << endl;

		cout << endl << "Лучший случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		insert_sort(best_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		insert_sort(best_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		insert_sort(best_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		insert_sort(best_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		insert_sort(best_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		insert_sort(best_case.LongDouble_el, n);
		cout << endl;

		cout << endl << "Рандомный случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		insert_sort(random_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		insert_sort(random_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		insert_sort(random_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		insert_sort(random_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		insert_sort(random_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		insert_sort(random_case.LongDouble_el, n);
		cout << endl;


		cout << endl << "Худший случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		insert_sort(worst_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		insert_sort(worst_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		insert_sort(worst_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		insert_sort(worst_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		insert_sort(worst_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		insert_sort(worst_case.LongDouble_el, n);
		cout << endl;

	}
	else if (choice_sort == 2)
	{
		cout << "(2) - Придурковатая сортировка" << endl;

		cout << endl << "Лучший случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		stooge_sort(best_case.Int_el, 0, n - 1);
		out(best_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		stooge_sort(best_case.Short_el, 0, n - 1);
		out(best_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		stooge_sort(best_case.Long_el, 0, n - 1);
		out(best_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		stooge_sort(best_case.Float_el, 0, n - 1);
		out(best_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		stooge_sort(best_case.Double_el, 0, n - 1);
		out(best_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		stooge_sort(best_case.LongDouble_el, 0, n - 1);
		out(best_case.LongDouble_el, n);
		cout << endl;


		cout << endl << "Рандомный случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		stooge_sort(random_case.Int_el, 0, n - 1);
		out(random_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		stooge_sort(random_case.Short_el, 0, n - 1);
		out(random_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		stooge_sort(random_case.Long_el, 0, n - 1);
		out(random_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		stooge_sort(random_case.Float_el, 0, n - 1);
		out(random_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		stooge_sort(random_case.Double_el, 0, n - 1);
		out(random_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		stooge_sort(random_case.LongDouble_el, 0, n - 1);
		out(random_case.LongDouble_el, n);
		cout << endl;


		cout << endl << "Худший случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		stooge_sort(worst_case.Int_el, 0, n - 1);
		out(worst_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		stooge_sort(worst_case.Short_el, 0, n - 1);
		out(worst_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		stooge_sort(worst_case.Long_el, 0, n - 1);
		out(worst_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		stooge_sort(worst_case.Float_el, 0, n - 1);
		out(worst_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		stooge_sort(worst_case.Double_el, 0, n - 1);
		out(worst_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		stooge_sort(worst_case.LongDouble_el, 0, n - 1);
		out(worst_case.LongDouble_el, n);
		cout << endl;
	}
	else if (choice_sort == 3)
	{
		cout << "(3) - Гномья сортировка" << endl;

		cout << endl << "Лучший случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		gnome_sort(best_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		gnome_sort(best_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		gnome_sort(best_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		gnome_sort(best_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		gnome_sort(best_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		gnome_sort(best_case.LongDouble_el, n);
		cout << endl;


		cout << endl << "Рандомный случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		gnome_sort(random_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		gnome_sort(random_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		gnome_sort(random_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		gnome_sort(random_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		gnome_sort(random_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		gnome_sort(random_case.LongDouble_el, n);
		cout << endl;


		cout << endl << "Худший случай: " << endl
			<< "--------------" << endl;
		cout << endl;
		cout << "int" << endl;
		gnome_sort(worst_case.Int_el, n);
		cout << endl;

		cout << "short" << endl;
		gnome_sort(worst_case.Short_el, n);
		cout << endl;

		cout << "long" << endl;
		gnome_sort(worst_case.Long_el, n);
		cout << endl;

		cout << "float" << endl;
		gnome_sort(worst_case.Float_el, n);
		cout << endl;

		cout << "double" << endl;
		gnome_sort(worst_case.Double_el, n);
		cout << endl;

		cout << "long double" << endl;
		gnome_sort(worst_case.LongDouble_el, n);
		cout << endl;
	}
}

System::Void lab3::MyForm::button_Click(System::Object^ sender, System::EventArgs^ e)
{

	int i;
	int n, N = 20, p = 20;

	/*cout << "Задайте количество элементов: \t > ";
	for (i = 0; i < 1; ++i)
	{
		n = check_number<int>();
		if (n < 0) {
			cout << "Введите положительное число" << endl;
			i--;
		}
		else {}
	}*/
	
	double** timer_1, ** timer_2, **timer_3;
	timer_1 = new double* [3]; // insert
	timer_2 = new double* [3]; // stooge
	timer_3 = new double* [3]; // gnome
	for (i = 0; i < 3; ++i)
	{
		timer_1[i] = new double[N];
		timer_2[i] = new double[N];
		timer_3[i] = new double[N];
		for (int j = 0; j < N; j++)
		{
			timer_1[i][j] = 0;
			timer_2[i][j] = 0;
			timer_3[i][j] = 0;
		}
	}

	for(n = 2; n <= N; ++n)
	{
		cout.setstate(std::ios_base::failbit);
		Element best_case(n), worst_case(n), random_case(n);

		//insert
		if (this->radioButton1->Checked)
		{
			for (int i = 0; i < n; ++i)
			{
				best_case.Int_el[i] = i;
				worst_case.Int_el[i] = i;
				random_case.Int_el[i] = rand();
			}

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				insert_sort(best_case.Int_el, n);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_1[0][n - 2] += elapsed_time.count();
			}
			timer_1[0][n - 2] /= p;

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				insert_sort(random_case.Int_el, n);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_1[1][n - 2] += elapsed_time.count();
			}
			timer_1[1][n - 2] /= p;

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				insert_sort(worst_case.Int_el, n);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_1[2][n - 2] += elapsed_time.count();
			}
			timer_1[2][n - 2] /= p;
		}

		//stooge
		else if (this->radioButton2->Checked)
		{
			for (int i = 0; i < n; ++i)
			{
				best_case.Int_el[i] = i;
				worst_case.Int_el[i] = i;
				random_case.Int_el[i] = rand();
			}

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				stooge_sort(best_case.Int_el, 0, n - 1);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_2[0][n - 2] += elapsed_time.count();
			}
			timer_2[0][n - 2] /= p;

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				stooge_sort(random_case.Int_el, 0, n - 1);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_2[1][n - 2] += elapsed_time.count();
			}
			timer_2[1][n - 2] /= p;

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				stooge_sort(worst_case.Int_el, 0, n - 1);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_2[2][n - 2] += elapsed_time.count();
			}
			timer_2[2][n - 2] /= p;
		}

		//gnome
		else if (this->radioButton3->Checked)
		{
			for (int i = 0; i < n; ++i)
			{
				best_case.Int_el[i] = i;
				worst_case.Int_el[i] = i;
				random_case.Int_el[i] = rand();
			}

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				gnome_sort(best_case.Int_el, n);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_3[0][n - 2] += elapsed_time.count();
			}
			timer_3[0][n - 2] /= p;

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				gnome_sort(random_case.Int_el, n);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_3[1][n - 2] += elapsed_time.count();
			}
			timer_3[1][n - 2] /= p;

			for (int e = 0; e < p; ++e)
			{
				auto startTime = system_clock::now();
				stooge_sort(worst_case.Int_el, 0, n - 1);
				auto currentTime = system_clock::now();
				duration<double> elapsed_time = duration_cast<duration<double>>(currentTime - startTime);
				timer_3[2][n - 2] += elapsed_time.count();
			}
			timer_3[2][n - 2] /= p;
		}

		cout.clear();
		//cout << n << endl;
	}


	chart_1->Series[0]->Points->Clear();
	chart_1->Series[1]->Points->Clear();
	chart_1->Series[2]->Points->Clear();

	for (i = 0; i < n-2; ++i)
	{
		if (this->radioButton1->Checked)
		{
			if(this->checkBox1->Checked) chart_1->Series[0]->Points->AddXY(i + 2, timer_1[0][i]);
			if(this->checkBox2->Checked) chart_1->Series[1]->Points->AddXY(i + 2, timer_1[1][i]);
			if(this->checkBox3->Checked) chart_1->Series[2]->Points->AddXY(i + 2, timer_1[2][i]);
		}

		else if (this->radioButton2->Checked)
		{
			if (this->checkBox1->Checked) chart_1->Series[0]->Points->AddXY(i + 2, timer_2[0][i]);
			if (this->checkBox2->Checked) chart_1->Series[1]->Points->AddXY(i + 2, timer_2[1][i]);
			if (this->checkBox1->Checked) chart_1->Series[2]->Points->AddXY(i + 2, timer_2[2][i]);
		}

		else if (this->radioButton3->Checked)
		{
			if (this->checkBox1->Checked) chart_1->Series[0]->Points->AddXY(i + 2, timer_3[0][i]);
			if (this->checkBox2->Checked) chart_1->Series[1]->Points->AddXY(i + 2, timer_3[1][i]);
			if (this->checkBox3->Checked) chart_1->Series[2]->Points->AddXY(i + 2, timer_3[2][i]);
		}
	}

	cout << "hello" << endl;
	for (i = 0; i < 3; ++i) {
		delete[] timer_1[i];
		delete[] timer_2[i];
		delete[] timer_3[i];
	}
	delete[] timer_1;
	timer_1 = nullptr;
	delete[] timer_2;
	timer_2 = nullptr;
	delete[] timer_3;
	timer_3 = nullptr;

    return System::Void();
}

#endif