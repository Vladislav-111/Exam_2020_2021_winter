#include <fstream> //���������� ��� ������ � fstream
#include <iostream>
#include "Header1.h"

/* �� ��������� ������� �������� f ������� ������� ���������� ���������� ���������� n ���� �������. ����� ������� f ���� pow(2,n). */
int num_of_args(vector<bool> f) {
	int size = f.size(), n = 0; // size - ����� ������� �������, n - ���������� ���������� �������
	while (size > 1) {          //���� ��� ����������� ������� 2 �����
		size /= 2;
		n++;
	}
	return n;
}

/* �� ��������� ������������ � ����� ����� file_name ������� ������ �������� ������� ������� vector<bool>*/
vector<bool> read_from_file(std::string file_name)
{
	vector <bool> f;
	fstream fs;								//�������� ������� ��� ������ � �++
	string str;
	fs.open(file_name, std::fstream::in);  //�������� �����, �� ������ 
	getline(fs, str);					   // ���������� ������ � ��������

	for (int i = 0; i < str.length(); i += 2) {
		f.push_back((bool)str[i]);

	}

	fs.close();
	return f;
}

/*�������� �������� ������ �������� f ������� ������� � ����, ��������� ������������� � �������� ����� file_name. ������� true ��� �������� ������.*/
bool write_to_file(std::string file_name, vector<bool> f) {
	fstream fs;								//�������� ������� ��� ������ � �++
	fs.open(file_name, std::fstream::out);  //�������� �����, �����: �� ������
	if (fs.fail()) return false;

	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";

	fs.close();

	return true;
}