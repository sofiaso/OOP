#pragma once
#include "Header.h"

string Name;

void Add(vector<Product*> &v);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void Table(const int& symbol, const int& number) {
	for (int i = 0; i < number; i++) {
		cout << char(symbol);
	}
}

void space(const int& number) {
	for (int i = 0; i < number; i++) {
		cout << " ";
	}
}

void Print(vector<Product*> v) 
{
	for (auto it = v.begin(); it < v.end(); it++) 
	{
		(* (*it)).Print();
	}
}

void Refil(vector <Product*>& v) {
	v.clear();
	bool T = true, K = true;
	int i = 0;
	int choose;
	while (T) {
		Sleep(500);
		Sleep(500);
		Sleep(500);
		system("cls");
		Add(v);
		K = true;
		while (K) {
			cout << "Enter 0 if you have already fill in all goods\nEnter 1 if you want to continue"<<endl;
			cout << "Choose: " << endl;
			cin >> choose;
			i++;
			if ((choose != 1) && (choose != 0)) {
				SetConsoleTextAttribute(h, 4);
				cout << "Choose correct number" << endl;
				SetConsoleTextAttribute(h, 7);
				Sleep(500);
				Sleep(500);
				Sleep(500);
				system("cls");
			}
			else if (choose == 0) {
				T = false;
				K = false;
			}
			else if (choose == 1)
				K = false;
		}
	}
}

void Add(vector<Product*> &v)
{
	int choose;
	bool K = true;
	while (K) {
		cout << "Choose which product would you add:" << endl;
		cout << "1 - Computer" << endl;
		cout << "2 - Telephone" << endl;
		cout << "3 - headphone" << endl;
		cout << "Choose: ";
		cin >> choose;
		if ((choose != 1) && (choose != 2) && (choose != 3)) {
			SetConsoleTextAttribute(h, 4);
			cout << "Choose correct number" << endl;
			SetConsoleTextAttribute(h, 7);
			Sleep(500);
			Sleep(500);
			Sleep(500);
			system("cls");
		}
		else
			K = false;
	}

	if (choose == 1) {
		Computer* comp = new Computer;
		cout << "Enter name: ";
		cin >> (*comp).Name();
		cout << "Enter price: ";
		cin >> (*comp).Price();
		cout << "Enter number which remain: ";
		cin >> (*comp).Number();
		cout << "Enter firm: ";
		cin >> (*comp).Firm();
		cout << "Enter Computers diagonal:";
		cin >> (*comp).Diagonal();
		v.push_back(comp);
	}
	else if (choose == 2) {
		Telephone* comp = new Telephone;
		cout << "Enter name: ";
		cin >> (*comp).Name();
		cout << "Enter price: ";
		cin >> (*comp).Price();
		cout << "Enter number which remain: ";
		cin >> (*comp).Number();
		cout << "Enter firm: ";
		cin >> (*comp).Firm();
		cout << "Enter amount of memory: ";
		cin >> (*comp).Memory();
		v.push_back(comp);
	}
	else if (choose == 3) {
		HeadPhones* comp = new HeadPhones;
		cout << "Enter name: ";
		cin >> (*comp).Name();
		cout << "Enter price: ";
		cin >> (*comp).Price();
		cout << "Enter number which remain: ";
		cin >> (*comp).Number();
		cout << "Enter firm: ";
		cin >> (*comp).Firm();
		v.push_back(comp);
	}
	Sleep(500);
	Sleep(500);
	Sleep(500);
	system("cls");
}

void Delete(vector<Product*>& v, string name, bool &F) 
{
	Name = name;
	auto it = find_if(v.begin(), v.end(), [](Product* pr) {if ((*pr).Name() == Name) return true; else return false; });

	if (it < v.end()) {
		v.erase(it);
		F = false;
	}
	else {
		SetConsoleTextAttribute(h, 4);
		cout << "Invalid name" << endl;
		SetConsoleTextAttribute(h, 7);
		Sleep(500);
		Sleep(500);
		Sleep(500);
	}
}

void SortPrice(vector<Product*>& v) 
{
	sort(v.begin(), v.end(), [](Product* pr1, Product* pr2) {return (*pr1).Price() < (*pr2).Price(); });
}

void SortName(vector<Product*>& v)
{
	sort(v.begin(), v.end(), [](Product* pr1, Product* pr2) {return (*pr1).Name() < (*pr2).Name(); });
}

void SortNumber(vector<Product*>& v)
{
	sort(v.begin(), v.end(), [](Product* pr1, Product* pr2) {return (*pr1).Number() < (*pr2).Number(); });
}

void SortFirm(vector<Product*>& v)
{
	sort(v.begin(), v.end(), [](Product* pr1, Product* pr2) {return (*pr1).Firm() < (*pr2).Firm(); });
}

void ShowComputers(vector<Product*> v)
{
	int counter = 0;
	for (auto i : v) {
		if ((*i).Type() == 'c') {
			(*i).Print();
			counter++;
		}

		if (counter == 0) {
			SetConsoleTextAttribute(h, 4);
			cout << "There is no hesdphones" << endl;
			SetConsoleTextAttribute(h, 7);
		}
	}
}

void ShowTelephones(vector<Product*> v)
{
	int counter = 0;
	for (auto i : v) {
		if ((*i).Type() == 't') {
			(*i).Print();
			counter++;
		}

		if (counter == 0) {
			SetConsoleTextAttribute(h, 4);
			cout << "There is no hesdphones" << endl;
			SetConsoleTextAttribute(h, 7);
		}
	}
}

void ShowHeadphones(vector<Product*> v)
{
	int counter = 0;
	for (auto i : v) {
		if ((*i).Type() == 'h') {
			(*i).Print();
			counter++;
		}

		if (counter == 0) {
			SetConsoleTextAttribute(h, 4);
			cout << "There is no hesdphones" << endl;
			SetConsoleTextAttribute(h, 7);
		}
	}
}

void ShowFirmComputers(vector<Product*> v, string firm)
{
	int count = 0;
	for (auto i : v) {
		if (((*i).Type() == 'c') && ((*i).Firm() == firm)) {
			(*i).Print();
			count++;
		}
	}

	if (count == 0) {
		SetConsoleTextAttribute(h, 4);
		cout << "There is no product exist w this firm" << endl;
		SetConsoleTextAttribute(h, 7);
	}
}

void ShowFirmTelphones(vector<Product*> v, string firm)
{
	int count = 0;
	for (auto i : v) {
		if (((*i).Type() == 't') && ((*i).Firm() == firm)) {
			(*i).Print();
			count++;
		}
	}

	if (count == 0) {
		SetConsoleTextAttribute(h, 4);
		cout << "There is no product exist w this firm" << endl;
		SetConsoleTextAttribute(h, 7);
	}
}

void ShowFirmHeadphones(vector<Product*> v, string firm)
{
	int count = 0;
	for (auto i : v) {
		if (((*i).Type() == 'h') && ((*i).Firm() == firm))
		{
			(*i).Print();
			count++;
		}

		if (count == 0) {
			SetConsoleTextAttribute(h, 4);
			cout << "There is no product exist w this firm" << endl;
			SetConsoleTextAttribute(h, 7);
		}
	}
}

void ShowTelephoneByPrice(vector<Product*> v, int sum)
{
	int counter = 0;
	for (auto el : v) {
		if (((*el).Type() == 't') && ((*el).Price() < sum)) {
			(*el).Print();
			counter++;
		}
	}
	if (counter == 0) {
		SetConsoleTextAttribute(h, 4);
		cout << "There is no product exist in this sum range" << endl;
		SetConsoleTextAttribute(h, 7);
	}
}

void ShowCmputerByPrice(vector<Product*> v, int sum)
{
	int count = 0;
	for (auto el : v) {
		if (((*el).Type() == 'c') && ((*el).Price() < sum)) {
			(*el).Print();
			count++;
		}
	}
	if (count == 0) {
		SetConsoleTextAttribute(h, 4);
		cout << "There is no product exist in this sum range" << endl;
		SetConsoleTextAttribute(h, 7);
	}
}

void ShowHeadphoneByPrice(vector<Product*> v, int sum)
{
	int count = 0;
	for (auto el : v) {
		if (((*el).Type() == 'h') && ((*el).Price() < sum)) {
			(*el).Print();
			count++;
		}
	}
	if (count == 0) {
		SetConsoleTextAttribute(h, 4);
		cout << "There is no product exist in this sum range" << endl;
		SetConsoleTextAttribute(h, 7);
	}
}

void Convert_d(vector<Product*> v) {
	for (auto it = v.begin(); it < v.end(); it++) {
		if ((*(*it)).Currency() == 'g') {
			(*(*it)).Price() /= 27;
		}
		if ((*(*it)).Currency() == 'd') {
			(*(*it)).Price() *= 1;
		}
		if ((*(*it)).Currency() == 'e') {
			(*(*it)).Price() *= 1.11111111;
		}
		(*(*it)).Currency() = 'd';
	}
}

void Convert_e(vector<Product*> v) {
	for (auto it = v.begin(); it < v.end(); it++) {
		if ((*(*it)).Currency() == 'g') {
			(*(*it)).Price() /= 30;
		}
		if ((*(*it)).Currency() == 'd') {
			(*(*it)).Price() /= 1.11111111;
		}
		if ((*(*it)).Currency() == 'e') {
			(*(*it)).Price() *= 1;
		}
		(*(*it)).Currency() = 'e';
	}
}

void Convert_g(vector<Product*> v) {
	for (auto it = v.begin(); it < v.end(); it++) {
		if ((*(*it)).Currency() == 'g') {
			(*(*it)).Price() *= 1;
		}
		if ((*(*it)).Currency() == 'd') {
			(*(*it)).Price() *= 27;
		}
		if ((*(*it)).Currency() == 'e') {
			(*(*it)).Price() *= 30;
		}
		(*(*it)).Currency() = 'g';
	}
}

void Convert(vector<Product*> v) {
	system("cls");
	bool T = false;
	int choose;
	do {
		T = false;
		cout << char(201); Table(205, 35); cout << char(187) << endl;
		cout << char(186) << "~Choose 1 to convert into dollars  " << char(186) << endl;
		cout << char(204); Table(205, 35); cout << char(185) << endl;
		cout << char(186) << "~Choose 2 to convert into euros    " << char(186) << endl;
		cout << char(204); Table(205, 35); cout << char(185) << endl;
		cout << char(186) << "~Choose 3 to convert into hryvnia  " << char(186) << endl;
		cout << char(200); Table(205, 35); cout << char(188) << endl;
		cout << "\nYour choose: ";
		cin >> choose;
		if (choose == 1)
			Convert_d(v);
		else if (choose == 2)
			Convert_e(v);
		else if (choose == 3)
			Convert_g(v);
		else /*if ((choose != 1)&&(choose != 2)&&(choose != 3))*/ {
			SetConsoleTextAttribute(h, 4);
			cout << "Choose correct number." << endl;
			SetConsoleTextAttribute(h, 7);
			T = true;
			Sleep(500);
			Sleep(500);
			Sleep(500);
			system("cls");
		}
	} while (T);
}

void Write(ofstream& out, vector<Product*> v) {
	out.open("file.txt");
	for (auto el : v) {
		(*el).Writee(out);
	}
}