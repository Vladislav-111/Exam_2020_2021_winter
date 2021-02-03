#include "Bool_functions.h"
#include <fstream> //���������� ��� ������ � fstream
#include <bitset> //���������� ��� ������ � �������� ��������������

/* �� ��������� ������� �������� f ������� ������� ���������� ���������� ���������� n ���� �������. ����� ������� f ���� pow(2,n). */
int num_of_args(vector<bool> f) {
	int size = f.size(), n = 0; // size - ����� ������� �������, n - ���������� ���������� �������
	while (size > 1) { //����, ������������ ������� 2 �����
		size /= 2;
		n++;
	}
	return n;
}

/* �� ��������� ������������ � ����� ����� file_name ������� ������ �������� ������� ������� vector<bool>*/
vector<bool> read_from_file(std::string file_name)
{
	vector <bool> f;
	fstream fs;  //�������� ������� ��� ������ � �++
	string str;
	fs.open(file_name, std::fstream::in);  //�������� �����, �����: �� ������ 
	getline(fs, str); // ���������� ������ � ��������

	for (int i = 0; i < str.length(); i += 2) {
		if (str[i] == '1') f.push_back(1);
		else f.push_back(0);
	}

	fs.close();
	return f;
}

/*�������� �������� ������ �������� f ������� ������� � ����, ��������� ������������� � �������� ����� file_name. ������� true ��� �������� ������.*/
bool write_to_file(std::string file_name, vector<bool> f) {
	fstream fs;  //�������� ������� ��� ������ � �++
	fs.open(file_name, std::fstream::out);  //�������� �����, �����: �� ������
	if (fs.fail()) return false;

	for (int i = 0; i < f.size(); i++) fs << f[i] << " ";

	fs.close();

	return true;
}

/* �� ��������� ������� �������� f ������� ������� ������� ������, � ������� �������� ������� ���������� ���� ������� �������. */
std::string table(vector<bool> f) {
	string table = "", str, str_1;
	int num_args = num_of_args(f);
	for (int i = 0; i < num_args; i++) table = table + "x" + char(i + 49) + "\t"; // ����� �������
	table += "f \n";
	if (num_args == 2) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <2> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	} 
	else if (num_args == 3) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <3> b(i); // �������� ����������
			str_1 = b.to_string(); 
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 4) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <4> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 5) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <5> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 6) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <6> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 7) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <7> b(i); // �������� ����������
			str_1 = b.to_string(); 
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 9) {
		for (int i = 0; i < f.size(); i++) {
			str = "";
			bitset <8> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	else if (num_args == 10) {
		for (int i = 0; i < f.size(); i++) {
			str = ""; 
			bitset <9> b(i); // �������� ����������
			str_1 = b.to_string();
			for (int i = 0; i < num_args; i++) str = str + str_1[i] + "\t"; // ���������� ����������� ����� ����������
			table = table + str + char(f[i] + 48) + "\n"; // ������������ ������ ������� � ������ �������� ������� �� ������ ������
		}
	}
	return table;
}