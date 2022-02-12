#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <algorithm>
#include <stdlib.h>
#include <string>

using namespace std;

void AddNote(int*, string[], string[], string[]);
void DelNote(int*, string[], string[], string[]);
void ShowNote(int*, string[], string[], string[]);
void SortNote(int*, string[], string[], string[]);


void main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int *size = new int;
	*size = 5;
	string* arrName =	  new string[10]{	"����� � ������ �����",	"������������" ,		"1+1",							"�������",				"����� � �������",					"�������"};
	string* arrStyle =	  new string[10]{	"�������, ��������",	"����������, �����",	"�������, �����",				"������, ����������" ,	"�����������, ����������, �������",	"����������, ���������, ������"};
	string* arrDirector = new string[10]{	"��� ������",			"��������� �����",		"������ �����, ���� ��������",	"���� ���������",		"������ �������",					"������ ��������"};
	cout << "������� �������\n\n";

	while (true) 
	{
		int a;
		cout << "������� ����� ������� ������\n1. �������� ����� �����\n2. ������� �����\n3. ������� ���� ������ �������\n4. �������������� ������ �� ������������ ����\n0. �����\n\n";
		cin >> a;
		system("cls");
		switch (a) 
		{
			case(0): {cout<<"�����\n"; return; }
			case(1): {AddNote(size, arrName, arrStyle, arrDirector); break; }
			case(2): {DelNote(size, arrName, arrStyle, arrDirector); break; }
			case(3): {ShowNote(size, arrName, arrStyle, arrDirector); break; }
			case(4): {SortNote(size, arrName, arrStyle, arrDirector); break; }
			default: {cout << "�������� �������\n\n"; break; }
		}

	}
}



void AddNote(int *size, string arrName[], string arrStyle[], string arrDirector[])
{
	if (*size >= 10) {
		cout << "\n�������� ����� �������. �����\n\n";
		return;
	}
	cout << "\n�� ������� \"�������� ����� ������\"\n\n";
	string newName, newStyle, newDirector;
	
	cout << "������� �������� ������\n";
	cin.get();
	getline(cin, newName);
	cout << "������� ����(�, ����� �������)\n";
	getline(cin, newStyle);
	cout << "������� �� ��������\n";
	getline(cin, newDirector);
	
	system("cls");

	/*while (true)
	{
		cout << "\n�����: " << newName << " ����(�): " << newStyle << " �������: " << newDirector << endl;
		cout << "1. ������\t2. ��������\n����� ������ ����� - �����\n";
		int succ;
		cin >> succ;
		switch (succ) {
			case(1): { cout << "������\n\n"; break; }
			case(2):
			{
				cout << "\n�������� ��� ��������\n1. �������� ������\n2. ����(�)\n3. ��������\n����� ������ ����� ����� �� ��������������\n";
				int s;
				cin >> s;
				switch (s) {
				case(1):
				{
					cout << "�����: ";
					cin.get();
					getline(cin, newName);
					break;
				}
				case(2):
				{
					cout << "����(�, ����� �������): ";
					cin.get();
					getline(cin, newStyle);
					break;
				}
				case(3):
				{
					cout << "�������: ";
					cin.get();
					getline(cin, newDirector);
					break;
				}
				default: {cout << "\n����� �� ��������������\n"; break; }
				}
				break;
			}
			default: {cout << "�����\n\n"; break; }
		}
	}*/

	arrName[*size] = newName;
	arrStyle[*size] = newStyle;
	arrDirector[*size] = newDirector;

	cout << "\n�������� �����: " << newName << " �����(��): " << newStyle << " ������� ������: " << newDirector << endl;

	system("cls");

	(*size)++;
	cout << endl;
	};




void DelNote(int* size, string arrName[], string arrStyle[], string arrDirector[])
{
	cout << "\n�� ������� \"������� ������\"\n\n";
	int countErr = 0;
	if (*size == 0) { cout << "������ ������, ������� �������� �����\n\n"; return; }
	if (*size == 1)
	{
		while (true) {
			cout << "� ������ ������� ���� �����, ������� ���?\n1. ��\t2. ���\n";
			int l;
			cin >> l;
			switch (l) {
			case(1): {cout << "������ �������� �����\n\n"; (*size)--; return; }
			case(2): {cout << "�����\n\n"; return; }
			default: {cout << "\n������ �����,������� ��� ���\n\n"; break; }
			}
		}
	}

	cout << "����� ��\n1. �����y � �������\n2. �������� ������\n����� ������ ����� - �����\n";
	int g;
	cin >> g;
	system("cls");
	switch (g) {
		case(1): 
		{
			while (true) {
				cout << "\n������� ����� ���������� ������ (0. �����): ";
				int x;
				cin >> x;
				x--;
				if (*size < x) { cout << "\n������� �������� ��������\n"; continue; }
				if (x == -1) { cout << "�����\n\n"; break; }
				cout << "\n������� \"" << arrName[x] << "\" �� �������\n1. ��\t2. ���\t0. �����\n";
				int p;
				cin >> p;
				if (p == 0) break;
				if (p == 2) continue;
				if (p == 1)
				{
					if (x == ((*size) - 1)) { cout << "\n������ �������� �����\n"; (*size)--; }
					else {
						(*size)--;
						arrName[x] = arrName[*size];
						arrStyle[x] = arrStyle[*size];
						arrDirector[x] = arrDirector[*size];
					}
				}
			}
			break;
		}
		case(2):
		{
			/*int I;
			while (true) {
				cout << "������� �������� ������ (0. �����)\n";
				string str;
				cin.get();
				getline(cin, str);
				if (str == "0") break;
				int maxCou = 0;
				int delI = 0;
				for (int i = 0; i < *size; i++)
				{
					int countA = 0;
					int len = 0;
					if (arrName[i].length() < str.length()) len = arrName[i].length();
					else len = str.length();
					for (int j = 0; j < len; j++)
					{
						if (arrName[i][j] == str[j]) countA++;
					}
					if (countA > maxCou) {
						maxCou = countA;
						delI = i;
					}
				}
				if (delI < 1) { I = delI; break; }
			}*/
			cout << "������� �������� ������ (0. �����)\n";
			string str;
			cin.get();
			getline(cin, str);
			system("cls");
			if (str == "0") break;
			for (int i = 0; i < *size; i++) {
				if (arrName[i] == str) {
					cout << "�� ������ ������� \"" << arrName[i] << "\" �� �������\n1. ��\t2. ���\t0. �����\n";
					int q;
					cin >> q;
					system("cls");
					switch (q) {
						case(2): {cout << "������\n"; break; }
						case(0): {cout << "�����\n"; return; }
						case(1): {
							if (i == ((*size) - 1)) { cout << "\n������ �������� �����\n"; (*size)--; }
							else {
								(*size)--;
								arrName[i] = arrName[*size];
								arrStyle[i] = arrStyle[*size];
								arrDirector[i] = arrDirector[*size];
							}
						}
					}
					system("cls");
				}
			}

			break;
		}
		default: {cout << "����� �� ��������\n\n"; break; }
	}
	cout << endl;
};




void ShowNote(int* size, string arrName[], string arrStyle[], string arrDirector[])
{
	cout << "\n�� ������� \"������� ���� ������ �������\"\n\n";

	if (*size == 0) { cout << "������ ������, ������� �������� �����\n\n"; return; }

	int maxLenName = 8;
	int maxLenStyle = 7;
	int maxLenDirector = 11;
	int maxLength = 10;
	for (int i = 0; i < *size; i++) {
		int LenName = arrName[i].length();
		int LenStyle = arrStyle[i].length();
		int LenDirector = arrDirector[i].length();
		if (LenName > maxLenName) {
			maxLenName = LenName;
		}
		if (LenStyle > maxLenStyle) {
			maxLenStyle = LenStyle;
		}
		if (LenDirector > maxLenDirector) {
			maxLenDirector = LenDirector;
		}
	}
	maxLength += maxLenName + maxLenStyle + maxLenDirector;
	//cout << endl << maxLength << "\t" << maxLenName << "\t" << maxLenStyle << "\t" << maxLenDirector << endl;

	for (int i = 0; i < (maxLength/2)-3; i++) { cout << " "; }
	cout << "������" << endl;

	for (int i = 0; i < maxLength; i++) { cout << "-"; }
	cout << endl;

	printf_s("| %*s | %*s | %*s |", maxLenName, "������", maxLenStyle, "�����", maxLenDirector, "��������");
	cout << endl;

	for (int i = 0; i < maxLength; i++) { cout << "-"; }
	cout << endl;

	for (int i = 0; i < *size; i++) {
		printf_s("| %*s | %*s | %*s |", maxLenName, arrName[i].c_str(), maxLenStyle, arrStyle[i].c_str(), maxLenDirector, arrDirector[i].c_str());
		cout << endl;
		for (int i = 0; i < maxLength; i++) { cout << "-"; }
		cout << endl;
	}

	cout << endl << endl;
};




void SortNote(int* size, string arrName[], string arrStyle[], string arrDirector[])
{
	cout << "\n�� ������� \"�������������� �� ������������ ����\"\n\n";

	cout << "���������� ��\n1. ��������� �������\n2. ������\n3. ���������\n0.�����\n\n";
	int d; cin >> d;
	switch (d) {
		case(0): {cout << "�����\n\n"; return; }
		case(1): {
			cout << "���������� �� ��������\n1. �� ������������\n2. �� ��������\n0. �����\n";
			int l; cin >> l;
			switch (l) {
				case(0): {cout << "�����\n\n"; break; }
				case(1): {
					for (int i = 1; i < *size; i++) {
						for (int j = 0; j < (*size) - i; j++) {
							if (arrName[j] > arrName[j + 1]) {
								string temp = arrName[j];
								arrName[j] = arrName[j + 1];
								arrName[j + 1] = temp;
								temp = arrStyle[j];
								arrStyle[j] = arrStyle[j + 1];
								arrStyle[j + 1] = temp;
								temp = arrDirector[j];
								arrDirector[j] = arrDirector[j + 1];
								arrDirector[j + 1] = temp;
							}
						}
					}
					break;
				}
				case(2): {
					for (int i = 1; i < *size; i++) {
						for (int j = 0; j < (* size) - i; j++) {
							if (arrName[j] < arrName[j + 1]) {
								string temp = arrName[j];
								arrName[j] = arrName[j + 1];
								arrName[j + 1] = temp;
								temp = arrStyle[j];
								arrStyle[j] = arrStyle[j + 1];
								arrStyle[j + 1] = temp;
								temp = arrDirector[j];
								arrDirector[j] = arrDirector[j + 1];
								arrDirector[j + 1] = temp;
							}
						}
					}
					break;
				}
				default: {cout << "�����\n\n"; break; }
			}
			break;
		}
		case(2): {
			cout << "\n������� ���� (0. �����)\n";
			string y;
			cin.get();
			getline(cin, y);
			if (y == "0")break;
			int m = *size;
			int *assArr = new int[*size], 
				*delArr = new int[*size];
			int counterA = 0, counterE = 0;
			for (int i = 0; i < m; i++) {
				bool finded = false;
				(((arrStyle[i]).find(y)) != std::string::npos ? finded = true : finded = false);
				//(s.find("�����") != std::string::npos ? "����" : "���")
				if (finded == true) { counterA++;  assArr[counterA] = i; }
				if (finded == false) { counterE++;  delArr[counterE] = i; }
			}
			if (counterA == 0) { cout << "\n������ �� �������\n\n"; }
			else {
				cout << "\n������������� �� ����� \"" << y << "\"\n1. ��\t2. ���\n����� ������ ����� - �����\n";
				int h; cin >> h;
				cout << endl;
				if (h == 2) { cout << "�����\n\n"; break; }
				if (h == 1) {
					int e = 0;
					int couAss = 0;
					int couDel = 0;
					for (int i = 0; i < counterA; i++) {
						int couA = (couAss % counterA) + 1,
							couE = (couDel % counterE) + 1;
						//cout << assArr[couA]<<endl<<delArr[couE];
						if (assArr[couA] > delArr[couE]) {
							string str = arrName[assArr[couA]];
							arrName[assArr[couA]] = arrName[delArr[couE]];
							arrName[delArr[couE]] = str;
							str = arrStyle[assArr[couA]];
							arrStyle[assArr[couA]] = arrStyle[delArr[couE]];
							arrStyle[delArr[couE]] = str;
							str = arrDirector[assArr[couA]];
							arrDirector[assArr[couA]] = arrDirector[delArr[couE]];
							arrDirector[delArr[couE]] = str;
							int tem = assArr[couA];
							assArr[couA] = delArr[couE];
							delArr[couE] = tem;
							couAss++;
						}
						else couDel++;
					}
					(*size) -= counterE;
				}
			}
			break; 
		}
		case(3): {
			cout << "���������� �� ��������\n1. �� ������������\n2. �� ��������\n0. �����\n";
			int l; cin >> l;
			switch (l) {
			case(0): {cout << "�����\n\n"; break; }
			case(1): {
				for (int i = 1; i < *size; i++) {
					for (int j = 0; j < (*size) - i; j++) {
						if (arrDirector[j] > arrDirector[j + 1]) {
							string temp = arrName[j];
							arrName[j] = arrName[j + 1];
							arrName[j + 1] = temp;
							temp = arrStyle[j];
							arrStyle[j] = arrStyle[j + 1];
							arrStyle[j + 1] = temp;
							temp = arrDirector[j];
							arrDirector[j] = arrDirector[j + 1];
							arrDirector[j + 1] = temp;
						}
					}
				}
				break;
			}
			case(2): {
				for (int i = 1; i < *size; i++) {
					for (int j = 0; j < (*size) - i; j++) {
						if (arrDirector[j] < arrDirector[j + 1]) {
							string temp = arrName[j];
							arrName[j] = arrName[j + 1];
							arrName[j + 1] = temp;
							temp = arrStyle[j];
							arrStyle[j] = arrStyle[j + 1];
							arrStyle[j + 1] = temp;
							temp = arrDirector[j];
							arrDirector[j] = arrDirector[j + 1];
							arrDirector[j + 1] = temp;
						}
					}
				}
				break;
			}
			default: {cout << "�����\n\n"; break; }
			}
			cout << endl;
			break;
		}
		default: {cout << "�����\n\n"; return; }
	}
};