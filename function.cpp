#include "function.h"
#include <iostream>
#include <vector> //��� ��������
#include <string> //��� ����� �����
#include <fstream> //��� ������ � ������ ������

using namespace std;

int function::num_of_args(vector<bool> f) {
	int n = 0;
	int t = f.size(); //����� ��� �������� n
	for (int i = 0; i < f.size(); i++) {
		while (t != 1) {
			t = t / 2;
			n++;
		}
	}
	cout << "� ������� " << n << " ���������" << endl;
	return n;
}

vector<bool> function::read_from_file(std::string file_name) { //C:\Users\DELL Inspiron\Desktop\file_name.txt
	bool p = 0;
	ifstream file(file_name);  //��������� ���� �� ������� ��� ������
	if (!file) { //���������, ���� ��������� ���� ��� ���
		p = 0;
	}
	else {
		p = 1;
	}
	//ofstream file(file_name);  //��������� ����
	string s;
	vector<bool> f;
	while (!file.eof()) { //���������, �������� �� ����
		getline(file, s);  //��������� ��������� �����
	}
	for (int i = 0; i < s.size(); i++) {
		f.push_back(s[i]); //��������� ������ � ����� �������
	}
	file.close();  //��������� ����
	if (p == 0) {
		std::cout << "������" << std::endl;
	}
	if (p == 1) {
		std::cout << "������ �������� ������� �������: " << std::endl;
	}
	return f;
}

bool function::write_to_file(std::string file_name, vector<bool> f) {
	bool p = 0;
	ifstream file(file_name);  //��������� ���� �� ������� ��� ������
	if (!file) { //���������, ���� ��������� ���� ��� ���
		p = 0;
	}
	else {
		p = 1;
	}
	ofstream filecopy(file_name);  //��������� ����
	string s;
	int i = 0;
	while (i != f.size()) { //���������, �������� �� ������
		filecopy << f[i]; //��������� ������ � ����
		i++;
	}
	file.close();  //��������� ����
	if (p == 0) {
		std::cout << "������" << std::endl;
	}
	if (p == 1) {
		std::cout << "�������� ����������" << std::endl;
	}
	return 0;
}

std::string function::table(vector<bool> f) {
	string text;
	return text;
}

std::string function::func_sdnf(vector<bool> f) {
	string text;
	return text;
}

std::string function::func_sknf(vector<bool> f) {
	string text;
	return text;
}

std::string function::func_Zhegalkin(vector<bool> f) {
	string text;
	return text;
}

//������ ����� ��������

std::string roman_to_arab(std::string roman_number){
	int num = 0; //���������� �������� �������� �����
	for (int i = 0; i < roman_number.size(); i++) {
		if (roman_number[i] == 'I') {
			if ((roman_number[i + 1] == 'I') || (i == (roman_number.size() - 1))) //�������� ���� �� ����� 1 ����� ����� 1, ����� �������� ������ 1
				num++;
		}
		if (roman_number[i] == 'V') {
			if (roman_number[i - 1] == 'I') //�������� 5
				num = num + 4;
			else
				num = num + 5;
		}
		if (roman_number[i] == 'X') {
			if (roman_number[i - 1] == 'I') //�������� 10
				num = num + 9;
			if ((roman_number[i + 1] != 'L') && (roman_number[i + 1] != 'C')) //������������ ����� �� ������� �������
				num = num + 10;
		}
		if (roman_number[i] == 'L') {
			if ((i != 0) && (roman_number[i - 1] == 'X')) //�������� 50
				num = num + 40;
			else
				num = num + 50;
		}
		if (roman_number[i] == 'C') {
			if ((i != 0) && (roman_number[i - 1] == 'X'))//�������� 100
				num = num + 90;
			if ((roman_number[i + 1] != 'D') && (roman_number[i + 1] != 'M')) //������������ ����� �� ������� �������
				num = num + 100;
		}
		if (roman_number[i] == 'D') {
			if ((i != 0) && (roman_number[i - 1] == 'C'))//�������� 500 
				num = num + 400;
			else
				num = num + 500;
		}
		if (roman_number[i] == 'M') {
			if ((i != 0) && (roman_number[i - 1] == 'C'))//�������� 1000
				num = num + 900;
			else
				num = num + 1000;
		}
	}
	cout << num;
	string text;
	return text;
}

int pasc(int n, int k) {//��� ������� ����� ��������� ����������� �������
	return ((n < k) ? 0 : ((k == 0) ? 1 : ((n - k + 1) / int(k) * pasc(n, k - 1)))); // ���������� ������ ������������ �������
}

std::vector<int> func_Pascal(int k) {
	vector<int> f;
	for (int i = 0; i <= k; i++){
		if (i == k){
			for (int j = 0; j <= i; j++){
				cout << pasc(i, j) << " "; //����� ����� ������������ �������
			}
		}
	}
	return f;
}

int func_substr_len(std::string input_str) {
	bool p = 1; //��� �������� ����������
	int k = 0; //������� ����������
	int max = k; //������������ ����� ��� ����������
	vector<char> f; //������ ��� 
	for (int i = 0; i < input_str.size(); i++) {
		if (input_str[i] != input_str[i + 1]) {
			k++;
			for (int j = 0; j < f.size(); j++) { //�������� ���������� ��� �������� ����
				if (f[j] == input_str[i])
					p = 0;
			}
			f.push_back(input_str[i]); //���������� ����� ����
		}
		else {
			k = 0;
			f.clear(); //��������� ������
		}

		if ((k >= max) && (p == 1)) { //������ �������� �����
			max = k;
		}
	}
	cout << max;
	return max;
}