#include "Header.h"
#include "functions.h"

//Відділ компютерної техніки

HANDLE g = GetStdHandle(STD_OUTPUT_HANDLE);

void main() {
	vector<Product *> v;
	Product* c = new Computer("computer1", 3400, 4, "firm1", 13);
	Product* t = new Telephone("telephone1", 4000, 19, "firm2", 128);
	Product* h = new HeadPhones("headphones1", 120, 45, "firm3");
	v.push_back(c);
	v.push_back(t);
	v.push_back(h);

	bool C = true; string name; bool T = true; int choose;
	
	if (v.empty())
		C = false;
	
	while (T) {
		cout << char(201); Table(205, 60); cout << char(187) << endl;
		cout << char(186) << "\t\t\tMenu"; space(33); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 1 to refill your base"; space(31); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 2 to show all products"; space(30); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 3 to add new product"; space(32); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 4 to delete one product"; space(29); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 5 to organize your products"; space(25); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 6 to show products which are in certain price range"; space(1); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 7 to show producr by certain firm"; space(19); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 8 to convert price"; space(34); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "~Choose 9 to write into file"; space(32); cout << char(186) << endl;
		cout << char(204); Table(205, 60); cout << char(185) << endl;
		cout << char(186) << "10 - exit"; space(51); cout << char(186) << endl;
		cout << char(200); Table(205, 60); cout << char(188) << endl;
		cout << "\nYour choose: ";
		cin >> choose;
		cout << endl;

		if (choose == 1) {
			system("cls");
			Refil(v);
			if (v.empty())
				C = false;
		}

		else if (choose == 2) {
			system("cls");
			if (C)
				Print(v);
			else {
				SetConsoleTextAttribute(g, 4);
				cout << "You have no products in base." << endl;
				SetConsoleTextAttribute(g, 7);
			}
		}

		else if (choose == 3) {
			system("cls");
			Add(v);
		}

		else if (choose == 4) {
			bool F = true;
			while (F) {
				system("cls");
				cout << "Enter name: ";
				cin.ignore();
				getline(cin, name);
				if (C)
					Delete(v, name, F);
				else {
					SetConsoleTextAttribute(g, 4);
					cout << "You have no goods in base." << endl;
					SetConsoleTextAttribute(g, 7);
				}
			}
		}

		else if (choose == 5) {
			system("cls");
			bool F = true;
			int chose;
			while (F) {
				if (C) {
					cout << "Choose:\n1 - to sort by Price\n2 - to sort by Name\n3 - to sort bu Number\n4 - to sort by Firm" << endl;
					cin >> chose;
					switch (chose) {
					case 1: SortPrice(v); F = false;  break;
					case 2: SortName(v); F = false; break;
					case 3: SortNumber(v); F = false; break;
					case 4: SortFirm(v); F = false; break;
					default: 
						system("cls");
						F = true;
						SetConsoleTextAttribute(g, 4);    
						cout << "Choose correct number" << endl; 
						SetConsoleTextAttribute(g, 7); 
						Sleep(500); 
						Sleep(500); 
						Sleep(500); 
						system("cls");  
						break;
					}
				}

				else {
					SetConsoleTextAttribute(g, 4);
					cout << "You have no goods in base." << endl;
					SetConsoleTextAttribute(g, 7);
				}
			}
		}


		else if (choose == 6) {
			system("cls");
			bool F = true;
			int chose;
			int price;
			while (F) {
				if (C) {
					cout << "Choose:\n1 - to show Computers\n2 - to show Telephones\n3 - to show Headphones\nChoose: ";
					cin >> chose;
					system("cls");
					cout << "Choose price: ";
					cin >> price;
					switch (chose) {
					case 1: ShowCmputerByPrice(v, price); F = false;  break;
					case 2: ShowTelephoneByPrice(v, price); F = false; break;
					case 3: ShowHeadphoneByPrice(v, price); F = false; break;
					default:
						system("cls");
						F = true;
						SetConsoleTextAttribute(g, 4);
						cout << "Choose correct number" << endl;
						SetConsoleTextAttribute(g, 7);
						Sleep(500);
						Sleep(500);
						Sleep(500);
						system("cls");
						break;
					}
				}

				else {
					SetConsoleTextAttribute(g, 4);
					cout << "You have no goods in base." << endl;
					SetConsoleTextAttribute(g, 7);
				}
			}
		}
		else if (choose == 7) {
		system("cls");
		bool F = true;
		int chose;
		string firm;
		while (F) {
			if (C) {
				cout << "Choose:\n1 - to show Computers\n2 - to show Telephones\n3 - to show Headphones\nChoose: ";
				cin >> chose;
				system("cls");
				cout << "Choose firm: ";
				cin >> firm;
				switch (chose) {
				case 1: ShowFirmComputers(v, firm); F = false;  break;
				case 2: ShowFirmTelphones(v, firm); F = false; break;
				case 3: ShowFirmHeadphones(v, firm); F = false; break;
				default:
					system("cls");
					F = true;
					SetConsoleTextAttribute(g, 4);
					cout << "Choose correct number" << endl;
					SetConsoleTextAttribute(g, 7);
					Sleep(500);
					Sleep(500);
					Sleep(500);
					system("cls");
					break;
				}
			}

			else {
				SetConsoleTextAttribute(g, 4);
				cout << "You have no goods in base." << endl;
				SetConsoleTextAttribute(g, 7);
			}
		}
		}
		else if (choose == 8) {
			if (C) {
				Convert(v);
			}
			else {
				SetConsoleTextAttribute(g, 4);
				cout << "You have no goods in base." << endl;
				SetConsoleTextAttribute(g, 7);
			}
		}
		else if (choose == 9) {
		if (C) {
			ofstream out;
			Write(out, v);
		}
		else {
			SetConsoleTextAttribute(g, 4);
			cout << "You have no goods in base." << endl;
			SetConsoleTextAttribute(g, 7);
		}
		}
		/*else if (choose == 9) {
			if (C) {
				ofstream fout;
				fout.open("file.bin", ios::binary);
				int sizeV = v.size();
				fout.write((char*)&sizeV, sizeof(int));
				for (auto el : v)
				{
					(*el).Write(fout);
				}

				fout.close();			}
			else {
				SetConsoleTextAttribute(h, 4);
				cout << "You have no goods in base." << endl;
				SetConsoleTextAttribute(h, 7);
			}
		}*/
		/*else if (choose == 10) {
			if (C){
				ifstream fin;
				fin.open("file.bin", ios::binary);
				int sizeV2; char type;
				fin.read((char*)&sizeV2, sizeof(int));
				vector<Product*> newV(sizeV2);
				for (int i = 0; i < newV.size(); i++)
				{
					fin.read((char*)&type, sizeof(char));
					if (type == 'c') {
						Product* pr = new Computer;
						newV.push_back(pr);
					}
					if (type == 't') {
						Product* pr = new Telephone;
						newV.push_back(pr);
					}
					if (type == 'h') {
						Product* pr = new HeadPhones;
						newV.push_back(pr);
					}
					(*newV[i]).Read(fin);
				}
				fin.close();
		}
			else {
				SetConsoleTextAttribute(h, 4);
				cout << "You have no goods in base." << endl;
				SetConsoleTextAttribute(h, 7);
			}
		}*/
		else if (choose == 10)
			T = false;
		else
			cout << "Please, choose correct" << endl;

		system("pause");
		system("cls");
	}

	SetConsoleTextAttribute(g, 4);
	cout << "Goodbye" << endl;
	SetConsoleTextAttribute(g, 7);
	delete c;
	delete t;
	delete h;
}