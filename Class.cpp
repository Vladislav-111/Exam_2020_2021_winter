#include "Class.h"
#include <fstream> 
#include <iostream>
#include <bitset>
int num_of_args(std::vector<bool> f)//�� ��������� ������� �������� f ������� ������� ���������� ���������� ���������� n ���� �������. ����� ������� f ���� pow(2,n).
{
	return (int)log2(f.size());;
}

vector<bool> read_from_file(std::string file_name)// �� ��������� ������������ � ����� ����� file_name ������� ������ �������� ������� ������� vector<bool>
{
	vector <bool> f;
	fstream fs; 
	string str;
	fs.open(file_name, std::fstream::in);  //�������� ����� �� ������ 
	getline(fs, str); // ���������� ������

	for (int i = 0; i < str.length(); i += 2) {
		if (str[i] == '1') f.push_back(1);
		else f.push_back(0);
	}

	fs.close();
	return f;
}
bool write_to_file(std::string file_name, vector<bool> f) { //�������� �������� ������ �������� f ������� ������� � ����, ��������� ������������� � �������� ����� file_name. ������� true ��� �������� ������.
	fstream fs;  
	fs.open(file_name, std::fstream::out);  //�������� ����� �� ������
	if (fs.fail()) return false;
	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";
	fs.close();
	return true;

}