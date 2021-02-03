#include "function.h"
#include <iostream>
#include <vector>
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
	ofstream file(file_name);  //��������� ����
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

	return 0;
}

std::string function::func_sdnf(vector<bool> f) {

	return 0;
}

std::string function::func_sknf(vector<bool> f) {
	
	return 0;
}

std::string function::func_Zhegalkin(vector<bool> f) {

	return 0;
}