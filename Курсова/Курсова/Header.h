#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <Windows.h>
#include<fstream>

using namespace std;

class Product {
protected:
	string name;
	double price;
	int number;
	string firm;

public:
	Product(){}
	Product(string name, double price, int number, string firm) : name{ name }, price{ price }, number{ number }, firm{ firm } {}

	virtual string& Name() = 0;

	virtual double& Price() = 0;

	virtual int& Number() = 0;

	virtual string& Firm() = 0;

	virtual void Write(ostream& out) = 0;

	virtual void Read(istream& in) = 0;

	virtual void Print() = 0;

	virtual char Type() = 0;

	virtual char& Currency() = 0;

	virtual void Writee(ofstream& out) = 0;
};

class Computer : public Product {
private:
	int diagonal;
	const static char type = 'c';
	static char money;
public:
	Computer() {};
	Computer(string name, double price, int number, string firm, int diagonal) : Product(name, price, number, firm)
	{
		this->diagonal = diagonal;
	}

	char Type() override
	{
		return type;
	}

	char& Currency()override
	{
		return money;
	}

	string& Name() override{
		return name;
	}

	double& Price() override{
		return price;
	}

	int& Number() override{
		return number;
	}

	string& Firm() override{
		return firm;
	} 

	int& Diagonal() {
		return diagonal;
	}

	void Write(ostream& out) override
	{
		//Type
		out.write((char*)&type, sizeof(char));
		//name
		int size = name.length();
		out.write((char*)&size, sizeof(int));
		const char* mas = name.data();
		out.write(mas, sizeof(char) * size);
		//price
		out.write((char*)&price, sizeof(double));
		//number
		out.write((char*)&number, sizeof(int));
		//firm
		size = firm.length();
		out.write((char*)&size, sizeof(int));
		const char* mass = name.data();
		out.write(mass, sizeof(char) * size);
		out.write((char*)&diagonal, sizeof(int));
	}

	void Read(istream& in) override
	{
		//name
		int size;
		in.read((char*)&size, sizeof(int));
		char* mas = new char[size];
		in.read((char*)mas, sizeof(char));
		for (size_t i = 0; i < size; i++) {
			name[i] = mas[i];
		}
		//price
		in.read((char*)&price, sizeof(double));
		//number
		in.read((char*)&number, sizeof(int));
		//firm
		in.read((char*)&size, sizeof(int));
		char* mass = new char[size];
		in.read((char*)mass, sizeof(char));
		for (size_t i = 0; i < size; i++) {
			firm[i] = mass[i];
		}
		in.read((char*)&diagonal, sizeof(int));
	}


	void Writee(ofstream& out) override{
		if (out.is_open()) {
			out << "\tComputer" << endl;
			out << "Name: " << name << endl;
			out << "Price: " << price << endl;
			out << "Number: " << number << endl;
			out << "Firm: " << firm << endl;
			out << "Diagonal: " << diagonal << endl;
		}
	}

	void Print() override
	{
		cout << "Computer:" << endl;
		cout << "Name: " << name << endl;
		cout << "Price: " << price << endl;
		cout << "Number which remain: " << number << endl;
		cout << "Firm: " << firm << endl;
		cout << "Diagonal: " << diagonal << endl;
		cout << "---------" << endl;
	}
};

class Telephone : public Product {
	int memory;
	const static char type = 't';
	static char money;
public:
	Telephone(){}
	Telephone(string name, double price, int number, string firm, int memory) : Product(name, price, number, firm)
	{
		this->memory = memory;
	}

	char& Currency()override
	{
		return money;
	}

	char Type()override
	{
		return type;
	}

	string& Name() override {
		return name;
	}

	double& Price() override{
		return price;
	}

	int& Number() override {
		return number;
	}

	string& Firm() override{
		return firm;
	}

	int& Memory() {
		return memory;
	}

	void Write(ostream& out) override
	{
		out.write((char*)&type, sizeof(char));
		//name
		int size = name.length();
		out.write((char*)&size, sizeof(int));
		const char* mas = name.data();
		out.write(mas, sizeof(char) * size);
		//price
		out.write((char*)&price, sizeof(double));
		//number
		out.write((char*)&number, sizeof(int));
		//firm
		size = firm.length();
		out.write((char*)&size, sizeof(int));
		const char* mass = name.data();
		out.write(mass, sizeof(char) * size);
		out.write((char*)&memory, sizeof(int));
	}

	void Read(istream& in) override
	{
		int size;
		in.read((char*)&size, sizeof(int));
		char* mas = new char[size];
		in.read((char*)mas, sizeof(char));
		for (size_t i = 0; i < size; i++) {
			name[i] = mas[i];
		}
		//price
		in.read((char*)&price, sizeof(double));
		//number
		in.read((char*)&number, sizeof(int));
		//firm
		in.read((char*)&size, sizeof(int));
		char* mass = new char[size];
		in.read((char*)mass, sizeof(char));
		for (size_t i = 0; i < size; i++) {
			firm[i] = mass[i];
		}
		in.read((char*)&memory, sizeof(int));
	}

	void Writee(ofstream& out) override {
		if (out.is_open()) {
			out << "\tTelephone" << endl;
			out << "Name: " << name << endl;
			out << "Price: " << price << endl;
			out << "Number: " << number << endl;
			out << "Firm: " << firm << endl;
			out << "Memory: " << memory << endl;
		}
	}

	void Print() override
	{
		cout << "Telephone:" << endl;
		cout << "Name: " << name << endl;
		cout << "Price: " << price << endl;
		cout << "Number which remain: " << number << endl;
		cout << "Firm: " << firm << endl;
		cout << "Amount of memory: " << memory << endl;
		cout << "---------" << endl;
	}
};

class HeadPhones : public Product {
private:
	const static char type = 'h';
	static char money;
public:
	HeadPhones(){}
	HeadPhones(string name, double price, int number, string firm) : Product(name, price, number, firm) {}

	char Type() override
	{
		return type;
	}

	char& Currency()override
	{
		return money;
	}

	string& Name() override {
		return name;
	}

	double& Price() override {
		return price;
	}

	int& Number() override {
		return number;
	}

	string& Firm() override{
		return firm;
	}

	//std::ofstream out;			// поток для записи
	//out.open("D:\\hello.txt"); // окрываем файл для записи
	//if (out.is_open())
	//{
	//	out << "Hello World!" << std::endl;
	//}

	//std::cout << "End of program" << std::endl;
	//return 0;
	void Writee(ofstream& out) override {
		if (out.is_open()) {
			out << "\tHeadphones" << endl;
			out << "Name: " << name << endl;
			out << "Price: " << price << endl;
			out << "Number: " << number << endl;
			out << "Firm: " << firm << endl;
		}
	}

	void Write(ostream& out) override
	{
		out.write((char*)&type, sizeof(char));
		//name
		int size = name.length();
		out.write((char*)&size, sizeof(int));
		const char* mas = name.data();
		out.write(mas, sizeof(char) * size);
		//price
		out.write((char*)&price, sizeof(double));
		//number
		out.write((char*)&number, sizeof(int));
		//firm
		size = firm.length();
		out.write((char*)&size, sizeof(int));
		const char* mass = name.data();
		out.write(mass, sizeof(char) * size);
	}

	void Read(istream& in) override
	{
		//name
		int size;
		in.read((char*)&size, sizeof(int));
		char* mas = new char[size];
		in.read((char*)mas, sizeof(char));
		for (size_t i = 0; i < size; i++) {
			name[i] = mas[i];
		}
		//price
		in.read((char*)&price, sizeof(double));
		//number
		in.read((char*)&number, sizeof(int));
		//firm
		in.read((char*)&size, sizeof(int));
		char* mass = new char[size];
		in.read((char*)mass, sizeof(char));
		for (size_t i = 0; i < size; i++) {
			firm[i] = mass[i];
		}
	}

	void Print() override
	{
		cout << "Headphones:" << endl;
		cout << "Name: " << name << endl;
		cout << "Price: " << price << endl;
		cout << "Number which remain: " << number << endl;
		cout << "Firm: " << firm << endl;
		cout << "---------" << endl;
	}
};

char Computer::money = 'g';
char Telephone::money = 'g';
char HeadPhones::money = 'g';